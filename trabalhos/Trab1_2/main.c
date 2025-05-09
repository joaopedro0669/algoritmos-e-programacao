#include <stdio.h>
#include <stdlib.h>
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

void limparTela(){ //mesma coisa do primeiro exercício
    #ifdef _WIN32
        system("cls");
    #else:
        system("clear");
    #endif
}

int maiorNome(const char *nome1, const char *nome2, const char *nome3, const char *nome4){
    int verificando = 0, maior = 0;
    for (int i = 0; nome1[i] != '\0'; i++){
        verificando++;
    }
    maior = verificando;
    verificando = 0;

    for (int i = 0; nome2[i] != '\0'; i++){
        verificando++;
    }
    if(verificando > maior)
        maior = verificando;
    verificando = 0;

    for (int i = 0; nome3[i] != '\0'; i++){
        verificando++;
    }
    if(verificando > maior)
        maior = verificando;
    verificando = 0;

    for (int i = 0; nome4[i] != '\0'; i++){
        verificando++;
    }
    if(verificando > maior)
        maior = verificando;
    verificando = 0;

    if(maior < 14)
        maior = 14;

    return maior + 3;
}

void printSync(const char *nome, int num, int tamanho){
    int tamanhoNome = 0;
    for (int i = 0; nome[i] != '\0'; i++){
        tamanhoNome++;
    }

    printf("%s", nome);
    for(int i = 0; i < tamanho - tamanhoNome; i++){
        printf(".");
    }

    printf("%d\n", num);
}

void vencedor(const char (*nome)[200], int *voto){

    int maior = voto[0], maior_id = 0, empate = 0;
    int empatados[4] = {-1, -1, -1, -1};

    for (int i = 1; i < 4; i++){
        if(voto[i] > maior){
            maior = voto[i];
            maior_id = i;
            empate = 0;
            empatados[0]= -1;
            empatados[1]= -1;
            empatados[2]= -1;
            empatados[3]= -1;

        }
        else if (voto[i] == maior){
            empate = 1;
            for(int j = 0; j < 4; j++){
                if(empatados[j] == maior_id)
                    j = 4;
                else if(empatados[j] == -1){
                    empatados[j] = maior_id;
                    j = 4;
                }
            }
            for(int j = 0; j < 4; j++){
                if(empatados[j] == i)
                    j = 4;
                else if(empatados[j] == -1){
                    empatados[j] = i;
                    j = 4;
                }
            }
        }
    }


    if(maior >= voto[4] && maior >= voto[5] && !empate){
        printf("O vencedor da eleicao foi %s, com %d votos.", nome[maior_id], voto[maior_id]);
    }
    else if(maior >= voto[4] && maior >= voto[5] && empate){
        int num_empatados = 0;
        for(int i = 0; i < 4; i++){
            if(empatados[i] != -1)
                num_empatados++;
        }

        if(num_empatados == 2){
            printf("Nao houve vencedores, pois houve um empate entre %s e %s.", nome[empatados[0]], nome[empatados[1]]);
        }
        else if(num_empatados == 3){
            printf("Nao houve vencedores, pois houve um empate entre %s, %s e %s.", nome[empatados[0]], nome[empatados[1]], nome[empatados[2]]);
        }
        else if(num_empatados == 4){
            printf("Nao houve vencedores, pois todos os participantes empataram.");
        }
    }
    else if (voto[4] > voto[5]){
        printf("Houve mais votos nulos.");
    }
    else if (voto[5] > voto[4]){
        printf("Houve mais votos em branco.");
    }
}

int main()
{
    char nome[4][200];
    int votos[6] = {0, 0, 0, 0, 0, 0};


    printf("Eleicao para representante de sala:\n");
    printf("Digite o nome completo do primeiro candidado: ");
    fgets(nome[0], 200, stdin);
    printf("Digite o nome completo do segundo candidado: ");
    fgets(nome[1], 200, stdin);
    printf("Digite o nome completo do terceiro candidado: ");
    fgets(nome[2], 200, stdin);
    printf("Digite o nome completo do quarto candidado: ");
    fgets(nome[3], 200, stdin);

    //tirar o '\n' da string
    nome[0][strcspn(nome[0], "\n")] = '\0';
    nome[1][strcspn(nome[1], "\n")] = '\0';
    nome[2][strcspn(nome[2], "\n")] = '\0';
    nome[3][strcspn(nome[3], "\n")] = '\0';

    limparTela();


    int valor_maiornome = maiorNome(nome[0], nome[1], nome[2], nome[3]);
    char resp[4];
    int parar1 = 0;
    while(!parar1){
        printf("Em quem deseja votar?\n");
        printf("Digite o numero para votar:\n\n");

        printSync(nome[0], 1, valor_maiornome);
        printSync(nome[1], 2, valor_maiornome);
        printSync(nome[2], 3, valor_maiornome);
        printSync(nome[3], 4, valor_maiornome);
        printSync("Voto nulo", 5, valor_maiornome);
        printSync("Voto em branco", 6, valor_maiornome);
        printSync("Fim da votacao", 0, valor_maiornome);

        scanf("%s", resp);
        removerEspacos(resp);
        if(!strcmp(resp, "1")){
            votos[0]++;
            limparTela();
            printf("Voto para %s registrado.\n\n", nome[0]);
        }
        else if(!strcmp(resp, "2")){
            votos[1]++;
            limparTela();
            printf("Voto para %s registrado.\n\n", nome[1]);
        }
        else if(!strcmp(resp, "3")){
            votos[2]++;
            limparTela();

            printf("Voto para %s registrado.\n\n", nome[2]);
        }
        else if(!strcmp(resp, "4")){
            votos[3]++;
            limparTela();
            printf("Voto para %s registrado.\n\n", nome[3]);
        }
        else if(!strcmp(resp, "5")){
            votos[4]++;
            limparTela();
            printf("Voto nulo registrado.\n\n");
        }
        else if(!strcmp(resp, "6")){
            votos[5]++;
            limparTela();
            printf("Voto em branco registrado.\n\n");
        }
        else if(!strcmp(resp, "0")){
            parar1 = 1;
        }
        else {
            limparTela();
            printf("Resposta invalida.\n\n");
        }
    }

    limparTela();

    printf("Total de votos:\n");

    printSync(nome[0], votos[0], valor_maiornome);
    printSync(nome[1], votos[1], valor_maiornome);
    printSync(nome[2], votos[2], valor_maiornome);
    printSync(nome[3], votos[3], valor_maiornome);
    printSync("Voto nulo", votos[4], valor_maiornome);
    printSync("Voto em branco", votos[5], valor_maiornome);
    float p1 = votos[4] + votos[5];
    float p2 = votos[0] + votos[1] + votos[2] + votos[3] + votos[4] + votos[5];
    float porcentagem = 0;
    if(p2 != 0)
        porcentagem = p1 / p2 * 100;
    printf("%.2f%% dos votos totais foram brancos e nulos.\n", porcentagem);

    printf("\nResultado: ");
    vencedor(nome, votos);
    printf("\n");
    return 0;
}
