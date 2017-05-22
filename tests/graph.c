#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "graph.h"


struct s_Node{
	int x;
	int y;
	int color;
	Node* neighbors;
	int nbNeighbors;
};

struct s_Graph{
	Node W1; // Bord Haut
	Node W2; // Bord Bas
	Node B1; // Bord Gauche
	Node B2; // Bord Droite
	int size;
};

Graph graph_malloc () {
    Graph tmp = (Graph) malloc (sizeof(struct s_Graph));
    return tmp;
}

Node node_malloc(){
	Node tmp = (Node) malloc (sizeof(struct s_Node));
	return tmp;
}

Node* neighbors_malloc(int size) {
    Node* neighbors = (Node*) malloc (sizeof(struct s_Node*)*size);
    return neighbors;
}

void init_bord (Graph g) {
    g -> W1 = node_malloc();
    g -> W1 -> nbNeighbors = g -> size;
    g -> W1 -> color = WHITE;
    g -> W1 -> x = -1;
    g -> W1 -> neighbors = neighbors_malloc(g -> size);


    g -> W2 = node_malloc();
    g -> W2 -> nbNeighbors = g -> size;
    g -> W2 -> color = WHITE;
    g -> W2 -> x = g->size;
    g -> W2 -> neighbors = neighbors_malloc(g -> size);


    g -> B1 = node_malloc();
    g -> B1 -> nbNeighbors = g -> size;
    g -> B1 -> color = BLACK;
    g -> B1 -> x = -1;
    g -> B1 -> neighbors = neighbors_malloc(g -> size);


    g -> B2 = node_malloc();
    g -> B2 -> nbNeighbors = g -> size;
    g -> B2 -> color = BLACK;
    g -> B2 -> x = g->size;
    g -> B2 -> neighbors = neighbors_malloc(g -> size);
}

void init_nbNeighbors (Node n, int size) {
    n -> nbNeighbors = 6;
    if(n->x==0 || n->x==size-1 || n->y==0 || n->y==size-1){
        n -> nbNeighbors = 5;
    }

    if((n->y==0 && n->x==0) || (n->y==size-1 && n->x==size-1) ){
        n -> nbNeighbors = 4;
    }
}

