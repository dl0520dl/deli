#include <bits/stdc++.h>
using namespace std;


//双向链表（带头结点）
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
