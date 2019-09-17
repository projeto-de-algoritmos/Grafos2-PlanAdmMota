#ifndef _INTERFACE_
#define _INTERFACE_

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void menu(Graph *);
/*
Menu of program
*/

int catch_option();
/*
Show all options of program
*/

void conections(Graph *, int);
/*
 * Creates the list of linked streets of one node
 */

Graph* prim(Graph *);
/*
 * Creates the minimum tree
 */

int dijkstra(Graph *, int, int, int);
/*
 * Return the minimum cost to go from one point to another
 */
#endif //_INTERFACE_