#include "interface.h"

#define MAX_INVITEDS

void menu(Graph *grafo) {
	printf("\n\t\tLista de Convidados\n");
	
	Node * node;
	for (node = grafo -> start; node != NULL; node = node -> next) {
		printf("%d - %s\n", node -> id, node -> contents.name);
	}
	free(node);

	printf("\nOPCOES:\n");
	printf("1- Adicionar pessoa.\n");
	printf("2- Adicionar amizade.\n");
	printf("3- Retirar pessoa.\n");
	printf("4- Retirar amizade.\n");
	printf("5- Lista de Amigos.\n");
	printf("0- Sair do programa.\n");

	return;
}

int catch_option () {
	int select;
	printf("\nO que deseja: ");
	scanf("%d", &select);
	printf("\n");

	return select;
}

void invite(Graph *grafo, int id) {
    int *neighbor_2, *neighbor = neighbors(grafo, id);

    for(int i = 1; i <= neighbor[0]; i++) {
        printf("Amigo %d: %s\n", neighbor[i], return_node_value(grafo, neighbor[i]).name);
        neighbor_2 = neighbors(grafo,  neighbor[i]);
        printf("Ciclo de Amigos:\n");
        for (int j = 1; j <= neighbor_2[0]; j++) {
        	printf("%d: %s\n", neighbor_2[j], return_node_value(grafo, neighbor_2[j]).name);
        }
        printf("\n");
    }

    free(neighbor);
    free(neighbor_2);

    return;
}
