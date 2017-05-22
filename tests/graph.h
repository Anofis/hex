#ifndef __GRAPH_H__
#define __GRAPH_H__

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

/*
 *  Parametre: taille que doit faire le tableau "neighbors", qui correspond au nombre de voisins qu'un noeud aura.
 */
Node* neighbors_malloc(int size);

/*
 * Fonction qui permet d'initialiser les données des bords du graphe:
 initialisation du noeud (malloc) correspondant à chaque bord, leur tableau "neighbors" ainsi que le nombre de voisins qu'ils auront, leur couleur, une coordonnée (-1 ou la taille maximale, par rapport à leur position dans le graphe).
 * Parametre: le graphe
 */
void init_bord (Graph g);

/*
 * Fonction qui permet d'initialiser les pointeurs, pour toutes les cases du graphe, vers tous les voisins de chaque case.
 * Parametres: la case (node) et la taille maximale du graphe.
 */
void init_nbNeighbors (Node n, int size);

/*
 * Fonction qui crée complètement un graphe.
 * Parametre: un tableau d'entiers dont la premiere case du tableau determine la taille maximale du graphe, et le reste de cases determinent les couleurs des cases.
 */
Graph graph_create (int* tab);

/*
 * Fonction qui retourne un noeud/case recherchée à partir de ses coordonnées.
 * Parametres: le graphe, un entier x donnant l'ordonnée et un entier y donnant l'abscise (x implique le parcours des lignes, y implique le parcours des colonnes).
 * Retourne: le noeud de coordonnées x,y.
 */
Node get_node(Graph g, int x, int y);

int max(int x1, int x2);

/*
 * Fonction qui permet de savoir si un noeud est present dans un tableau de noeuds.
 * Parametres: t = tableau de Noeuds; j = taille du tableau t; n = noeud cherché dans t.
 * Retourne: 1 si le noeud est present, 0 sinon.
 */
int present (Node* t, int j, Node n);

/*
 * Fonction qui cherche l'indice de la case qui pointe vers un noeud, dans le tableau de voisins d'un autre noeud.
 * Parametres: n = noeud dans lequel on cherche l'indice de case de son tableau de voisins; g = noeud vers lequel la case doit pointer.
 * Retourne: l'indice si un des voisins de n pointe vers g, -1 sinon.
 */
int indice (Node n, Node g);

/*
 * Fonction qui permet de savoir si on doit regrouper un noeud avec d'autres noeuds ou d'autres groupes de noeuds.
 * Parametres: le graphe, le noeud dont on doit verifier s'il faut le regrouper.
 * Retourne: l'indice du voisin (groupe ou noeud) au quel le noeud doit se regrouper, -1 s'il ne peux pas se regrouper.
 */
int toRegroup (Graph g,Node n);

/*
 * Fonction qui regroupe deux groupes (de 1 ou plusieurs noeuds).
 * Parametres: le graphe, un premier groupe de noeuds et un deuxieme groupe de noeuds.
 * Retourne: le noueveau groupe de noeuds crée.
 */
Node regroup (Graph sg, Node n1, Node n2);

/*
 * Fonction qui cree le graph reduit.
 * Parametre: le graphe normal (complet avec toutes les cases, sans aucun groupe).
 * Retourne: le graphe reduit.
 */
Graph short_graph (Graph g);

/*
 * Fonction qui crée les deux graphes.
 * Parametre: un tableau d'entiers.
 * Retourne: le graphe reduit.
 */
Graph graphs_create (int *tab);

/*
 * Fonction qui verifie si le joueur avec des pions blancs a gagne la partie.
 * Parametre: le graphe reduit.
 * Retourne: true s'il a gagné (s'il a lié les deux bords), false sinon.
 */
bool end_white (Graph g);

/*
 * Fonction qui verifie si le joueur avec des pions noirs a gagne la partie.
 * Parametre: le graphe reduit.
 * Retourne: true s'il a gagné (s'il a lié les deux bords), false sinon.
 */
bool end_black (Graph g);

/*
 * Fonction qui test si la partie est finie.
 * Parametre: le graphe reduit.
 * Retourne: true si la partie est finie, false sinon.
 */
bool end (Graph g);

/*
 * Fonction qui crée un graphe reduit, à partir d'un graphe normal, créé grâce à un tableau d'entiers, et qui teste ensuite si la partie est finie.
 * Parametre: un tableau d'entiers, représentant la taille du tableau et les entiers correspondants aux couleurs dans chaque case.
 * Retourne: 1 si la partie est fini, 0 sinon.
 * Cette Fonction fait la liaison avec la partie Java.
 */
int victory (int *tab);

/*
* Retoune la couleur d'un noeud
*/
int get_val(Node n);

#endif