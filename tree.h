#ifndef TREE_H
#define TREE_H

#include "info.h"

struct SNode {
   TInfo info;
   struct SNode *left;
   struct SNode *right;
};

typedef struct SNode TNode;
typedef TNode* TTree;

TTree tree_create();
TTree tree_destroy(TTree tree);
void tree_visit(TTree tree);
TNode* tree_search(TTree tree, TKey Key);
TTree tree_insert(TTree tree, TInfo info);
TTree tree_delete(TTree tree, TKey key);
void tree_print_preOrder(TTree tree);
void tree_print_postOrder(TTree tree);
void tree_print(TTree tree);
TNode* tree_min(TTree tree);
TNode* tree_max(TTree tree);
TNode* tree_min_iterative(TTree tree);
TNode* tree_max_iterative(TTree tree);
int tree_leaves_count(TTree tree);
int tree_nodes_count(TTree tree);
int tree_depth(TTree tree);
int tree_verify_balanced(TTree tree);

#endif
