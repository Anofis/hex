#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "graph.h"


struct s_Node{
	int x;
	int y;
	int color;
	struct s_Node ** neighbors;
	int nbNeighbors;
};

struct s_Graph{
	Node B1; // Bord Haut
	Node B2; // Bord Bas
	Node W1; // Bord Gauche
	Node W2; // Bord Droite
	int size;
};

Node node_create(){
	Node tmp = (Node) malloc (sizeof(struct s_Node));
	return tmp;
}

Graph graph_create(int size){
	//Allocation des bords
	Graph g = (Graph) malloc (sizeof(struct s_Graph));
	g -> size = size;
	g -> B1 = node_create();
	g -> B1 -> nbNeighbors = size;
	g -> B1 -> neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*size);


	g -> B2 = node_create();
	g -> B2 -> nbNeighbors = size;
	g -> B2 -> neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*size);


	g -> W1 = node_create();
	g -> W1 -> nbNeighbors = size;
	g -> W1 -> neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*size);

	g -> W2 = node_create();
	g -> W2 -> nbNeighbors = size;
	g -> W2 -> neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*size);


	Node mat [size][size];

	for(int x=0; x<size;x++){
		for(int y=0; y<size;y++){



			Node tmp = node_create();
			tmp -> x = x;
			tmp -> y = y;
			mat[x][y] = tmp;
			tmp -> color = EMPTY;
			tmp -> nbNeighbors = 6;


			if(x==0 || x==size-1 || y==0 || y==size-1){
				tmp -> nbNeighbors = 5;
			}

			if((y==0 && x==0) || (y==size-1 && x==size-1) ){
				tmp -> nbNeighbors = 4;
			}
			tmp -> neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*tmp->nbNeighbors);
			
			if(x==0){
				g -> B1 -> neighbors[y] = tmp;		
				tmp -> neighbors[0] = g -> B1;	
			}
			if(y==0){
				g -> W1 -> neighbors[x] = tmp;	
				tmp -> neighbors[2] = g -> W1;
			}
			if(x==size-1){
				g -> B2 -> neighbors[y] = tmp;
				tmp -> neighbors[tmp-> nbNeighbors-1] = g -> B2;			
			}
			if(y==size-1){
				g -> W2 -> neighbors[x] = tmp;
				tmp -> neighbors[2] = g -> W2;
			}


		}
	}
	for(int x=0; x<size;x++){
		for(int y=0; y<size;y++){
			if(x != 0 && x!=size-1 && y!=0 && y!=size-1){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x-1][y+1];
				mat[x][y] -> neighbors[2] = mat[x][y-1];
				mat[x][y] -> neighbors[3] = mat[x][y+1];
				mat[x][y] -> neighbors[4] = mat[x+1][y-1];
				mat[x][y] -> neighbors[5] = mat[x+1][y];
			}
			if(x==0 && y==0){
				mat[x][y] -> neighbors[1] = mat[x][y+1];
				mat[x][y] -> neighbors[3] = mat[x+1][y];
			}
			if(x==0 && y==size-1){
				mat[x][y] -> neighbors[1] = mat[x][y-1];
				mat[x][y] -> neighbors[3] = mat[x+1][y-1];
				mat[x][y] -> neighbors[4] = mat[x+1][y];
			}
			if(x==size-1 && y==0){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x-1][y+1];
				mat[x][y] -> neighbors[3] = mat[x][y+1];
			}
			if(x==size-1 && y==size-1){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x][y-1];
			}

			if(x==0 && y!= 0 && y!= size-1){
				mat[x][y] -> neighbors[1] = mat[x][y-1];
				mat[x][y] -> neighbors[2] = mat[x][y+1];
				mat[x][y] -> neighbors[3] = mat[x+1][y-1];
				mat[x][y] -> neighbors[4] = mat[x+1][y];
			}
			if(y==0 && x!= 0 && x!= size-1){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x-1][y+1];
				mat[x][y] -> neighbors[3] = mat[x][y+1];
				mat[x][y] -> neighbors[4] = mat[x+1][y];
			}
			if(y!=0 && y!=size-1 && x==size-1){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x-1][y+1];
				mat[x][y] -> neighbors[2] = mat[x][y-1];
				mat[x][y] -> neighbors[3] = mat[x][y+1];
			}
			if(y==size-1 && x!=0 && x!=size-1){
				mat[x][y] -> neighbors[0] = mat[x-1][y];
				mat[x][y] -> neighbors[1] = mat[x][y-1];
				mat[x][y] -> neighbors[3] = mat[x+1][y-1];
				mat[x][y] -> neighbors[4] = mat[x+1][y];
			}

		}
	}

	return g;
}

Node get_node(Graph g,int x,int y){
	Node tmp = g -> B1 -> neighbors[y];
	while(tmp->x != x){
		tmp = tmp -> neighbors[tmp->nbNeighbors-1];
	}
	return tmp;
}

void graph_free(Graph g){
	for(int x=g->size-1;x>=0;x--){
		for(int y=g->size-1;y>=0;y--){
			free(get_node(g,x,y)->neighbors);
			free(get_node(g,x,y));

		}
	}
	free(g->B1->neighbors);
	free(g->B1);
	free(g->B2->neighbors);
	free(g->B2);
	free(g->W1->neighbors);
	free(g->W1);
	free(g->W2->neighbors);
	free(g->W2);
	free(g);
}

Graph change_color(Graph g,int x,int y,int color){
	Node tmp = get_node(g,x,y);
	if(tmp -> color == EMPTY){
		tmp -> color = color;
	}
	return g;
}

void print_node(Node n){
	printf("Color : %d \n", n-> color);
	printf("X : %d Y: %d\n", n->x,n->y);
}


// Functions Sandra
int get_nbNeighbors (Node n) {
  return n->nbNeighbors;
}

struct s_Node ** get_neighbors (Node n) {
  return n->neighbors;
}

int get_color (Node n) {
  return n->color;
}

void set_color (Node n, int color) {
  n->color = color;
}

void set_nbNeighbors(Node n, int size) {
    n->nbNeighbors = size;
}
void init_neighbors(Node n) {
    n->neighbors = (struct s_Node**) malloc (sizeof(struct s_Node)*n->nbNeighbors);
}

void set_neighbors (Node n, int i, Node neighbors) {
  n->neighbors[i] = neighbors;
}
