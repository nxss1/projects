#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HISTORICO_SIZE 10

typedef struct {
    char operacao[50];
    double resultado;
} Historico;

void menu() {
    printf("\nCalculadora Avancada\n");
    printf("Selecione a operacao desejada:\n");
    printf("1. Adicao\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("5. Exponenciacao\n");
    printf("6. Raiz Quadrada\n");
    printf("7. Seno\n");
    printf("8. Cosseno\n");
    printf("9. Tangente\n");
    printf("10. Converter Graus para Radianos\n");
    printf("11. Converter Radianos para Graus\n");
    printf("12. Mostrar Historico\n");
    printf("0. Sair\n");
}

void adicionar_historico(Historico *historico, int *indice, const char *operacao, double resultado) {
    snprintf(historico[*indice].operacao, sizeof(historico[*indice].operacao), "%s", operacao);
    historico[*indice].resultado = resultado;
    *indice = (*indice + 1) % HISTORICO_SIZE;
}

void mostrar_historico(Historico *historico, int indice) {
    printf("\nHistorico de Calculos:\n");
    for (int i = 0; i < HISTORICO_SIZE; i++) {
        if (historico[i].resultado != 0) {
            printf("%dº: %s = %.2lf\n", i + 1, historico[i].operacao, historico[i].resultado);
        }
    }
}

int main() {
    int opcao;
    double num1, num2, resultado;
    Historico historico[HISTORICO_SIZE] = {0};
    int indice_historico = 0;
    
    do {
        menu();
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf\n", resultado);
                adicionar_historico(historico, &indice_historico, "Adicao", resultado);
                break;
            case 2:
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf\n", resultado);
                adicionar_historico(historico, &indice_historico, "Subtracao", resultado);
                break;
            case 3:
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf\n", resultado);
                adicionar_historico(historico, &indice_historico, "Multiplicacao", resultado);
                break;
            case 4:
                printf("Digite dois numeros: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf\n", resultado);
                    adicionar_historico(historico, &indice_historico, "Divisao", resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                }
                break;
            case 5:
                printf("Digite a base e o expoente: ");
                scanf("%lf %lf", &num1, &num2);
                resultado = pow(num1, num2);
                printf("Resultado: %.2lf\n", resultado);
                adicionar_historico(historico, &indice_historico, "Exponenciacao", resultado);
                break;
            case 6:
                printf("Digite um numero: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    resultado = sqrt(num1);
                    printf("Resultado: %.2lf\n", resultado);
                    adicionar_historico(historico, &indice_historico, "Raiz Quadrada", resultado);
                } else {
                    printf("Erro: Numero negativo nao tem raiz quadrada real.\n");
                }
                break;
            case 7:
                printf("Digite um angulo em graus: ");
                scanf("%lf", &num1);
                resultado = sin(num1 * M_PI / 180);
                printf("Seno de %.2lf graus: %.2lf\n", num1, resultado);
                adicionar_historico(historico, &indice_historico, "Seno", resultado);
                break;
            case 8:
                printf("Digite um angulo em graus: ");
                scanf("%lf", &num1);
                resultado = cos(num1 * M_PI / 180);
                printf("Cosseno de %.2lf graus: %.2lf\n", num1, resultado);
                adicionar_historico(historico, &indice_historico, "Cosseno", resultado);
                break;
            case 9:
                printf("Digite um angulo em graus: ");
                scanf("%lf", &num1);
                resultado = tan(num1 * M_PI / 180);
                printf("Tangente de %.2lf graus: %.2lf\n", num1, resultado);
                adicionar_historico(historico, &indice_historico, "Tangente", resultado);
                break;
            case 10:
                printf("Digite um angulo em graus: ");
                scanf("%lf", &num1);
                resultado = num1 * M_PI / 180;
                printf("%.2lf graus equivalem a %.2lf radianos\n", num1, resultado);
                adicionar_historico(historico, &indice_historico, "Graus para Radianos", resultado);
                break;
            case 11:
                printf("Digite um angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = num1 * (180 / M_PI);
                printf("%.2lf radianos equivalem a %.2lf graus\n", num1, resultado);
                adicionar_historico(historico, &indice_historico, "Radianos para Graus", resultado);
                break;
            case 12:
                mostrar_historico(historico, indice_historico);
                break;
            case 0:
                printf("Saindo da calculadora...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}