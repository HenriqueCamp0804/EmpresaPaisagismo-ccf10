#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresaPaisagismo.h"



int main() {
    //declarando variaveis
    int result;                                 //pergunta, eu posso declarar as variaveis q uso so na funcao apenas nas proprias funcoes?//
    tipoClientes dadosCliente[100];
    tipoVenda dadosVenda[100];
    int contaVenda = 0;
    float media;

    while (1) {
        result = menuOpcoes();

        if (result == 1) {
            contaVenda++;
            cadastroVenda(dadosVenda,contaVenda);

        }else if(result == 2) {
            media = 0;
            mediaValores(dadosVenda,contaVenda);

        } else if (result == 3) {
            determina_PlantaCara(dadosVenda,contaVenda);

        } else if (result == 4) {
            determina_PlantaBarata(dadosVenda,contaVenda);

        } else if (result == 5) {
            somaVenda(dadosVenda,contaVenda);


        } else if (result == 6) { //como eu faria pra calcular o estoque de uma mesma planta q aparece em vendas diferentes
            controleEstoque(dadosVenda,contaVenda);

        }else if (result == 7){
            clienteSemana();

        } else if(result == 8 ){
            cadastraCLiente();

        }else if(result == 9){
            faturamento();

        }else if(result == 10){
            compraCliente(dadosVenda,contaVenda,dadosCliente);

        }else if(result == 11){
            break;

        }else{
            printf("Opcao invalida!\nEntre com outra opcao.\n");
        }

    }
    return 0;
}