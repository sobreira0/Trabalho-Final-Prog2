#ifndef LISTA_H
#define LISTA_H

#include "biblioteca.h"

typedef struct node{
    struct node *next; // 8 bytes bytes
    LIVRO *data; // 8 bytes
} Node;

typedef struct {
    Node *head;
} List;

// Funções para manipular a LISTA

bool insert_LISTA(List*, LIVRO*, size_t);
bool delete_LISTA(List*, LIVRO*, size_t);
void print_LISTA(List*);

#ifdef LISTA_IMPLEMENTATION

bool insert_LISTA(List *l, LIVRO *data, size_t pos)
{
    Node* new = (Node *) malloc(sizeof(Node));
    
    if (new == NULL) {
        print_error(MALLOC_ERR);
        return false;
    }
    
    new->data = data;

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
        print_error(OUT_OF_RANGE);
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
        print_error(EMPTY_LIST);
        return false;
    }
    Node *temp = l->head;
    if (pos == 0) {
        *livro = *(temp->data);
        l->head = temp->next;
        free(temp);
        return true;
    }
    Node *prev;
    for (size_t i = 0; temp != NULL && i < pos-1; ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        print_error(OUT_OF_RANGE);
        return false;
    }
    
    *livro = *(temp->data);
    prev->next = temp->next;
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
        print_LIVRO(*(n->data));  
        n = n->next;
        i++;
    }
}


#endif // LISTA_IMPLEMENTATION
#endif // LISTA_H
