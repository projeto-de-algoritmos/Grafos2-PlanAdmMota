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

void invite(Graph *, int);
/*
 * Creates the list of birthday of one node
 */

#endif //_INTERFACE_