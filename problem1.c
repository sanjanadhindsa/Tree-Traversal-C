#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main() {
    
    
	bst_node * root = NULL;
	
    
    char * instruction = (char*) malloc(256*sizeof(char) ) ;
    char * word = NULL; 
    
    while ( scanf("%s", instruction) > 0 ) {
        //printf ( "read: %c\n", instruction); 
        if ( strncmp(instruction,"a", 2) == 0 ) {
            //add a value to the tree
            word = (char*) malloc (256 * sizeof(char) );
            scanf("%s\n", word);
            add(&root, word);
        }
        else if ( strncmp(instruction,"s", 2) == 0 ) {
            //remove the smallest value in the tree 
            word = removeSmallest( &root);
            //free memory that was allocated for the word
            if (word != NULL) {
                free(word);
                word = NULL; 
            }
        }
        else if ( strncmp(instruction,"l", 2) == 0 ){
            //remove the largest value in the tree 
            word = removeLargest( &root);
            //free memory that was allocated for the word
            if (word != NULL) {
                free(word);
                word = NULL; 
            }
        }
        else if ( strncmp(instruction,"p", 2) == 0 ){
            //print the content of the tree in the inorder traversal
            inorder ( root );
            printf ( "\n");
        }
        else {
            printf ("Error: %s is not a valid instruction\n", instruction);
        }
        
    }
	
    if (word != NULL) {
        free(word);
        word = NULL; 
    }
	
    if (instruction != NULL) {
        free(instruction);
        instruction = NULL; 
    }

	return 0;
}




