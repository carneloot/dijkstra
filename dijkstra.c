#include "dijkstra.h"

#include <stdlib.h>
#include <string.h>
#include <float.h>

struct DVInfo {
  char *label;
  double distancia;
  struct DVInfo *anterior;
};

typedef struct DVInfo *DVInfo;

static DVInfo create_dvinfo(char *label, double distancia) {
  DVInfo this = calloc(1, sizeof(*this));

  this->label     = label;
  this->distancia = distancia;
  this->anterior  = NULL;

  return this;
}

static Posic pegarMaisProximo(Lista vertices) {
  Posic it = Lista_t.get_first(vertices);

  Posic pMenor = it;
  DVInfo menor = Lista_t.get(vertices, pMenor);

  while (it) {
    DVInfo atual = Lista_t.get(vertices, it);

    if (atual->distancia < menor->distancia) {
      pMenor = it;
      menor = atual;
    }
    
    it = Lista_t.get_next(vertices, it);
  }

  return pMenor;
}

static Lista getVertices(char **labels, int tamanho, char *inicial) {
  Lista vertices = Lista_t.create();

  for (int i = 0; i < tamanho; i++) {
    char *label = labels[i];

    DVInfo info = create_dvinfo(label, DBL_MAX);

    if (!strcmp(label, inicial))
      info->distancia = 0;

    Lista_t.insert(vertices, info);
  }

  return vertices;
}

static int labelIgual(const Item _info, const void *_label) {
  DVInfo info = (DVInfo) _info;
  char *label = (char *) _label;

  return strcmp(info->label, label);
}

static void gerarCaminhoRec(DVInfo atual, Lista lista) {
  if (atual->anterior == NULL) {
    Lista_t.insert(lista, atual->label);
    return;
  }

  gerarCaminhoRec(atual->anterior, lista);

  Lista_t.insert(lista, atual->label);
}

static Lista gerarCaminho(DVInfo target) {
  Lista lista = Lista_t.create();

  gerarCaminhoRec(target, lista);

  return lista;
}

Lista dijkstra(GrafoD grafo, char *origem, char *destino, double (*get_dist_aresta)(void *aresta_info)) {

  char **labels = GrafoD_t.get_all_vertices(grafo);
  Lista vertices = getVertices(labels, GrafoD_t.total_vertices(grafo), origem);
  free(labels);

  Lista nao_visitados = Lista_t.copy(vertices);

  DVInfo target;

  // Enquanto todos nao forem visitados
  while (Lista_t.length(nao_visitados) > 0) {

    // Pegue o nao visitado mais proximo
    Posic pMaisProximo = pegarMaisProximo(nao_visitados);
    DVInfo maisProximo = Lista_t.get(nao_visitados, pMaisProximo);

    // Insira ele a lista de visitados
    Lista_t.remove(nao_visitados, pMaisProximo);

    // Se cheguei ao alvo para
    if (!strcmp(destino, maisProximo->label)) {
      target = maisProximo;
      break;
    }


    // Passar por todos os adjacentes atualizando a distancia e o anterior
    Lista adjacentes = GrafoD_t.adjacentes(grafo, maisProximo->label);

    Posic it = Lista_t.get_first(adjacentes);

    while (it) {
      char *adjacenteLabel  = Lista_t.get(adjacentes, it);

      void *infoAresta = GrafoD_t.get_info_aresta(grafo, maisProximo->label, adjacenteLabel);
      Posic pInfoAtual = Lista_t.search(vertices, Lista_t.get_first(vertices), adjacenteLabel, labelIgual);
      DVInfo infoAtual = Lista_t.get(vertices, pInfoAtual);

      double novaDist = maisProximo->distancia + get_dist_aresta(infoAresta);

      if (novaDist < infoAtual->distancia) {
        infoAtual->distancia = novaDist;
        infoAtual->anterior  = maisProximo;
      }

      it = Lista_t.get_next(adjacentes, it);
    }

    Lista_t.destruir(adjacentes, 0);
  }

  Lista_t.destruir(nao_visitados, 0);

  Lista caminho = gerarCaminho(target);

  Lista_t.destruir(vertices, free);

  return caminho;
}