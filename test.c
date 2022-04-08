#include <stdio.h>
#include <stdlib.h>
#include "attack.h"
#include "time.h"
#include "mc48.h"


int main(int argc, char const *argv[]) {





  clock_t begin = clock();

  uint8_t h1[6] = { 0 ,0 ,0 ,0 ,0 ,0} ;
  uint8_t h2[6] = { 0 ,0 ,0 ,0 ,0 ,0} ;
  uint8_t *m1 = malloc ( 16 * sizeof(uint8_t)) ;
  uint8_t *m2 = malloc ( 16 * sizeof(uint8_t)) ;

  find_col(h1, m1,  m2) ;
  clock_t end = clock();
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("%x %x %f\n",*m1,*m2,time_spent );
  tcz48_dm(m1, h1);
  tcz48_dm(m2, h2);

  printf("h1 for m1 is %x & h2 for m2 is %x \n",*h1,*h2);




  return 0;
}
