#include "interface.h"

#define INFINITO 999
#define VISITED -1

void menu(Graph *grafo) {
	printf("\n\t\tPosiciona administração.\n");
	
	Node * node;
	for (node = grafo -> start; node != NULL; node = node -> next) {
		printf("%d - %s\n", node -> id, node -> contents.name);
	}
	free(node);

	printf("\nOPCOES:\n");
	printf("1- Adicionar esquina.\n");
	printf("2- Adicionar rua.\n");
	printf("3- Retirar esquina.\n");
	printf("4- Retirar rua.\n");
	printf("5- Esquinas conectadas.\n");
    printf("6- Menor caminho entre dois pontos.\n");
    printf("7- Melhor local para se pôr uma administração.\n");
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

void conections(Graph *grafo, int id) {
    int *neighbor = neighbors(grafo, id);

    for(int i = 1; i <= neighbor[0]; i++) {
        printf("Esquina %d: %s\n", neighbor[i], return_node_value(grafo, neighbor[i]).name);
    }

    free(neighbor);

    return;
}

Graph* prim(Graph *grafo) {

    Graph *minimum_graph = (Graph *) malloc(sizeof(Graph));

    char* name_prim = "Caminho da Rede";
    int length = strlen(name_prim);

    minimum_graph -> graph_name = (char*) malloc(length * sizeof(char));

    strcpy(minimum_graph -> graph_name, name_prim);
    minimum_graph -> n_nodes = 0;
    minimum_graph -> n_edges = 0;
    minimum_graph -> start = NULL;
    minimum_graph -> finish = NULL;

    return minimum_graph;
}

int dijkstra(Graph *grafo, int origin, int destiny, int print) {

    int size_graph = (grafo -> n_nodes) + 1;

    int visited[size_graph];
    for (int i = 0; i < size_graph; i++) {
        visited[i] = 0;
    }

    int minimum_cost_to[size_graph];
    for (int i = 1; i < size_graph; i++) {
        if (i != origin) {
            minimum_cost_to[i] = INFINITO;
        } else {
            minimum_cost_to[i] = 0;
        }
    }

    int id_min, min;
    do {
        if (print) {
            // Print the list of minimum path until now
            printf("Calculo dos menores valores atualizado\n");
            for (int i = 1; i < size_graph; i++) {
                printf("%d: %d\n", i, minimum_cost_to[i]);
            }
            printf("\n");
        }

        id_min = INFINITO;
        min = INFINITO;
        // find the minimum cost not visited until now
        for (int i = 1; i < size_graph; i++) {
            if (minimum_cost_to[i] < min && visited[i] == 0) {
                min = minimum_cost_to[i];
                id_min = i;
            }
        }

        int *neighbor = neighbors(grafo, id_min);
        int cost = 0;

        if (print) {
            printf("Menor caminho ate agora: %d\n", id_min);
            printf("Custo atual ate %d: %d\n", id_min, minimum_cost_to[id_min]);
        }
        // att cost to edges if smaller
        for (int i = 1; i <= neighbor[0]; i++) {
            if (visited[neighbor[i]] == 0) {
                cost = minimum_cost_to[id_min] + return_edge_value(grafo, id_min, neighbor[i]).weight;
                if (print) {
                    printf("Velho custo ate %d: %d\n",neighbor[i], minimum_cost_to[neighbor[i]]);
                    printf("Custo ate %d passando por %d: %d\n", neighbor[i], id_min, cost);
                }
                if (cost < minimum_cost_to[neighbor[i]]) {
                    minimum_cost_to[neighbor[i]] = cost;
                }
                if (print) {
                    printf("Custo atualizado para %d: %d\n", neighbor[i], minimum_cost_to[neighbor[i]]);
                    printf("\n");
                }                
            }
        }

        visited[id_min] = 1;

    } while(visited[destiny] == 0);

    return minimum_cost_to[destiny];
};
