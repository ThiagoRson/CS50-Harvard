#include <stdio.h>
#include <cs50.h>

int main(void) {
  int initial = get_int("População inicial: ");
  int final = get_int("População final: ");

  int years = 0; //Numero de tempo necessário para alcançar a população final
  int current = initial; //População atual

  while (current < final) {
    current += current * 0.08355; //Aumenta a população em 8,355%
    years++;  //Soma os anos
  }

 while (years < 1) {
    final = get_int("Coloque uma população maior do que a inicial: ");
    current += current * 0.08355; //Aumenta a população em 8,355%
    years++;  //Soma os anos
     }

if (years > 1){
  printf("Isso leva %d ano(s) para alcançar uma população de %d com a população de %d\n", years, final, initial);
 }else{
   printf("Isso leva 1 ano ou menos para alcançar uma população de %d com a população de %d\n", final, initial);
 }
  return 0;
}
