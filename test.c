#include <stdio.h>
#include <stdlib.h>
#include "attack.h"
#include "time.h"


int main(int argc, char const *argv[]) {





  clock_t begin = clock();

  uint8_t h[6] = { 0 ,0 ,0 ,0 ,0 ,0} ;
  uint8_t *m1 = malloc ( 16 * sizeof(uint8_t)) ;
  uint8_t *m2 = malloc ( 16 * sizeof(uint8_t)) ;

  find_col(h, m1,  m2) ;
  clock_t end = clock();
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("%x %x %f\n",m1,m2,time_spent );



  return 0;
}
