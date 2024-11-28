#ifndef FILA_H
#define FILA_H

#include "biblioteca.h"
#include "pessoa.h"

typedef struct ELEMENTO_FILA {
    PESSOA pessoa;
    struct ELEMENTO_FILA* prox;
} ELEMENTO_FILA;

typedef struct FILA {
    ELEMENTO_FILA* frente;
    ELEMENTO_FILA* tras;
    size_t tamanho;
} FILA;

// Funções para manipular a fila

#ifdef FILA_IMPLEMENTATION

void inicializarFila(FILA *f)
{
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

bool adiciona_FILA(FILA *f, PESSOA p) 
{
    ELEMENTO_FILA *novo = (ELEMENTO_FILA*) malloc(sizeof(ELEMENTO_FILA));
    
    if(novo == NULL) {
        print_error(MALLOC_ERR);
        return false;
    }

    novo->pessoa = p;
    novo->prox = NULL;

    if(f->frente == NULL) {
        f->frente = novo;
    } else {
        f->tras->prox = novo;
    }
    f->tras = novo;
    f->tamanho++;

    return true;
}

bool remove_FILA(FILA *f, PESSOA *p) 
{
    ELEMENTO_FILA *ptr = f->frente;

    if(ptr == NULL) {
        printf("Fila vazia");
        return false;
    }

    f->frente = f->frente->prox;
    ptr->prox = NULL;
    *p = ptr->pessoa;

    free(ptr);

    if(f->frente == NULL) {
        f->tras = NULL;
    }
    
    f->tamanho--;
    return true;
}

size_t tamanhoFila(FILA *f) 
{
    return f->tamanho;
}

#endif // FILA_IMPLEMENTATION 

#endif // FILA_H