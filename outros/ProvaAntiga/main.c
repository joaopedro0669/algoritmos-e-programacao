#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int resp = 0;
    while (resp != 3){
        printf("O que desejas?\n[1] Calculo varias contas de energia eletrica residencial.\n[2] Sequencia com variacao triplice de sinal.\n[3] Finalizar algoritmo.\nInforme uma das opcoes: ");
        scanf("%d", &resp);
        fflush(stdin);
        if(resp == 1){
            //exercicio 1
            system("cls");

            float cons;
            float preCons;
            float maiorConta = 0;
            float menorConta = 0;
            float gastoTotal = 0;
            int respExer1 = 1;
            int quantContas = 0;
            float quantContasFaixa1 = 0, quantContasFaixa2 = 0, quantContasFaixa3 = 0, quantContasFaixa4 = 0, quantContasFaixa5 = 0;
            float porcFaixa1, porcFaixa2, porcFaixa3, porcFaixa4, porcFaixa5;
            int quantContasZero = 0;
            float mediaContas;

            while (respExer1 == 1){
                do{
                    printf("Informe o consumo de energia: ");
                    scanf("%f", &cons);
                    fflush(stdin);
                    if(cons < 0){
                        printf("Valor invalido.\n");
                    }
                    else if(cons == 0){
                        printf("Nao houve consumo. ");
                        quantContasZero = quantContasZero + 1;
                    }
                    else if(cons > 0){
                        if(cons <= 30){
                            preCons = cons * 1.3;
                            quantContasFaixa1 = quantContasFaixa1 + 1;
                        }
                        else if (cons <= 70){
                            preCons = 30 * 1.3 + (cons - 30) * 1.9;
                            quantContasFaixa2 = quantContasFaixa2 + 1;
                        }
                        else if (cons <= 90){
                            preCons = 30 * 1.3 + 40 * 1.9 + (cons - 70) * 2.4;
                            quantContasFaixa3 = quantContasFaixa3 + 1;
                        }
                        else if (cons <= 120){
                            preCons = 30 * 1.3 + 40 * 1.9 + 20 * 2.4 + (cons - 90) * 3.1;
                            quantContasFaixa4 = quantContasFaixa4 + 1;
                        }
                        else {
                            preCons = 30 * 1.3 + 40 * 1.9 + 20 * 2.4 + 30 * 3.1 + (cons - 120) * 3.8;
                            quantContasFaixa5 = quantContasFaixa5 + 1;
                        }
                        quantContas = quantContas + 1;

                        if(quantContas == 1){
                            maiorConta = preCons;
                            menorConta = preCons;
                        }
                        else{
                            if(preCons > maiorConta){
                                maiorConta = preCons;
                            }
                            else if(preCons < menorConta){
                                menorConta = preCons;
                            }
                        }
                        gastoTotal += preCons;
                    }
                } while (cons < 0);
                do{
                    printf("Voce deseja informar outro consumo? Digite 1 para sim e 0 para nao: ");
                    scanf("%d", &respExer1);
                    fflush(stdin);
                    if(respExer1 != 1 && respExer1 != 0){
                        printf("Voce eh burro. Digita certo. ");
                    }
                    else if(respExer1 == 1){
                        system("cls");
                    }
                    else if(respExer1 == 0){
                        porcFaixa1 = quantContasFaixa1 / quantContas * 100;
                        porcFaixa2 = quantContasFaixa2 / quantContas * 100;
                        porcFaixa3 = quantContasFaixa3 / quantContas * 100;
                        porcFaixa4 = quantContasFaixa4 / quantContas * 100;
                        porcFaixa5 = quantContasFaixa5 / quantContas * 100;
                        mediaContas = gastoTotal / quantContas;

                        system("cls");
                        printf("Relatorio:\nQuantidade de contas maiores que zero registradas: %d contas.\nQuantidade de contas com consumo 0: %d contas.\nMaior valor registrado: %.2f reais.\nMenor valor registrado: %.2f reais.\n", quantContas, quantContasZero, maiorConta, menorConta);
                        printf("\nPorcentagem de faixas:\nFaixa 1 (entre 1 a 30 kw): %.2f%%.\nFaixa 2 (entre 30 a 70 kw): %.2f%%.\nFaixa 3 (entre 70 a 90 kw): %.2f%%.\nFaixa 4 (entre 90 a 120 kw): %.2f%%.\nFaixa 5(acima de 120 kw): %.2f%%.\n", porcFaixa1, porcFaixa2, porcFaixa3, porcFaixa4, porcFaixa5);
                        printf("\nMedia de consumo do bairro: %.2f", mediaContas);
                        printf("\nPressione qualquer tecla para continuar...\n");
                        getch();
                        system("cls");
                    }
                } while(respExer1 != 1 && respExer1 != 0);
            }




        }
        else if(resp == 2){
            //exercicio 2
            system("cls");

            int numLimite;
            float numerador, denominador;
            int numBaseNumerador;
            int multi = 1;
            int contMulti = 3;
            float soma = 0;

            do{
                printf("Informe o valor do numerador final: ");
                scanf("%d", &numLimite);
                fflush;
                if(numLimite <= 0){
                    printf("Voce digitou errado. Num pode, seu burro. ");
                }
            } while(numLimite <= 0);
            for (int i = 1; i <= numLimite; i++){
                numBaseNumerador = 2 * i - 1; //para pegar os numeros de 2 em 2. 1, 3, 5, 7, 9
                float resultado = 1; //para guardar o resultado da potencia

                //função da potência:
                for (int j = 0; j < numBaseNumerador; j++){
                    resultado = resultado * numBaseNumerador;
                }
                numerador = resultado;

                resultado = 1; //para guardar o resultado do fatorial
                //função do fatorial:
                for(int j = i; j >= 1; j--){
                    resultado = resultado * j;
                }
                denominador = resultado;

                if(contMulti > 0){
                    contMulti =  contMulti - 1;
                }
                else{
                    contMulti = 2;
                    multi = -multi;
                }

                soma += numerador/denominador * multi;
            }
            printf("O resultado da soma de todos os termos eh: %.2f\n", soma);
            printf("Pressione qualquer tecla para continuar...\n");
            getch();
            system("cls");
        }
        else if(resp == 3){
            printf("Fim de programa.\n");
        }
        else {
            system("cls");
            printf("Voce eh burro. Informe um valor decente. ");
            printf("\nPressione qualquer tecla para continuar...\n");
            getch();
            system("cls");
        }
    }

    return 0;
}
