#include "biblioteca.h"

char configDificuldade(char dificuldade){

  char i='0', alx;
  if (dificuldade =='D'){
    do {
      LIMPATELA;
      printf("----------------------------\n");
      printf("       JOGO DA FORCA\n");
      printf("----------------------------\n\n");

      printf("F- FÁCIL\n");
      printf("D- DIFÍCIL*\n\n");

      printf("V- VOLTAR\n\n");

      if (i=='1') {
        printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
      }

      printf("OPÇÃO DESEJADA:");
      scanf("%c", &alx);
      flush();

      if (alx != 'D' && alx >'F')
        i='1';
      else 
        dificuldade = alx;

    } while(alx != 'F' && alx != 'D' && alx != 'V');
  }
  
  else{
    do {
      LIMPATELA;
      printf("----------------------------\n");
      printf("       JOGO DA FORCA\n");
      printf("----------------------------\n\n");

      printf("F- FÁCIL*\n");
      printf("D- DIFÍCIL\n\n");

      printf("V- VOLTAR\n\n");

      if (i=='1') {
        printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
      }

      printf("OPÇÃO DESEJADA:");
      scanf("%c",&alx);
      flush();

      if (alx != 'D' && alx >'F')
        i='1';
      else 
        dificuldade = alx;
      
    } while(alx != 'F' && alx != 'D' && alx != 'V');
  }
  return dificuldade;
}
