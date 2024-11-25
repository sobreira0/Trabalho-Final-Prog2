#ifndef UTILS_H
#define UTILS_H

#include "biblioteca.h"
#include "lista.h"

// Funções úteis para manipulação de listas com Merge Sort

void split_lista(Node* source, Node** frontRef, Node** backRef);
Node* sortedMerge(Node* a, Node* b);
void mergeSort_LISTA(Node** headRef);

#ifdef UTILS_IMPLEMENTATION

// Função para dividir a lista em duas partes
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

    // Mover 'fast' duas vezes mais rápido que 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Dividir a lista
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;  // Quebra a lista em duas partes
}

// Função para mesclar duas listas ordenadas
Node* sortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    // Caso base: uma das listas está vazia
    if (a == NULL) return b;
    if (b == NULL) return a;

    // Comparar os títulos das obras em ordem alfabética
    if (strcmp(a->data->titulo, b->data->titulo) <= 0) {
        result = a;
        result->next = sortedMerge(a->next, b);  // Recursão para mesclar
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);  // Recursão para mesclar
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

    printf("Dividindo a lista...\n");
    split_lista(head, &a, &b);  // Divide a lista

    printf("Ordenando recursivamente a primeira metade...\n");
    mergeSort_LISTA(&a);  // Ordena recursivamente a primeira metade

    printf("Ordenando recursivamente a segunda metade...\n");
    mergeSort_LISTA(&b);  // Ordena recursivamente a segunda metade

    printf("Mesclando as duas metades ordenadas...\n");
    *headRef = sortedMerge(a, b);  // Mescla as duas metades ordenadas
}

#endif
#endif
