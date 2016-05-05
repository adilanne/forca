#include "biblioteca.h"

int main(int argc, char const *argv[]) {

  char escolhaMenu, dificuldade ='F';
  
  setlocale(LC_ALL,""); //função para aparecer acentos nas palavras

  do {
    escolhaMenu = menuPrincipal();
    if (escolhaMenu =='3')
      break;

    //selecionando opção escolhida pelo usuário no menu
    switch (escolhaMenu) {
      case '1':
      {
        iniciarPartida(dificuldade);
        break;
      }

      case '2':
      {
        dificuldade = configDificuldade(dificuldade);
        break;
      }
    }

  } while(escolhaMenu!='3');


  return 0;
}
