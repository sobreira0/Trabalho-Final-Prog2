#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
                    
#ifdef DEBUG
/**
 * Nossa parte de logging de erros, com algumas contantes
 * definidas para termos tracking dos erros em momento de producao
 */
#define OUT_OF_RANGE "Index out of range"
#define EMPTY_LIST "List is empty"
#define EMPTY_QUEUE "Queue is empty"
#define MALLOC_ERR "Error at allocating dynamic space"
#define PERSON_NOT_FOUND "Error at finding person within the queue"
#define BOOK_NOT_FOUND "Error at finding book within the list"
#define MENU_ERROR "Error at menu func"

#define print_error(x)                                                          \
        do {                                                                    \
            fprintf(stderr, "%s: linha: %d - %s\n", __FILE__, __LINE__, x);     \
        } while (0)

#endif // DEBUG

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
LIVRO* ler_livro(FILE*);

#ifdef BIBLIOTECA_IMPLEMENTATION

void print_LIVRO(LIVRO l)
{
    fprintf(stdout, "Titulo: %s\nAutor: %s\nAno de Publicacao: %d\nISBN: %s\nDisponivel? %s\n"
            , l.titulo, l.autor, l.ano_publicacao, l.isbn, l.disponivel ? "sim" : "nao");
}

LIVRO* create_LIVRO(char *titulo, char *autor, char *ISBN, int ano)
{
    /**
     * Cria um livro dinamicamente na memoria, com o status de disponivel
     * 
     */
    LIVRO *new = (LIVRO *) malloc(sizeof(LIVRO));

    if (new == NULL) {
        #ifdef DEBUG
            print_error(MALLOC_ERR);
        #else
            perror("Erro ao alocar memoria");
        #endif
        return NULL;
    }

    new->titulo = strdup(titulo);
    new->autor = strdup(autor);
    strcpy(new->isbn, ISBN);
    new->ano_publicacao = ano;
    new->disponivel = true;
    
    return new;
}

LIVRO* ler_livro(FILE* arquivo_livro)
{
    /**
     * Le um livro do arquifvo livros.txt e retorna um endereco
     * do livro dinamicamente alocado
     */
    char linha[500];

    if(fgets(linha, sizeof(linha), arquivo_livro) == NULL)
    {
        return NULL;
    }

    linha[strcspn(linha, "\n")] = 0;

    char titulo[200], autor[200];
    int ano_publicacao;
    char isbn[15];
    int disponivel;

    int campos_lidos = sscanf(linha, "\"%[^\"]\",\"%[^\"]\",%d,\"%[^\"]\",%d", titulo, autor, &ano_publicacao, isbn, &disponivel);
    
    if(campos_lidos != 5)
    {
        return NULL;
    }

    LIVRO* livro = create_LIVRO(titulo, autor, isbn, ano_publicacao);

    return livro;
}
#endif // BIBLIOTECA_IMPLEMENTATION
#endif // BIBLIOTECA_H
