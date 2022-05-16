#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

SearchTree MakeEmpty(SearchTree T){
    if(T!=NULL){
        MakeEmpty(T->L_child);
        MakeEmpty(T->R_child);
        free(T);
    }
    return NULL;
}

TNode Find(ElemType x,SearchTree T){
    if(T==NULL){
        return NULL;
    }
    if(x<T->Elem){
        return (x,T->L_child);
    }else if(x>T->Elem){
        return (x,T->R_child);
    }else{
        return T;
    }
}

TNode FindMin(SearchTree T){
    if(T==NULL){
        return NULL;
    }else if(T->L_child==NULL){
        return T;
    }else{
        return FindMin(T->L_child);
    }
}

TNode FindMax(SearchTree T){
    if(T==NULL){
        return NULL;
    }else if(T->R_child==NULL){
        return T;
    }else{
        return FindMax(T->R_child);
    }
}

SearchTree Insert(ElemType x,SearchTree T){
    if(T==NULL){
        T=(BinaryTree *)malloc(sizeof(BinaryTree));
        T->Elem=x;
        T->R_child=T->L_child=NULL;
    }else if(x<T->Elem){
        return Insert(x,T->L_child);
    }else{
        return Insert(x,T->R_child);
    }
    return T;
}

SearchTree Delete(ElemType x,SearchTree T){
    TNode node;
    if(T==NULL){
        return NULL;
    }else if(x>T->Elem){
        Delete(x,T->R_child);
    }else if(x<T->Elem){
        Delete(x,T->L_child);
    }else{
        if(T->R_child&&T->L_child){
            node= FindMin(T->R_child);
            T->Elem=node->Elem;
            Delete(node->Elem,T->R_child);
        }else{
            node=T;
            if(T->R_child==NULL){
                T=T->L_child;
            }else if(T->L_child==NULL){
                T=T->R_child;
            }
            free(node);
        }
    }
    return T;
}
