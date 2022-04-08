#ifndef __NODE_H
#define __NODE_H
#include <stdint.h>


typedef struct node {
  struct node * next ;
  uint8_t * h ;
  uint8_t * message ;
} node ;

enum STATE { NOT_FOUND , FOUND };

typedef struct info {
  enum STATE state ;
  uint8_t * message;
} info ;

node * creat_node(uint8_t * h , uint8_t * message );



void add_node_( node * new , node *n  );




uint8_t * first_element( node * n ) ;



uint8_t * second_element( node * n ) ;


info * search_enc ( node * n , uint8_t * h , uint8_t * message );






#endif
