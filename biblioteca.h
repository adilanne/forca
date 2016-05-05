#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void flush();//Procedimento para tratar comparações em CHAR
void iniciarPartida(char );
char configDificuldade(char );
char menuPrincipal();

#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("CLS")
#else
#define LIMPATELA system("clear")
#endif