Graph graph_create (int* tab) {
    Graph g = graph_malloc();
    g -> size = tab[0];
    init_bord(g);
    Node mat [tab[0]][tab[0]];

    for(int x=0; x<g -> size;x++){
        for(int y=0; y<g -> size;y++){
            int i = tab[0]*x+y+1;

            Node tmp = node_malloc();
            tmp -> x = x;
            tmp -> y = y;
            init_nbNeighbors(tmp,g -> size);
            tmp -> neighbors = neighbors_malloc(tmp->nbNeighbors);
            mat[x][y] = tmp;
            tmp -> color = tab[i];
        }
    }
    // initialisation pointeurs
    for(int x=0; x<g->size;x++){
        for(int y=0; y<g->size;y++){
            if(x != 0 && x!=g->size-1 && y!=0 && y!=g->size-1){ //cas du milieu
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x-1][y+1];
                mat[x][y] -> neighbors[2] = mat[x][y-1];
                mat[x][y] -> neighbors[3] = mat[x][y+1];
                mat[x][y] -> neighbors[4] = mat[x+1][y-1];
                mat[x][y] -> neighbors[5] = mat[x+1][y];
            }
            if(x==0 && y==0){ //premiere case
                g -> W1 -> neighbors[y] = mat[x][y];
                g -> B1 -> neighbors[x] = mat[x][y];
                mat[x][y] -> neighbors[0] = g -> W1;
                mat[x][y] -> neighbors[1] = mat[x][y+1];
                mat[x][y] -> neighbors[2] = g -> B1;
                mat[x][y] -> neighbors[3] = mat[x+1][y];
            }
            if(x==0 && y==g->size-1){ //derniere case de la 1ere ligne
                g -> W1 -> neighbors[y] = mat[x][y];
                g -> B2 -> neighbors[x] = mat[x][y];
                mat[x][y] -> neighbors[0] = g -> W1;
                mat[x][y] -> neighbors[1] = mat[x][y-1];
                mat[x][y] -> neighbors[2] = g -> B2;
                mat[x][y] -> neighbors[3] = mat[x+1][y-1];
                mat[x][y] -> neighbors[4] = mat[x+1][y];
            }
            
            if(x==g->size-1 && y==0){ //premiere case de la derniere ligne
                g -> B1 -> neighbors[x] = mat[x][y];
                g -> W2 -> neighbors[y] = mat[x][y];
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x-1][y+1];
                mat[x][y] -> neighbors[2] = g -> B1;
                mat[x][y] -> neighbors[3] = mat[x][y+1];
                mat[x][y] -> neighbors[4] = g -> W2;
            }
            if(x==g->size-1 && y==g->size-1){ // derniere case
                g -> W2 -> neighbors[y] = mat[x][y];
                g -> B2 -> neighbors[x] = mat[x][y];
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x][y-1];
                mat[x][y] -> neighbors[2] = g -> B2;
                mat[x][y] -> neighbors[3] = g -> W2;
            }
            if(x==0 && y!= 0 && y!= g->size-1){ // bord haut
                g -> W1 -> neighbors[y] =  mat[x][y];
                mat[x][y] -> neighbors[0] = g -> W1;
                mat[x][y] -> neighbors[1] = mat[x][y-1];
                mat[x][y] -> neighbors[2] = mat[x][y+1];
                mat[x][y] -> neighbors[3] = mat[x+1][y-1];
                mat[x][y] -> neighbors[4] = mat[x+1][y];
            }
            if(y==0 && x!= 0 && x!= g->size-1){ //bord gauche
                g -> B1 -> neighbors[x] = mat[x][y];
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x-1][y+1];
                mat[x][y] -> neighbors[2] = g -> B1;
                mat[x][y] -> neighbors[3] = mat[x][y+1];
                mat[x][y] -> neighbors[4] = mat[x+1][y];
            }
            if(y!=0 && y!=g->size-1 && x==g->size-1){ //bord bas
                g -> W2 -> neighbors[y] = mat[x][y];
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x-1][y+1];
                mat[x][y] -> neighbors[2] = mat[x][y-1];
                mat[x][y] -> neighbors[3] = mat[x][y+1];
                mat[x][y] -> neighbors[4] = g -> W2;
            }
            if(y==g->size-1 && x!=0 && x!=g->size-1){ //bord droit
                g -> B2 -> neighbors[x] = mat[x][y];
                mat[x][y] -> neighbors[0] = mat[x-1][y];
                mat[x][y] -> neighbors[1] = mat[x][y-1];
                mat[x][y] -> neighbors[2] = g -> B2;
                mat[x][y] -> neighbors[3] = mat[x+1][y-1];
                mat[x][y] -> neighbors[4] = mat[x+1][y];
            }
        }
    }
    return g;
}

Node get_node(Graph g, int x, int y) {
    Node tmp = g -> W1 -> neighbors[y];
    int i = 0;
    while(tmp->x != x){
        if (tmp->neighbors[i]->x ==(tmp->x+1) && tmp->neighbors[i]->y==y) {
            tmp = tmp -> neighbors[i];
            i = 0;
        }
        else
            ++i;
        if (i>=tmp->nbNeighbors)
            tmp = tmp -> neighbors[tmp->nbNeighbors-1];
    }
    return tmp;
}

int toRegroup (Graph g,Node n) {
    for (int i=0; i<n->nbNeighbors;++i) {
        if (n->neighbors[i]->color == n->color && n->neighbors[i]!=g->B1 && n->neighbors[i]!=g->B2 && n->neighbors[i]!=g->W1 && n->neighbors[i]!=g->W2)
            return i;
    }
    return -1;
}

int max(int x1, int x2) {
    if (x1 > x2)
        return x1;
    else
        return x2;
}

int present (Node* t, int j, Node n) {
  for (int i=0;i<j;++i) {
    if (t[i] == n)
      return 1;
  }
  return 0;
}

int indice (Node n, Node g) {
  for (int i=0; i<n->nbNeighbors;++i) {
    if(n->neighbors[i] == g)
      return i;
  }
  return -1;
}

