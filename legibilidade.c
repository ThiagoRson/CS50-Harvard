#include <stdio.h>
#include <string.h>

int main()
{
//Cria uma string para armazenar o texto inserido
char str[100];

//Ler uma linha de texto do usuário
printf("Enter some text: ");
fgets(str, 100, stdin);

//Inicializa a letra, sentenças e paravras começando do 0
int letter_count = 0;
int sentence_count = 0;
int word_count = 0;
float grade;
float l;
float s;

for (int i = 0; i < strlen(str); i++)
{
    //Se o caractere é uma letra, incremetará na conta da letra
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
    {
        letter_count++;
    }

    //Se o caractere é um ponto final, ponto de exclamação ou ponto de interrogação aumentará na conta da sentença
    if (str[i] == '.' || str[i] == '!' || str[i] == '?')
    {
        sentence_count++;
    }

    //Se o caractere é um espaço, incrementarar na contagem de palavra
    if (str[i] == ' ')
    {
        word_count++;
    }
}

//Incrementará a contagem das palavras por mais 1 até contar para a última palavra da string
word_count++;

//Printa a letra, sentença e contagem de palavras
printf("Letter count: %d\n", letter_count);
printf("Sentence count: %d\n", sentence_count);
printf("Word count: %d\n", word_count);

l = (float)letter_count/word_count;
s = (float)sentence_count/word_count;

//usa o teste de legibilidade de Coleman-Liau.
grade = 0.0588 * l * 100 - 0.296 * s * 100 - 15.8;

//informa a grade do leitor
printf("Grade: %.1f\n", grade);

return 0;
 }
