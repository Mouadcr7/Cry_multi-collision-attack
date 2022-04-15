#ifndef __UTILS_H
#define __UTILS_H

#include <stdint.h>

void copy_tab ( uint8_t * h1 , uint8_t *h2 , int n );

void print_hexa_128(uint8_t *tab);

void print_hexa_48(uint8_t *tab);

uint8_t getRandom(int lower, int upper) ;


#endif