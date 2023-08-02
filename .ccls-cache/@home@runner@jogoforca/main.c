#include "cabecalho.h"
#include "tela.h"
#include "processamento.h"

int main(void) {

  char chutevet[TAM2];
  char espelho[TAM];
  char palavrasecreta[TAM];
  char chute;
  int  acertou, enforcou, tentativas, achou, chutou, errou;

  telaentrada();
  escolhepalavra(palavrasecreta);
  carregaespelhoecontadoresexternos(espelho, palavrasecreta, &errou, &tentativas);
  do{
    carregarchutevet(&chutou, &chute, &tentativas, chutevet, &achou);
    pesquisarvetorespelho(palavrasecreta, chute, &achou, espelho);
    mostraespelho(palavrasecreta, chutou, espelho);
    chuterrado(&achou, &enforcou, &errou, palavrasecreta);
    chutecerto(&acertou, espelho, palavrasecreta);
  } while(!acertou && !enforcou);
  adicionapalavra();
  
  return 0;
}
