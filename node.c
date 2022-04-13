#include <stdlib.h>
#include "node.h"
#include <stdio.h>



node * creat_node(uint8_t * h , uint8_t * message ){
  node * new = malloc(sizeof(node));
  if ( !new ) return NULL ;
  new -> next = NULL ;
  new -> h = h ;
  new -> message = message ;
  return new ;
}

void add_node_( node ** H , node * new , int pos  ){


  if ( H[pos] ){
    new->next = H[pos] ;
  }
  H[pos] = new ;

}


uint8_t * first_element( node * n ){
  if ( ! n ) return NULL ;
  return n->h ;
}



uint8_t * second_element( node * n ){
    if ( ! n ) return NULL ;
  return n->message ;
}



int comparaison_tab ( uint8_t  * tab1 , uint8_t * tab2 , int size  ){

  if ( size == 48 ){
    return *((uint32_t*)(tab1)) != *((uint32_t*)(tab2)) ||  *((uint16_t*)(tab1+4)) != *((uint16_t*)(tab2+4)) ; 
  }

    return  *((uint64_t *)((tab1))) != *((uint64_t *)((tab2))) ||  *((uint64_t *)(tab1+64)) != *((uint64_t *)((tab2 + 64)))  ;     
}



void search_enc ( node * n , uint8_t * h , uint8_t * message , info *  inf){

  inf->state = ENC_NOT_FOUND ;

  while(n){
    int b1 = 1 ;

    
     if ( comparaison_tab ( n->h , h , 48  )  ){
        b1 = 0 ; // not the same encryption ==> keep searching in the next nodes
      }     
    


    if ( b1 == 1 ) {
      // same encription
      // look if this is a different message first !

     if ( comparaison_tab ( n->message, message , 128  )  ){

          // same encription with different messages => collision
           inf->state = ENC_FOUND ;
           inf->result  = n ;

           return;

      }     
      
      inf->state = MSG_EXIST ;
      return ; // the message is already saved

    }
    else {
      n = n->next ;
    }
  }
  return ;
}




void free_list( node * n ){
  while (n){
    node * temp = n->next ;
    free ( n ->h ) ;
    free ( n->message ) ;
    free ( n ) ;
    n = temp ;
  }
}

void free_hash( node ** H  , int size ) {
  for ( int i = 0 ; i< size ; i++){
    if (H[i]){
      free_list(H[i]);
    }
  }
  free (H);
}
