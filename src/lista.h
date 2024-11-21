#ifndef LISTA_H
#define LISTA_H

#include "biblioteca.h"

typedef struct ELEMENTO_LISTA
{
    LIVRO livro;
    struct ELEMENTO_LISTA* prox;
} ELEMENTO_LISTA;

typedef struct LISTA 
{
    ELEMENTO_LISTA* inicio;
    int tamanho;
} LISTA;

// Funções para manipular a LISTA


#endif // LISTA_H
