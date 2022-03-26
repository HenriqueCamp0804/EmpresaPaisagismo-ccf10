#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresaPaisagismo.h"



int main() {
    //declarando variaveis
    int result;
    tipoClientes dadosCliente[100];
    tipoVenda dadosVenda[100];
    int contaVenda = 0;
    float media;
    char nome[30],logradouro[20],cidade[20],bairro[20];
    int telefone,ID,num,cep;
    int contaCliente = 0;
    FILE *arqClientes;
    if((arqClientes = fopen("clientesProjeto.txt","r+"))!=NULL){
        while(!feof(arqClientes)){
            fscanf(arqClientes,"%s %d %d %s %s %s %d %d ",nome,&telefone,&ID,logradouro,cidade,bairro,&num,&cep);
            strcpy(dadosCliente[contaCliente].nome,nome);
            dadosCliente[contaCliente].telefone = telefone;
            dadosCliente[contaCliente].ID = ID;
            strcpy(dadosCliente[contaCliente].endereco.logradouro,logradouro);
            strcpy(dadosCliente[contaCliente].endereco.cidade,cidade);
            strcpy(dadosCliente[contaCliente].endereco.bairro,bairro);
            dadosCliente[contaCliente].endereco.numero = num;
            dadosCliente[contaCliente].endereco.cep = cep;
            contaCliente++;

        }
    }
    fclose(arqClientes);

    while (1) {
        result = menuOpcoes();

        if (result == 1) {
            contaVenda++;
            cadastroVenda(dadosVenda, contaVenda);

        } else if (result == 2) {
            media = 0;
            mediaValores(dadosVenda, contaVenda);

        } else if (result == 3) {
            determina_PlantaCara(dadosVenda, contaVenda);

        } else if (result == 4) {
            determina_PlantaBarata(dadosVenda, contaVenda);

        } else if (result == 5) {
            somaVenda(dadosVenda, contaVenda);


        } else if (result == 6) {
            controleEstoque(dadosVenda, contaVenda);

        } else if (result == 7) {
            clienteSemana();

        } else if (result == 8) {
            cadastraCLiente(dadosCliente, contaCliente);
            contaCliente++;
            if ((arqClientes = fopen("clientesProjeto.txt", "a")) != NULL) {
                for (int i = contaCliente-1; i < contaCliente; i++) {
                    fputs("\n",arqClientes);
                    fputs(dadosCliente[i].nome, arqClientes);
                    fputs(" ", arqClientes);
                    fprintf(arqClientes, "%d", dadosCliente[i].telefone);
                    fputs(" ", arqClientes);
                    fprintf(arqClientes, "%d", dadosCliente[i].ID);
                    fputs(" ", arqClientes);
                    fputs(dadosCliente[i].endereco.logradouro, arqClientes);
                    fputs(" ", arqClientes);
                    fputs(dadosCliente[i].endereco.cidade, arqClientes);
                    fputs(" ", arqClientes);
                    fputs(dadosCliente[i].endereco.bairro, arqClientes);
                    fputs(" ", arqClientes);
                    fprintf(arqClientes, "%d", dadosCliente[i].endereco.numero);
                    fputs(" ", arqClientes);
                    fprintf(arqClientes, "%d", dadosCliente[i].endereco.cep);
                }
                fclose(arqClientes);
            }

        } else if (result == 9) {
            faturamento();

        } else if (result == 10) {
            compraCliente(dadosVenda, contaVenda, dadosCliente);

        } else if (result == 11) {
            imprimirClientes(dadosCliente, contaCliente);

        } else if (result == 12) {
            break;

        } else {
            printf("Opcao invalida!\nEntre com outra opcao.\n");
        }
    }
    return 0;
}