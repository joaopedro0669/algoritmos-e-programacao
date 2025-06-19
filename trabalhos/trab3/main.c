//João Pedro de Oliveira Leal - 1º Período

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TAM1 50
#define TAM2 50
#define RAND_MAX_TEST 30

void limparTela(){
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif // _WIN32
}

void removeSpace(char *str){
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] != ' ')
            str[j++] = str[i];
    str[j] = '\0';
}

void strtolower(char *str){
    for(int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

void recebernome(char *str){
    fflush(stdin);
    gets(str);
}

int isaname(const char *str){
    int i = -1;
    while(str[++i] == ' ' && str[i] != '\0');
    //printf("%c", str[i]);
    if(str[i] == toupper(str[i]))
        return 1;
    return 0;
}

void validarnome(char *str){
    int isname = 0;
    do{
        recebernome(str);
        isname = isaname(str);
        removeSpace(str);
        strtolower(str);
        if(!strcmp(str, ""))
            printf("Nome inválida. Insira ao menos um caractere válido... ");
        else if(!isname)
            printf("Todo nome começa com uma letra maiúscula... não pense que não vi... ");

    } while(!strcmp(str, "") || !isname);
}

void mostrarvalores(int matriz[TAM1][TAM2], int linha, int coluna){
    int quantNumRep = 0;
        for (int k = 1; k <= RAND_MAX_TEST; k++){
            int contagem = 0;
            for (int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    if(matriz[i][j] == k)
                        contagem++;
                }
            }
            if(contagem >= 2){
                printf("O número %d aparece %d vezes.\n", k, contagem);
                quantNumRep++;
            }
        }

        if(quantNumRep == 0)
            printf("Não houve números repetidos.");
}

int continuarf(){
    char resp[100];
    while(1){
        fflush(stdin);
        gets(resp);
        removeSpace(resp);
        strtolower(resp);
        if(!strcmp(resp, "s") || !strcmp(resp, "sim") || !strcmp(resp, "1"))
            return 1;
        else if(!strcmp(resp, "n") || !strcmp(resp, "nao") || !strcmp(resp, "0"))
            return 0;
        else
            printf("Resposta inválida... tente algo como \"Sim\" ou \"Nao\"! ");
    }
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    srand(time(NULL));

    int matriz[TAM1][TAM2], linha, coluna, continuar = 1;
    char nome[100];

    for (int i = 0; i < TAM1; i++){
        for(int j = 0; j < TAM2; j++){
            matriz[i][j] = 0;
        }
    }
    while(continuar){
        printf("Informe a quantidade de linhas: ");
        do{
            fflush(stdin);
            scanf("%d", &linha);
            if(linha < 1 || linha > TAM1)
                printf("Por favor, informe um número entre 1 e %d... ", TAM1);
        } while (linha < 1 || linha > TAM1);

        printf("Informe a quantidade de colunas: ");
        //while(getchar() != '\n');
        do{
            fflush(stdin);
            scanf("%d", &coluna);
            if(coluna < 1 || coluna > TAM2)
                printf("Por favor, informe um número entre 1 e %d... ", TAM2);
        } while (coluna < 1 || coluna > TAM2);

        printf("Informe o nome do aluno: ");
        //while(getchar() != '\n');
        validarnome(nome);

        limparTela();

        for (int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                matriz[i][j] = rand() % RAND_MAX_TEST + 1; //não irá gerar zeros
            }
        }

        for (int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                printf("%3d ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        mostrarvalores(matriz, linha, coluna);

        printf("\nDeseja gerar uma nova matriz?\n");
        continuar = continuarf();
        limparTela();
    }

    return 0;
}
