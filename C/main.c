#include <stdlib.h>
#include <assert.h>
#include "graph.h"

int main(){
	Graph g = graph_create(3);
	g = change_color(g,0,0,BLACK);
	g = change_color(g,0,0,WHITE);
	print_node(get_node(g,0,0));
	graph_free(g);
	return 0;
}