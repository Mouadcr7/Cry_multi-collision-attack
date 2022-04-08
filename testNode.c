#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "node.h"

int main(int argc, char const *argv[])
{
    

    node * H[2]  ;
    H[0] = NULL; 
    H[1] = NULL; 
    
    for (int i = 65; i < 70 ; i++)
    {
        int * j = malloc ( sizeof (int))  ;
        *j = i ;
        node *  new  =creat_node(  (uint8_t *)j , (uint8_t *)j );
        add_node_( H , new , i%2  );
        if ( i < 67 ){
        //printf("%s - %s \n",new->message,new->h);
        }

        
    }

    for (int i = 0; i < 2; i++)
    {
        node * new = H[i] ; 
        while(new ){
            printf("%s - %s \n",new->message,new->h);
            new = new -> next ;
        }
        printf("------------------------\n");

    }
    
    
    return 0;
}
