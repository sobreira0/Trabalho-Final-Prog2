#ifndef FILA_H
#define FILA_H

#include "biblioteca.h"

typedef struct ELEMENTO_FILA {
    LIVRO livro;
    struct ELEMENTO_FILA* prox;
} ELEMENTO_FILA;

typedef struct FILA {
    ELEMENTO_FILA* frente;
    ELEMENTO_FILA* tras;
    int tamanho;
} FILA;

// Funções para manipular a fila

#endif // FILA_H
