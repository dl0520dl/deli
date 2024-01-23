#include <bits/stdc++.h>
using namespace std;

//����������ͷ��㣩���ֲ���

typedef struct SLNode
{
    int data;
    struct SLNode *next;
    SLNode(int value) : data(value),next(nullptr){}
}SLNode;

//��ӡ����
void SListPrint(SLNode *phead){
    SLNode *cur = phead;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

//�������
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

//�����ڵ�
SLNode* CreateSLNode(int data){
    SLNode* Node = new SLNode(data);
    return Node;
}


//����ڵ㣨β�巨��

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


//����ڵ㣨ͷ�巨��

void SListPushHead(SLNode *pphead ,int data){
    SLNode* Node = CreateSLNode(data);
    Node->next = pphead;
    pphead = Node;

}


//ɾ���ڵ㣨βɾ����

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


//ɾ���ڵ㣨ͷɾ����

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

//����ĳһֵ�Ľڵ�

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

//��posָ��ǰ����ڵ�
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

//ɾ��posָ��ָ��Ľڵ�

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






