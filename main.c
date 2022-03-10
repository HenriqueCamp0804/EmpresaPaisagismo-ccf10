#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criando struct para planta
typedef struct{
    char nome[100];
    float valor;
    int estoqueAtual;
    int qtdEstoque;
    int qtdComprada;
}infoPlantas;

//criando struct endereco para aninhar no cadastro do cliente
typedef struct{
    char logradouro[100];
    char cidade[50];
    char bairro[50];
    int numero;
    int cep;
}tipoEndereco;

//criando struct para cadastro de cliente
typedef struct{
    char nome[100];
    int telefone;
    tipoEndereco endereco;
}infoClientes;

int main() {
    //declarando variaveis
    infoPlantas dadosPlanta[1000];
    infoClientes dadosCliente[1000];
    int opcao,estoqueIdeal=500;
    float valorMenor=100,valorMaior=0;
    int qtdEspecies,numClientes_Cadast;
    int estoqueMinimo,vetNumClientes[7],i,somaClientes=0;
    char plantaCara[30],plantaBarata[30];
    float media,soma=0;
    float tabelaGastos[12][4],tabelaGanhos[12][4],tabelaLucro[12][4];
    int j,mesAtual;
    float ganhoParcial=0.0,gastoParcial=0.0,lucroParcial=0.0;

    while (1) {
        printf("1 - Cadastrar venda\n");
        printf("2 - Media dos valores das plantas\n");
        printf("3 - Planta mais cara\n");
        printf("4 - Planta mais barata\n");
        printf("5 - Valor total das plantas\n");
        printf("6 - Verificar estoque\n");
        printf("7 - Quantidade de clientes na semana\n");
        printf("8 - Cadastrar Clientes:\n");
        printf("9 - Controle de faturamento parcial\n");
        printf("10 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        if (opcao == 1) {
            printf("Entre com a quantidade de especies diferentes compradas,nesta venda: ");
            scanf("%d",&qtdEspecies);
            for(i=0;i<qtdEspecies;i++){

                printf("Entre com o nome da planta %d: ",i+1);
                fflush(stdin);
                gets(dadosPlanta[i].nome);
                printf("Digite o valor da planta %d: ",i+1);
                scanf("%f",&dadosPlanta[i].valor);
                printf("Entre com a quantidade em estoque da planta %d: ",i+1);
                scanf("%d",&dadosPlanta[i].qtdEstoque);
                printf("Entre com a quantidade compradas da planta %d: ",i+1);
                scanf("%d",&dadosPlanta[i].qtdComprada);
                dadosPlanta[i].estoqueAtual = (dadosPlanta[i].qtdEstoque - dadosPlanta[i].qtdComprada);
                estoqueMinimo = estoqueIdeal*0.6;
                soma = soma + (dadosPlanta[i].valor* dadosPlanta[i].qtdComprada);

                if(dadosPlanta[i].valor>valorMaior){
                    valorMaior = dadosPlanta[i].valor;
                    strcpy(plantaCara,dadosPlanta[i].nome);

                }
                if(dadosPlanta[i].valor<valorMenor){
                    valorMenor = dadosPlanta[i].valor;
                    strcpy(plantaBarata,dadosPlanta[i].nome);
                }
            }
            media = soma/qtdEspecies;

        } else if (opcao == 2) {
            printf("Media dos valores das plantas = %.2f\n",media);

        } else if (opcao == 3) {
            printf("A planta mais cara = %s\n",plantaCara);
            printf("O valor da planta mais cara = R$ %.2f\n",valorMaior);

        } else if (opcao == 4) {
            printf("A planta mais barata = %s\n",plantaBarata);
            printf("O valor da planta mais barata = R$ %.2f\n",valorMenor);

        } else if (opcao == 5) {
            printf("O valor total das plantas compradas eh de R$ %.2f\n",soma);

        } else if (opcao == 6) {
            for(i=0;i<qtdEspecies;i++){
                printf("O estoque atual de %s = %d unidades\n", dadosPlanta[i].nome,dadosPlanta[i].estoqueAtual);
                if (dadosPlanta[i].estoqueAtual < estoqueMinimo) {
                    printf("Eh necessario repor o estoque desta planta!\n");
                } else if (dadosPlanta[i].estoqueAtual > estoqueMinimo) {
                    printf("O estoque desta planta ainda eh suficiente!\n");
                } else if (dadosPlanta[i].estoqueAtual > estoqueIdeal) {
                    printf("O estoque desta planta esta acima do ideal!\n");
                }
            }

        }else if (opcao == 7){
            for(i=0;i<7;i++){
                printf("Entre com a quantidade de clientes do dia %d: ",i+1);
                scanf("%d",&vetNumClientes[i]);
            }
            for(i=0;i<7;i++){
                somaClientes = somaClientes + vetNumClientes[i];
            }
            printf("A quantidade de clientes da semana foi de: %d\n",somaClientes);

        } else if(opcao == 8 ){
            printf("Entre com a quantidade de clientes para cadastro:\n");
            scanf("%d",&numClientes_Cadast);
            for(i=0;i<numClientes_Cadast;i++){
                printf("Entre com o nome do cliente %d:\n",i+1);
                fflush(stdin);
                gets(dadosCliente[i].nome);
                printf("Entre com o numero de telefone do cliente %d:\n",i+1);
                scanf("%d",&dadosCliente[i].telefone);
                printf("Entre com o logradouro do cliente %d:\n",i+1);
                fflush(stdin);
                gets(dadosCliente[i].endereco.logradouro);
                printf("Entre com a cidade do cliente %d:\n",i+1);
                fflush(stdin);
                gets(dadosCliente[i].endereco.cidade);
                printf("Entre com o bairro do cliente %d:\n",i+1);
                fflush(stdin);
                gets(dadosCliente[i].endereco.bairro);
                printf("Entre com o numero da residencia do cliente %d:\n",i+1);
                scanf("%d",&dadosCliente[i].endereco.numero);
                printf("Entre com o CEP,sem hifen e sem ponto, do cliente %d:\n",i+1);
                scanf("%d",&dadosCliente[i].endereco.cep);
                printf("Dados do cliente %d:\n",i+1);
                printf("Nome: %s // Telefone: %d // Endereco: %s | %s | %s | %d | %d |\n",dadosCliente[i].nome,dadosCliente[i].telefone,
                       dadosCliente[i].endereco.logradouro,dadosCliente[i].endereco.cidade,dadosCliente[i].endereco.bairro,
                       dadosCliente[i].endereco.numero,dadosCliente[i].endereco.cep);
            }

        }else if(opcao == 9){
            printf("Entre com o mes atual: ");
            scanf("%d",&mesAtual);

            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    printf("Entre com os ganhos do mes %d,semana %d: ",i+1,j+1);
                    scanf("%f",&tabelaGanhos[i][j]);
                    ganhoParcial = ganhoParcial+tabelaGanhos[i][j];
                }
            }
            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    printf("Entre com os gastos do mes %d, semana %d: ",i+1,j+1);
                    scanf("%f",&tabelaGastos[i][j]);
                    gastoParcial = gastoParcial+tabelaGastos[i][j];
                }
            }
            for(i=0;i<mesAtual;i++){
                for(j=0;j<4;j++){
                    tabelaLucro[i][j] = tabelaGanhos[i][j] - tabelaGastos[i][j];
                    lucroParcial = lucroParcial+tabelaLucro[i][j];
                }
            }
            printf("Tabela de Lucros Parcias: \n");
            for(i=0;i<mesAtual;i++){
                printf("\n");
                for(j=0;j<4;j++){
                    printf("%.2f ",tabelaLucro[i][j]);
                }
            }
            printf("\n");
            printf("Lucro parcial até o mes %d = %.2f\n",i,lucroParcial);
            if(lucroParcial<ganhoParcial*0.6){
                printf("Lucro abaixo do esperado, tente economizar mais!\n");
            }
            else{
                printf("Lucro acima do esperado, continue assim!\n");
            }

        }else if(opcao == 10){
            break;

        }else{
            printf("Opcao invalida!\n");
        }

    }
    return 0;
}
//
// Created by Pichau on 10/03/2022.
//

