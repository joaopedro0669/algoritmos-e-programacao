//Nome completo: Jo�o Pedro de Oliveira Leal
//Curso: Bacharelado em Engenharia da Computa��o
//CPF: xxx.xxx.xxx-xx
//Data: 06/06/2026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

//fun��es gerais
void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32
}

void removespace(char *str){
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] != ' ' && str[i] != '\n')
            str[j++] = str[i];
    str[j] = '\0';
}

void strtolower(char *str){
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

//parte 1 e 2
void ReceberDia(int dia[], int transTotal){
    do{
        printf("Informe o dia da data de hoje: ");
        fflush(stdin);
        scanf("%d", &dia[transTotal]);
        if((transTotal > 0 && dia[transTotal] < dia[transTotal - 1]) || dia[transTotal] < 1 || dia[transTotal] > 31)
            printf("Dia inv�lido... ");
    } while((transTotal > 0 && dia[transTotal] < dia[transTotal - 1]) || dia[transTotal] < 1 || dia[transTotal] > 31);
}

void ReceberNomeTransacao(char nome_transacao[], const char *tipo){
    do{
        printf("Informe o nome do tipo de %s (Dinheiro, Pix): ", tipo);
        fflush(stdin);
        fgets(nome_transacao, 100, stdin);
        removespace(nome_transacao);
        strtolower(nome_transacao);
        if(strcmp(nome_transacao, "dinheiro") && strcmp(nome_transacao, "pix"))
            printf("Op��o inv�lida... ");
    } while(strcmp(nome_transacao, "dinheiro") && strcmp(nome_transacao, "pix"));
}

void ReceberValorCredito(float *valor_transacao){
    do {
        printf("Informe o valor: ");
        fflush(stdin);
        scanf("%f", valor_transacao);
        if(*valor_transacao < 0)
            printf("Valor incorreto... ");
    } while(*valor_transacao < 0);
}

void ReceberValorDebito(float *valor_transacao, float saldo_atual){

    do {
        printf("Informe o valor: ");
        fflush(stdin);
        scanf("%f", valor_transacao);
        if(*valor_transacao < 0)
            printf("Valor incorreto... ");
        else if(*valor_transacao > saldo_atual)
            printf("Dinheiro insuficiente! Fa�a um saque menor... ");
    } while(*valor_transacao < 0 || *valor_transacao > saldo_atual);
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese"); //corrigir acentua��o
    //setlocale(LC_NUMERIC, "Portuguese");
    int respMenu = 0;
    char nome_transacao[1000][100];
    float valor_transacao[1000];
    float saldo_atual[100];
    int dia[1000];
    char status[1000];
    int transTotal = 0;
    while(respMenu != 5){
        limparTela();

        //printf("Transa��es totais: %d\nNome transa��o: %s\nValor transa��o: %f\nSaldo atual: %f\nDia: %d\nStatus: %c\n\n", transTotal, nome_transacao[transTotal - 1], valor_transacao[transTotal - 1], saldo_atual[transTotal - 1], dia[transTotal - 1], status[transTotal - 1]);

        printf("TRANSA��ES BANC�RIAS\n\n1) Dep�sito (entrada)\n2) Retiradas (sa�da)\n3) Relat�rio saldo atual\n4) Relat�rio extrato do per�odo do m�s\n5) Finalizar\nInforme uma das op��es (1, 2, 3, 4 ou 5) ...: ");
        do{
            fflush(stdin);
            scanf("%d", &respMenu);
            if(respMenu < 1 || respMenu > 5){
                printf("Op��o inexistente. Tente novamente: ");
            }
        } while(respMenu < 1 || respMenu > 5);
        if(respMenu == 1){
            //parte 1
            limparTela();
            printf("Op��o 1 - Dep�sito (entrada)\n\n");
            ReceberDia(dia, transTotal);
            ReceberNomeTransacao(nome_transacao[transTotal], "dep�sito");
            ReceberValorCredito(&valor_transacao[transTotal]);

            status[transTotal] = 'C';

            if(transTotal == 0)
                saldo_atual[0] = valor_transacao[0];
            else{
                saldo_atual[transTotal] = saldo_atual[transTotal-1] + valor_transacao[transTotal];
            }

            printf("\nR$%.2f depositados com sucesso!\n\nPressione qualquer tecla para voltar ao menu...\n", valor_transacao[transTotal]);
            getch();

            transTotal++;
        }
        else if(respMenu == 2){
            //parte 2
            limparTela();
            if(transTotal == 0){
                printf("N�o h� saldo para sacar...\n\nPressione qualquer tecla para voltar ao menu...\n", valor_transacao[transTotal]);
                getch();
            }
            else if(saldo_atual[transTotal - 1] == 0){
                printf("N�o h� saldo para sacar...\n\nPressione qualquer tecla para voltar ao menu...\n", valor_transacao[transTotal]);
                getch();
            }
            else{
                printf("Op��o 2 - Saque (sa�da)\n\n");
                ReceberDia(dia, transTotal);
                ReceberNomeTransacao(nome_transacao[transTotal], "saque");
                ReceberValorDebito(&valor_transacao[transTotal], saldo_atual[transTotal - 1]);

                status[transTotal] = 'D';

                saldo_atual[transTotal] = saldo_atual[transTotal-1] - valor_transacao[transTotal];

                printf("\nSaque de R$%.2f realizado com sucesso!\n\nPressione qualquer tecla para voltar ao menu...\n", valor_transacao[transTotal]);
                getch();


                transTotal++;
            }
        }
        else if(respMenu == 3){
            //parte 3
            limparTela();
            printf("Op��o 3 - Saldo atual\n\n");
            if(transTotal == 0){
                printf("Saldo atual: R$0.\n\nPressione qualquer tecla para voltar ao menu...\n");
                getch();
            }
            else{
                printf("Saldo atual: R$%.2f.\n\nPressione qualquer tecla para voltar ao menu...\n", saldo_atual[transTotal - 1]);
                getch();
            }
        }
        else if(respMenu == 4){
            //parte 4
            limparTela();
            printf("Op��o 4 - Relat�rio extrato por per�odo mensal\n\n");
            printf("Dia | Descri��o | Status | Valor da transi��o | Saldo atual\n");
            for(int i = 0; i < transTotal; i++){
                printf("%-3d | %-9s | %-6c | %-18.2f | %.2f\n", dia[i], nome_transacao[i], status[i], valor_transacao[i], saldo_atual[i]);
            }

            printf("\nPressione qualquer tecla para voltar ao menu...\n");
            getch();
        }
        else if(respMenu == 5){
            //finalizar
            limparTela();
            printf("Obrigado por usar o programa!\nPor: Jo�o Pedro de Oliveira Leal.\n\nPressione qualquer tecla para encerrar o programa...\n");
            getch();
        }
    }

    return 0;
}
