#ifndef __UTILS_H
#define __UTILS_H

#include <stdint.h>


/*
    * Print an array tab of 128 bits in hexa format, followed by separator if separator is not null.
*/
void print_hexa_128(uint8_t *tab, char  * separator );

/*
    * Print an array tab of 48 bits in hexa format.
*/
void print_hexa_48(uint8_t *tab);

/*
    * Return a random integer uint8_t between lower and upper.
*/
uint8_t getRandom(int lower, int upper) ;

/*
    * Print a list of  2^d collisions messages followed by the encryption h.
    * if d=2 , message0 = [a,b] , message1 = [c,d] , h = x 
    * The output is : 
        ab h
        ad h
        cd h
        cb h
*/
void print_messages(int d , uint8_t * message0 , uint8_t * message1 , uint8_t * h ,int size  ) ;


#endif