Node regroup (Graph sg, Node n1, Node n2) {
    Node group = node_malloc();
    group->color = n1->color;
    group->x = max(n1->x,n2->x);
    group->y = max(n1->y,n2->y);
    int x=0;
    for(int i = 0; i<n1->nbNeighbors;++i) {
        if (n1->neighbors[i]!=n2) {
            group->neighbors = (Node*) realloc(group->neighbors, sizeof(struct s_Node*)*x + sizeof(struct s_Node*));
            group->neighbors[x++] = n1->neighbors[i];
            if (n1->neighbors[i] == sg->W1 || n1->neighbors[i]== sg->W2)
                n1->neighbors[i]->neighbors[n1->y] = group;
            else if (n1->neighbors[i] == sg->B1 || n1->neighbors[i]== sg->B2)
                n1->neighbors[i]->neighbors[n1->x] = group;
            else 
                n1->neighbors[i]->neighbors[indice(n1->neighbors[i],n1)] = group;
        }    
    }
    for(int i = 0; i<n2->nbNeighbors;++i) {
        if (!present(group->neighbors,x,n2->neighbors[i]) && n2->neighbors[i]!=n1) {
            group->neighbors = (Node*) realloc(group->neighbors, sizeof(struct s_Node*)*x + sizeof(struct s_Node*));
            group->neighbors[x++] = n2->neighbors[i];
            if (n2->neighbors[i] == sg->W1 || n2->neighbors[i]== sg->W2)
                n2->neighbors[i]->neighbors[n2->y] = group;
            else if (n2->neighbors[i] == sg->B1 || n2->neighbors[i]== sg->B2)
                n2->neighbors[i]->neighbors[n2->x] = group;
            else  
                n2->neighbors[i]->neighbors[indice(n2->neighbors[i],n2)] = group;
        }
        else if(present(group->neighbors,x,n2->neighbors[i]) && n2->neighbors[i]!=n1) {
            for (int j=0; j<n2->neighbors[i]->nbNeighbors;++j) {
                if(n2->neighbors[i]->neighbors[j] == n2)
                    n2->neighbors[i]->neighbors[j] = group;
            }
        }
    }
    group->nbNeighbors = x;
    free(n1->neighbors);
    free(n2->neighbors);
    free(n1);
    free(n2);
    return group;
} 

// void init_groups (Graph g, Graph sg) {
//     for (int x = 0; x<g->size; ++x) {
//         for (int y=0; y<g->size; ++y){
//             Node n =  get_node(g,x,y);
//             n->group = get_node(sg,x,y);
//             n->group->group = n;
//         }
//     }
// }
// 
// Graph short_graph (Graph g, int* tab) {
//     Graph sg = graph_create(tab);
//     int x = 0;
//     int y = 0;
//     init_groups(g,sg);
//     while (x!=g->size) {
//         printf("\nshort_graph\n");
//         Node n = get_node(g,x,y);
//         printf("n->x=%d, n->y=%d, n->group->x=%d\n",n->x,n->y, n->group->x);
//         int i = toRegroup(sg,n->group);
//         if (n->group->color!= EMPTY && i!=-1) {
//             n->group = regroup(sg,n->group,n->group->neighbors[i]);
//             n->neighbors[i]->group = n->group;
//             printf("n->group->x=%d, n->x=%d, n->y=%d, n->neighbors[i]->x=%d,n->neighbors[i]->y=%d\n",n->group->x, n->x,n->y,n->neighbors[i]->x,n->neighbors[i]->y);
//         }
// //         printf("case n->x=%d, n->y=%d,z->x=%d, z->y=%d\n",n->x,n->y,z->x,z->y);
//         if (y != g->size-1)
//             ++y;
//         else {
//             y=0;
//             ++x;
//         }
//     }
//     return sg;
// }

Graph short_graph (Graph g) {
    Graph sg = g;
    int x = 0;
    int y = 0;
    while (x!=g->size) {
        Node n = get_node(g,x,y);
        int i = toRegroup(sg,n);
        if (n->color!= EMPTY && i!=-1)
            n = regroup(sg,n,n->neighbors[i]);
        if (n->y != g->size-1)
            y=n->y+1;
        else {
            y=0;
            ++x;
        }
    }
    return sg;
}

bool end_white (Graph g) {
  for (int i = 0; i<g->W1->nbNeighbors; ++i) {
    if (g->W1->neighbors[i]->color == g->W1->color) {
        for (int j=0; j<g->W1->neighbors[i]->nbNeighbors; ++j)
            if (g->W1->neighbors[i]->neighbors[j] == g->W2)
                return true;
    }
  }
  return false;
}

bool end_black (Graph g) {
  for (int i = 0; i<g->B1->nbNeighbors; ++i) {
    if (g->B1->neighbors[i]->color == g->B1->color) {
        for (int j=0; j<g->B1->neighbors[i]->nbNeighbors; ++j) {
            if (g->B1->neighbors[i]->neighbors[j] == g->B2)
                return true;
        }
    }
  }
  return false;
}

bool end (Graph g) { 
  return (end_white(g) || end_black(g));
}

Graph graphs_create (int *tab) {
    Graph g = graph_create(tab);
    Graph sg = short_graph(g);
    return sg;
}

int victory (int *tab) {
    Graph g = graphs_create(tab);
   if (end(g))
       return 1;
   else 
       return 0;
}

int get_val(Node n){
    return n->color;
}




















