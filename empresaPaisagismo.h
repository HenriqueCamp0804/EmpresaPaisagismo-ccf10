//
// Created by Henrique on 17/03/2022.
//

#ifndef EMPRESAPAISAGISMO_CCF110_EMPRESAPAISAGISMO_H
#define EMPRESAPAISAGISMO_CCF110_EMPRESAPAISAGISMO_H

//declarando as structs usadas
typedef struct{
    char nome[100];
    float valor;
    int estoqueAtual;
    int qtdEstoque;
    int qtdComprada;
}infoPlantas;

//criando struct endereco para aninhar no cadastro do cliente
typedef struct{
    char logradouro[20];
    char cidade[20];
    char bairro[20];
    int numero;
    int cep;
}tipoEndereco;

//criando struct para data
typedef struct{
    int dia;
    int mes;
    int ano;
}tipoData;

//criando struct para cadastrar venda
typedef struct{
    int ID;
    infoPlantas planta[100];
    int qtdEspecies;
    float soma;
    tipoData dataCompra;
    tipoData dataEntrega;
}tipoVenda;

//criando struct para cadastro de cliente
typedef struct{
    char nome[30];
    int ID;
    int telefone;
    tipoEndereco endereco;
}tipoClientes;

//funcao para menu
int menuOpcoes(){
    int opcao;
    printf("------------------\n");
    printf("------MENU------\n");
    printf("1 - Cadastrar venda\n");
    printf("2 - Media dos valores das plantas\n");
    printf("3 - Planta mais cara\n");
    printf("4 - Planta mais barata\n");
    printf("5 - Valor total da venda\n");
    printf("6 - Verificar estoque\n"); //?
    printf("7 - Quantidade de clientes na semana\n");
    printf("8 - Cadastrar Clientes\n");
    printf("9 - Controle de faturamento parcial\n");
    printf("10 - Verificar compra de algum cliente\n");
    printf("11 - Lista de clientes cadastrados\n");
    printf("12 - Sair\n");
    printf("Opcao: ");
    scanf("%d",&opcao);
    return opcao;
}

//funcao para cadastro de vendas
void cadastroVenda(tipoVenda dadosVenda[],int contaVenda) {
    int j;

    printf("Digite com o ID da venda %d:\n", contaVenda);
    scanf("%d",&dadosVenda[contaVenda].ID);

    printf("Entre com a data da venda %d:\n", contaVenda);
    printf("Dia: \n");
    scanf("%d", &dadosVenda[contaVenda].dataCompra.dia);
    printf("Mes: \n");
    scanf("%d", &dadosVenda[contaVenda].dataCompra.mes);
    printf("Ano: \n");
    scanf("%d", &dadosVenda[contaVenda].dataCompra.ano);

    printf("Entre com a data de entrega da venda %d:\n", contaVenda);
    printf("Dia: \n");
    scanf("%d", &dadosVenda[contaVenda].dataEntrega.dia);
    printf("Mes: \n");
    scanf("%d", &dadosVenda[contaVenda].dataEntrega.mes);
    printf("Ano: \n");
    scanf("%d", &dadosVenda[contaVenda].dataEntrega.ano);


    printf("Entre com a quantidade de especies compradas:\n");
    scanf("%d", &dadosVenda[contaVenda].qtdEspecies);

    for (j = 0; j < dadosVenda[contaVenda].qtdEspecies; j++) {
        printf("Entre com o nome da planta %d: ", j + 1);
        fflush(stdin);
        gets(dadosVenda[contaVenda].planta[j].nome);

        printf("Digite o valor da planta %d: ", j + 1);
        scanf("%f", &dadosVenda[contaVenda].planta[j].valor);

        printf("Entre com a quantidade em estoque da planta %d: ", j + 1);
        scanf("%d", &dadosVenda[contaVenda].planta[j].qtdEstoque);

        printf("Entre com a quantidade compradas da planta %d: ", j + 1);
        scanf("%d", &dadosVenda[contaVenda].planta[j].qtdComprada);
    }
}
//funcao para ler pesquisador de venda
int recebeID(){
    int buscaID;
    printf("Digite o ID da venda que deseja somar:\n");
    scanf("%d",&buscaID);
    return buscaID;
}

//funcao para somar valor da venda
float somaVenda(tipoVenda dadosVenda[],int contaVenda){
    int i,j;
    dadosVenda[contaVenda].soma = 0;
    int ID;
    ID = recebeID();
    for(i=1;i<contaVenda+1;i++) {
        if (dadosVenda[i].ID == ID) {
            for (j = 0; j < dadosVenda[i].qtdEspecies; j++) {
                dadosVenda[i].soma = dadosVenda[i].soma + (dadosVenda[i].planta[j].valor * dadosVenda[i].planta[j].qtdComprada);
            }
            return dadosVenda[i].soma;
        }
    }
}


//funcao para calcular a media dos valores das plantas
void mediaValores(tipoVenda dadosVenda[],int contaVenda){
    int i,ID;
    float media;
    ID = recebeID();
    for(i=1;i<contaVenda+1;i++){
        if(dadosVenda[i].ID == ID){
            media = somaVenda(dadosVenda,contaVenda)/dadosVenda[i].qtdEspecies;
            printf("Media dos valores das plantas,da venda %s = %.2f\n",ID,media);
        }
    }
}

