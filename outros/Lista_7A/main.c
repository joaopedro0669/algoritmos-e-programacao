#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(){

    int resp = 0;
    while(resp != 3){
        printf("O que deseja ver?\n[1] Sequencia com variacao com sinal duplicado.\n[2] Sequencia de numeros por linhas.\n[3] Sair.\nEscolha o numero de uma das opcoes acima: ");
        scanf("%d", &resp);
        fflush(stdin);

        if(resp == 1){
            //exercício 1
            system("cls");

            int quantTermos;
            float resultado = 0;
            float numerador, denominador;
            float soma = 0;
            int multi = 1;
            int contMulti = 2;

            do {
                printf("Digite a quantidade de termos da sequencia: ");
                scanf("%d", &quantTermos);
                fflush(stdin);
                if(quantTermos <= 0){
                    printf("Valor invalido. Informe um valor maior do que 0. ");
                }
            } while (quantTermos <= 0);

            for (int base = 1, exp = 1, exp3 = 0; base <= quantTermos; base++, exp = exp + 2, exp3++){

                for (int j = 1; j <= exp; j++){ //função de calcular a potencia
                    if(j == 1){
                        resultado = base;
                    }
                    else {
                        resultado = resultado * base;
                    }
                }
                numerador = resultado;


                for (int j = 0; j <= exp3; j++){ //função de calcular a potencia
                    if (j == 0){
                        resultado = 1;
                    }
                    else if(j == 1){
                        resultado = 3;
                    }
                    else {
                        resultado = resultado * 3;
                    }
                }
                denominador = resultado;

                if(contMulti == 0){
                    contMulti = 1;
                    multi = -multi;
                }
                else{
                    contMulti = contMulti - 1;
                }

                soma += numerador / denominador * multi;
            }

            printf("O somatorio da sequencia eh: %.2f\n", soma);
            printf("Pressione qualquer tecla para prosseguir...\n");
            getch();
            system("cls");

        }
        else if(resp == 2){
            //exercício 2
            int continuar = 1;
            do{
                system("cls");

                int quantLinhas;
                int termo;

                do {
                    printf("Digite a quantidade de linhas: ");
                    scanf("%d", &quantLinhas);
                    fflush(stdin);
                    if(quantLinhas <= 0){
                        printf("Valor invalido. Informe um valor maior do que 0. ");
                    }
                } while (quantLinhas <= 0);

                for(int linha = 1; linha <= quantLinhas; linha++){
                    for(int coluna = 1; coluna <= linha; coluna++){
                        termo = linha * coluna;
                        printf("%5d ", termo);
                    }
                    printf("\n");
                }

                do{
                    printf("Voce quer continuar? Digite 1 para sim e 0 para nao: ");
                    scanf("%d", &continuar);
                    fflush(stdin);
                } while(continuar != 1 && continuar != 0);

                if(continuar == 0){
                    system("cls");
                    printf("Pressione qualquer tecla para prosseguir...\n");
                    getch();
                    system("cls");
                }
            } while (continuar == 1);

        }
        else if(resp == 3){
            system("cls");
            printf("Obrigado por usar o programa.\n");
            printf("Pressione qualquer tecla para prosseguir...\n");
            getch();
        }
        else {
            system("cls");
            printf("Valor incorreto.\n");
            printf("Pressione qualquer tecla para prosseguir...\n");
            getch();
            system("cls");
        }
    }

    return 0;
}
