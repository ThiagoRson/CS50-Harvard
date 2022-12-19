#include <stdio.h>
#include <string.h>

int main(void) {
// Pedir ao usuário o número de candidatos
int numCandidatos;
printf("Quantos candidatos há na votação? ");
scanf("%d", &numCandidatos);

// Criar um vetor de strings para armazenar os nomes dos candidatos
char nomes[numCandidatos][50];

// Pedir ao usuário para informar os nomes dos candidatos
for (int i = 0; i < numCandidatos; i++) {
printf("Informe o nome do candidato %d: ", i + 1);
scanf("%s", nomes[i]);
}

// Criar um vetor para armazenar os votos
int votos[numCandidatos];

// Inicializar o vetor de votos com 0
for (int i = 0; i < numCandidatos; i++) {
votos[i] = 0;
}

// Pedir ao usuário para votar em cada candidato
for (int i = 0; i < numCandidatos; i++) {
printf("Em quem o candidato %d vota? ", i + 1);
char voto[50];
scanf("%s", voto);

// Procurar o índice do candidato escolhido pelo usuário
int indice = -1;
for (int j = 0; j < numCandidatos; j++) {
  if (strcmp(voto, nomes[j]) == 0) {
    indice = j;
    break;
  }
}

// Incrementar o voto do candidato escolhido, se ele foi encontrado
if (indice != -1) {
  votos[indice]++;
}
}

// Exibir o resultado da votação
printf("Resultado da votação:\n");
for (int i = 0; i < numCandidatos; i++) {
printf("Candidato %s: %d votos\n", nomes[i], votos[i]);
}
// Encontrar o candidato vencedor
int indiceVencedor = 0;
for (int i = 1; i < numCandidatos; i++) {
if (votos[i] > votos[indiceVencedor]) {
indiceVencedor = i;
}
}

// Exibir o vencedor para o usuário
printf("O vencedor da votação foi o candidato %s com %d votos\n", nomes[indiceVencedor],votos[indiceVencedor]);

return 0;
}
