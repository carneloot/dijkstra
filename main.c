#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "grafod.h"
#include "dijkstra.h"

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
  VerticeInfo v0 = newVerticeInfo("0");
  GrafoD_t.insert_vertice(grafo, "0"); GrafoD_t.define_info_vertice(grafo, "0", v0);
  Lista_t.insert(vertices, v0);

  VerticeInfo v1 = newVerticeInfo("1");
  GrafoD_t.insert_vertice(grafo, "1"); GrafoD_t.define_info_vertice(grafo, "1", v1);
  Lista_t.insert(vertices, v1);

  VerticeInfo v2 = newVerticeInfo("2");
  GrafoD_t.insert_vertice(grafo, "2"); GrafoD_t.define_info_vertice(grafo, "2", v2);
  Lista_t.insert(vertices, v2);

  VerticeInfo v3 = newVerticeInfo("3");
  GrafoD_t.insert_vertice(grafo, "3"); GrafoD_t.define_info_vertice(grafo, "3", v3);
  Lista_t.insert(vertices, v3);

  VerticeInfo v4 = newVerticeInfo("4");
  GrafoD_t.insert_vertice(grafo, "4"); GrafoD_t.define_info_vertice(grafo, "4", v4);
  Lista_t.insert(vertices, v4);

  VerticeInfo v5 = newVerticeInfo("5");
  GrafoD_t.insert_vertice(grafo, "5"); GrafoD_t.define_info_vertice(grafo, "5", v5);
  Lista_t.insert(vertices, v5);

  VerticeInfo v6 = newVerticeInfo("6");
  GrafoD_t.insert_vertice(grafo, "6"); GrafoD_t.define_info_vertice(grafo, "6", v6);
  Lista_t.insert(vertices, v6);

  VerticeInfo v7 = newVerticeInfo("7");
  GrafoD_t.insert_vertice(grafo, "7"); GrafoD_t.define_info_vertice(grafo, "7", v7);
  Lista_t.insert(vertices, v7);

  VerticeInfo v8 = newVerticeInfo("8");
  GrafoD_t.insert_vertice(grafo, "8"); GrafoD_t.define_info_vertice(grafo, "8", v8);
  Lista_t.insert(vertices, v8);

  ArestaInfo v0v1 = newArestaInfo(4); Lista_t.insert(arestas, v0v1);
  GrafoD_t.insert_aresta(grafo, "0", "1"); GrafoD_t.define_info_aresta(grafo, "0", "1", v0v1);
  ArestaInfo v0v7 = newArestaInfo(8); Lista_t.insert(arestas, v0v7);
  GrafoD_t.insert_aresta(grafo, "0", "7"); GrafoD_t.define_info_aresta(grafo, "0", "7", v0v7);

  ArestaInfo v1v0 = newArestaInfo(4); Lista_t.insert(arestas, v1v0);
  GrafoD_t.insert_aresta(grafo, "1", "0"); GrafoD_t.define_info_aresta(grafo, "1", "0", v1v0);
  ArestaInfo v1v2 = newArestaInfo(8); Lista_t.insert(arestas, v1v2);
  GrafoD_t.insert_aresta(grafo, "1", "2"); GrafoD_t.define_info_aresta(grafo, "1", "2", v1v2);
  ArestaInfo v1v7 = newArestaInfo(11); Lista_t.insert(arestas, v1v7);
  GrafoD_t.insert_aresta(grafo, "1", "7"); GrafoD_t.define_info_aresta(grafo, "1", "7", v1v7);

  ArestaInfo v2v1 = newArestaInfo(8); Lista_t.insert(arestas, v2v1);
  GrafoD_t.insert_aresta(grafo, "2", "1"); GrafoD_t.define_info_aresta(grafo, "2", "1", v2v1);
  ArestaInfo v2v3 = newArestaInfo(7); Lista_t.insert(arestas, v2v3);
  GrafoD_t.insert_aresta(grafo, "2", "3"); GrafoD_t.define_info_aresta(grafo, "2", "3", v2v3);
  ArestaInfo v2v5 = newArestaInfo(4); Lista_t.insert(arestas, v2v5);
  GrafoD_t.insert_aresta(grafo, "2", "5"); GrafoD_t.define_info_aresta(grafo, "2", "5", v2v5);
  ArestaInfo v2v8 = newArestaInfo(2); Lista_t.insert(arestas, v2v8);
  GrafoD_t.insert_aresta(grafo, "2", "8"); GrafoD_t.define_info_aresta(grafo, "2", "8", v2v8);

  ArestaInfo v3v2 = newArestaInfo(7); Lista_t.insert(arestas, v3v2);
  GrafoD_t.insert_aresta(grafo, "3", "2"); GrafoD_t.define_info_aresta(grafo, "3", "2", v3v2);
  ArestaInfo v3v4 = newArestaInfo(9); Lista_t.insert(arestas, v3v4);
  GrafoD_t.insert_aresta(grafo, "3", "4"); GrafoD_t.define_info_aresta(grafo, "3", "4", v3v4);
  ArestaInfo v3v5 = newArestaInfo(14); Lista_t.insert(arestas, v3v5);
  GrafoD_t.insert_aresta(grafo, "3", "5"); GrafoD_t.define_info_aresta(grafo, "3", "5", v3v5);

  ArestaInfo v4v3 = newArestaInfo(9); Lista_t.insert(arestas, v4v3);
  GrafoD_t.insert_aresta(grafo, "4", "3"); GrafoD_t.define_info_aresta(grafo, "4", "3", v4v3);
  ArestaInfo v4v5 = newArestaInfo(10); Lista_t.insert(arestas, v4v5);
  GrafoD_t.insert_aresta(grafo, "4", "5"); GrafoD_t.define_info_aresta(grafo, "4", "5", v4v5);

  ArestaInfo v5v2 = newArestaInfo(4); Lista_t.insert(arestas, v5v2);
  GrafoD_t.insert_aresta(grafo, "5", "2"); GrafoD_t.define_info_aresta(grafo, "5", "2", v5v2);
  ArestaInfo v5v3 = newArestaInfo(14); Lista_t.insert(arestas, v5v3);
  GrafoD_t.insert_aresta(grafo, "5", "3"); GrafoD_t.define_info_aresta(grafo, "5", "3", v5v3);
  ArestaInfo v5v4 = newArestaInfo(10); Lista_t.insert(arestas, v5v4);
  GrafoD_t.insert_aresta(grafo, "5", "4"); GrafoD_t.define_info_aresta(grafo, "5", "4", v5v4);
  ArestaInfo v5v6 = newArestaInfo(2); Lista_t.insert(arestas, v5v6);
  GrafoD_t.insert_aresta(grafo, "5", "6"); GrafoD_t.define_info_aresta(grafo, "5", "6", v5v6);

  ArestaInfo v6v5 = newArestaInfo(2); Lista_t.insert(arestas, v6v5);
  GrafoD_t.insert_aresta(grafo, "6", "5"); GrafoD_t.define_info_aresta(grafo, "6", "5", v6v5);
  ArestaInfo v6v7 = newArestaInfo(1); Lista_t.insert(arestas, v6v7);
  GrafoD_t.insert_aresta(grafo, "6", "7"); GrafoD_t.define_info_aresta(grafo, "6", "7", v6v7);
  ArestaInfo v6v8 = newArestaInfo(6); Lista_t.insert(arestas, v6v8);
  GrafoD_t.insert_aresta(grafo, "6", "8"); GrafoD_t.define_info_aresta(grafo, "6", "8", v6v8);

  ArestaInfo v7v0 = newArestaInfo(8); Lista_t.insert(arestas, v7v0);
  GrafoD_t.insert_aresta(grafo, "7", "0"); GrafoD_t.define_info_aresta(grafo, "7", "0", v7v0);
  ArestaInfo v7v1 = newArestaInfo(11); Lista_t.insert(arestas, v7v1);
  GrafoD_t.insert_aresta(grafo, "7", "1"); GrafoD_t.define_info_aresta(grafo, "7", "1", v7v1);
  ArestaInfo v7v6 = newArestaInfo(1); Lista_t.insert(arestas, v7v6);
  GrafoD_t.insert_aresta(grafo, "7", "6"); GrafoD_t.define_info_aresta(grafo, "7", "6", v7v6);
  ArestaInfo v7v8 = newArestaInfo(7); Lista_t.insert(arestas, v7v8);
  GrafoD_t.insert_aresta(grafo, "7", "8"); GrafoD_t.define_info_aresta(grafo, "7", "8", v7v8);

  ArestaInfo v8v2 = newArestaInfo(2); Lista_t.insert(arestas, v8v2);
  GrafoD_t.insert_aresta(grafo, "8", "2"); GrafoD_t.define_info_aresta(grafo, "8", "2", v8v2);
  ArestaInfo v8v6 = newArestaInfo(6); Lista_t.insert(arestas, v8v6);
  GrafoD_t.insert_aresta(grafo, "8", "6"); GrafoD_t.define_info_aresta(grafo, "8", "6", v8v6);
  ArestaInfo v8v7 = newArestaInfo(7); Lista_t.insert(arestas, v8v7);
  GrafoD_t.insert_aresta(grafo, "8", "7"); GrafoD_t.define_info_aresta(grafo, "8", "7", v8v7);

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