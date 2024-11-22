#ifndef FILA_H
#define FILA_H

#include "biblioteca.h"

typedef struct ELEMENTO_FILA {
    PESSOA pessoa;
    struct ELEMENTO_FILA* prox;
} ELEMENTO_FILA;

typedef struct FILA {
    ELEMENTO_FILA* frente;
    ELEMENTO_FILA* tras;
    int tamanho;
} FILA;

typedef struct PESSOA {
    char nome[MAX];
} PESSOA;

// Funções para manipular a fila
void inicializarFila(FILA *f){
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

 void enfileiramento(FILA *f, PESSOA p){
    ELEMENTO_FILA *novo = malloc(sizeof(ELEMENTO_FILA));
    if(novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }else {
        novo->pessoa = p;
        novo->prox = NULL;
        if(f->frente == NULL) {
            f->frente = novo;
        } else {
            f->tras->prox = novo;
        }
        f->tras = novo;
    }
 }
#endif // FILA_H