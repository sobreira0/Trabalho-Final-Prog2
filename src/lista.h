#ifndef LISTA_H
#define LISTA_H

#include "biblioteca.h"

typedef struct node{
    struct node *next;
    LIVRO livro;
} Node;

typedef struct {
    Node *head;
} List;

// Funções para manipular a LISTA

bool insert_LISTA(List*, LIVRO, size_t);
bool delete_LISTA(List*, LIVRO*, size_t);
void print_LISTA(List*);

#ifdef LISTA_IMPLEMENTATION

bool insert_LISTA(List *l, LIVRO data, size_t pos)
{
    Node* new = (Node *) malloc(sizeof(Node));
    
    if (new == NULL) {
        #ifdef DEBUG
            print_error(MALLOC_ERR);
        #else
            perror("Erro ao alocar memoria");
        #endif
        return false;
    }
    
    new->livro = data;

    if (pos == 0) {
        new->next = l->head;  
        l->head = new;        
        return true;
    }
    
    Node *temp = l->head;
 
    for (size_t i = 0; temp != NULL && i < pos-1; ++i) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        #ifdef DEBUG
            print_error(OUT_OF_RANGE);
        #else
            fprintf(stdout, "%s\n", "Posicao indicada esta alem do alcance da lista");
        #endif
        free(new);
        return false;
    }
 
    new->next = temp->next; 
    temp->next = new;        
    return true;
}


bool delete_LISTA(List *l, LIVRO *livro, size_t pos)
{
    if (l->head == NULL) {
        #ifdef DEBUG
            print_error(EMPTY_LIST);
        #else   
            fprintf(stdout, "%s\n", "Lista esta vazia");
        #endif
        return false;
    }
    Node *temp = l->head;
    if (pos == 0) {
        l->head = temp->next;
    } else {
        Node *prev;
        for (size_t i = 0; temp != NULL && i < pos-1; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            #ifdef DEBUG
                print_error(OUT_OF_RANGE);
            #else
                fprintf(stdout, "%s\n", "Posicao indicada esta alem do alcance da lista");
            #endif
            return false;
        }
        prev->next = temp->next;
    }

    *livro = temp->livro;
    free(temp);
    return true;
}

void print_LISTA(List *l)
{
    Node *n = l->head;
    int i = 1;
    while (n != NULL) {
        printf("*---------------------*\n");
        printf("Elemento %d:\n", i);
        print_LIVRO(n->livro);  
        n = n->next;
        i++;
    }
}

LIVRO *procura_livro(List *lista, const char *ISBN)
{
    Node *n = lista->head;
    while (n != NULL && (strcmp(n->livro.isbn, ISBN)) != 0) n = n->next;
    if (n == NULL) {
        #ifdef DEBUG
            print_error(BOOK_NOT_FOUND);
        #else 
            fprintf(stdout, "%s\n", "Livro nao esta cadastrado.");
        #endif
        return NULL;
    }

    return &n->livro;
}

#endif // LISTA_IMPLEMENTATION
#endif // LISTA_H
