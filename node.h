#ifndef __NODE_H
#define __NODE_H
#include <stdint.h>


typedef struct node {
  struct node * next ;
  uint8_t * h ;
  uint8_t * message ;
} node ;

enum STATE { ENC_NOT_FOUND , ENC_FOUND , MSG_EXIST  };

typedef struct info {
  enum STATE state ;
  node *  result ;
} info ;

node * creat_node(uint8_t * h , uint8_t * message );



void add_node_( node ** H , node * new , int pos  );




uint8_t * first_element( node * n ) ;



uint8_t * second_element( node * n ) ;


int comparaison_tab ( uint8_t  * tab1 , uint8_t * tab2 , int size  ) ;


void search_enc ( node * n , uint8_t * h , uint8_t * message , info *  inf);



void free_list( node * n );


#endif
