#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafod.h"
#include "dijkstra.h"

char *verticesLookup[] = {
  "0",
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
};

struct {
  char *origem;
  char *destino;
  double peso;
} arestasLookup[] = {
  {"0", "1", 4},
  {"0", "7", 8},

  {"1", "0", 4},
  {"1", "2", 8},
  {"1", "7", 11},

  {"2", "1", 8},
  {"2", "3", 7},
  {"2", "5", 4},
  {"2", "8", 2},

  {"3", "2", 7},
  {"3", "4", 9},
  {"3", "5", 14},

  {"4", "3", 9},
  {"4", "5", 10},

  {"5", "2", 4},
  {"5", "3", 14},
  {"5", "4", 10},
  {"5", "6", 2},

  {"6", "5", 2},
  {"6", "7", 1},
  {"6", "8", 6},

  {"7", "0", 8},
  {"7", "1", 11},
  {"7", "6", 1},
  {"7", "8", 7},

  {"8", "2", 2},
  {"8", "6", 6},
  {"8", "7", 7},

};


struct VerticeInfo {
  char *identificador;
};

typedef struct VerticeInfo *VerticeInfo;

VerticeInfo newVerticeInfo(char *id) {
  VerticeInfo this = calloc(1, sizeof(*this));
  this->identificador = id;
  return this;
}

struct ArestaInfo {
  double distancia;
};

typedef struct ArestaInfo *ArestaInfo;

ArestaInfo newArestaInfo(double distancia) {
  ArestaInfo this = calloc(1, sizeof(*this));
  this->distancia = distancia;
  return this;
}

void initGrafo(GrafoD grafo, Lista vertices, Lista arestas) {
  int tamanho = sizeof(verticesLookup) / sizeof(verticesLookup[0]);
  for (int i = 0; i < tamanho; i++) {
    VerticeInfo v = newVerticeInfo(verticesLookup[i]);
    GrafoD_t.insert_vertice(grafo, verticesLookup[i]);
    GrafoD_t.define_info_vertice(grafo, verticesLookup[i], v);
    Lista_t.insert(vertices, v);
  }

  tamanho = sizeof(arestasLookup) / sizeof(arestasLookup[0]);
  for (int i = 0; i < tamanho; i++) {
    ArestaInfo aresta = newArestaInfo(arestasLookup[i].peso);
    Lista_t.insert(arestas, aresta);
    GrafoD_t.insert_aresta(grafo, arestasLookup[i].origem, arestasLookup[i].destino);
    GrafoD_t.define_info_aresta(grafo, arestasLookup[i].origem, arestasLookup[i].destino, aresta);
  }

}

double get_distancia_aresta(void *_aresta) {
  ArestaInfo aresta = _aresta;
  return aresta->distancia;
}

int main(int argc, char *argv[]) {

  GrafoD grafo    = GrafoD_t.create();
  Lista vertices  = Lista_t.create();
  Lista arestas   = Lista_t.create();

  initGrafo(grafo, vertices, arestas);

  FILE *arqGrafo = fopen("grafo.dot", "w");

  GrafoD_t.generate_dot(grafo, arqGrafo);

  fclose(arqGrafo);

  Lista caminho = dijkstra(grafo, "0", argv[1], get_distancia_aresta);
  
  // Printar as distancias
  Posic it = Lista_t.get_first(caminho);

  while (it) {
    char *info = Lista_t.get(caminho, it);

    printf("%s\n", info);

    it = Lista_t.get_next(caminho, it);
  }

  GrafoD_t.destroy(grafo);
  Lista_t.destruir(vertices, free);
  Lista_t.destruir(arestas, free);

  Lista_t.destruir(caminho, 0);

  return 0;
}