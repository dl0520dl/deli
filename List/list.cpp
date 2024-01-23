#include <stdio.h>
#include <stdlib.h>

//单链表（不带头结点）各种操作

typedef struct SLNode
{
    int data;
    struct SLNode *next;
}SLNode;

//打印链表
void SListPrint(SLNode *phead){
    SLNode *cur = phead;
    while(cur!=NULL)
    {
        printf("%d",cur->data);
        cur = cur->next;
    }
}

//清除链表
void SListClear(SLNode **pphead){
    SLNode *cur = *pphead;
    SLNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}

//创建节点
SLNode* CreateSLNode(int data){
    SLNode* Node = (SLNode*)malloc(sizeof(SLNode));
    Node->data = data;
    Node->next = NULL;
    return Node;
}

//插入节点（尾插法）

void SListPushBack(SLNode **pphead ,int data){
    SLNode* Node = CreateSLNode(data);
    if(*pphead = NULL){
        *pphead = Node;
    }
    else{
         SLNode *tail = *pphead;
         while (tail->next != NULL)
         {
            tail = tail->next;
         }
         tail->next = Node;
    }
   
}


//插入节点（头插法）

void SListPushHead(SLNode **pphead ,int data){
    SLNode* Node = CreateSLNode(data);
    Node->next = *pphead;
    *pphead = Node;

}


//删除节点（尾删法）

void SListPopBack(SLNode **pphead ){
    if(*pphead == NULL){
        return ;
    }
    else if((*pphead)->next == NULL){
        free(*pphead);
        *pphead = NULL;
        return ;
    }
    else{
        SLNode* tail = *pphead;
        SLNode* prev = NULL;
        while(tail->next !=NULL){
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}


//删除节点（头删法）

void SListPopHead(SLNode **pphead ){
    if(*pphead == NULL){
        return ;
    }
    else{
        SLNode *cur = (*pphead)->next;
        free(*pphead);
        *pphead = cur;
    }
}


//查找某一值的节点

SLNode* search(SLNode *phead,int x){
    if(phead == NULL){
        return NULL;
    }
    else{
        SLNode *cur = phead;
        while (cur != NULL)
    {
            if (cur->data == x)
         {
             return cur;
         }
         else{
            cur = cur->next;
         }    
    }
    return NULL;
}
}

//在pos指针前插入节点
void SListInsert(SLNode **pphead ,SLNode *pos ,int data){
    if(*pphead = pos){
        SListPushHead(pphead ,data);
    }else{
        SLNode *Node = CreateSLNode(data);
        SLNode* cur = *pphead;
        while(cur->next != pos)
        {
            cur = cur->next;
        }
        cur->next = Node;
        Node->next = pos;
    }
}

//删除pos指针指向的节点

void SListDelete(SLNode **pphead ,SLNode *pos){
    if(*pphead = NULL){
        return ;
    }
    else if(*pphead == pos){
        free(*pphead);
        pos->next = NULL;
    }
    else{
        SLNode *cur = *pphead;
        while(cur ->next!= pos)
        {
            cur = cur->next;
        }
        free(pos);
        cur->next = pos->next;
    }
}


//以上均为单链表基础操作






//双向循环链表（带头结点）各种操作


typedef struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
}ListNode;

//创建节点
ListNode * CreateSListNode(int data){
    ListNode* LNode = (ListNode*)malloc(sizeof(ListNode));
    LNode->data = data;
    LNode->next = NULL;
    LNode->prev = NULL;
    return LNode;
}

//链表初始化

ListNode *ListInit(){
    ListNode* phead = CreateSListNode(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

// 插入节点(尾插法)

void ListPushBack(ListNode* Phead, int data){
    ListNode* cur = CreateSListNode(data);
    ListNode* tail = Phead->prev;
    tail->next = cur;
    cur->next = Phead;
    Phead->prev = cur;
    cur->prev = tail;    
}

//插入节点(头插法)

void ListPushHead(ListNode* phead, int data ){
    ListNode* cur = CreateSListNode(data);
    ListNode* head = phead->next;
    phead->next = cur;
    cur->prev = phead;
    cur->next = head;
    head->prev = cur;
}


//删除节点（尾删法）

void ListPopBack(ListNode* phead){
    ListNode* tail = phead->prev;
    ListNode* prev = tail->prev;
    prev->next = phead;
    phead->prev = prev;
    free(tail);
    tail = NULL;
}

//删除节点（头删法）

void ListPopHead(ListNode* phead){
    ListNode* head = phead->next;
    ListNode* prev = phead->prev;
    phead->next = prev;
    prev->prev = head;
    free(head);
    head = NULL;
    }


//查找值为x的节点

ListNode* ListNodeSearch(ListNode* phead, int x){
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        if(cur->data = x){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


//在pos前插入一个值为data的节点

void ListNodeInsert(ListNode* pos, int data){
    ListNode* cur = CreateSListNode(data);
    ListNode*prev = pos->prev;
    pos->prev = cur;
    cur->next = pos;
    cur = prev->next;
    cur->prev = prev;
}


//删除pos指针的节点

void ListNodeDelete(ListNode* pos){
    ListNode* head = pos->prev;
    ListNode* tail = pos->next;
    head->next = tail;
    tail->prev = head;
    free(pos);
    pos = NULL;
}


//链表长度

int ListNodeLength(ListNode* phead){
    int length = 0;
    ListNode* cur = phead;
    while(cur->next != phead)
    {
        length++;
        cur = cur->next;
    }
}





