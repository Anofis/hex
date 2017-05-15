#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdlib.h>
#include <assert.h>

#define BLACK 2
#define WHITE 1
#define EMPTY 0

typedef struct s_Graph *Graph;

typedef struct s_Node *Node;

Graph graph_create(int size);
Node node_create();
Node get_node(Graph g,int x,int y);
void graph_free(Graph g);
Graph change_color(Graph g,int x,int y,int color);
void print_node(Node n);

int get_nbNeighbors (Node n);
struct s_Node ** get_neighbors (Node n);
int get_color (Node n);
void set_color (Node n, int color);
void set_nbNeighbors(Node n, int size);
void init_neighbors(Node n);
void set_neighbors (Node n, int i, Node neighbors);

#endif