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

int depth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       
       int ldepth = depth(node->left);
       int rdepth = depth(node->right);
 
       
       if (ldepth > rdepth) 
           return(ldepth+1);
       else return(rdepth+1);
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
   root = insert(root,4);
   root = insert(root,5);
   
   int i = depth(root);
   printf("%d",i);
    

}















