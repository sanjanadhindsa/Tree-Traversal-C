#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//make file!!

void add ( bst_node ** root, char * word ) {
    //exactly like java
    //base case --> wanna check if tree is empty!!
    struct bst_node *temp ;
    temp = (bst_node*)malloc(sizeof(*word)) ;
    temp->data = word ;
    temp->right = NULL ;
    temp->left = NULL ;

    if (*root == NULL)
    {
        *root = temp ;
    }
    //check then if less than or greater than
    int ans = strcmp((*root)->data, word) ;
    if (ans<0)
    {
       //root->left = add(root->left, word) ;
        add(&((*root)->right), word) ;
    }
    //greater than check!
    //else if(word > node -> key)
    else if (ans>0)
    {
        //root->right = add(root->right, word) ;
        add(&((*root)->left), word) ;
    }
}
 
void inorder ( bst_node * root ) {
   if (root != NULL)
   {
       inorder(root->left) ;
       printf("%s ", root->data) ;
       inorder(root->right) ;
    
   }
}

 
char * removeSmallest (  bst_node ** root ){
//do the temp with nodes because you don't wanna change the other stuff
    //do the temp with nodes !!
    //bc you don't wanna actually change the other stuff
    if (*root == NULL)
    {
        return NULL ;
    }
    bst_node * temp = *root ;
    bst_node * parent = *root ;
    while (temp -> left != NULL)
    {
        parent = temp ;
        temp = temp ->left ;
    }
    char*c = temp->data ;
    if (parent!=temp)
    {
        if(temp->right == NULL)
        {
            parent->left = NULL ;
        }
        else
        {
            parent->left = temp->right ;
        }
    }
    else{
        *root = (*root)->right ;
    }
    if (temp != NULL)
    {
        free(temp) ;
        temp = NULL ;
    }
    return c ;
} 

 
char * removeLargest (  bst_node ** root ){
    //do the temp with nodes !!
    //bc you don't wanna actually change the other stuff
    if (*root == NULL)
    {
        return NULL ;
    }
    bst_node * temp = *root ;
    bst_node * parent = *root ;
    while (temp -> right != NULL)
    {
        parent = temp ;
        temp = temp ->right ;
    }
    char*c = temp->data ;
    if (parent!=temp)
    {
        if(temp->left == NULL)
        {
            parent->right = NULL ;
        }
        else
        {
            parent->right = temp->left ;
        }
    }
    else{
        *root = (*root)->left ;
    }
    if (temp != NULL)
    {
        free(temp) ;
        temp = NULL ;
    }
    return c ;
}




