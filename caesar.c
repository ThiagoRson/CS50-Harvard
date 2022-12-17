#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET_LENGTH 26

void caesar_cipher(char* plaintext, int shift, char* ciphertext) {
    //Iterar sobre os caracteres de texto simples e deslocá-los
    for (int i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            //Mude o caractere se for uma letra
            if (isupper(c)) {
                ciphertext[i] = 'A' + (c - 'A' + shift) % ALPHABET_LENGTH;
            } else {
                ciphertext[i] = 'a' + (c - 'a' + shift) % ALPHABET_LENGTH;
            }
        } else {
            //Caso contrário, basta anexar o caractere ao texto cifrado
            ciphertext[i] = c;
        }
    }
}

int main(int argc, char* argv[]) {
    //Leia o valor de deslocamento na linha de comando
    int shift = atoi(argv[1]);

    //Leia o texto simples do usuário
    char plaintext[256];
    printf("Digite uma mensagem para criptografar: ");
    fgets(plaintext, 256, stdin);

    //Remova o caractere de nova linha do final da string
    plaintext[strcspn(plaintext, "\n")] = '\0';

    //Inicialize o texto cifrado como uma string vazia
    char ciphertext[256] = "";

    //Criptografe o texto simples e armazene o resultado no texto cifrado
    caesar_cipher(plaintext, shift, ciphertext);

    //Imprimir o texto cifrado
    printf("texto cifrado: %s\n", ciphertext);

    return 0;
}
