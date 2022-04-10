#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "attack.h"
#include "time.h"
#include "mc48.h"



void print_hexa_128(uint8_t *tab) {
  for (int i = 0; i < 16; i++)
  {
    printf("%02x",tab[i]);
  }
  printf("\t");
  
}

void print_hexa_48(uint8_t *tab) {
  for (int i = 0; i < 6; i++)
  {
    printf("%02x",tab[i]);
  }
  printf("\t");
  
}

int main(int argc, char const *argv[]) {





  clock_t begin = clock();

  // uint8_t h1[6] = { IVB0 ,IVB1 ,IVB2 ,IVB3 ,IVB4 ,IVB5} ;
  // uint8_t h2[6] = { IVB0 ,IVB1 ,IVB2 ,IVB3 ,IVB4 ,IVB5} ;

  uint8_t h1[6] = { 0X12 ,0X59 ,0XA2 ,0XBC ,0XFF ,0X08} ;
  uint8_t h2[6] = { 0X12 ,0X59 ,0XA2 ,0XBC ,0XFF ,0X08} ;


  uint8_t *m1 = malloc ( 16 * sizeof(uint8_t)) ;
  uint8_t *m2 = malloc ( 16 * sizeof(uint8_t)) ;

  find_col(h1, m1,  m2) ;
  clock_t end = clock();
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  

  print_hexa_128(m1);
  print_hexa_128(m2);
  printf("%f\n",time_spent);
  print_hexa_128(m1);
  print_hexa_48(h1);
  printf("\n");
  print_hexa_128(m2);
  print_hexa_48(h1);
  printf("\n");



  printf("****************************************\n");
  tcz48_dm(m1, h1);
  tcz48_dm(m2, h2);

  printf("h1 ==== ");
  print_hexa_48(h1);
  printf("\n");
  printf("h2 ==== ");
  print_hexa_48(h2);

  printf("\n");




  return 0;
}

