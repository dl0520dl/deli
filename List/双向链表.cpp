#include <bits/stdc++.h>
using namespace std;


//˫��������ͷ��㣩
typedef struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;
}ListNode;

//�����ڵ�
ListNode * CreateSListNode(int data){
    ListNode* LNode = (ListNode*)malloc(sizeof(ListNode));
    LNode->data = data;
    LNode->next = NULL;
    LNode->prev = NULL;
    return LNode;
}

//�����ʼ��

ListNode *ListInit(){
    ListNode* phead = CreateSListNode(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

// ����ڵ�(β�巨)

void ListPushBack(ListNode* Phead, int data){
    ListNode* cur = CreateSListNode(data);
    ListNode* tail = Phead->prev;
    tail->next = cur;
    cur->next = Phead;
    Phead->prev = cur;
    cur->prev = tail;    
}

//����ڵ�(ͷ�巨)

void ListPushHead(ListNode* phead, int data ){
    ListNode* cur = CreateSListNode(data);
    ListNode* head = phead->next;
    phead->next = cur;
    cur->prev = phead;
    cur->next = head;
    head->prev = cur;
}


//ɾ���ڵ㣨βɾ����

void ListPopBack(ListNode* phead){
    ListNode* tail = phead->prev;
    ListNode* prev = tail->prev;
    prev->next = phead;
    phead->prev = prev;
    free(tail);
    tail = NULL;
}

//ɾ���ڵ㣨ͷɾ����

void ListPopHead(ListNode* phead){
    ListNode* head = phead->next;
    ListNode* prev = phead->prev;
    phead->next = prev;
    prev->prev = head;
    free(head);
    head = NULL;
    }


//����ֵΪx�Ľڵ�

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


//��posǰ����һ��ֵΪdata�Ľڵ�

void ListNodeInsert(ListNode* pos, int data){
    ListNode* cur = CreateSListNode(data);
    ListNode*prev = pos->prev;
    pos->prev = cur;
    cur->next = pos;
    cur = prev->next;
    cur->prev = prev;
}


//ɾ��posָ��Ľڵ�

void ListNodeDelete(ListNode* pos){
    ListNode* head = pos->prev;
    ListNode* tail = pos->next;
    head->next = tail;
    tail->prev = head;
    free(pos);
    pos = NULL;
}


//������

int ListNodeLength(ListNode* phead){
    int length = 0;
    ListNode* cur = phead;
    while(cur->next != phead)
    {
        length++;
        cur = cur->next;
    }
}
