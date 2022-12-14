// Contador de menor troco possível em moedas de 25,10,5,1 centavos

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float askPositiveFloat(void)
{
//Perguntar usário com double
float positiveFloat;
//Negar até ficar positivo, basicamente uma troca de turn on e turn off
bool negative = true;
//Loops a questão até dar a você uma boa resposta
while (negative)
{
//Get_float irá automaticamente filtrar numeros não decimais mas não filtrar os negativos
positiveFloat = get_float("Troco devido: ");
//Chegar por negativos
if (positiveFloat > 0)
{
//Colocar falso se nosso número é positivo
negative = false;
}
}
//como prometido, nós retornamos o float positiveFloat
return positiveFloat;
}

//Esta função irá performar o caminho das moedas que nós temos contado e retornar isso como uma integral
int coinNum()
{
//Pegar o input do usuário e retornar isso em número total de centavos, nós iremos falar para arredondar com uma função de math.h
int totalCents = round(askPositiveFloat()*100);
//Declara a variável no armazenamento de contagem de moeda
int numOfCoins = 0;
//Declara a variável para o armazenamento restante
int remainder;
//Declara a variável por num numero temporário para divisão
int tempNum;
//Declara as variáveis para o armazenamento de valores da moeda
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

//Iremos apenas colocar em castata uma lista de moedas das grandes para menores, tudo com basicamente a mesma fórmula

//Se totalCents é maior do que OR EQUAL TO o valor é de um quarter (25)
if (totalCents >= quarter)
{
    //usaremos matematica modular para ver quantos quartes(25) cabem dentro do nosso totalCents, esto irá guardar as sobras dentro do nosso restante também conhecido como 16 = 41 % 25
    remainder = totalCents % quarter;
    //Aqui faremos uma variável temporária que armazena o valor de 25 centavos, terminaremos usando para cobrir o totalCents sem ser passar por cima da quantia totalCents
    tempNum = totalCents - remainder;
    //Então dividiremos o tempNum pelo nosso valor de 25 centavos para pegar o número de moedas também conhecido como 0 + 75 / 25 = 3 moedas, e então adicionaremos isso ao nosso caminho de numero numofCoins
    numOfCoins = numOfCoins + (tempNum / quarter);
    //Aqui podemos colocar nosso totalCents como igual ao nosso restante até terminamos com essa etapa
    totalCents = remainder;
}
// Para a próxima moeda podemos seguramente chegar por elas e usar a mesma fórmula na sequência até o final da função
if (totalCents >= dime)
{
    remainder = totalCents % dime;
    tempNum = totalCents - remainder;
    numOfCoins = numOfCoins + (tempNum / dime);
    totalCents = remainder;
}
if (totalCents >= nickel)
{
    remainder = totalCents % nickel;
    tempNum = totalCents - remainder;
    numOfCoins = numOfCoins + (tempNum / nickel);
    totalCents = remainder;
}
if (totalCents >= penny)
{
    remainder = totalCents % penny;
    tempNum = totalCents - remainder;
    numOfCoins = numOfCoins + (tempNum / penny);
    totalCents = remainder;
}
// como prometido retornamos uma integral de numOfCoins
return numOfCoins;
}
int main(void)
{
    //podemos usar a função printf e chamar coinNum() sem a função dela mesma
    printf("%i\n", coinNum());
}
