#include "dijkstra.hpp"

using namespace std;

/*
███████╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ███████╗███████╗
██╔════╝██║   ██║████╗  ██║██╔════╝██╔═══██╗██╔════╝██╔════╝
█████╗  ██║   ██║██╔██╗ ██║██║     ██║   ██║█████╗  ███████╗
██╔══╝  ██║   ██║██║╚██╗██║██║     ██║   ██║██╔══╝  ╚════██║
██║     ╚██████╔╝██║ ╚████║╚██████╗╚██████╔╝███████╗███████║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝
*/

void percorreCaminho(Grafo* grafo, int vertice, vector<int>* caminho){
    caminho->push_back(vertice);

    if (grafo->vertices[vertice - 1].rot == numeric_limits<int>::max()){
        return;
    }

    percorreCaminho(grafo, grafo->vertices[vertice - 1].rot, caminho);
}

void printFinal(Grafo* grafo, bool altera){
    if (altera){
        cout << "ERRO: CICLO DE CUSTO NEGATIVO!" << endl;
    }
    else{
        for (int i = 0; i < static_cast<int>(grafo->vertices.size()); i++){
            if (grafo->vertices[i].id == grafo->vertice_inicial){
                continue;
            }

            vector<int> aux;

            cout << grafo->vertices[i].id << " (" << grafo->vertices[i].dt << "): ";

            percorreCaminho(grafo, grafo->vertices[i].id, &aux);
            for (int j = static_cast<int>(aux.size()) - 1; j >= 0; j--){
                if (j == 0){
                    cout << aux[j] << endl;
                }
                else{
                    cout << aux[j] << " ";
                }
            }
        }
    }
}

/*
 █████╗ ██████╗ ███████╗███████╗████████╗ █████╗ 
██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗
███████║██████╔╝█████╗  ███████╗   ██║   ███████║
██╔══██║██╔══██╗██╔══╝  ╚════██║   ██║   ██╔══██║
██║  ██║██║  ██║███████╗███████║   ██║   ██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝
*/

Aresta::Aresta(int id, int origem, int destino, double peso, bool visitado, bool direcionado){

    this->id = id;
    this->origem = origem;
    this->destino = destino;
    this->peso = peso;
    this->visitado = visitado;
    this->direcionado = direcionado;
}
Aresta::~Aresta(){}

void Aresta::printInfo(){
    cout << "--------- Aresta ---------\n";
    cout << "Id         : " << this->id << "\n" ;
    cout << "Origem     : " << this->origem << "\n" ;
    cout << "Destino    : " << this->destino << "\n" ;
    cout << "Peso       : " << this->peso << "\n" ;
    cout << "Visitado   : " << this->visitado << "\n" ;
    cout << "Direcionado: " << this->direcionado << "\n\n" ;
}

/*
██╗   ██╗███████╗██████╗ ████████╗██╗ ██████╗███████╗
██║   ██║██╔════╝██╔══██╗╚══██╔══╝██║██╔════╝██╔════╝
██║   ██║█████╗  ██████╔╝   ██║   ██║██║     █████╗  
╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██║██║     ██╔══╝  
 ╚████╔╝ ███████╗██║  ██║   ██║   ██║╚██████╗███████╗
  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝╚══════╝
*/

Vertice::Vertice(int id, bool fechado){
    this->id = id;
    this->fechado = fechado;
    this->dt = 0.0;
    this->rot = 0;
}
Vertice::~Vertice(){}

void Vertice::printInfo(){
    cout << "--------- Vertice ---------\n";
    cout << "Id                            : " << this->id << "\n" ;
    cout << "Fechado                       : " << this->fechado << "\n" ;
    cout << "Tamanho da lista de adjacencia: " << static_cast<int>(this->adjacencia.size()) << "\n\n" ;
}

/*
 ██████╗███████╗██╗     ██╗   ██╗██╗      █████╗ 
██╔════╝██╔════╝██║     ██║   ██║██║     ██╔══██╗
██║     █████╗  ██║     ██║   ██║██║     ███████║
██║     ██╔══╝  ██║     ██║   ██║██║     ██╔══██║
╚██████╗███████╗███████╗╚██████╔╝███████╗██║  ██║
 ╚═════╝╚══════╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝
*/

