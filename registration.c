#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gerar_senha(int comprimento, int incluir_maiusculas, int incluir_minusculas, int incluir_numeros, int incluir_especiais) {
    char senha[comprimento + 1]; // +1 para o caractere nulo
    char caracteres[100]; // Array para armazenar os caracteres permitidos
    int index = 0;

    // Adiciona caracteres ao conjunto com base nas opções do usuário
    if (incluir_maiusculas) {
        for (char c = 'A'; c <= 'Z'; c++) {
            caracteres[index++] = c;
        }
    }
    if (incluir_minusculas) {
        for (char c = 'a'; c <= 'z'; c++) {
            caracteres[index++] = c;
        }
    }
    if (incluir_numeros) {
        for (char c = '0'; c <= '9'; c++) {
            caracteres[index++] = c;
        }
    }
    if (incluir_especiais) {
        char especiais[] = "!@#$%^&*()-_=+[]{}|;:,.<>?/";
        for (int i = 0; i < strlen(especiais); i++) {
            caracteres[index++] = especiais[i];
        }
    }

    // Verifica se pelo menos um tipo de caractere foi selecionado
    if (index == 0) {
        printf("Erro: Pelo menos um tipo de caractere deve ser selecionado.\n");
        return;
    }

    caracteres[index] = '\0'; // Adiciona o caractere nulo ao final da string

    // Gera a senha aleatória
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    for (int i = 0; i < comprimento; i++) {
        senha[i] = caracteres[rand() % index]; // Seleciona um caractere aleatório
    }
    senha[comprimento] = '\0'; // Adiciona o caractere nulo ao final da senha

    printf("Sua senha gerada é: %s\n", senha);
}

int main() {
    int comprimento;
    int incluir_maiusculas, incluir_minusculas, incluir_numeros, incluir_especiais;

    printf("Bem-vindo ao gerador de senhas seguras!\n");

    // Solicita as opções do usuário
    printf("Digite o comprimento da senha desejada: ");
    scanf("%d", &comprimento);
    printf("Incluir letras maiúsculas? (1 para sim, 0 para não): ");
    scanf("%d", &incluir_maiusculas);
    printf("Incluir letras minúsculas? (1 para sim, 0 para não): ");
    scanf("%d", &incluir_minusculas);
    printf("Incluir números? (1 para sim, 0 para não): ");
    scanf("%d", &incluir_numeros);
    printf("Incluir caracteres especiais? (1 para sim, 0 para não): ");
    scanf("%d", &incluir_especiais);

    // Gera a senha com base nas opções do usuário
    gerar_senha(comprimento, incluir_maiusculas, incluir_minusculas, incluir_numeros, incluir_especiais);

    return 0;
}