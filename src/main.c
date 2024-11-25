#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "lista.h"
#include "utils.h"

#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION
#define UTILS_IMPLEMENTATION

int main() {
    // Criação da lista
    List minhaLista = {NULL};

    // Livros para adicionar na lista
    LIVRO livro1 = {"O Senhor dos Aneis", "J.R.R. Tolkien", 1954, "1234567890123", 1}; // true
    LIVRO livro2 = {"O Hobbit", "J.R.R. Tolkien", 1937, "9876543210123", 1}; // true
    LIVRO livro3 = {"A Revolucao dos Bichos", "George Orwell", 1945, "1928374650123", 1}; // true
    LIVRO livro4 = {"1984", "George Orwell", 1949, "5647382910123", 1}; // true

    // Inserção dos livros na lista
    insert_LISTA(&minhaLista, &livro1, 1);
    insert_LISTA(&minhaLista, &livro2, 2);
    insert_LISTA(&minhaLista, &livro3, 3);
    insert_LISTA(&minhaLista, &livro4, 4);

    // Imprimir lista antes da ordenação
    printf("Lista antes de ordenar:\n");
    print_LISTA(&minhaLista);

    // Ordena a lista por título (merge sort)
    
    mergeSort_LISTA(&minhaLista.head);
    
    // Imprimir lista após a ordenação
    printf("\nLista apos ordenar por titulo:\n");
    print_LISTA(&minhaLista);

    return 0;
}
