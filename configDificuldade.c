#include "biblioteca.h"

char configDificuldade(char dificuldade){

  char i='0', alx;
  if (dificuldade =='D'){
    do {
      LIMPATELA;
      printf("----------------------------\n");
      printf("       JOGO DA FORCA\n");
      printf("----------------------------\n\n");

      printf("F- F�CIL\n");
      printf("D- DIF�CIL*\n\n");

      printf("V- VOLTAR\n\n");

      if (i=='1') {
        printf("DESCULPE, A OP��O DIGITADA � INV�LIDA\n\n");
      }

      printf("OP��O DESEJADA:");
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

      printf("F- F�CIL*\n");
      printf("D- DIF�CIL\n\n");

      printf("V- VOLTAR\n\n");

      if (i=='1') {
        printf("DESCULPE, A OP��O DIGITADA � INV�LIDA\n\n");
      }

      printf("OP��O DESEJADA:");
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
