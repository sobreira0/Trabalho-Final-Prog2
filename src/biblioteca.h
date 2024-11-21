#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct LIVRO 
{
    char titulo[100];
    char autor[100];
    int ano_publicacao;
    char isbn[13]; // 13 caracteres para ISBN-13
    int status;    // 0 = disponível, 1 = emprestado
} LIVRO;

#endif // BIBLIOTECA_H
