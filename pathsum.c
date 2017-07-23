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

int haspathsum(struct node* node,int sum)
{
  if(node == NULL)
    return (sum == 0);
   else {
   int pathsum = sum - node->data;
   return(haspathsum(node->left, pathsum) || haspathsum(node->right,pathsum));
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
  struct node* root = build123();
  
  root = insert(root,5);
  root = insert(root,8);
  root = insert(root,10);

 printf(" %d ",haspathsum(root,4));
}







