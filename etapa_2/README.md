# Compiladores - Etapa 2
A segunda etapa do desenvolvimento de um compilador para a desciplina de compiladores 2020/1 (UFRGS), consiste nos seguintes objetivos:

  - Criação de um analisador sintático
  - Utilização da ferramenta bison
  - Criação das regras do analisador sintático de acordo com as especificações

# Começando

  - Para executar o analisador sintático, execute o comando `make`.
  - Após isso execute o comando `./parser` e começe a testar o analisador.
  - Caso queira executar um arquivo de testes execute o comando `./parser < arquivo`
  - Também pode executar `./parser < tests`, para executar o arquivo de testes basicos.

# Objetivos
 O objetivo desta etapa é a criaçao do analisador sintático para a nossa linguagem, nele fizemos com que o analisador consigo determinar se uma determinada entrada faz parte da nossa linguagem ou não. Para que isso fosse possivel foram defenidas algumas regras que essa linguagem deve respeitar:
 - **Relatorio e Erro Sintatico:** Caso a entrada não seja reconhecida é retornado um erro indicando a possivel linha e coluna deste erro e que seria este.
 
  - **Linguagem:** A criação da linguagem é feita a partir de algumas regras listadas abaixo, seguindo o padrão da documentação.

# Linguagem
 A linguagem criada nesta etapa,é constituida de:  **variaveis globais**, **variaveis locais**,**função**, **blocos simples**, **blocos de comandos**, **comandos de entradas e saídas**, **shift**, **comandos de retorno, break e continue**, **comandos de controle de fluxo** e **expressões aritméticas, lógicas**. Onde cada uma segue uma série de regras diferentes,  que são:
 
  ### Variáveis Globais
   São declaradas inicialmente por um tipo seguidas de uma lista composta de pelo menos um nome de varável (identificador) separado por vírgula, alguns exemplos:
   ```sh
    int a;
    string a, b;
    static int b;
   ```
  ### Variáveis Locais
   Semelhates as varáveis globais, mas neste caso não permitem vetores e podem usar a palavra const antes do tipo. Tabém pode ser inicializada utilizando `<=`.
   ```sh
    const string b;
    float c <= 7.5;
   ```

  ### Funções
   As funções são separadas em duas partes, o cabeçalho composto de tipo do retorno, o nome da funçao e entre parenteses os parametros, e o corpo composto por bloco de comandos.
   ```
    char nome(int a, float b){
        // blocos de comandos
    }
   ```
   
  ### Bloco de Comandos
   Um bloco de comandos e definido entre chaves, e consiste em uma sequencia, possivelmente vazia, de comandos simples cada um terminado por ponto e vírgula.
   ```sh
    char nome(int a, float b){
        if(a > b){
          // bloco de comando      
        };
    }
   ```
  ### Comando de Atribuição
   Um identificador pode receber a atribuição a partir de uma expressão.
   ```sh
    a = b + c;
    e[4] = c + d;
   ```
   
### Comandos de Entrada e Saída
   Para entrada ou saída e dados é utilizado os comandos `input` ou `output` seguida por um identificador ou um literal.
   ```sh
    input a;
    output b;
   ```
   
### Chamada de Função
   Consiste no nome da função seguida de argumento entre parênteses separados por virgula.
   ```sh
    abc(b);
    cbd(b, 2);
   ```
   
### Comandos de Shift
   É possivel a utilização o comando shift utilizando literais inteiros.
   ```sh
    id << 12;
    id[exp] << 14;
   ```
   
### Comando de Retorno, Break, Continue
 Palavras como `return`, `break` e `continue`, são reservadas para utilização futura na construção do compilador.

### Comandos de Controle de Fluxo
 É possivel também a utilização de comandos de controle de fluxos: `if`, `else`, `while do`, são constituidos por um cabeçalho com atributos e/ou expressões e um corpo formado por um bloco de comandos.
 
 ```sh
 if (a) {
    // bloco de comanos
 };
 
 if (b) {
    // bloco de comanos
 } else {
    // bloco de comanos
 };

  for (a = 2 : a : a + 1) {
      
  };

  while ( a ) do {
    // bloco de comanos
  };
 ```
 
 ### Expressões Aritméticas e Lógicos
   As expressões podem ser do tipo aritmética ou lógico. No caso das expressões aritméticas são compostas por `operandos` seguidos ou não por colchetes,`literais numéricos` e `chamadas de funções`. Enquanto as expressões lógicas são formadas por `operadores relacionais aplicados a expressões aritméticas` ou `operadores lógicos aplicados a expressões lógicas`;
   
   `Operadores Unários: + , -, !, &, *, ?, #`;
   `Operadores Binários: +, -, *, /, |, &, ^, <, >, <=, >=, ==, !=, &&, ||`
   `Operadores Ternários: exp ? exp : exp`
   
exemplos:
   ```sh
    a = 1 * 2 + (5 * 2);
    d = a ^ 2
    c == b;
    a ? b : c
   ```
   
# Desenvolvimento

Para o desenvolvimento desta etapa utilizamos recuros da ferramenta [Bison](https://www.gnu.org/software/bison/), alem do analisador léxico criado na primeira etapa do projeto desenvonvido através da ferramenta [FLEX](https://github.com/westes/flex/).

# Colaboradores

Projeto do compilador esta sendo desenvolvido por: 
- [Leonardo Abreu](https://github.com/leosiimas)
- [Rodrigo Bastos](https://github.com/ropbastos/)