//funcao para determinar a planta mais cara
void determina_PlantaCara(tipoVenda dadosVenda[],int contaVenda){
    char plantaCara[30];
    int i,j,ID;
    float valorMaior = 0;
    ID = recebeID();
    for(i=1;i<contaVenda+1;i++){
        if(dadosVenda[i].ID == ID){
            for(j=0;j<dadosVenda[i].qtdEspecies;j++){
                if (j == 0){
                    valorMaior = dadosVenda[i].planta[j].valor;
                    strcpy(plantaCara,dadosVenda[i].planta[j].nome);
                }
                if(dadosVenda[i].planta[j].valor>valorMaior){
                    valorMaior = dadosVenda[i].planta[j].valor;
                    strcpy(plantaCara,dadosVenda[i].planta[j].nome);
                }
            }
        }
    }
    printf("A planta mais cara,da venda %s = %s\n",ID,plantaCara);
    printf("O valor da planta mais cara, da venda %s = R$ %.2f\n",ID,valorMaior);
}

//funcao para determinar planta mais barata
void determina_PlantaBarata(tipoVenda dadosVenda[],int contaVenda){
    char plantaBarata[30];
    int i,j,ID;
    float valorMenor = 1000;
    ID = recebeID();
    for(i=1;i<contaVenda+1;i++){
        if(dadosVenda[i].ID == ID){
            for(j=0;j<dadosVenda[i].qtdEspecies;j++){
                if(j == 0){
                    valorMenor = dadosVenda[i].planta[j].valor;
                    strcpy(plantaBarata,dadosVenda[i].planta[j].nome);
                }
                if(dadosVenda[i].planta[j].valor<valorMenor){
                    valorMenor = dadosVenda[i].planta[j].valor;
                    strcpy(plantaBarata,dadosVenda[i].planta[j].nome);
                }
            }
        }
    }
    printf("A planta mais barata da venda %s = %s\n",ID,plantaBarata);
    printf("O valor da planta mais barata da venda %s = R$ %.2f\n",ID,valorMenor);
}

//funcao para verificar a quantidade de clientes na semana
void clienteSemana(){
    int i;
    int vetNumClientes[7];
    int somaClientes = 0;
    for(i=0;i<7;i++){
        printf("Entre com a quantidade de clientes do dia %d: ",i+1);
        scanf("%d",&vetNumClientes[i]);
    }
    for(i=0;i<7;i++){
        somaClientes = somaClientes + vetNumClientes[i];
    }
    printf("A quantidade de clientes da semana foi de: %d\n",somaClientes);
}

//funcao para determinar o estoque apos uma venda
void controleEstoque(tipoVenda dadosVenda[],int contaVenda) {
    int i, j,estoqueIdeal = 500,estoqueMinimo,ID;
    estoqueMinimo = estoqueIdeal*0.6;
    ID = recebeID();
    printf("Verificando o estoque apos a venda %s :\n\n", ID);
    for (i = 1; i < contaVenda + 1; i++) {
        if(dadosVenda[i].ID == ID) {
            for (j = 0; j < dadosVenda[i].qtdEspecies; j++) {
                dadosVenda[i].planta[j].estoqueAtual = (dadosVenda[i].planta[j].qtdEstoque - dadosVenda[i].planta[j].qtdComprada);
                printf("O estoque atual de %s = %d unidades\n", dadosVenda[i].planta[j].nome, dadosVenda[i].planta[j].estoqueAtual);
                if (dadosVenda[i].planta[j].estoqueAtual < estoqueMinimo) {
                    printf("Eh necessario repor o estoque desta planta!\n");
                } else if (dadosVenda[i].planta[j].estoqueAtual > estoqueMinimo) {
                    printf("O estoque desta planta ainda eh suficiente!\n");
                } else if (dadosVenda[i].planta[j].estoqueAtual > estoqueIdeal) {
                    printf("O estoque desta planta esta acima do ideal!\n");
                    printf("---------------\n");
                }
            }
        }

    }
}

//funcao para realizar o cadastro de um cliente
void cadastraCLiente(tipoClientes dadosCliente[],int contaCliente) {

    printf("Entre com o nome do cliente %d:\n", contaCliente);
    fflush(stdin);
    gets(dadosCliente[contaCliente].nome);

    printf("Entre com o ID do cliente %d:\n",contaCliente);
    scanf("%d",&dadosCliente[contaCliente].ID);

    printf("Entre com o numero de telefone do cliente %d:\n", contaCliente);
    scanf("%d",&dadosCliente[contaCliente].telefone);

    printf("Entre com o logradouro do cliente %d:\n", contaCliente);
    fflush(stdin);
    gets(dadosCliente[contaCliente].endereco.logradouro);

    printf("Entre com a cidade do cliente %d:\n", contaCliente);
    fflush(stdin);
    gets(dadosCliente[contaCliente].endereco.cidade);

    printf("Entre com o bairro do cliente %d:\n",contaCliente);
    fflush(stdin);
    gets(dadosCliente[contaCliente].endereco.bairro);

    printf("Entre com o numero da residencia do cliente %d:\n", contaCliente);
    scanf("%d",&dadosCliente[contaCliente].endereco.numero);

    printf("Entre com o CEP,sem hifen e sem ponto, do cliente %d:\n", contaCliente);
    scanf("%d",&dadosCliente[contaCliente].endereco.cep);

}

