#include "bellmanford.hpp"

/*
██████╗ ███████╗██╗     ██╗     ███╗   ███╗ █████╗ ███╗   ██╗      ███████╗ ██████╗ ██████╗ ██████╗ 
██╔══██╗██╔════╝██║     ██║     ████╗ ████║██╔══██╗████╗  ██║      ██╔════╝██╔═══██╗██╔══██╗██╔══██╗
██████╔╝█████╗  ██║     ██║     ██╔████╔██║███████║██╔██╗ ██║█████╗█████╗  ██║   ██║██████╔╝██║  ██║
██╔══██╗██╔══╝  ██║     ██║     ██║╚██╔╝██║██╔══██║██║╚██╗██║╚════╝██╔══╝  ██║   ██║██╔══██╗██║  ██║
██████╔╝███████╗███████╗███████╗██║ ╚═╝ ██║██║  ██║██║ ╚████║      ██║     ╚██████╔╝██║  ██║██████╔╝
╚═════╝ ╚══════╝╚══════╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝      ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═════╝ 
*/
bool bellmanford(Grafo* grafo){

    vector<Vertice> aux = {};
    bool altera = false;

    int count = 0;
    for (int i = 0; i < grafo->qntd_vertices - 1; i++){
        altera = false;

        grafo->dijkstra(&altera);
        count += 1;

        if (!altera){
            break;
        }

        for (int j = 0; j < grafo->qntd_vertices; j++){
            grafo->vertices[j].fechado = false;
        }
    }

    return altera;

}
