#ifndef __ATTACK_H
#define __ATTACK_H


#include <string.h>
#include <stdlib.h>
#include <stdint.h>


void copy_tab ( uint8_t * h1 , uint8_t *h2 , int n ) ;
void find_col(uint8_t h[6], uint8_t m1[16], uint8_t m2[16]) ;
void attack(int d) ;



#endif
