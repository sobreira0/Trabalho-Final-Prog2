#include <stdio.h>
#include "biblioteca.h"
#include "lista.h"
#include "fila.h"
#include "utils.h"

#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION

int main()
{
    LIVRO *teste = create_LIVRO("titulo", "Guilherme", "978-8533613409", 2024);
    LIVRO *teste2 = create_LIVRO("titulo2", "Andre", "123-4567891012", 1999);

    List l = {0};

    insert_LISTA(&l, teste, 1);
    insert_LISTA(&l, teste2, 2);
    print_LISTA(&l);
    return 0;
}
