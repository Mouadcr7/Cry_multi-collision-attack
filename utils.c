#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "utils.h"




void copy_tab ( uint8_t * h1 , uint8_t *h2 , int n ){
    for (int i = 0; i < n; i++) {
      h2[i] = h1[i];
    }
}



void print_hexa_128(uint8_t *tab)
{
  for (int i = 0; i < 16; i++)
  {
    printf("%02x", tab[i]);
  }
  printf("\t");
}

void print_hexa_48(uint8_t *tab)
{
  for (int i = 0; i < 6; i++)
  {
    printf("%02x", tab[i]);
  }
  printf("\t");
}

uint8_t getRandom(int lower, int upper)
{

  uint8_t num = (rand() %
                 (upper - lower + 1)) +
                lower;

  return num;
}