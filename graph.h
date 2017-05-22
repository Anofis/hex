#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


#define BLACK 2
#define WHITE 1
#define EMPTY 0

typedef struct s_Graph *Graph;

typedef struct s_Node *Node;

Graph graph_malloc ();

Node node_malloc();

Node* neighbors_malloc(int size);

void init_bord (Graph g);

void init_nbNeighbors (Node n, int size);

Graph graph_create (int* tab);

int get_val(Node n);

Node get_node(Graph g, int x, int y);

int min(int x1, int x2);

int max(int x1, int x2);

int present (Node* t, int j, Node n);

int indice_retour (int i);

int toRegroup (Graph g,Node n);

Node regroup (Graph sg, Node n1, Node n2);

Graph short_graph (Graph g);

bool end_white (Graph g);

bool end_black (Graph g);

bool end (Graph g);

Graph graphs_create (int *tab);

int victory (int *tab);