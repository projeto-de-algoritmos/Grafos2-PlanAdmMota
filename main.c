#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "graph.h"
#include "reader.h"

int main() {

    Graph *grafo = load_graph("nodes.txt", "edges.txt");

    menu(grafo);
    
    int id;
    char name[50];
    int weight;
    NodeData insert_node;
    EdgeData insert_edge;
    int conection;
    int idBest,shorterTotalCost = 999,shorterActualCost;
    char option;

    do {
        option = catch_option();

        switch (option) {
            case 1:
                printf("Coloque o id da esquina: ");
                scanf("%d", &id);
                printf("Coloque o nome da esquina: ");
                scanf("%s", name);
                getchar();
                add_node(grafo, id);
                strcpy(insert_node.name, name);
                set_node_value(grafo, id, insert_node);
            break;

            case 2:
                printf("Digite o id das duas esquinas conectadas: ");
                scanf("%d %d %d", &id, &conection, &weight);
                insert_edge.weight = weight;
                add_edge(grafo, id, conection);
                set_edge_value(grafo, id, conection, insert_edge);
                add_edge(grafo, conection, id);
                set_edge_value(grafo, conection, id, insert_edge);
            break;

            case 3:
                printf("Digite o id da esquina que deseja retirar: ");
                scanf("%d", &id);
                remove_node(grafo, id);
            break;

            case 4:
                printf("Digite o id das duas esquinas que não são mais conectadas: ");
                scanf("%d %d", &id, &conection);
                remove_edge(grafo, id, conection);
                remove_edge(grafo, conection, id);
            break;

            case 5:
                printf("Digite o id que deseja ver suas conexões: ");
                scanf("%d", &id);
                conections(grafo, id);
            break;

            case 6:
                printf("Digite a origem e destino do caminho desejado: ");
                scanf("%d %d", &id, &conection);
                conection = dijkstra(grafo, id, conection, 1);
                printf("%d\n", conection);
            break;

            case 7:
                for(int origin = 1; origin <= grafo -> n_nodes; origin++) {
                    shorterActualCost = 0;
                    for(int destiny = 1; destiny <= grafo -> n_nodes; destiny++) {
                        if(origin != destiny) {
                            shorterActualCost = shorterActualCost + dijkstra(grafo, origin, destiny, 0);
                        }
                    }
                    if(shorterActualCost < shorterTotalCost){
                        idBest = origin;
                        shorterTotalCost = shorterActualCost;
                    }
                }
                printf("O melhor ponto pra se colocar a central na cidade e: %d\n",idBest);
            break;

            case 0:
                printf("Ate a proxima!\n\n");
            break;

            default:
                printf("DIGITE UMA OPCAO VALIDA\n\n");
            break;
        }
         menu(grafo);
    } while (option != 0);

    destroy_graph(grafo);

    return 0;
}
