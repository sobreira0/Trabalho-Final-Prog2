#ifndef LISTA_H
#define LISTA_H

#include "biblioteca.h"

typedef struct ELEMENTO
{
    LIVRO livro;
    struct ELEMENTO* prox;
} ELEMENTO;

typedef struct LISTA 
{
    ELEMENTO* inicio;
    int tamanho;
} LISTA;

// Funções para manipular a LISTA


#endif // LISTA_H
