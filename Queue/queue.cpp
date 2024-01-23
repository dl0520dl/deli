#include <stdio.h>
#include <stdlib.h>

//顺序队列

#define Maxsize 10



//顺序队列存储结构
typedef struct queue
{
    int data[Maxsize];
    int front;
    int rear;
}queue;



//循环队列存储结构
typedef struct Cqueue
{
    int data[Maxsize];
    int front;
    int rear;
}Cqueue;


//初始化

void QueueInit(Cqueue* q){
    q->front = 0;
    q->rear = 0;
    return ;
}


//循环队列判断队空

bool IsEmpty(Cqueue q){
    if(q.front == q.rear){
        return true;
    }else{
        return false;
    }
}


//求循环队列长度

int QueueLength(Cqueue q){
    return (q.rear - q.front + Maxsize) % Maxsize;
}


//循环队列入队

void QueuePush(Cqueue  q, int data){
    if((q.rear+1) % Maxsize == q.front){
        return ;
    }else{
        q.data[q.rear] = data;
        q.rear = (q.rear + 1) % Maxsize;
        return ;
    }
}


//循环队列出队

void QueuePop(Cqueue q, int &x){
    if(q.front == q.rear){
        return ;
    }else{
        x = q.data[q.front];
        q.front = (q.front+1) % Maxsize;
    }
}







//链队列


//链队列存储类型


//链队列节点

typedef struct  LQueueNode{
    int data;
    struct LQueueNode* next;
}LQueueNode;


//链队列

typedef struct  LQueue{
    LQueueNode* front;
    LQueueNode* rear;
}LQueue;



//初始化


void LQueueInit(LQueue* q){
    //建立头结点
    q->front = q->rear = (LQueueNode*)malloc(sizeof(LQueueNode));
    q->front->next = NULL;
}


//入队

void LQueuePush(LQueue* q, int data){
    LQueueNode *node = (LQueueNode*)malloc(sizeof(LQueueNode));
    node->data = data;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}


//出队

void LQueuePop(LQueue *q, int &data){
    if(q->front == q->rear){
        return ;
    }else{
        LQueueNode* cur;
        cur = q->front->next;
        data = cur->data;
        q->front->next = cur->next;
        if(q->rear == cur){
            q->front =q->rear;
        }
        free(cur);
    }
}









int main()
{


    


    system("pause");
}