#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "graph.h"
#include "short_graph.h"

int present (Node* t, int j, Node n) {
  int i;
  for (i=0;i<j;++i) {
    if (t[i] == n)
      return 1;
  }
  return 0;
}

int point (Node n, Node g) {
  struct s_Node ** neighbors = get_neighbors(n);
  int i;
  for (i=0; i<get_nbNeighbors(n);++i) {
    if(neighbors[i] == g)
      return i;
  }
  return -1;
}

Graph regroup (Graph g, Node n) {
  Node *toRegroup = NULL;
  int i;
  int j = 0;
  int nbNeighbors = get_nbNeighbors(n);
  struct s_Node ** neighbors = get_neighbors(n);
  for (i=0; i<nbNeighbors;++i) {
    if (get_color(neighbors[i]) == get_color(n))
      toRegroup[j++] = neighbors[i];
  }
  if (j==0)
    return g;
  toRegroup[j++] = n;
  //dans toRegroup on a tout les groupes auxquels le noeud n doit se regrouper
  Node newGroup = node_create();
  set_color(newGroup,get_color(n));
  Node *voisins = NULL; // tableau avec les voisins qu'aura le nouveau groupe
  int x = 0;	 // nombre de voisins qu'aura le nouveau groupe
// pour tout les groupes de toRegroup, ajouter les voisins de ces groupes dans le tableau "voisins" (ne pas ajouter le noeud n comme voisin) s'il ne sont pas presents déjà
  for (i=0;i<j;++i) {
    int a;
    for (a=0;a< get_nbNeighbors(toRegroup[i]);++a) {
      struct s_Node ** v = get_neighbors(toRegroup[i]);
      if (!present(voisins,x,v[a]) && v[a]!= n)
	voisins[x++] = v[a];
    }
  }
  set_nbNeighbors(newGroup,x);
  init_neighbors(newGroup);
  for (i=0; i<x;++i) {
    set_neighbors(newGroup, i, voisins[i]);
    int y;
    int tmp;
    for (y=0;y<j;++y){
      tmp = point(voisins[i],toRegroup[y]);
      if (tmp != -1)
	set_neighbors(voisins[i],tmp,newGroup);
    }
  }
  return g;
}