Celula::Celula(bool status, bool visitado, double peso):status(status), visitado(visitado), peso(peso){}
Celula::~Celula(){}

/*
 ██████╗ ██████╗  █████╗ ███████╗ ██████╗ 
██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔═══██╗
██║  ███╗██████╔╝███████║█████╗  ██║   ██║
██║   ██║██╔══██╗██╔══██║██╔══╝  ██║   ██║
╚██████╔╝██║  ██║██║  ██║██║     ╚██████╔╝
 ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝      ╚═════╝ 
*/

Grafo::Grafo(){}
Grafo::Grafo(int qntd_vertices, int qntd_arestas, int vertice_inicial, bool direcionado):qntd_vertices(qntd_vertices), qntd_arestas(qntd_arestas), vertice_inicial(vertice_inicial), direcionado(direcionado){}
Grafo::~Grafo(){}

void Grafo::inicializaGrafo(){

    // Leitura dos dados iniciais
    int qntd_vertices, qntd_arestas, eh_direcionado, vertice_inicial;
    bool direcionado;

    cin >> qntd_vertices >> qntd_arestas >> eh_direcionado >> vertice_inicial;
    if (eh_direcionado == 1){
        direcionado = true;
    }
    else{
        direcionado = false;
    }

    this->qntd_arestas = qntd_arestas;
    this->qntd_vertices = qntd_vertices;
    this->direcionado = direcionado;
    this->vertice_inicial = vertice_inicial;

    // Lendo vertices
    for (int i = 1; i <= this->qntd_vertices; i++){
        Vertice v(i, false);

        if (i != this->vertice_inicial){
            v.dt = numeric_limits<double>::max();
            v.rot = 0;
        }
        else{
            v.dt = 0.0;
            v.rot = numeric_limits<int>::max();
        }

        this->vertices.push_back(v);

        vector<Celula> vet;
        this->matriz.push_back(vet);
        for (int j = 1; j <= this->qntd_vertices; j++){
            this->matriz[i - 1].push_back(Celula());
        }
    }

    // Lendo arestas e criando listas de adjacencia
    int origem, destino;
    double peso;

    for (int i = 1; i <= this->qntd_arestas; i++){
        cin >> origem >> destino >> peso;
        
        Aresta a = Aresta(i, origem, destino, peso, false, this->direcionado);
        this->arestas.push_back(a);

        if (this->direcionado){
            // Preenchendo lista de adjacencia e de antecessores
            this->vertices[origem - 1].adjacencia.push_back(i);
            this->vertices[destino - 1].antecessores.push_back(i);

            // Preenchendo matriz com o peso correspondente da aresta
            this->matriz[origem - 1][destino - 1].status = true;
            this->matriz[origem - 1][destino - 1].peso = peso;

            /*
            A INICIALIZACAO ABAIXO CAUSAVA PROBLEMAS DURANTE A EXECUCAO DO ALGORITMO
            */

            // Atualizando o rot e o dt dos vertices vizinhos do vertice inicial
            // if (origem == this->vertice_inicial){
            //     this->vertices[destino - 1].dt = peso;
            //     this->vertices[destino - 1].rot = this->vertice_inicial;
            // }
        }
        else{
            // Preenchendo lista de adjacencia e de antecessores do primeiro vertice
            this->vertices[origem - 1].adjacencia.push_back(i);
            this->vertices[origem - 1].antecessores.push_back(i);

            // Preenchendo lista de adjacencia e de antecessores do segundo vertice
            this->vertices[destino - 1].adjacencia.push_back(i);
            this->vertices[destino - 1].antecessores.push_back(i);

            // Preenchendo matriz com o peso correspondente da aresta indo da origem para o destino
            this->matriz[origem - 1][destino - 1].status = true;
            this->matriz[origem - 1][destino - 1].peso = peso;
            
            // Preenchendo matriz com o peso correspondente da aresta indo do destino para a origem
            this->matriz[destino - 1][origem - 1].status = true;
            this->matriz[destino - 1][origem - 1].peso = peso;

            /*
            A INICIALIZACAO ABAIXO CAUSAVA PROBLEMAS DURANTE A EXECUCAO DO ALGORITMO
            */

            // Atualizando o rot e o dt dos vertices vizinhos do vertice inicial
            // if (origem == this->vertice_inicial){
            //     this->vertices[destino - 1].dt = peso;
            //     this->vertices[destino - 1].rot = this->vertice_inicial;
            // }

            // if (destino == this->vertice_inicial){
            //     this->vertices[origem - 1].dt = peso;
            //     this->vertices[origem - 1].rot = this->vertice_inicial;
            // }
        }
    }
}

