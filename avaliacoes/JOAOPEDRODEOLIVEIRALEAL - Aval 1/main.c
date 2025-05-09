/*
Nome: João Pedro de Oliveira LeaL
Curso: Bacharelado em Engenharia de Computação
CPF: xxx.xxx.xxx-xx
Data: 22/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int main()
{
    int resp = 0;
    while (resp != 4){
        printf("O que deseja ver?\n\n[1] Numeros primos.\n[2] Lucro de mercadorias.\n[3] Crescimento populacional\n[4] Finalizar o programa.\n\nInforme uma das opcoes (1, 2, 3 ou 4): ");
        scanf("%d", &resp);
        fflush(stdin);

        if(resp == 1){
            //exercício 1

            int respExer1 = 1;
            while(respExer1 == 1){
                system("cls");

                int num;

                do{
                    printf("Informe um numero inteiro positivo: ");
                    scanf("%d", &num);
                    fflush(stdin);
                    if(num <= 0){
                        system("cls");
                        printf("Apenas numeros inteiros positivos.\n");
                    }
                } while (num <= 0);

                if(num == 1){
                    printf("Nao existem numeros primos ate este numero.\n");
                }
                else if(num == 2){
                    printf("Apenas existe o numero 2 como primo ate esse numero.\n");
                }
                else if(num > 2){
                    int primeiroNum = 1;
                    int divInt = 0;
                    float divReal = 0;

                    printf("Os numeros primos ate esse numero sao: ");

                    for (int n = 2; n <= num; n++){
                        int ehPrimo = 1;
                        for (float i = 2; i < n; i++){
                            divInt = n / i;
                            divReal = n / i;
                            if(divInt == divReal){
                                ehPrimo = 0;
                                i = num;
                            }
                        }

                        if(ehPrimo == 1){
                            if(primeiroNum == 1){
                                primeiroNum = 0;
                                printf("%d", n);
                            }
                            else {
                                printf(", %d", n);
                            }
                        }
                    }
                    printf(".\n");
                }
                do{
                    printf("\nDigite 1 para continuar ou 0 para finalizar o exercicio.\n");
                    scanf("%d", &respExer1);
                    fflush(stdin);
                    if(respExer1 != 1 && respExer1 != 0){
                        printf("Digite apenas 1 ou 0.\n");
                    }
                } while (respExer1 != 1 && respExer1 != 0);

                if(respExer1 == 0){
                    system("cls");
                    printf("Pressione qualquer tecla para voltar ao menu...\n");
                    getch();
                    system("cls");
                }
            }
        }
        else if(resp == 2){
            //exercício 2

            int respExer2 = 1;

            char nomeMercadoria[10];
            float preCompra, preVenda, lucro, totalCompras = 0, totalVendas = 0, totalLucros = 0;
            int produtosTotais = 0, lucro10 = 0, lucro1020 = 0, lucro20 = 0;

            while (respExer2 == 1){
                system("cls");

                do{
                    printf("Digite o nome do produto: ");
                    fgets(nomeMercadoria, 10, stdin);
                    fflush(stdin);
                    if(nomeMercadoria[0] == '\n'){
                        printf("Digite ao menos um caractere.\n");
                    }
                } while(nomeMercadoria[0] == '\n');

                do {
                    printf("Digite o preco de compra do produto: ");
                    scanf("%f", &preCompra);
                    fflush(stdin);
                    if(preCompra <= 0){
                        printf("Digite apenas numeros positivos.\n");
                    }
                } while (preCompra <= 0);

                do {
                    printf("Digite o preco de venda do produto: ");
                    scanf("%f", &preVenda);
                    fflush(stdin);
                    if(preVenda < preCompra){
                        printf("Digite um valor maior ou igual a %.2f\n", preCompra);
                    }
                } while (preVenda < preCompra);

                lucro = preVenda - preCompra;
                produtosTotais++;

                if(lucro <= (preCompra / 10))
                    lucro10++;
                else if (lucro <= (preCompra / 5))
                    lucro1020++;
                else if (lucro > (preCompra / 5))
                    lucro20++;

                totalCompras += preCompra;
                totalVendas += preVenda;
                totalLucros += lucro;

                do {
                    printf("\nDigite 1 para informar novos dados ou digite 0 para ver o resultado.\n");
                    scanf("%d", &respExer2);
                    fflush(stdin);
                    if(respExer2 != 1 && respExer2 != 0){
                        printf("Digite apenas 1 ou 0.\n");
                    }
                } while (respExer2 != 1 && respExer2 != 0);

                if(respExer2 == 0){
                    system("cls");

                    printf("Total de mercadorias informadas: %d\n", produtosTotais);
                    printf("Total de mercadorias com ate 10%% de lucro: %d\n", lucro10);
                    printf("Total de mercadorias com entre 10%% a 20%% de lucro: %d\n", lucro1020);
                    printf("Total de mercadorias acima de 20%% de lucro: %d\n", lucro20);
                    printf("Valor total de compras: %.2f\n", totalCompras);
                    printf("Valor total de vendas: %.2f\n", totalVendas);
                    printf("Valor total de lucros: %.2f\n", totalLucros);

                    printf("\nPressione qualquer tecla para voltar ao menu...\n");
                    getch();
                    system("cls");
                }
            }
        }
        else if(resp == 3){
            //exercício 3

            system("cls");

            float popA = 90000000;
            float popB = 200000000;
            float taxaCresPopA = 3;
            float taxaCresPopB = 1.5;

            printf("Informacoes:\nPopulacao do pais \"A\": %.0f.\nTaxa de crescimento anual da populacao do pais \"A\": %.2f%%.\nPopulacao do pais \"B\": %.0f.\nTaxa de crescimento anual da populacao do pais \"B\": %.2f%%.\n\n", popA, taxaCresPopA, popB, taxaCresPopB);
            int ano;
            for (ano = 0; popA <= popB; ano++){
                popA += popA * taxaCresPopA / 100;
                popB += popB * taxaCresPopB / 100;
            }
            printf("Para a populacao do pais \"A\" ser maior ou igual a populacao do pais \"B\", ira precisar que se passe %d anos.\n", ano);
            printf("No final, a populacao do pais \"A\" tera %.0f habitantes, enquanto a populacao do pais \"B\" tera %.0f habitantes.\n", popA, popB);
            printf("\nPressione qualquer tecla para voltar ao menu...\n");
            getch();
            system("cls");
        }
        else if (resp == 4){
            system("cls");
            printf("Por: Joao Pedro de Oliveira Leal.\n\nObrigado por usar o programa.\nPressione qualquer tecla para continuar...\n");
            getch();

        }
        else {
            system("cls");
            printf("Opcao invalida... Digite apenas uma das quatro opcoes presentes.\nPressione qualquer tecla para continuar...\n");
            getch();
            system("cls");
        }
    }

    return 0;
}
