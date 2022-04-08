#include <stdio.h>
#include <stdlib.h>
#include "attack.h"
#include "time.h"


int main(int argc, char const *argv[]) {

  uint8_t h[6] = { 0 ,0 ,0 ,0 ,0 ,0} ;
  uint8_t *m1 = malloc ( 16 * sizeof(uint8_t)) ;
  uint8_t *m2 = malloc ( 16 * sizeof(uint8_t)) ;

  find_col(h, m1,  m2) ;
  



  return 0;
}
