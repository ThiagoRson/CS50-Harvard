#include <cs50.h>
#include <stdio.h>

//Protótipo de função que declara para uso depois, askHeight, printBlok, and printRow, essas três funções resolvem os problemas principais discutidos
int askHeight(void);
void printBlok(int rowLength, int rowNumber);
void printRow(int height);

// Funções principais que se delega todo o trabalho
int main(void)
{
    //Aqui chamremos printRow e sustenta isso na altura, isto deixa saber qual altura fazer a pirâmide
    printRow(askHeight());
}

//Pergunte ao usuário pela altura, repita até o usuário dar o que queremos, um numero inteiro entre e incluindo 1-8
int askHeight(void)
{
    //Declara o bool para mudar uma vez por cada input colocado
    bool incorrect_input = true;
    //Declara uma variável de altura para armazenar nossa altura
    int height;
    //usa um loop enquanto guardar perguntando ao usuário pelos inputs deles até pegar o input correto
    while (incorrect_input)
    {
        //Usar get_int do cs50 para perguntar ao usuário pela altura deles e armazenar isso na altura
        height = get_int("Height: \n");
        //Se altura é maior do que 0 e menor do que 9 iremos mudar o incorrect_input boolen para falso, no qual parará enquanto loop
        if (height > 0 && height < 9)
        {
        //Coloca o incorrect_input boolean para falso
        incorrect_input = false;
      }
    }
    //Aqui retornaremos a altura para o pragrama usar porém gostamos, chamamos esta função, askHeight, irá colocar a altura sempre que chamada
    return height;
 }

 //Esta função printa os blocos ao longo da linha, há a probabilidade de mais maneiras de fazer isso, mas esta é uma delas, isso leva ao rowLength para determianr quantos blocos printar (vazio blocos & blocos regulares) e isso leva ao romNumber para determinar quantos blocos regulares são necessários sobre a linha própria que estamos focando
 void printBlok(int rowLength, int rowNumber)
{
    //Primeiro eu coloco uma quantia para contar o numero de bloco que estou atualmente colocando
    int blokCount = 0;

    //A maneira que eu imaginei isso foi printando espaços vazios onde estão faltando blocos, então essencialmente printar dois grandes retangulos e meio dos retangulos estão perdendo, então as variáveis de bloco vazio contadas os numeros de blocos vazios
    int emptyBloks = (rowLength - rowNumber) - 1;

    //Neste caso blocos completos poderão ser o inverso de blocos vazios
    int fullBloks = (rowLength - emptyBloks) - 1;

    //Variáveis que armazenam um numero do tamanho de linhas inteiras também conhecido como o tamanho de ambos os lados da piramide combinada, podendo ter doubled o rowLength, mas este caminho não precisa ser printado os blocos vazios sobre os lados certos da piramide
    int fullRowLength = (rowLength + fullBloks) + 1;

    //Enquanto meu blokCount(o bloco que está atualmente focando) é menor do que o fullRowLength nós iremos printar alguma coisa
    while (blokCount < fullRowLength)
    {
        //Se o blockCount é igual ao rowLength, signica, está no final da linha da pirâmide que aqui temos feito. Printaremos o ultimo bloco dessa linha e adicionaremos espaço para introduzir o vão entre as pirâmides
        if (blokCount == (rowLength - 1))
        {
            //Isto irá fazer o "printamento"
            printf("# ");
            //Muito importante, estes turnos de blocos iremos focar para o proximo bloco na linha
            blokCount++;
        }
        // Aqui printaremos um bloco e então moveremos para uma nova linha porque teremos alcançado o fullRowLength. Subitraremos 1 porque o blocoCount começa em 0.
        else if (blokCount == (fullRowLength - 1))
        {
            //Do mesmo modo que de cima, mas printamos um bloco e movemos para uma nova linha
            printf("#\n");
            //Incremente a contagem de bloco o qual foca no próximo bloco (neste caso irá parar o loop porque o bloco será igual a fullRowLength)
            blokCount++;
        }
        //Aqui checaremos se o blokCount tem superado o valor do emptyBlok, até emptyBloks é maior do que ou igual ao blockCount iremos apenas printar emptyBloks também conhecido como ESPAÇOS
        else if (blokCount < emptyBloks)
        {
            // Prints a space
            printf(" ");
            //mudança de foco no próximo bloco
            blokCount++;
        }
        // Se todas as condições acima não são conhecidas, significa, o slot que estamos focando não está no lado direito dentre a pirâmide e o blokCount é maior do que ou igual ao valor de emptyBlok iremos apenas printar um sozinho #
        else{
            //Mesmo como de cima
            printf("#");
            blokCount++;

        }
    }
}

//Aqui printaremos uma linha, pegaremos um argumento de altura e contaremos o printRow quantos totais de linhas printar
void printRow(int height)
{
    //rowCount continua caminhando em qual linha estamos
    int rowCount = 0;

    //Este loop chama printBlok parar printar as linhas até alcançar o valor da altura
    while (rowCount < height)
    {
        //Aqui atualizamos a chamada printBlock e alimentamos isso nas variáveis height e rowCount para funcionar com
        printBlok(height, rowCount);
        //Mudaremos nosso foco para a próxima linha
        rowCount++;
    }
}
