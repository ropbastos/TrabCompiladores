## ETAPA 7

As seguintes otimizações são utilizadas caso o programa seja chamado com a flag -O:

  1) Remoção de instruções repetidas.

  2) Remoção do uso de intermediários na passagem de valores.

    Com isso se quer dizer que coisas do tipo:

      mov $1, %rax
      mov %rax, %rbx
    
    São compactadas para o equivalente:

      mov $1, %rbx
  
  3) Uso da instrução de shift aritmético (sar) para efetuar divisões por 2, em vez
     da de divisão (idivq).

# Resultados

  Pode ser verificada a diminuição no número de instruções geradas a partir da compilação 
  de diversor programas contidos na pasta "testsE7", que vêm sendo utilizados por nós no
  desenvolvimento das etapas do trabalho.

  Por exemplo, o programa "fib" (testsE7/fib), que calcula o n-ésimo número da sequência
  de Fibonacci, se compilado sem a flag '-O' tem o assembly gerado com 83 linhas, já com 
  a otimização ligada, 78 linhas.

  Outros 3 exemplos são os programas "expBool3" (testsE7/expBool3), "expArit1" 
  (testsE7/expArit1) e "while4" (testsE7/while4) que testam a compilação de comandos de
  controle de fluxo, de laço e aritméticos. 

  O programa "wc", presente na maioria das instalações linux, permite a contagem de linhas
  em um arquivo mediante o comando "$ wc -l < <nome_do_arquivo>". Abaixo seguem linhas 
  demonstrando como averiguar a diminuição do assembly gerado para o programa "fib":

    FIB:
    $ ./etapa7 < testsE7/fib > not_optimized.s
    $ wc -l < not_optimized.s
    $ 83
    $ ./etapa7 -O < testsE7/fib > optimized.s
    $ wc -l < optimized.s
    $ 78

  Substituindo-se "fib" pelo nome de qualquer outro dos programas aqui citados, ou que se
  encontrem na pasta "testsE7", pode-se averiguar a diminuição das linhas geradas para eles.


  
   
