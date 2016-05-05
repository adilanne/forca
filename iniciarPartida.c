#include "biblioteca.h"
#define QUANTIDADEFACIL 3
#define QUANTIDADEDIFICIL 5

void palavraDaVez(char); //Gerando paralava randomicamente
void mensagens(int,int);
void zeraLetras(); //Zera letrasUtilizadas letrasAcertadas
int verificaLetra(int, int); //Verifica se letra analizada esta no vetor palavra
int verificaPalavras(int, int); //Verifica se o vetor letrasAcertadas esta igual a palavraEscolhida. Caso sim, acaba o jogo

char facil[][20] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
char dificil[][20] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};
char palavraEscolhida[20]; //Variavel utilizada para gurdar palavra da vez
char letrasUtilizadas[25]=""; //Vetor que vai conter letras tentadas pelo usu�rio
char letrasAcertadas[21]="____________________"; //Vetor que vai conter letras acertadas pelo usu�rio
char letrasAcertadasComp[21] = ""; //compara a palavra formada pelo usu�rio com o vetor palavraEscolhida
char digitada[2]; //Vetor que vai conter letras que o usu�rio esta tentando
int idx = 0; //Variavel usada para conter indice
int idxVerificao = 0; //Variavel usada na fun��o verificaLetra com a utilidade de mudar indice da letrasUtilizadas
int naoTinha = 1; //Tem a fun��o de verificar se a letra ja foi usada. Caso j�, aparecer� mensagem na tela
int acertou = 0;//Verifica se usu�rio acertou a letra. Caso sim, exibe a mensagem de acerto



void iniciarPartida(char dificuldade){

  zeraLetras();
  palavraDaVez(dificuldade);


  int errou = 0;
  if (dificuldade == 'F'){

    for (errou = 0; errou < QUANTIDADEFACIL; errou++){
      mensagens(QUANTIDADEFACIL, errou);
      errou = verificaLetra(errou, QUANTIDADEFACIL);
      errou = verificaPalavras(QUANTIDADEFACIL, errou);

    }
  }
  else{
    for (errou = 0; errou < QUANTIDADEDIFICIL; errou++){
      mensagens(QUANTIDADEDIFICIL, errou);
      errou = verificaLetra(errou, QUANTIDADEDIFICIL);
      errou = verificaPalavras(QUANTIDADEDIFICIL, errou);

    }
  }
}


//Fun��o ira selecionar palavra escolhida aleatoriamente
void palavraDaVez(char dificuldade){

  srand( (unsigned) time(NULL) );//cria��o da semente para o rand() com o tempo atual
  if (dificuldade == 'F') 
    strcpy(palavraEscolhida,facil[rand()%17]);

  else 
    strcpy(palavraEscolhida,dificil[rand()%15]);
}


void mensagens(int QUANTIDADE,int errou){

  int i=0;

  LIMPATELA;

  printf("Letras j� utilizadas: ");

  for(i = 0; i < strlen(letrasUtilizadas); i++){
    printf(" %c",letrasUtilizadas[i]);
  }

  printf("\n\nPalavra: ");

  for(i = 0; i < strlen(palavraEscolhida); i++){
    printf(" %c",letrasAcertadas[i]);
  }

  do {
    //printf("\n\n%s\n\n", palavraEscolhida);


    if (naoTinha == 0){
      printf("\n\nLetra '%c' j� utilizada. Tente outra.\n", digitada[0]); //Verifica se letra tentada j� foi tentada anteriormente
      naoTinha = 1;
    }

    if (acertou == 1){
      printf("\n\nBoa! A letra '%c' existe na palavra :%c\n",digitada[0],')');
      acertou = 0;
    }

    else if (acertou == 666) {
      printf("\n\nLetra '%c' n�o existe na palavra :%c\n", digitada[0],'(');
    }

    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>", QUANTIDADE - errou);
    scanf("%c", digitada);

    //verifica se usu�rio colocou mais de uma letra
    if (strlen(digitada) > 1)
      printf("\n\nOi? Isso n�o � uma letra.\n");

    } while(strlen(digitada) > 1);

  flush();
}


void zeraLetras(){
  int j;

  for (j=0;j < strlen(letrasUtilizadas);j++){
    letrasUtilizadas[j]=' ';
  }
  for (j=0;j < strlen(letrasAcertadas);j++){
    letrasAcertadas[j]='_';
  }

  idx = 0;
  idxVerificao = 0;
  naoTinha = 1;
  acertou = 0;

}


int verificaLetra(errou, QUANTIDADE){

  //verifica se letra esta dentro do vetor letrasUtilizadas. Caso sim, n�o continua processo de verifica��o
  int j;

  for(j = 0; j < strlen(letrasUtilizadas); j++){
    if (letrasUtilizadas[j] == digitada[0]) {
      naoTinha = 0;
      errou--; //Para n�o contar vez tentada
      break;
    }
  }

  if (naoTinha){
    letrasUtilizadas[idxVerificao] = digitada[0];
    idxVerificao += 1;
    int i = 0;
    for(idx = 0; idx < strlen(palavraEscolhida); idx++){
      if(palavraEscolhida[idx] == digitada[0]){
        letrasAcertadasComp[idx] = digitada[0];
        letrasAcertadas[idx] = digitada[0];
        i++;
      }
    }

    if (digitada[0] == '0'){
      return QUANTIDADE + 1;
    }

    if(i > 0){
      errou--;
      acertou = 1;
    }

    else{
      acertou = 666;
    }
  }

  return errou;
}


int verificaPalavras(QUANTIDADE, errou){

  if (strcmp(letrasAcertadasComp, palavraEscolhida) == 0){
    printf("\nParab�ns! Voc� ganhou. A palavra era '%s'.\nPressione enter para continuar...\n", palavraEscolhida);
    getchar();
    return QUANTIDADE;
  }
  if ((errou + 1) == QUANTIDADE){
    printf("Jogo encerrado. Voc� perdeu. A palavra era '%s'.\nPressione enter para continuar...\n", palavraEscolhida);
    getchar();
    return QUANTIDADE;
  }
  return errou;
}
