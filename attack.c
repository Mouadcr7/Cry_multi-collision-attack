#include "attack.h"
#include "xoshiro256starstar.h"
#include "node.h"
#include <stdint.h>

//#define SIZE 167772160 48 sec

#define SIZE 167772160


// #define SIZE 599999999
// #define SIZE 2

void copy_tab ( uint8_t * h1 , uint8_t *h2 , int n ){
    for (int i = 0; i < n; i++) {
      h2[i] = h1[i];
    }
}

void find_col(uint8_t h[6], uint8_t m1[16], uint8_t m2[16]){


  __my_little_xoshiro256starstar_unseeded_init();

  //uint64_t rand = xoshiro256starstar_random() ;


  uint8_t * h_temp = (uint8_t * ) malloc ( 6 * sizeof(uint8_t)) ;
  copy_tab (h , h_temp ,6 );

  node **  H = (node ** ) malloc ( SIZE  * sizeof(node * )) ;

  info * inf =  ( info * )malloc ( sizeof(info)) ;

  unsigned long int  * i  =    ( unsigned long int *) malloc ( sizeof (   unsigned long int )) ;;

  for ( int i = 0  ; i < SIZE ; i ++ ){
    H[i] = NULL ;
  }
  int p = 0 ;
  do {

    // if( H[0] ){
    //       printf("H[0] : encry %s   message : %s \n" ,H[0]->h,H[0]->message );

    // }    
    // if( H[1] ){
    //       printf("H[1] : encry %s   message : %s \n",H[1]->h,H[1]->message );

    // }
    uint64_t mfirst = xoshiro256starstar_random() ;
    uint64_t msecond = xoshiro256starstar_random() ;

    uint8_t * m = (uint8_t * ) malloc ( 16 * sizeof(uint8_t)) ;  ;
    memcpy ( m ,  &mfirst , 8 );
    memcpy ( m+8 ,  &msecond , 8 );

    tcz48_dm(m, h_temp);



 
    memcpy(i,h_temp,6);
    unsigned long int pos = (*i % SIZE) ;

    // printf("encryptage genere : %s\n",h_temp);
    // printf("message genere : %s\n",m);
    // if( H[pos] ){
    //       printf("H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );

    // }
    search_enc ( H[ pos ] , h_temp , m , inf) ;


      // printf("%d\n",p++ );



    if ( inf->state == ENC_NOT_FOUND){
      node * new = creat_node(h_temp,m );

      add_node_(H, new, pos  );

      // printf("apres add node H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );



    }
    else if( inf->state == ENC_FOUND ) {
      memcpy ( m1 ,  m , 16 );
      memcpy ( m2 ,  inf->message , 16 ); 
      return  ;
    }

    h_temp = (uint8_t * ) malloc ( 6 * sizeof(uint8_t)) ;
    copy_tab (h , h_temp , 6);
    

  } while(1);


}
