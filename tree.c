#include <stdlib.h>

#include "info.h"
#include "tree.h"

TTree tree_create()
{
   return NULL;
}

TTree tree_destroy(TTree tree) {
   if(tree==NULL)
     return NULL;
   else if((tree->left==NULL) && (tree->right==NULL)) {
     free(tree);
     return NULL;
   }
   else {
     tree->left = tree_destroy(tree->left);
     tree->right = tree_destroy(tree->right);
     free(tree);
     return NULL;
   }
}

void tree_print(TTree tree)
{
  if(tree!=NULL)
  {
    tree_print(tree->left);
    print_info(tree->info);
    tree_print(tree->right);
  }
}

TNode* tree_search(TTree tree, TKey key)
{
  if((tree==NULL) || equal(tree->info.key, key))
    return tree;
  else
  {
    if(greater(key, tree->info.key))
      return tree_search(tree->right, key);
    else
      return tree_search(tree->left, key);
  }
}

TTree tree_insert(TTree tree, TInfo info)
{
  if(tree==NULL){
    TNode* newnode;
    newnode=(TNode*) malloc(sizeof(TNode));
    if(newnode==NULL){
      printf("Errore di allocazione");
      exit(1);
    }
    newnode->right=newnode->left=NULL;
    newnode->info=info;
    return newnode;
  }
  else if(!greater(info.key,tree->info.key)){
    tree->left=tree_insert(tree->left,info);
    return tree;
  }
  else{
    tree->right=tree_insert(tree->right,info);
    return tree;
  }
}


void tree_print_preOrder(TTree tree)
{
  if(tree!=NULL){
    print_info(tree->info);  //Stampa della Radice
    tree_print_preOrder(tree->left);  //Stampa del sottoalbero Sinistro
    tree_print_preOrder(tree->right);  //Stampa del sottoalbero Destro
  }
}

void tree_print_postOrder(TTree tree)
{
  if(tree!=NULL){
    tree_print_postOrder(tree->left);  //Stampa del sottoalbero Sinistro
    tree_print_postOrder(tree->right);  //Stampa del sottoalbero Destro
    print_info(tree->info);  //Stampa della Radice
  }
}

int tree_nodes_count(TTree tree)
{
  if(tree==NULL)
    return 0;
  else
    return  1+tree_nodes_count(tree->left)+tree_nodes_count(tree->right);
}


