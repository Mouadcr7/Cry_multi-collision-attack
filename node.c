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

  
  // if ( n && n-> next ){
  //     new->next = n->next ;
  //     n->next = new ;
  // }
  // else{
  //   n->h = new->h ;
  //   n->message = new->message ;
  // }


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
    // for ( int i = 0 ; i < 6 ; i++ ){
    //   if ( (uint8_t) (*((n->h)+i)) != (uint8_t)(*(h+i))  ){
    //     b1 = 0 ; // not the same encryption ==> keep searching in the next nodes
    //     break ;
    //   }

    // }    
    
     if ( comparaison_tab ( n->h , h , 48  )  ){
        b1 = 0 ; // not the same encryption ==> keep searching in the next nodes
      }     
    
    // if ( *((uint32_t*)(n->h)) != *((uint32_t*)(h)) ||  *((uint16_t*)(n->h+4)) != *((uint16_t*)(h+4))  ){
    //     b1 = 0 ; // not the same encryption ==> keep searching in the next nodes
    // }

    if ( b1 == 1 ) {
      // same encription
      // look if this is a different message first !



      // for (int i=0 ; i< 2 ; i++ ){
      //   if ( *((uint64_t *)((n->message)+(64*i))) != *((uint64_t *)((message)+(64*i)))  ){
      //      // same encription with different messages => collision
      //      inf->state = ENC_FOUND ;
      //      inf->message = n->message ;
      //      printf("COLLISIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOON \n");

      //      return;
      //   }
      // }

     if ( comparaison_tab ( n->message, message , 128  )  ){

          // same encription with different messages => collision
           inf->state = ENC_FOUND ;
           inf->message = n->message ;

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
