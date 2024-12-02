# Trabalho Final - Prog2

## Bem-vindo à Biblioteca BCC!

Nosso programa simula uma biblioteca digital, onde você pode:
- Emprestar ou devolver livros.
- Consultar a lista de livros por ordem alfabética ou disponibilidade.
- Cadastrar novos livros.

---

## Arquivos e suas Funcionalidades

### 1. `biblioteca.h`
Define uma biblioteca para gerenciar livros, com as seguintes funcionalidades:

- **Criação de um livro (`create_LIVRO`)**  
  Aloca dinamicamente um livro com título, autor, ISBN e ano de publicação. Define o livro como disponível para empréstimo.

- **Leitura de um livro de arquivo (`ler_livro`)**  
  Lê informações de um livro a partir de um arquivo CSV e retorna o ponteiro do livro criado dinamicamente.

- **Exibição de informações do livro (`print_LIVRO`)**  
  Exibe o título, autor, ano de publicação, ISBN e status de disponibilidade do livro.

- **Escrita de um livro em arquivo (`escrever_livro`)**  
  Grava as informações de um livro no final de um arquivo CSV.

---

### 2. `fila.h`
Gerencia uma fila FIFO de pessoas (`PESSOA`). Funcionalidades principais:

- **Inicialização da fila (`inicializarFila`)**  
  Configura uma fila vazia.

- **Adicionar pessoa à fila (`adiciona_FILA`)**  
  Adiciona uma pessoa ao final da fila e atualiza o ponteiro `tras`.

- **Remover pessoa da fila (`remove_FILA`)**  
  Remove a pessoa da frente da fila e retorna suas informações, liberando memória do elemento removido.

- **Obter tamanho da fila (`tamanhoFila`)**  
  Retorna o número de elementos na fila.

- **Liberar todos os elementos da fila (`explode_FILA`)**  
  Libera a memória de todos os elementos e redefine a fila para vazia.

---

### 3. `lista.h`
Gerencia uma lista ligada de livros (`LIVRO`). Funcionalidades principais:

- **Inserção de livro (`insert_LISTA`)**  
  Insere um livro em uma posição específica da lista.

- **Remoção de livro (`delete_LISTA`)**  
  Remove um livro da lista e copia seus dados para uma variável fornecida.

- **Impressão da lista de livros (`print_LISTA`)**  
  Exibe detalhes de todos os livros na lista.

- **Impressão de livros disponíveis (`print_LISTA_disponiveis`)**  
  Exibe apenas os livros disponíveis para empréstimo.

- **Busca por ISBN (`procura_livro_ISBN`)**  
  Retorna um ponteiro para o livro com o ISBN fornecido, ou `NULL` se não encontrado.

- **Inicialização e limpeza da lista (`inicializa_LISTA` e `explode_LISTA`)**  
  Configura a lista como vazia e libera memória de todos os elementos.

---

### 4. `pessoa.h`
Gerencia informações sobre pessoas que podem emprestar livros. Funcionalidades principais:

- **Criação de pessoa (`cria_PESSOA`)**  
  Cria uma nova pessoa com nome e CPF. Inicializa campos relacionados a empréstimos.

- **Empréstimo de livro (`empresta_Livro`)**  
  Permite emprestar um livro caso esteja disponível e a pessoa não tenha outro livro emprestado.

- **Devolução de livro (`devolve_Livro`)**  
  Devolve um livro emprestado, tornando-o novamente disponível.

- **Leitura de pessoa de arquivo (`ler_pessoa`)**  
  Lê informações de uma pessoa de um arquivo formatado e tenta associar um livro emprestado.

---

### 5. `utils.h`
Implementa funções utilitárias para ordenar listas ligadas de livros. Funcionalidades principais:

- **Divisão da lista (`split_lista`)**  
  Divide uma lista ligada em duas partes para o Merge Sort.

- **Intercalação ordenada (`sortedMerge`)**  
  Combina duas listas ordenadas em uma única lista.

- **Ordenação da lista (`mergeSort_LISTA`)**  
  Ordena uma lista ligada de livros pelo título utilizando Merge Sort.

---

### 6. `main.c`
Implementa o sistema principal para gerenciar a biblioteca virtual. Passos principais:

1. **Inicialização das estruturas**
   - Configura a fila de pessoas e a lista de livros.

2. **Abertura de arquivos**
   - Abre `livros.txt` e `pessoas.txt` para carregar dados.

3. **Leitura de dados**
   - Insere livros na lista e pessoas na fila com base nos arquivos.

4. **Menu interativo**
   - Oferece as seguintes opções:
     - Emprestar ou devolver livros.
     - Cadastrar novos livros.
     - Listar livros por ordem alfabética ou por disponibilidade.

5. **Encerramento**
   - Salva as mudanças nos arquivos e libera a memória alocada.

---

Esse design modular facilita futuras expansões, como novas funcionalidades ou melhorias na interface do usuário.
