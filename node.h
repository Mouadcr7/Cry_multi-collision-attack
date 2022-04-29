#ifndef __NODE_H
#define __NODE_H
#include <stdint.h>

/**
 * @brief node is an an element of the hashmap, it contains a hash and his message,   
 * and point to the next node in the list 
 */
typedef struct node {
  struct node * next ;
  uint8_t * h ;
  uint8_t * message ;
} node ;
/**
 * @brief this enumeration contains the possible results of a search with search_enc function.
 * The field state of the structure info contains one of these values : ENC_NOT_FOUND , ENC_FOUND , MSG_EXIST.
 */
enum STATE { ENC_NOT_FOUND , ENC_FOUND , MSG_EXIST  };
/**
 * @brief this structure  is the result of search_enc function.
 */
typedef struct info {
  enum STATE state ;
  node *  result ;
} info ;
/**
 * @brief creat_node create a node that contains a message and his hash value.
 * 
 * @param h the hash value in the node
 * @param message the message in the nopde
 * @return a pointer to the node that contains message and h
 */
node * creat_node(uint8_t * h , uint8_t * message );


/**
 * @brief add_node_ add a new node in the hashmap H, exactly in H[pos]
 * if there are nodes in H[pos], we add the  new node in the beginning
 * of h[pos] 

 * @param H is a pointer to the Hashmap.
 * @param new is a pointer the new node we want to add.
 * @param pos is the position the arraylist in hashmap where we want to add the new node.
 */
void add_node_( node ** H , node * new , int pos  );


/**
 * @brief comparaison_tab compare tab1 to tab2.  
 * 
 * @param tab1 first element of the comparaison
 * @param tab2 second element of the comparaison
 * @param size can be 48 bits or 128 bits.
 * @return 0 if the tab1 is equal to tab2, or 1 otherwise. 
 */
int comparaison_tab ( uint8_t  * tab1 , uint8_t * tab2 , int size  ) ;

/**
 * @brief search_enc search in a list of the hashMap pointed by n, the node containing the hash h and verify if there's a collusion 
 * or if the message is the same. 
 * @param n is a pointer to a node.
 * @param h is a pointer to a hash.
 * @param message is a pointer to a message.
 * @param inf the result of the research, we have three cases:
 * if h isn't in the list n, inf->state=ENC_NOT_FOUND,
 * if h is in the list n, but we have the same message, inf->state=MSG_EXIST.  
 * if h is in the list n, and the hash h is for a different message, so we have a collision, inf->result points to the node and inf->state=ENC_FOUND. 
 **/
void search_enc ( node * n , uint8_t * h , uint8_t * message , info *  inf);


/**
 * @brief free the memory used by a node.
 * 
 * @param n is a pointer to a node.
 */
void free_list( node * n );
/**
 * @brief free the Hashmap H. 
 * 
 * @param H a pointer to the hashmap.
 * @param size is the size of the Hashmap.
 */
void free_hash( node ** H  , int size );


#endif
