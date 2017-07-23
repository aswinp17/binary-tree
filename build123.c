#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data) 
{
   struct node* node = malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
  
   return (node);
}

static int lookup(struct node* node,int data)
{
   if( node == NULL)
    return 0;
   else { 
     
      if(node->data == data)
        return(1);
      else if (node->data <= data)
         return(lookup(node->left,data));
      else
          return(lookup(node->right,data));
       }
} 


struct node* insert( struct node* node, int data) {
 if( node == NULL) { 
   return(newnode(data));
   }
 else {
     if(data <= node->data)
        node->left = insert(node->left,data);
      else
        node->right = insert(node->right,data);
       
       return node;
     }
  }

struct node* build123()
{
  struct node* root = NULL;
  root = insert(root,2);
  root = insert(root,1);
  root = insert(root,3);

  return (root);

}








int main()
{
  struct node* root = NULL;
   
   root = build123(); 

 

}





























