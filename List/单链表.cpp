#include <bits/stdc++.h>
using namespace std;

//单链表（不带头结点）各种操作

typedef struct SLNode
{
    int data;
    struct SLNode *next;
    SLNode(int value) : data(value),next(nullptr){}
}SLNode;

//打印链表
void SListPrint(SLNode *phead){
    SLNode *cur = phead;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

//清除链表
void SListClear(SLNode *pphead){
    SLNode *cur = pphead;
    SLNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    pphead = NULL;
}

//创建节点
SLNode* CreateSLNode(int data){
    SLNode* Node = new SLNode(data);
    return Node;
}


//插入节点（尾插法）

void SListPushBack(SLNode *pphead ,int data){
    SLNode* Node = CreateSLNode(data);
    if(pphead == NULL){
        pphead = Node;
    }
    else{
         SLNode *tail = pphead;
         while (tail->next != NULL)
         {
            tail = tail->next;
         }
         tail->next = Node;
    }
}


//插入节点（头插法）

void SListPushHead(SLNode *pphead ,int data){
    SLNode* Node = CreateSLNode(data);
    Node->next = pphead;
    pphead = Node;

}


//删除节点（尾删法）

void SListPopBack(SLNode *pphead ){
    if(pphead == NULL){
        return;
    }
    else if(pphead->next == NULL){
        free(pphead);
        pphead = NULL;
        return;
    }
    else{
        SLNode* tail = pphead;
        SLNode* prev = NULL;
        while(tail->next != NULL){
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}


//删除节点（头删法）

void SListPopHead(SLNode *pphead ){
    if(pphead == NULL){
        return;
    }
    else{
        SLNode *cur = pphead->next;
        free(pphead);
        pphead = cur;
    }
}

//查找某一值的节点

SLNode* search(SLNode *phead,int x){
    if(phead == NULL){
        return NULL;
    }
    else{
        SLNode *cur = phead;
        while (cur != NULL){
            if (cur->data == x){
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
void SListInsert(SLNode *pphead ,SLNode *pos ,int data){
    if(pphead == pos){
        SListPushHead(pphead ,data);
    }else{
        SLNode* Node = CreateSLNode(data);
        SLNode* cur = pphead;
        while(cur->next != pos)
        {
            cur = cur->next;
        }
        cur->next = Node;
        Node->next = pos;
    }
}

//删除pos指针指向的节点

void SListDelete(SLNode *pphead ,SLNode *pos){
    if(pphead == NULL){
        return;
    }
    else if(pphead == pos){
        free(pphead);
        pos->next = NULL;
    }
    else{
        SLNode *cur = pphead;
        while(cur ->next!= pos)
        {
            cur = cur->next;
        }
        free(pos);
        cur->next = pos->next;
    }
}






