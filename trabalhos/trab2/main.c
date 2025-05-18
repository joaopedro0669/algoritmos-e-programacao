//Jo�o Pedro de Oliveira Leal - 1� Per�odo
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

typedef enum ModeFunction { //configura��o para a fun��o sequencia_array()
    MD_POS, //para retornar a posi��o da maior sequ�ncia
    MD_QUANT, //para retornar a quantidade de elementos da maior sequ�ncia
    MD_EMP, //para retornar se houve empate ou n�o
    MD_POS_CUSTOM //para mostrar a posi��o da primeira sequ�ncia com tal n�mero de elementos
} ModeFunction;

typedef struct InfoVet { //para o retorno dos dados da diferen�a dos elementos do array
    int dif;
    int pos1;
    int pos2;
} InfoVet;

//fun��es b�nus
void limparTela(){ //identifica o se o sistema operacional � Windows ou n�o para usar o comando de limpar a tela apropriado
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif // _WIN32
}

void menu(char *a){ //isso aqui faz um menu ao n�vel do GTA VI
    printf("MENU DE OP��ES\n=================\n1 � maior sequ�ncia de n�meros iguais consecutivos\n2 � maior diferen�a entre dois n�meros consecutivos\n3 � sair\nEscolha o n�mero de uma das op��es acima...: ");
    do{
        *a = getch();
        //while(getchar() != '\n');
        if(*a < '1' || *a > '3')
            printf("\nOp��o inv�lida! Tente novamente: ");
    } while(*a < '1' || *a > '3');
}

//fun��es exerc�cio 1
int input_array(int *array, int i){ //coletar e validar cada elemento do array. Retorna 1 caso deva continuar e retorna 0 caso deva parar a coleta
    do {
        (i == 0) ? printf("Informe um n�mero de 1 a 9 para o item %d: ", i+1) : printf("Informe zero para finalizar ou um n�mero de 1 a 9 para o item %d: ", i+1);
        scanf("%d", (array + i));
        while(getchar() != '\n');
        if((i == 0) && (*(array + i) < 1 || *(array + i) > 9))
            printf("Apenas n�meros entre 1 a 9! ");
        else if(*(array + i) < 0 || *(array + i) > 9)
            printf("Apenas n�meros entre 1 a 9 ou zero! ");
    } while (((i == 0) && (*(array + i) < 1 || *(array + i) > 9)) || (*(array + i) < 0 || *(array + i) > 9));
    if(*(array + i) == 0)
        return 0;
    else
        return 1;
}

int mostrar_maior_elemento_array(int *array, int tam){ //n�o vai usar isso aqui, fiz � toa. Confundi... Achei que era para pegar o n�mero que mais se repetia
    int vezes_maior_num = 1;
    int maior_num = 0;
    int vezes = 0;
    for(int i = 1; i <= 9; i++){
        vezes = 0;
        for(int j = 0; j < tam; j++){
            if(array[j] == i)
                vezes++;
        }
        if(vezes > vezes_maior_num){
            vezes_maior_num = vezes;
            maior_num = i;
        }
    }
    return maior_num;
}

int sequencia_array(int *array, int inicio, int tam, int buscatam, ModeFunction mf){ //identifica empate, identifica posi��o da maior sequ�ncia, identifica tamanho da maior sequ�ncia e encontra sequ�ncias personalizadas
    int maior_quant = 1;
    int pos = -1;
    int empate = 0;
    for(int i = inicio, j = inicio; i < tam; i++){
        int eleatual = 0;
        for(; *(array + j) == *(array + i); j++){
            eleatual++;
        }
        if(eleatual > maior_quant && mf != MD_POS_CUSTOM){
            maior_quant = eleatual;
            pos = i;
            empate = 0;
            i = j - 1;
        }
        else if (eleatual == maior_quant && maior_quant != 1 && mf != MD_POS_CUSTOM){
            empate = 1;
            i = j - 1;
        }
        else if(mf == MD_POS_CUSTOM && eleatual == buscatam){
            pos = i;
            i = tam;
        }

    }
    if(mf == MD_POS)
        return pos;
    else if(mf == MD_QUANT)
        return maior_quant;
    else if(mf == MD_EMP)
        return empate;
    else if(mf == MD_POS_CUSTOM)
        return pos;
    else
        return -2; //retorno de seguran�a para configura��o inv�lida.
}

