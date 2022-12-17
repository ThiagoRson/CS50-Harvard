#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Pontos atribuídos a cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    //Obtém palavras de entrada de ambos os jogadores
    string word1 = get_string("Jogador 1: ");
    string word2 = get_string("Jogador 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Jogador 1 ganha!\n");
    }
    else if (score2 > score1)
    {
        printf("Jogador 2 ganha!\n");
    }
    else
    {
        printf("É um empate!\n");
    }
}

int compute_score(string word)
{
    //Inicializa pontuação em 0
    int score = 0;

    //Iterar cada caractere na palavra
    for (int i = 0; i < strlen(word); i++)
    {
        //Obtém a versão minúscula do caractere
        char c = tolower(word[i]);

        //Verifica se o caractere é uma letra
        if (isalpha(c))
        {
            //Adiciona o valor do ponto correspondente à pontuação
            score += POINTS[c - 'a'];
        }
    }

    //Retorna a pontuação
    return score;
}
