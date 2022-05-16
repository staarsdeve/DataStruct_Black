
#define ElemType int


typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef Node *ptrNode;


//链表
typedef Node *List;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(ptrNode p,List L);
ptrNode Find(ElemType x,List L);
void Delete(ElemType x,List L);
ptrNode FindPre(ElemType x,List L);
void Insert(ElemType x,List L,Node *p);
void DeleteList(List L);
ptrNode Header(List L){
    return L;
}

ptrNode First(List L){
    return L->next;
}
//ptrNode Advance(List L);

ElemType Retrieve(ptrNode p){
    return p->data;
}


//栈
typedef Node *Stack;

int IsEmptyS(Stack s);
Stack CreateStack(void);
//void DisPoseStack(Stack s);//这个地方处理stack根据实际情况进行调整
void MakeEmptyStack(Stack s);
void PushStack(Stack s,ElemType x);
ElemType TopStack(Stack s);
void PopStack(Stack s);