//funcao para receber o mes atual
int recebeMes(){
    int mesAtual;
    printf("Entre com o mes atual: ");
    scanf("%d",&mesAtual);
    return mesAtual;
}

//funcao para calcular faturamento
void faturamento(){
    int i,j,result;
    result = recebeMes();
    float tabelaGanhos[12][4],tabelaGastos[12][4],tabelaLucro[12][4];
    float ganhoParcial=0.0,gastoParcial=0.0,lucroParcial=0.0;
    for(i=0;i<result;i++){
        for(j=0;j<4;j++){
            printf("Entre com os ganhos do mes %d,semana %d: ",i+1,j+1);
            scanf("%f",&tabelaGanhos[i][j]);
            ganhoParcial = ganhoParcial+tabelaGanhos[i][j];
        }
    }
    for(i=0;i<result;i++){
        for(j=0;j<4;j++){
            printf("Entre com os gastos do mes %d, semana %d: ",i+1,j+1);
            scanf("%f",&tabelaGastos[i][j]);
            gastoParcial = gastoParcial+tabelaGastos[i][j];
        }
    }
    for(i=0;i<result;i++){
        for(j=0;j<4;j++){
            tabelaLucro[i][j] = tabelaGanhos[i][j] - tabelaGastos[i][j];
            lucroParcial = lucroParcial+tabelaLucro[i][j];
        }
    }
    printf("Tabela de Lucros Parcias: \n");
    for(i=0;i<result;i++){
        printf("\n");
        for(j=0;j<4;j++){
            printf("%.2f ",tabelaLucro[i][j]);
        }
    }
    printf("\n");
    printf("Lucro parcial ate o mes %d = %.2f\n",i,lucroParcial);
    if(lucroParcial<ganhoParcial*0.6){
        printf("Lucro abaixo do esperado, tente economizar mais!\n");
    }
    else{
        printf("Lucro acima do esperado, continue assim!\n");
    }
}

//funcao para receber ID do cliente
int recebeClienteId(){
    int buscaID_cliente;
    printf("Entre com o ID do cliente procurado:\n");
    scanf("%d",&buscaID_cliente);
    return buscaID_cliente;
}

//funcao para printar a compra de algum cliente
void compraCliente(tipoVenda dadosVenda[],int contaVenda,tipoClientes dadosCliente[]){
    int i,j,clienteID;
    clienteID = recebeClienteId();
    for(i=1;i<contaVenda+1;i++){
        if(dadosVenda[i].ID == clienteID){
            printf("COMPRA DO CLIENTE %s:\n",clienteID);
            printf("DATA DA COMPRA: %d/%d/%d\n",dadosVenda[i].dataCompra.dia,dadosVenda[i].dataCompra.mes,dadosVenda[i].dataCompra.ano);
            printf("DATA DA ENTREGA/REALIZACAO DO PROJETO: %d/%d/%d\n",dadosVenda[i].dataEntrega.dia,dadosVenda[i].dataEntrega.mes,dadosVenda[i].dataEntrega.ano);
            printf("PLANTAS: \n");
            for(j=0;j<dadosVenda[i].qtdEspecies;j++){
                printf("ESPECIE: %s | QUANTIDADE: %d |\n",dadosVenda[i].planta[j].nome,dadosVenda[i].planta[j].qtdComprada);
            }
            printf("DADOS DO CLIENTE %s:\n",clienteID);
            printf("NOME: %s |\n TELEFONE: %d |\n ENDERECO: %s,%s,%s,%d,cep: %d\n",dadosCliente[i].nome,dadosCliente[i].telefone,
                   dadosCliente[i].endereco.logradouro,dadosCliente[i].endereco.bairro,
                   dadosCliente[i].endereco.cidade,dadosCliente[i].endereco.numero,dadosCliente[i].endereco.cep);
        }

    }
}
//funcao para imprimir lista de clientes
void imprimirClientes(tipoClientes dadosCliente[], int contaCliente){
    printf("---- CLIENTES ----\n");
    for(int i=0;i<contaCliente;i++){
        printf("\nCLIENTE %d:\n",i);
        printf("\n| NOME: %s | TELEFONE: %d | ID: %d | ENDERECO: %s %s %s %d %d",dadosCliente[i].nome,
               dadosCliente[i].telefone,dadosCliente[i].ID,dadosCliente[i].endereco.logradouro,
               dadosCliente[i].endereco.cidade,dadosCliente[i].endereco.bairro,dadosCliente[i].endereco.numero,
               dadosCliente[i].endereco.cep);
    }
}

#endif //EMPRESAPAISAGISMO_CCF110_EMPRESAPAISAGISMO_H
