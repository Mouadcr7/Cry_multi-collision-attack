#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "node.h"

int main(int argc, char const *argv[])
{
    

    node * H[2]  ;
    H[0] = creat_node(0,0); 
    H[1] = creat_node(0,0); 
    
    for (int i = 65; i < 71 ; i++)
    {
        node *  new  =creat_node(  (uint8_t *)&i , (uint8_t *)&i );
        add_node_( new , H[i%2]  );
        if ( i < 68 ){
        printf("%s - %s \n",new->message,new->h);
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
