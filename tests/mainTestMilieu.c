#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "graph.h"

int main () {
    int tab [10];
    tab[0] = 3;
    tab[1] = 2;
    tab[2] = 2;
    tab[3] = 0;
    tab[4] = 0;
    tab[5] = 2;
    tab[6] = 2;
    tab[7] = 0;
    tab[8] = 0;
    tab[9] = 0;

    printf("Test victoire passant par le milieu:\n");
    Graph g2 = graph_create(tab);
    for (int x=0;x<tab[0];++x) {
        for(int y=0;y<tab[0];++y) {
            printf("%d ",get_val(get_node(g2,x,y)));
        }
        printf("\n");
    }
    if (victory(tab))
        printf("VICTOIRE !\n");
    else
        printf("PAS DE VICTOIRE !\n");
    return 0;
}