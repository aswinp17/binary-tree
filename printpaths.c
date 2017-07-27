#include<stdio.h>
#include<malloc.h>

struct node
{
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

struct node* build123()
{
  struct node* root = NULL;
  root = insert(root,2);
  root = insert(root,1);
  root = insert(root,3);

  return (root);

} 

void printArray(int ints[], int len) 
{
  int i;
  for (i=0; i<len; i++) 
  {
    printf("%d ", ints[i]);
  }
  printf("\n");
}  


void printPathsRecur(struct node* node, int path[], int pathLen) 
{
  if (node==NULL) 
    return;
 
  path[pathLen] = node->data;
  pathLen++;
 
  
  if (node->left==NULL && node->right==NULL) 
  {
    printArray(path, pathLen);
  }
  else
  {
    
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
 
void printPaths(struct node* node) 
{
  int path[1000];
  printPathsRecur(node, path, 0);
}
 


 



int main()
{
  struct node* root = NULL;
    
   root = build123(); 
   root = insert(root,4);
   root = insert(root,5);
   
   printPaths(root);
    

}
