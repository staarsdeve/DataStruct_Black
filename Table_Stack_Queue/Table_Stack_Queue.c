#include "Table_Stack_Queue.h"
#include <stdio.h>
#include <stdlib.h>

List MakeEmpty(List L){
    while(L->next!=NULL){
        Node *node=L->next;
        L->next=node->next;
        free(node);
    }
    return L;
}

int IsEmpty(List L){
   return L->next==NULL;
}

int IsLast(ptrNode p,List L){
    Node *node=L->next;
    if(node==NULL){
        return p->next==NULL;
    }
    while(node->next!=NULL){
        node=node->next;
    }
    if(p->data==node->data&&p->next==node->next){
        return 1;
    }else {
        return 0;
    }
}

ptrNode Find(ElemType x,List L){
    Node *node=L->next;
    while(x!=node->data){
        if(node==NULL){
            return NULL;
        }
        else{
            node=node->next;
        }
    }
    return node;
}

void Delete(ElemType x,List L){
    Node *node=L;
    while(node->next!=NULL&&node->next->data!=x){
        node->next=node->next->next;
    }
    if(node->next!=NULL){
        Node *x_node=node->next;
        node->next=node->next->next;
        free(x_node);
    }
}

ptrNode FindPre(ElemType x,List L){
    Node *node=L;
    while(node->next!=NULL&&node->next->data!=x){
        node=node->next;
    }
    if(node->next==NULL){
        return NULL;
    }else{
        return node;
    }
}

void Insert(ElemType x,List L,Node *p){
    Node *node=FindPre(p->data,L);
    Node *p_x=(Node *)malloc(sizeof(Node));
    p_x->data=x;
    p_x->next=p;
    node->next=p_x;
}

void DeleteList(List L){
    Node *tmp;
    while(L!=NULL){
        tmp=L;
        L=L->next;
        free(tmp);
    }
}



int IsEmptyS(Stack s){
    return s->next==NULL;
}

Stack CreateStack(void){
    Stack s;
    s=(Node *)malloc(sizeof(Node));
    s->next=NULL;
    return s;
}

void MakeEmptyStack(Stack s) {
    while (!IsEmptyS(s)) {
        PopStack(s);
    }
}

void PushStack(Stack s,ElemType x){
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=x;
    node->next=s->next;
    s->next=node;
}

ElemType TopStack(Stack s){
    if(s->next==NULL){
        fprintf(stderr,"ERROR:THE STACK IS EMPTY");
        exit(EXIT_FAILURE);
    }
    else{
        return s->next->data;
    }
}

void PopStack(Stack s){
    if(s->next==NULL){
        fprintf(stderr,"ERROR:THE STACK IS EMPTY");
        exit(EXIT_FAILURE);
    }else{
        Node *node=s->next;
        s->next=node->next;
        free(node);
    }
}






