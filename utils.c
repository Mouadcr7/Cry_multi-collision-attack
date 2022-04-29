#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "utils.h"
#include <math.h>

void print_hexa_128(uint8_t *tab, char *separator)
{
  for (int i = 0; i < 16; i++)
  {
    printf("%02X", tab[i]);
  }
  if (separator)
  {
    printf("%c", *separator);
  }
}

void print_hexa_48(uint8_t *tab)
{
  for (int i = 0; i < 6; i++)
  {
    printf("%02X", tab[i]);
  }
}


void print_messages(int d, uint8_t *message0, uint8_t *message1, uint8_t *h, int size)
{
  uint8_t val = pow(2, d);
  for (uint8_t i = 0; i < val; i++)
  {
    for (int j = 0; j < d; j++)
    {
      int b = (i >> j) & 1;
      if (b == 0)
      {
        print_hexa_128(message0 + j * size, NULL);
      }
      else
      {
        print_hexa_128(message1 + j * size, NULL);
      }
    }
    printf(" ");
    print_hexa_48(h);
    printf("\n");
  }
}