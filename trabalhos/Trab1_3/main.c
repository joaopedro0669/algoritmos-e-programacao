#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int verificarStringInt(const char *ver){ //verificar se a string só contém caracteres numéricos.
    int numeros = 0;
    if(ver == NULL || *ver == '\0'){
        return 0; //retorna false caso dê NULL ou o conteúdo seja '\0'.
    }
    for(int i = 0; ver[i] != '\0'; i++){
        if (!isdigit(ver[i])){
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

void pergunta(char *str){
    int parar1 = 0;
    while(!parar1){
        int valor = 0;
        scanf("%s", str);

        removerEspacos(str);
        if(verificarStringInt(str)){
            valor = atof(str);
            if(valor < 1 || valor > 99)
                printf("Informe um valor entre 1 a 99: ");
            else
                parar1 = 1;
        }
        else
            printf("Informe apenas numeros inteiros: ");
        }
}

int main()
{
    char resp[10] = "";
    int viagensN = 0, viagensE = 0;
    float valor = 0, cargaN = 0, cargasE = 0;

    printf("Bem-vindo ao programa de avaliacao da empresa. Para continuar, precisamos de alguns dados...\n");

    int parar1 = 0;
    while(!parar1){
        parar1 = 0;
        //código do transportador
        printf("Informe o codigo do transportador (valor entre 1 a 99): ");
        pergunta(resp);
        printf("Informe o codigo do motorista (valor entre 1 a 99): ");
        pergunta(resp);
        printf("Informe o codigo do fornecedor (valor entre 1 a 99): ");
        pergunta(resp);
        printf("Informe o codigo da viagem: ");
        int parar2 = 0;
        while(!parar2){
            scanf("%s", resp);

            removerEspacos(resp);
            if(verificarStringInt(resp)){
                valor = atof(resp);
                parar2 = 1;
            }
            else
                printf("Informe apenas numeros inteiros: ");
        }

        printf("Informe a carga de cana (em quilos): ");
        parar2 = 0;
        while(!parar2){
            scanf("%s", resp);

            removerEspacos(resp);
            if(verificarStringFloat(resp)){
                valor = atof(resp);
                if(valor < 0)
                    printf("Informe um valor positivo: ");
                else
                    parar2 = 1;
            }
            else
                printf("Informe apenas numeros inteiros: ");
        }
        if(valor > 20000){
            viagensE++;
            cargaN += 20;
            cargasE += valor / 1000.0 - 20;
        }
        else {
            viagensN++;
            cargaN += valor / 1000.0;
        }

        printf("Como desejar continuar?\n1 - informar outros dados.\n2 - ver resumo dos dados.\n");
        scanf("%s", resp);
        removerEspacos(resp);
        if(!strcmp(resp, "1")){
            limparTela();
        }
        else if (!strcmp(resp, "2")){
            limparTela();
            parar1 = 1;
        }
        else
            printf("Resposta invalida. Informe 1 ou 2: ");
    }
    printf("Total de carga transportada: %.2f toneladas, sendo %.2f normais e %.2f excendentes.\n", cargaN + cargasE, cargaN, cargasE);
    printf("Total de viagens feitas: %d viagens, sendo %d normais e %d excendentes.\n", viagensN + viagensE, viagensN, viagensE);
    printf("%.2f%% das cargas transpostadas sao classificadas como cargas normais E %.2f como cargas excendentes.", cargaN / (cargaN + cargasE) * 100, cargasE / (cargaN + cargasE) * 100);


    return 0;
}
