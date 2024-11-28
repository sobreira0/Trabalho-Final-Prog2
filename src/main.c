#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION
#define UTILS_IMPLEMENTATION
#define FILA_IMPLEMENTATION
#define PESSOA_IMPLEMENTATION

#include "biblioteca.h"
#include "lista.h"
#include "fila.h"
#include "pessoa.h"
#include "utils.h"

int main() 
{
    FILA pessoas = {0};
    List livros = {0};  
    inicializarFila(&pessoas);

    const char *livros_path = "../livros.txt";
    FILE *arquivo_livro = fopen(livros_path, "r+");

    if (arquivo_livro == NULL) 
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int contador = 0;

    // Loop para ler todos os livros até o final do arquivo
    LIVRO *livro;
    while ((livro = ler_livro(arquivo_livro)) != NULL)
    {
        insert_LISTA(&livros, *livro, contador);
        contador++;
    }

    puts("Digite seu nome:");
    char nome[100] = {0};
    scanf("%s", nome);
    puts("Digite seu CPF:");
    char cpf[100] = {0};
    scanf("%s", cpf);
    PESSOA *p = cria_PESSOA(nome, cpf);
    if(!adiciona_FILA(&pessoas, *p)) return 1;
    
    getchar();
    char opt = -1;
    while (opt != 'q') {
        puts("<-------------------------------->");
        puts("\tBem vindo a Biblioteca BCC");
        puts("\tDigite 'q' para sair");
        puts("\tEscolha uma opcao:");
        puts("\t1 - Consultar meu livro emprestado");
        puts("\t2 - Pegar livro emprestado");
        puts("\t3 - Listar livros em ordem alfabetica de titulo");
        scanf("%c", &opt);
        switch (opt)
        {
        case '1':
            if (p->livro_emprestado == NULL) puts("Voce nao tem livros emprestados no momento");
            else print_LIVRO(*p->livro_emprestado);
            break;
        case '2': ;
            char ISBN[15];
            puts("Digite a ISBN do livro que deseja pegar emprestado");
            scanf("%s", ISBN);
            LIVRO *livro = procura_livro(&livros, ISBN);
            if (livro == NULL) puts("Nao temos este livro");
            else empresta_Livro(p, livro);
            break;
        case '3': ;
            List livros_sorted;
            memcpy(&livros_sorted, &livros, sizeof(List));
            mergeSort_LISTA(&livros_sorted.head);
            print_LISTA(&livros_sorted);
            break;
        }
        getchar();
    } 

    return 0;
}
