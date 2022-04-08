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



info *  search_enc ( node * n , uint8_t * h , uint8_t * message ){
  info * inf = malloc ( sizeof(info))  ;
  inf->state = NOT_FOUND ;

  while(n){
    int b1 = 1 ;
    for ( int i = 0 ; i < 6 ; i++ ){
      if ( (uint8_t) (*((n->h)+i)) != (uint8_t)(*(h+i))  ){
        b1 = 0 ; // not the same encryption ==> keep searching in the next nodes
        break ;
      }

    }
    if ( b1 == 1 ) {
      // same encription
      // look if this is a different message first !
      for (int i=0 ; i< 16 ; i++ ){
        if ( (uint8_t)(*((n->message)+i)) != (uint8_t)(*(message+i))  ){
           // same encription with different messages => collision
           inf->state = FOUND ;
           inf->message = n->message ;
           printf("COLLISIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOON \n");

           return inf ;
        }
      }
      return NULL ; // the message is already saved

    }
    else {
      n = n->next ;
    }
  }
  return inf ;
}
