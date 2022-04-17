#ifndef __ATTACK_H
#define __ATTACK_H


#include <stdint.h>

/*
    * searches for a collision for the compression function tcz48_ 
    * Input m1: a 128-bit message block
    * Input m2: a 128-bit message block
    * Input h: a 48-bit chaining value
    * Output: void, h is overwritten with the result, m1 and m2 are overwritten with the result 
*/

void find_col(uint8_t h[6], uint8_t m1[16], uint8_t m2[16]) ;

/*
    * Input d: Integer
    * Output: void, writes on the standard output a list of 2d colliding message
*/
void attack(int d) ;



#endif
