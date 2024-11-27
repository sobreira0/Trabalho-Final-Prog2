#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION
#define UTILS_IMPLEMENTATION

#include "biblioteca.h"
#include "lista.h"
#include "utils.h"

int main() 
{
    FILE *arquivo_livro = fopen("livros.txt", "r");
    if (arquivo_livro == NULL) 
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    
    List* lista = (List*) malloc(sizeof(List));
    if (lista == NULL) {
        print_error(MALLOC_ERR);
        return 1;
    }
    lista->head = NULL;  // Inicializa a lista com head como NULL

    LIVRO *livro;
    int contador = 0;

    // Loop para ler todos os livros até o final do arquivo
    while ((livro = ler_livro(arquivo_livro)) != NULL)
    {
        insert_LISTA(lista, livro, contador);
        contador++;
    }

    // Exibe a lista
    printf("Sua lista de livros:\n");
    print_LISTA(lista);
    
    // Fechar o arquivo
    fclose(arquivo_livro);
    
    // Liberar a memória alocada para a lista
    Node *n = lista->head;
    while (n != NULL) {
        Node *temp = n;
        n = n->next;
        free(temp->data->titulo);
        free(temp->data->autor);
        free(temp->data);
        free(temp);
    }
    free(lista);

    return 0;
}