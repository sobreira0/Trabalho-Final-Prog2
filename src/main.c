#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION
#define UTILS_IMPLEMENTATION

#include "biblioteca.h"
#include "lista.h"
#include "utils.h"



int main() {
    // Criação da lista
    List minhaLista = {0};

    // Livros para adicionar na lista
    LIVRO *livro1 = create_LIVRO("Senhor dos Aneis", "J.R.R. Tolkien", "123-4567890123", 1954);
    LIVRO *livro2 = create_LIVRO("O Hobbit", "J.R.R. Tolkien", "987-6543210123", 1937); 
    LIVRO *livro3 = create_LIVRO("A Revolucao dos Bichos", "George Orwell", "192-8374650123", 1945);
    LIVRO *livro4 = create_LIVRO("1984", "George Orwell", "564-7382910123", 1949);

    // Inserção dos livros na lista
    insert_LISTA(&minhaLista, livro1, 0);
    insert_LISTA(&minhaLista, livro2, 1);
    insert_LISTA(&minhaLista, livro3, 2);
    insert_LISTA(&minhaLista, livro4, 3);

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
