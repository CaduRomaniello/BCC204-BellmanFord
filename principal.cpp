#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "bellmanford.hpp"

using namespace std;

int main(){

    bool altera;

    // Criacao e inicializacao do grafo
    Grafo grafo = Grafo();
    grafo.inicializaGrafo();

    // Bellman-Ford
    altera = bellmanford(&grafo);

    // Print
    printFinal(&grafo, altera);

    return 0;

}