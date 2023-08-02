#include "cabecalho.h"
#include "tela.h"

void escolhepalavra(char palavrasecreta[TAM]){

  FILE* f;
  f =  fopen("palavras.txt", "r");
  
  if (f == 0){//ponteiro falhou ou nulo
    printf("Desculpe, banco de dados indisponivel!!!\n\n");
    exit(1); //sai do programa de vez
      }
     
  int qtddepalavras, randomico, i;
  //por padrao a primeira linha do arquivo e a quantidade de linhas ou palavras neste caso
  fscanf(f, "%d", &qtddepalavras);
  srand(time(0));
  randomico = rand() % qtddepalavras;

  for (i=0; i <= randomico; i++){
    fscanf(f, "%s", palavrasecreta);
  }

  fclose(f);
}

void adicionapalavra(){

  char quer;
  char novapalavra[20];
  int qtd;
  FILE *f;
  

  printf("\nVoce deseja adicionar nova palavra? (S/N) ");
  scanf(" %c", &quer);
 
  if (quer == 's' || quer == 'S'){

    printf("\nInforme a nova palavra: ");
    scanf("%s", novapalavra);
    f = fopen("palavras.txt", "r+");
    if (f == 0){//ponteiro falhou ou nulo
        printf("Desculpe, banco de dados indisponivel!!!\n\n");
        exit(1); //sai do programa de vez
      }
    //ler a quantidade do arquivo
    fscanf(f, "%d", &qtd);//variavel, tipo e para onde vai
    qtd++;//adicionar mais uma linha a ser lida
    
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);//subescrever a nova qtd de linha

    //posicionar o ponteiro no final do arquivo
    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novapalavra);//subescrever a nova linha
    fclose(f);
    printf("\033[34m"); 
    printf("\nPalavra registrada no banco com SUCESSO!!!");
    printf("\033[37m"); 
      }

  }

//Carregar o vetor espelho do mesmo tamanho de palavrasecreta com '_'
void carregaespelhoecontadoresexternos(char espelho[TAM], char palavrasecreta[TAM], int *errou, int *tentativas){

  int i;

  *errou = 0;//apenas para tirar do programa principal
  *tentativas = 1;
  for (i=0;i<strlen(palavrasecreta);i++){
        espelho[i] = '_';
         }
}

//carregar vetor chutevet inserindo as letras chutadas
void carregarchutevet(int *chutou, char *chute, int *tentativas, char chutevet[TAM2], int *achou){

   int i;
  
   
   *chutou = 0;
   
    while (!*chutou){
      *chutou = 1;
      printf("\nChute uma letra: ");
      scanf(" %c", *&chute);
      *chute = toupper(*chute);
      
      //pesquisar para verificar se a letra ja foi chutada
    
      for(i=0;i<*tentativas;i++){
        if(chutevet[i] == *chute){
          printf("\033[31m"); 
          printf("\nEssa letra já foi chutada. Informe outra..\n");
          printf("\033[37m"); 
          //*achou = 1;
          *chutou = 0;
          break;
          }
        }
      
        chutevet[*tentativas-0] = *chute;
       
      }
    *tentativas = *tentativas + 1;
  }

//pesquisar no vetor espelho se existe a letra e substituir pelo chute
void pesquisarvetorespelho(char palavrasecreta[TAM], char chute, int *achou, char espelho[TAM]){

  int i;
  *achou = 0;
  for (i = 0; i < strlen(palavrasecreta); i++){
        if (palavrasecreta[i] == chute){
            espelho[i] = chute;
            *achou = 1;
          }
        }
  
}

//mostrar o espelho apos pesquisa de chute
void mostraespelho(char palavrasecreta[TAM], int chutou, char espelho[TAM]){

  int i;
  
  
  for (i=0;i<strlen(palavrasecreta);i++){
         
          if(chutou){
              printf("%c  ", espelho[i] );
            }
        }
  
}
//mostrar mensagem que a letra nao tem em palavrasecreta e contar quantidade de erros
void chuterrado(int *achou, int *enforcou, int *errou, char palavrasecreta[TAM]){

  int i; 

  *enforcou = 0;
  
  
  if (!*achou){
      *errou = *errou + 1;
      if(*errou < NERROS){
        printf("\033[31m"); 
        printf("\nErrou!!!  Tente novamente...\n");
        telajogo(*&errou); 
        printf("\033[37m"); 
      }
    }
  if (*errou >= NERROS){
    *enforcou = 1;
    printf("\033[34m"); 
    printf("\nA palavra secreta é  ");
    for (i=0;i<strlen(palavrasecreta);i++){
       printf("%c", palavrasecreta[i] );
       }
    printf("\033[37m"); 
    telajogo(*&errou);
    telaperdeu();
     }
   *achou = 0;
  }

void chutecerto(int *acertou, char espelho[TAM], char palavrasecreta[TAM]){
    
  int i;
  int achei;
  
  *acertou = 0;
  achei = 0;
  for(i=0; i<strlen(espelho);i++){
    if(espelho[i] == '_')
      achei = 1;
   }
  
  if (!achei){
    *acertou = 1;
    telaganhou();
    }
  
}
  
  