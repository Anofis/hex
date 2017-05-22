#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../graph.h"

int main() {    
    int tab2 [17];
    tab2[0] = 4;
    tab2[1] = 2;
    tab2[2] = 2;
    tab2[3] = 2;
    tab2[4] = 2;
    tab2[5] = 0;
    tab2[6] = 0;
    tab2[7] = 0;
    tab2[8] = 0;
    tab2[9] = 0;
    tab2[10] = 0;
    tab2[11] = 0;
    tab2[12] = 0;
    tab2[13] = 0;
    tab2[14] = 0;
    tab2[15] = 0;
    tab2[16] = 0;

    printf("Test victoire simple grille 4x4:\n");
    Graph g2 = graph_create(tab2);
    for (int x=0;x<tab2[0];++x) {
        for(int y=0;y<tab2[0];++y) {
            printf("%d ",get_val(get_node(g2,x,y)));
        }
        printf("\n");
    }
    if (victory(tab2))
        printf("VICTOIRE !!!!\n");
    else
        printf("PAS DE VICTOIRE!!\n");
    return 0;
}