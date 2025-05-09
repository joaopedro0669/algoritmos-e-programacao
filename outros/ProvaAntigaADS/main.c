#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    //exercício 1
    /*
    int linhas;
    do{
        printf("Informe a quantidade de linhas: ");
        scanf("%d", &linhas);
        fflush(stdin);
        if(linhas <= 0){
            printf("Digite apenas numeros maiores que zero. ");
        }
    } while (linhas <= 0);

    for (int lin = 1; lin <= linhas; lin++){ //criando linhas novas
        for (int col = 1, cont = lin; col <= lin; col++, cont = cont + 2){ //ele que deixa a linha certinha
            if(col == lin){
                printf("%3d. ", cont);
            }
            else {
                printf("%3d, ", cont);
            }
        }
        printf("\n");
    }
    */

    //exercício 2
    /*
    char resp[10] = "sim";
    while (!strcmp(resp, "sim")){
        int num;
        int divInt = 0;
        float divReal = 0;
        int naoEhPrimo = 0;

        do{
            printf("Informe um numero maior do que 1: ");
            scanf("%d", &num);
            fflush(stdin);
            if(num <= 1){
                printf("Digite apenas numeros maiores que um. ");
            }
        } while(num <= 1);

        for (float div = 2; div < num; div++){
            divInt = num / div;
            divReal = num / div;

            if(divInt == divReal){
                naoEhPrimo = 1;
                div = num;
            }
        }
        if(naoEhPrimo == 1){
            printf("Nao eh primo.\n");
        }
        else if (naoEhPrimo == 0){
            printf("Eh primo.\n");
        }

        do{
            printf("Deseja continuar?\n");
            scanf("%s", resp);
            fflush(stdin);
            if(strcmp(resp, "sim") && strcmp(resp, "nao")){
                printf("Digite apenas numeros \"sim\" ou \"nao\". ");
            }
        } while(strcmp(resp, "sim") && strcmp(resp, "nao"));

        if(!strcmp(resp, "sim")){
            system("cls");
        }
        else if (!strcmp(resp, "nao")){
            system("cls");
            printf("Obrigado por usar o programa.\nPressione qualquer tecla para prosseguir...\n");
            getch();
        }
    }
    */


    //exercício 3
    /*
    char resp3[10] = "sim";
    while (!strcmp(resp3, "sim")){

        int n1, n2;
        int resultado;

        do{
            printf("Informe um numero: ");
            scanf("%d", &n1);
            fflush(stdin);
            if(n1 < 0){
                printf("Digite apenas numeros maiores ou iguais a zero. ");
            }
        } while (n1 < 0);

        do{
            printf("Informe um numero: ");
            scanf("%d", &n2);
            fflush(stdin);
            if(n2 < 0){
                printf("Digite apenas numeros maiores ou iguais a zero. ");
            }
        } while (n2 < 0);


        for (int i = 0; i <= n2; i++){
            if (i == 0){
                resultado = 1;
            }
            else if (i == 1){
                resultado = n1;
            }
            else {
                resultado = resultado * n1;
            }
        }
        printf("O resultado de %d elevado %d eh %d\n\n", n1, n2, resultado);


        do{
            printf("Deseja continuar?\n");
            scanf("%s", resp3);
            fflush(stdin);
            if(strcmp(resp3, "sim") && strcmp(resp3, "nao")){
                printf("Digite apenas numeros \"sim\" ou \"nao\". ");
            }
        } while(strcmp(resp3, "sim") && strcmp(resp3, "nao"));

        if(!strcmp(resp3, "sim")){
            system("cls");
        }
        else if (!strcmp(resp3, "nao")){
            system("cls");
            printf("Obrigado por usar o programa.\nPressione qualquer tecla para prosseguir...\n");
            getch();
        }
    }
    */
    return 0;
}
