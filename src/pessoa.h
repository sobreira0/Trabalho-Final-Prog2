#ifndef PESSOA_H
#define PESSOA_H

#include "biblioteca.h"

typedef struct {
    char *nome;
    char *cpf;
    LIVRO *livro_emprestado;
    unsigned int status;
} PESSOA;

#ifdef PESSOA_IMPLEMENTATION

PESSOA *cria_PESSOA(const char *nome, const char *cpf)
{
    PESSOA *p = (PESSOA*) malloc(sizeof(PESSOA));

    if (p == NULL) {
        print_error(MALLOC_ERR);
        return false;
    }

    p->nome = strdup(nome);
    p->cpf = strdup(cpf);
    p->livro_emprestado = NULL;
    p->status = 1;

    return p;
}

bool empresta_Livro(PESSOA *p, LIVRO *l)
{
    if(!l->disponivel) {
        fprintf(stdout, "%s\n", "O livro nao esta disponivel para emprestimo");
        return false;
    }

    p->livro_emprestado = l;
    l->disponivel = false;

    return true; 
}

#endif // PESSOA_IMPLEMENTATION

#endif // PESSOA_H