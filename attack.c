#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "attack.h"
#include "xoshiro256starstar.h"
#include "mc48.h"
#include "node.h"
#include "utils.h"

//#define SIZE 167772160 48 sec

#define SIZE 167772160


// #define SIZE 599999999
// #define SIZE 2



void find_col(uint8_t h[6], uint8_t m1[16], uint8_t m2[16]){


  __my_little_xoshiro256starstar_unseeded_init();

  //uint64_t rand = xoshiro256starstar_random() ;


  uint8_t * h_temp = (uint8_t * ) malloc ( 6 * sizeof(uint8_t)) ;
  copy_tab (h , h_temp ,6 );

  node **  H = (node ** ) malloc ( SIZE  * sizeof(node * )) ;



  info inf ;

  unsigned long int   i ;

  for ( int i = 0  ; i < SIZE ; i ++ ){
    H[i] = NULL ;
  }
  //int p = 0 ;
  do {
    uint64_t mfirst = xoshiro256starstar_random() ;
    uint64_t msecond = xoshiro256starstar_random() ;

    uint8_t * m = (uint8_t * ) malloc ( 16 * sizeof(uint8_t)) ;  ;
    memcpy ( m ,  &mfirst , 8 );
    memcpy ( m+8 ,  &msecond , 8 );

    tcz48_dm(m, h_temp);



 
    memcpy(&i,h_temp,6);
    unsigned long int pos = (i % SIZE) ;

    // printf("encryptage genere : %s\n",h_temp);
    // printf("message genere : %s\n",m);
    // if( H[pos] ){
    //       printf("H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );

    // }
    search_enc ( H[ pos ] , h_temp , m , &inf) ;


      // printf("%d\n",p++ );



    if ( inf.state == ENC_NOT_FOUND){
      node * new = creat_node(h_temp,m );

      add_node_(H, new, pos  );

      // printf("apres add node H[%ld] : encry %s   message : %s \n",pos ,H[pos]->h,H[pos]->message );



    }
    else if( inf.state == ENC_FOUND ) {
      memcpy ( m1 ,  m , 16 );
      memcpy ( m2 ,  inf.result->message , 16 ); 
      memcpy ( h ,  inf.result->h , 6 ); 

      free_hash( H  , SIZE ) ; 
      return  ;
    }

    h_temp = (uint8_t * ) malloc ( 6 * sizeof(uint8_t)) ;
    copy_tab (h , h_temp , 6);
    

  } while(1);


}



void attack(int d) {
  uint8_t h[6] = {IVB0 ,IVB1 ,IVB2 ,IVB3 ,IVB4 ,IVB5} ;
  uint8_t m1[16] ;
  uint8_t m2[16] ;

  //uint8_t * message1 = ( uint8_t * ) malloc ( d * 16  * sizeof(uint8_t)  );
  //uint8_t * message2 = ( uint8_t * ) malloc ( d * 16  * sizeof(uint8_t)  );

  for (int i = 0; i < d ; i++)
  {
    clock_t begin = clock();

    find_col(h , m1, m2) ;
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    //memcpy(message1+16*i , m1 , 16) ;
    //memcpy(message2+16*i , m2 , 16) ;

    print_hexa_128(m1);
    print_hexa_128(m2);
    printf("%f\n", time_spent);
  }
  

  //free(message1) ;
  //free(message2) ;

  
  return ;
}
