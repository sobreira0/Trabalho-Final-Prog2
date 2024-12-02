#define BIBLIOTECA_IMPLEMENTATION
#define LISTA_IMPLEMENTATION
#define UTILS_IMPLEMENTATION
#define FILA_IMPLEMENTATION
#define PESSOA_IMPLEMENTATION
#define DEBUG

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
    /**
     * Primeira versao do menu, ainda a ser implementado.
     */
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
        puts("\t2 - Cadastrar livro");
        puts("\t3 - Listar livros em ordem alfabetica de titulo");
        scanf("%c", &opt);
        switch (opt)
        {
        case '1':
            if (p->livro_emprestado == NULL) puts("Voce nao tem livros emprestados no momento");
            else print_LIVRO(p->livro_emprestado);
            break;
        case '2': ;
            char titulo[TITULO_MAX], autor[AUTOR_MAX];
            int ano_publicacao;
            puts("Digite o titulo do livro:");
            scanf("%s", titulo);
            puts("Digite o autor do livro:");
            scanf("%s", autor);
            puts("Digite o ano de lancamento do livro");
            scanf("%d", &ano_publicacao);
            char ISBN[ISBN_MAX];
            puts("Digite a ISBN do livro que deseja pegar emprestado");
            scanf("%s", ISBN);
            LIVRO *livro = create_LIVRO(titulo, autor, ISBN, ano_publicacao);
            if (livro == NULL) return 1;
            if(!escrever_livro(arquivo_livro, livro)) return 1;
            break;
        case '3': ;
            List livros_sorted;
            memcpy(&livros_sorted, &livros, sizeof(List));
            mergeSort_LISTA(&(livros_sorted.head));
            print_LISTA(&livros_sorted);
            break;
        }
        getchar();
    } 

    fclose(arquivo_livro);

    return 0;
}