int Grafo::posicaoMenorDT(){
    int pos = -1;
    int idAtual = numeric_limits<int>::max();
    double dt = numeric_limits<double>::max();
    for (int i = 0; i < this->qntd_vertices; i++){
        if (this->vertices[i].fechado){
            continue;
        }

        if (this->vertices[i].dt < dt){
            dt = this->vertices[i].dt;
            pos = i;
            idAtual = this->vertices[i].id;
        }
        else if (this->vertices[i].dt == dt){
            if (this->vertices[i].id < idAtual){
                dt = this->vertices[i].dt;
                pos = i;
                idAtual = this->vertices[i].id;
            }
        }
        else{
            continue;
        }
    }
    return pos;
}

void Grafo::dijkstra(bool* altera){
    int verticeAtual;

    vector<Vertice>* vertices = &this->vertices;
    vector<vector<Celula>>* matriz = &this->matriz;

    // vector<Vertice> f;

    // para se assemelhar ao pseudocodigo, ao inves de verificar se a lista f tem o mesmo tamanho da lista de vertices do grafo eh feito uma iteracao em ordem lexicografica por todos os vertices do grafo
    for (int i = 0; i < this->qntd_vertices; i++){

        // int pos = this->posicaoMenorDT();
        Vertice* v = &vertices->at(i);
        verticeAtual = v->id;
        // f.push_back(*v);
        // v->fechado = true;

        if (verticeAtual == this->vertice_inicial){continue;}

        // aqui foi trocado a logica da iteracao, pois no dijkstra vc percoree o fecho transitivo direto do vertice e no bellman-ford vc percorre o fecho transitivo indireto do vertice
        // dijkstra original: for (auto it = v->adjacencia.begin(); it != v->adjacencia.end(); it++){
        for (auto it = v->antecessores.begin(); it != v->antecessores.end(); it++){
            Aresta a = this->arestas[*it - 1];
            int vizinho;

            if (a.origem == verticeAtual){
                vizinho = a.destino;
            }
            else{
                vizinho = a.origem;
            }

            // no bellman-ford nao eh verificado se o vertice esta fechado ou nao
            // if (vertices->at(vizinho - 1).fechado){
            //     continue;
            // }

            // a logica para atualizacao dos dados eh inversa. No dijkstra vc verifica se o caminho ate o vizinho pode ser atualizado por um caminho que passe pelo vertice atual. No bellman-ford vc verifica se o caminho do vertice atual pode ser melhorado passando por um vertice vizinho
            if ((vertices->at(vizinho - 1).dt + matriz->at(vizinho - 1).at(verticeAtual - 1).peso) < vertices->at(verticeAtual - 1).dt){
                vertices->at(verticeAtual - 1).dt = vertices->at(vizinho - 1).dt + matriz->at(vizinho - 1).at(verticeAtual - 1).peso;
                vertices->at(verticeAtual - 1).rot = vizinho;

                *altera = true;
            }
        }
    }
}

void Grafo::printInfo(){
    cout << "--------- Grafo ---------\n";
    cout << "Qntd vertices  : " << this->qntd_vertices << "\n" ;
    cout << "Qntd arestas   : " << this->qntd_arestas << "\n" ;
    cout << "Vertice inicial: " << this->vertice_inicial << "\n" ;
    cout << "Direcionado    : " << this->direcionado << "\n\n" ;
}
