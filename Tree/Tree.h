#ifndef TREE_TREE_H
#define TREE_TREE_H

#define ElemType char


//森林的表示，兄弟孩子表示法
typedef struct TreeNode{
    ElemType c;
    struct TreeNode *first_child;
    struct TreeNode *bro;
}TreeNode;

//二叉树
typedef struct BinaryTree{
    ElemType Elem;
    struct BinaryTree *L_child;
    struct BinaryTree *R_child;
}BinaryTree;

typedef BinaryTree *SearchTree;
typedef BinaryTree *TNode;

SearchTree MakeEmpty(SearchTree T);
TNode Find(ElemType x,SearchTree T);
TNode FindMin(SearchTree T);
TNode FindMax(SearchTree T);
SearchTree Insert(ElemType x,SearchTree T);
SearchTree Delete(ElemType x,SearchTree T);
ElemType Retrieve(TNode node);



































































#endif //TREE_TREE_H
