#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Struct para os carros
struct Tcarro {
    char modelo[30];
    char placa[30];
    char cor[30];
};

// Funções
int fun_decre(int *fila);
int fun_incre(int *fila);
void flush_in();
float calcValor(float preco, float qtd);
int fun_invalidos(float prEta, float prGas, float prAdit, float tFila);
int fun_escreva();
char Fun_Tcar;

// MAIN
int main(void) {
    // VARIÁVEIS
    float prEta = 1, prGas = 1, prAdit = 1, qtdEta, qtdGas, qtdAdit, valRec;
    int CAtendido, tFila = 1;
    float etaRestante = 200, gasRestante = 200, aditRestante = 200;
    int fila = 0, opcao, relatorio, menu, tam, cont = 1;

    printf("--------------------------------------------------------------------------------\n\n");
    printf("Bem vindo ao programa de abastecimento do posto de gasolina! Nosso programa facilita o abastecimento para nossos clientes.\n\n");
    printf("--------------------------------------------------------------------------------\n\n");

    fun_invalidos(prEta, prGas, prAdit, tFila);

    printf("\nDigite o preço do etanol: ");
    scanf("%f", &prEta);

    printf("\nDigite o preço da gasolina: ");
    scanf("%f", &prGas);

    printf("\nDigite o preço da gasolina aditivada: ");
    scanf("%f", &prAdit);

    printf("\nInforme o tamanho da fila que o estabelecimento suportará: ");
    scanf("%f", &tFila);

    while (prEta < 0 || prGas < 0 || prAdit < 0 || tFila <= 0);

    struct Tcarro carros[tam];
    do {
        menu = fun_escreva();

        switch (menu) {
            case 1:
                system("clear");
                if (fila <= tFila) {
                    fun_incre(&fila);
                    flush_in();

                    printf("\nDigite o modelo do carro:\n ");
                    fgets(carros[cont].modelo, 30, stdin);

                    printf("\nDigite a cor do carro:\n ");
                    fgets(carros[cont].cor, 30, stdin);

                    printf("\nDigite a placa do carro:\n ");
                    fgets(carros[cont].placa, 30, stdin);

                    printf("\nModelo do carro: %s\nCor do carro: %s\nPlaca do carro: %s",
                           carros[cont].modelo, carros[cont].cor, carros[cont].placa);
                    cont++;

                    printf("\nCarro adicionado\n");
                } else {
                    printf("\nFila cheia\n");
                }
                break;

            case 2:
                system("clear");
                if (fila > 0) {
                    printf("\nDigite a quantidade vendida do etanol: ");
                    scanf("%f", &qtdEta);
                    etaRestante = etaRestante - qtdEta;

                    printf("\nDigite a quantidade vendida da gasolina comum: ");
                    scanf("%f", &qtdGas);
                    gasRestante = gasRestante - qtdGas;

                    printf("\nDigite a quantidade vendida da gasolina aditivada: ");
                    scanf("%f", &qtdAdit);
                    aditRestante = aditRestante - qtdAdit;

                    CAtendido = CAtendido + 1;
                    printf("\nCarros atendidos: %d.\n", CAtendido);
                    printf("Carro abastecido\n");
                } else {
                    printf("\nA fila está vazia! Adicione um carro antes de abastecer.\n");
                }
                break;

            case 3:
                system("clear");
                if (fila > 0)
                    fila = fila - 1;
                printf("\nPróximo cliente chamado");
                else
                    printf("\nA fila está vazia! Adicione um carro antes de abastecer.");
                break;

            case 4:
                do {
                    printf("--------------------------------------------------------------------------------\n\n");
                    printf("1 - Quantidade de litros vendida (por tipo de combustível)\n");
                    printf("2 - Valor total arrecadado com as vendas (por tipo de combustível)\n");
                    printf("3 - Quantidade de carros atendidos\n");
                    printf("4 - Quantidade de combustível restante em cada tanque\n");
                    printf("5 - Voltar ao menu anterior\n\n");
                    printf("--------------------------------------------------------------------------------\n\n");
                    printf("Informe a opção: ");
                    scanf("%d", &relatorio);

                    switch (relatorio) {
                        case 1:
                            system("clear");
                            printf("A quantidade de litros vendida foi: Etanol: %.2f\nGasolina Comum: %.2f \nGasolina Aditivada: %.2f\n",
                                   qtdEta, qtdGas, qtdAdit);
                            break;

                        case 2:
                            system("clear");
                            valRec = calcValor(prEta, qtdEta) + calcValor(prGas, qtdGas) + calcValor(prAdit, qtdAdit);
                            printf("Valor total arrecadado com as vendas foi: %.2f\n", valRec);
                            break;

                        case 3:
                            system("clear");
                            printf("%d carros foram atendidos\n", CAtendido);
                            break;

                        case 4:
                            system("clear");
                            printf("%.2f litros restante de Etanol\n %.2f litros restante de Gasolina Comum\n %.2f litros restante de Gasolina Aditivada",
                                   etaRestante, gasRestante, aditRestante);
                            break;

                        default:
                            printf("Opção inválida\n");
                    }
                } while (relatorio != 5);
                break;

            case 5:
                system("clear");
                printf("\nPrograma encerrado\n");
                break;

            default:
                system("clear");
                printf("\nOpção inválida\n");
        }
    } while (menu != 5);

    return 0;
}

// Funções
float calcValor(float preco, float qtd) {
    return preco * qtd;
}

int fun_invalidos(float prEta, float prGas, float prAdit, float tFila) {
    if (prEta < 0)
        printf("\nValor do preço do Etanol inválido!\nDigite o preço novamente\n");
    if (prGas < 0)
        printf("\nValor do preço da Gasolina inválido!\nDigite o preço novamente\n");
    if (prAdit < 0)
        printf("\nValor do preço da Gasolina Aditivada inválido!\nDigite o preço novamente\n");
    if (tFila <= 0)
        return printf("\nInforme um número para a fila válido!\n");
    return 0;
}

int fun_escreva(int opcao) {
    printf("\nPrograma para melhor experiência dos clientes do posto de gasolina\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("1 - Adicionar um carro na fila\n");
    printf("2 - Abastecimento\n");
    printf("3 - Chamar o próximo\n");
    printf("4 - Relatórios\n");
    printf("5 - Encerrar\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Informe a opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void flush_in() {
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
}

int fun_incre(int *fila) {
    *fila = *fila + 1;
    printf("\nNúmero de carros na fila: %d\n", *fila);
    return *fila;
}

int fun_decre(int *fila) {
    *fila = *fila - 1;
    printf("\nNúmero de carros na fila: %d\n", *fila);
    return *fila;
}
