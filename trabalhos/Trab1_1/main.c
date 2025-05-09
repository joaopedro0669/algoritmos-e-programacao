#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void stringParaMin(char *str){
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

void removerEspacos(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void limparTela()
{
#ifdef _WIN32
    system("cls"); //limpar a tela em sistemas Windows 32 ou 64 bit.
#else
    system("clear"); //para os demais sistemas.
#endif
}

int verificarStringFloat(const char *ver){ //verificar se a string só contém caracteres numéricos ou ponto decimal.
    int pontos = 0;
    int numeros = 0;
    if(ver == NULL || *ver == '\0'){
        return 0; //retorna false caso dê NULL ou o conteúdo seja '\0'.
    }
    for(int i = 0; ver[i] != '\0'; i++){
        if(ver[i] == '.'){
            pontos++;
            if(pontos > 1)
                return 0; //retorna false caso tenha dois pontos.
        }
        else if (!isdigit(ver[i])){
            if(ver[i] != '-')
                return 0;
        }
        else
            numeros++;
    }
    if(numeros == 0)
        return 0;
    else
        return 1; //retorna true
}

int main()
{
    double *num = malloc(1 * sizeof(double));
    if(!num){
        printf("Falha ao alocar memória. Reinicie o programa e tente novamente.\n"); //aí só resta chorar e finalizar o programa, né? Kkkkkkk. Não tem como ele continuar sem alocar memória pra cá.
        return 0;
    }
    printf("Informe um numero qualquer diferente de zero: ");
    double numInf = 0.0; //número informado.
    char verif[15] = ""; //string para verificar o que o usuário digitou.
    int n = 0; //isso vai ser o tamanho do array.

    int parar1 = 0;
    int parar2 = 0;
    while(!parar1){
        n++;
        parar2 = 0;
        while(!parar2){
            scanf("%s", verif);
            while (getchar() != '\n'); //limpar buffer de entrada
            if(verificarStringFloat(verif)){
                numInf = atof(verif); //converte a string em float ou double.
                if(numInf == 0 && n == 1)
                    printf("Valor invalido. Digite um valor diferente de zero: ");
                else
                    parar2 = 1;
            }
            else
                printf("Valor invalido. Digite apenas numeros inteiros ou decimais: ");
        }
        if(numInf != 0.0){
            if(n > 1){
                double *temp = realloc(num, n * sizeof(double)); //realoca mais memória para armazenar mais elementos no array.
                if(!temp){
                    printf("Falha ao realocar memória. Reinicie o programa e tente novamente.\n");
                    free(num);
                    return 0;
                }
                num = temp;
            }
            num[n-1] = pow(numInf * n, n); //o cálculo lá.
            printf("Informe outro ou 0 para finalizar: ");
        }
        else
            parar1 = 1;
    }
    n--;
    limparTela();

    //soma dos elementos
    double soma = 0;
    for(int i = 0; i < n; i++){
        soma += num[i];
    }

    //média aritmética
    double media = soma / n;

    //mostrar mensagem
    printf("Soma dos elementos da lista: %.2lf. \nMedia aritmetica dos elementos da lista: %.3lf. \nForam realizados %d calculos para os elementos das listas. \n\nDeseja visualizar a lista? (Digite S para sim e N para nao)\n", soma, media, n);
    char resp[4] = "";

    int parar3 = 0;
    while(!parar3){
        scanf("%s", resp);
        while (getchar() != '\n');
        removerEspacos(resp);
        stringParaMin(resp);

        if(!strcmp(resp, "s") || !strcmp(resp, "sim")){
            for(int i = 0; i < n; i++){
                printf("Elemento %d: %.2lf.\n", i+1, num[i]);
            }
            parar3 = 1;
        }
        else if(!strcmp(resp, "n") || !strcmp(resp, "nao") || !strcmp(resp, "não"))
            parar3 = 1;
        else
            printf("Resposta invalida. Deseja visualizar a lista? (Digite S para sim e N para nao)\n");
    }

    free(num);
    return 0;
}
