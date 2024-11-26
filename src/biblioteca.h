#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define print_error(x)                                                          \
        do {                                                                    \
            fprintf(stderr, "%s: linha: %s - %s\n", __FILE__, __LINE__, x);     \
        } while (0)
        
                           

#define OUT_OF_RANGE "Index out of range"
#define EMPTY_LIST "List is empty"
#define MALLOC_ERR "Error at allocating dynamic space"


typedef struct LIVRO 
{
    char *titulo;
    char *autor;
    int ano_publicacao;
    char isbn[15]; // 13 caracteres para ISBN-13
    bool disponivel;    // true = disponível, falso = emprestado
} LIVRO;

LIVRO* create_LIVRO(char*, char*, char*, int);
void print_LIVRO(LIVRO);

#ifdef BIBLIOTECA_IMPLEMENTATION

void print_LIVRO(LIVRO l)
{
    fprintf(stdout, "Titulo: %s\nAutor: %s\nAno de Publicacao: %d\nISBN: %s\nDisponivel? %s\n"
            , l.titulo, l.autor, l.ano_publicacao, l.isbn, l.disponivel ? "sim" : "nao");
}

LIVRO* create_LIVRO(char *titulo, char *autor, char *ISBN, int ano)
{
    LIVRO *new = (LIVRO *) malloc(sizeof(LIVRO));
    if (new == NULL) {
        print_error(MALLOC_ERR);
        return NULL;
    }

    new->titulo = strdup(titulo);
    new->autor = strdup(autor);
    strcpy(new->isbn, ISBN);
    new->ano_publicacao = ano;
    new->disponivel = true;
    return new;
}

#endif // BIBLIOTECA_IMPLEMENTATION
#endif // BIBLIOTECA_H
