#include "attack.h"
#include "xoshiro256starstar.h"
#include "node.h"
#include <stdint.h>
//#define SIZE 16777216
#define SIZE 2

void copy_tab ( uint8_t * h1 , uint8_t *h2 , int n ){
    for (int i = 0; i < n; i++) {
      h2[i] = h1[i];
    }
}

void find_col(uint8_t h[6], uint8_t m1[16], uint8_t m2[16]){

  uint64_t seed[4] = {0,1,2,3} ;
  xoshiro256starstar_random_set(seed) ;

  //uint64_t rand = xoshiro256starstar_random() ;


  uint8_t * h_temp = (uint8_t * ) malloc ( 6 * sizeof(uint8_t)) ;
  copy_tab (h , h_temp ,6 );

  node **  H = (node ** ) malloc ( SIZE  * sizeof(node * )) ;
  for ( int i = 0  ; i < SIZE ; i ++ ){
    H[i] = creat_node(0,0); 
  }
  int p = 0 ;
  do {

    if( H[0] ){
          printf("H[0] : encry %s   message : %s \n" ,H[0]->h,H[0]->message );

    }    
    if( H[1] ){
          printf("H[1] : encry %s   message : %s \n",H[1]->h,H[1]->message );

    }
    uint64_t mfirst = xoshiro256starstar_random() ;
    uint64_t msecond = xoshiro256starstar_random() ;

    uint8_t m[16] ;
    memcpy ( m ,  &mfirst , 8 );
    memcpy ( m+8 ,  &msecond , 8 );

    tcz48_dm(m, h_temp);



    unsigned long int * i = malloc ( sizeof(unsigned long int));
    memcpy(i,h_temp,6);
    unsigned long int pos = (*i % SIZE) ;

    printf("encryptage genere : %s\n",h_temp);
    printf("message genere : %s\n",m);
    if( H[pos] ){
          printf("H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );

    }
    info * inf =  search_enc ( H[ pos ] , h_temp , m ) ;





    if ( inf  && inf->state == NOT_FOUND){
      //printf("%d\n",p++ );
      node * new = creat_node(h_temp,m );

      
      add_node_(  new ,   H[ pos ] );
      printf("apres add node H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );



    }
    else if( inf  && inf->state == FOUND ) {
      m1 = m ;
      m2 = inf->message ;
      break ;
    }


    copy_tab (h , h_temp , 6);
    p++ ;

  } while(p <= 6);


}
