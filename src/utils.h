#ifndef UTILS_H
#define UTILS_H

#include "biblioteca.h"
#include "lista.h"

// Funções úteis para manipulação de listas com Merge Sort

void split_lista(Node* source, Node** frontRef, Node** backRef);
Node* sortedMerge(Node* a, Node* b);
void mergeSort_LISTA(Node** headRef);

#ifdef UTILS_IMPLEMENTATION


void split_lista(Node* source, Node** frontRef, Node** backRef) 
{
    // Se a lista tiver menos de 2 elementos
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Dividir a lista
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;  // Quebra a lista em duas partes
}


Node* sortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    // Caso base: uma das listas está vazia
    if (a == NULL) return b;
    if (b == NULL) return a;

    // Comparar os títulos das obras em ordem alfabética
    if (strcmp(a->livro->titulo, b->livro->titulo) <= 0) {
        result = a;
        result->next = sortedMerge(a->next, b);  
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);  
    }

    return result;
}

// Função principal de Merge Sort para a lista
void mergeSort_LISTA(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    // Caso base: lista com 0 ou 1 elemento
    if (head == NULL || head->next == NULL) {
        return;
    }

    split_lista(head, &a, &b);  
    mergeSort_LISTA(&a);  
    mergeSort_LISTA(&b); 
    *headRef = sortedMerge(a, b);  
}

#endif
#endif
