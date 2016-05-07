#include "biblioteca.h"

//Tratamento do menu principal e a escolha do usu�rio
char menuPrincipal(){
  char escolhaMenu, i = '0'; //variavel para quardar escolha do usu�rio no menu

  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       JOGO DA FORCA\n");
    printf("----------------------------\n\n");

    printf("1- INICIAR PARTIDA\n");
    printf("2- CONFIGURAR DIFICULDADE\n");
    printf("3- SAIR\n\n");

    if (i=='1') {
      printf("DESCULPE, A OP��O DIGITADA � INV�LIDA\n\n");
    }

    printf("OP��O DESEJADA:");
    scanf("%c",&escolhaMenu);
    flush();

    if (escolhaMenu < '0' || escolhaMenu >'3')
      i='1';
    
  } while(escolhaMenu <'0' || escolhaMenu >'3');

  return escolhaMenu;
}

void flush()//Procedimento para tratar compara��es em CHAR
{
  char c;
  do
  {
      c = getchar();
  }
  while (c != '\n' && c != EOF);
}
