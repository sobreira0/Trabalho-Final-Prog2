#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#define MAX 100
typedef struct LIVRO 
{
    char titulo[MAX];
    char autor[MAX];
    int ano_publicacao;
    char isbn[13]; // 13 caracteres para ISBN-13
    int status;    // 0 = disponível, 1 = emprestado
} LIVRO;

#endif // BIBLIOTECA_H