//fun��es exerc�cio 2
void input_array2(int *array, int tam){ //coleta todos os elementos e j� faz as verifica��es
    for(int i = 0; i < tam; i++){
        int continuar = 1;
        while(continuar){
            continuar = 0;
            printf("Digite o elemento %d: ", i+1);
            scanf("%d", &array[i]);
            while(getchar() != '\n');
            if(array[i] <= 0){
                continuar = 1;
                printf("Apenas n�meros maiores do que zero! ");
            }
            else{
                for(int j = 0; j < i; j++){
                    if(array[i] == array[j]){
                        continuar = 1;
                        printf("Apenas n�meros distintos! ");
                        j = i;
                    }
                }
            }
        }
    }
}

void mostrar_array(int *array, int tam){ //mostra o array j� formatado
    for(int i = 0; i < tam; i++){
        printf("%d ", array[i]);
        if((i+1) % 5 == 0 && i+1 < tam)
            printf("\n");
    }
}

InfoVet maior_dif(int *array, int tam){
    int maior_dif = 0, pos1, pos2;
    for(int i = 0; i < tam; i++){
        if(i > 0 && array[i] - array[i-1] > maior_dif){
            maior_dif = array[i] - array[i-1];
            pos1 = i;
            pos2 = i-1;
        }
        if(array[i] - array[i+1] > maior_dif){
            maior_dif = array[i] - array[i+1];
            pos1 = i;
            pos2 = i+1;
        }
    }
    InfoVet dados;
    dados.dif = maior_dif;
    dados.pos1 = pos1;
    dados.pos2 = pos2;

    return dados;
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese"); //faz o programa aceitar a acentua��o
    char resp;
    while(resp != '3'){
        limparTela();
        menu(&resp);

        if(resp == '1'){ //primeiro exerc�cio
            char resp1 = 49; //isso � '1'
            while(resp1 == '1'){
                limparTela();
                int num[300];
                int continuar = 1;
                int i;
                for(i = 0; i < 300 && continuar; i++)
                    continuar = input_array(num, i);

                i--;
                limparTela();
                printf("Vetor apresentado:\n");
                for(int j = 0; j < i; j++){
                    printf("%d ", num[j]);
                    if((j+1) % 5 == 0 && j+1 < i)
                        printf("\n");
                }


                int empate = sequencia_array(num, 0, i, 0, MD_EMP);
                if(empate){
                    int maior_quant = sequencia_array(num, 0, i, 0, MD_QUANT);

                    printf("\n\nMaiores sequ�ncias: \n");

                    for(int j = 0; j < i; j++){
                        int pos_maior_seq = sequencia_array(num, j, i, maior_quant, MD_POS_CUSTOM);
                        if (pos_maior_seq != -1){
                            int k = pos_maior_seq;
                            for(; *(num + k) == *(num + pos_maior_seq); k++)
                                printf("%d ", *(num + k));
                            printf("\n");
                            j = k - 1;
                        }
                        else{
                            j = i;
                        }
                    }
                }
                else {
                    int pos_maior_seq = sequencia_array(num, 0, i, 0, MD_POS);

                    printf("\n\nMaior sequ�ncia: \n");

                    if(pos_maior_seq == -1)
                        printf("Nenhuma sequ�ncia encontrada!");
                    else
                        for(int j = pos_maior_seq; *(num + j) == *(num + pos_maior_seq); j++)
                            printf("%d ", *(num + j));
                }

                printf("\n\nPressione 1 para continuar ou qualquer outra tecla para voltar ao menu...");
                resp1 = getch();
            }
        }
        else if(resp == '2'){ //segundo exerc�cio
            char resp2 = '1';
            while(resp2 == '1'){
                int num[50];
                limparTela();
                input_array2(num, 50);

                limparTela();
                printf("Vetor apresentado:\n");
                mostrar_array(num, 50);

                InfoVet res = maior_dif(num, 50);
                printf("\nA maior diferen�a encontrada foi %d. Isto pela subtra��o do elemento de posi��o %d (o n�mero %d) com o elemento de posi��o %d (o n�mero %d).", res.dif, res.pos1 + 1, num[res.pos1], res.pos2 + 1, num[res.pos2]);

                printf("\n\nPressione 1 para continuar ou qualquer outra tecla para voltar ao menu...");
                resp2 = getch();
            }

        }
        else if(resp == '3'){ //sair
            limparTela();
            printf("Fim de programa...");
            printf("\nPressione qualquer tecla para continuar...\n");
            getch();
        }
    }
    return 0;
}
