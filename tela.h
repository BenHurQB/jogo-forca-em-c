#pragma once
#include "cabecalho.h"


void telaentrada(void){

  printf("\n\n*******************************");
  printf("\n***   JOGO   DE   FORCA   *****");
  printf("\n\n*******************************");
}

void telajogo(int *erros){

printf("\033[31m"); 
printf("\n");
printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (*erros>=1?'(':' '), 
    (*erros>=1?'_':' '), (*erros>=1?')':' '));
printf(" |      %c%c%c  \n", (*erros>=3?'\\':' '), 
    (*erros>=2?'|':' '), (*erros>=3?'/': ' '));
printf(" |       %c     \n", (*erros>=2?'|':' '));
printf(" |      %c %c   \n", (*erros>=4?'/':' '), 
    (*erros>=4?'\\':' '));
printf("_|___           \n");
printf("\033[37m");  
}

void telaganhou(){

    printf("\033[34m"); 
    printf("\n\n******  PARABÉNSSSSSS VOCE GANHOU  !!!!!!!");
    printf("\n\n");   
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
    printf("\033[37m"); 
}

void telaperdeu(){

    printf("\033[31m"); 
    printf("\n Você foi enforcado!!!\n");
    printf("    _______________         \n");
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("       \\_______/           \n");
    printf("\033[37m"); 
}