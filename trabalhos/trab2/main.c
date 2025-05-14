//Jo�o Pedro de Oliveira Leal - 1� Per�odo
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

void limparTela(){
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif // _WIN32
}

void menu(int *a){
    printf("MENU DE OP��ES\n=================\n1 � maior sequ�ncia de n�meros iguais consecutivos\n2 � maior diferen�a entre dois n�meros consecutivos\n3 � sair\nEscolha o n�mero de uma das op��es acima...: ");
    do{
        scanf("%d", a);
        while(getchar() != '\n');
        if(*a < 1 || *a > 3)
            printf("Op��o inv�lida! Tente novamente: ");
    } while(*a < 1 || *a > 3);
}

int input_array(int *array, int i){
    do {
        printf("Informe zero ou um n�mero de 1 a 9 para o item %d: ", i+1);
        scanf("%d", (array + i));
        while(getchar() != '\n');
        if(*(array + i) < 0 || *(array + i) > 9)
            printf("Apenas n�meros entre 1 a 9 ou zero! ");
    } while (*(array + i) < 0 || *(array + i) > 9);
    if(*(array + i) == 0)
        return 0;
    else
        return 1;
}

int verificar_array(int *array, int tam){ //n�o vai usar isso aq
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

int main()
{
    setlocale(LC_CTYPE, "Portuguese");
    int resp;
    menu(&resp);

    if(resp == 1){
        limparTela();
        int num[300];
        int continuar = 1;
        int i;
        for(i = 0; i < 300 && continuar; i++)
            continuar = input_array(num, i);

        i--;
        limparTela();
        for(int j = 0; j < i; j++){
            printf("%d ", num[j]);
            if((j+1) % 5 == 0)
                printf("\n");
        }

        int maior_num = verificar_array(num, i);
        printf("%d", maior_num);

    }
    else if(resp == 2){

    }
    else if(resp == 3){
        limparTela();
        printf("Fim de programa...");
        printf("\nPressione qualquer tecla para continuar...\n");
        getch();
    }
    return 0;
}
