#include <stdio.h>
#include <stdlib.h>



//顺序栈

#define Maxsize 100

typedef struct Asatck
{
    int data[Maxsize];
    int top;
}Stack;


//栈的初始化

void StackInit(Stack &s){
    s.top = -1;
}


//栈的判空

bool IsEmpty(Stack &s){
    if(s.top == -1){
        return true;
    }else{
        return false;
    }
}


//进栈

void StackPush(Stack &s, int data){
    if (s.top >= Maxsize - 1)
    {
        return ;
    }
    s.top++;
    s.data[s.top] = data;
}


//出栈

void StackPop(Stack &s, int &x){
    if(s.top == -1){
        return ;
    }else{
        x = s.data[s.top];
        s.top--;
    }
}


//读栈顶元素

void StackTopRead(Stack &s, int &x){
    if(s.top == -1){
        return ;
    }else{
        x = s.data[s.top];
    }
}

//遍历输出栈元素


void StackPrint(Stack &s){
    while (s.top >= 0)
    {
        printf("%d" ,s.data[s.top]);
        s.top--;
    }
    
}


//销毁栈

void DestroyStack(Stack &s){
    s.top == -1;
}




//以上为顺序栈操作




//以下为链栈的操作


typedef struct  Lstack
{
    int data;
    Lstack* next;
}Lstack;



//栈的初始化

void LstackInit(Lstack* s){
    s = NULL;
}


//栈的判空
bool IsEmptyLstack(Lstack* s){
    if (s == NULL)
    {
        return true;
    }else{
        return false;
    }
}


//进栈

void LstackPush(Lstack* s, int data){
    Lstack* p = (Lstack*)malloc(sizeof(Lstack));
    p->data = data;
    p->next = NULL;
    if(s == NULL){
        s = p;
    }else{
        p->next = s;
        s = p;
    }

}

//出栈


void LstackPop(Lstack* s,int &x){
    Lstack* p = (Lstack*)malloc(sizeof(Lstack));;
    if(s == NULL){
        return ;
    }else{
        p = s;
        x = s->data;
        s = s->next;
        free(p);
    }
}



//读栈顶元素


int StackTopRead(Lstack* s, int data){
    if (s == NULL)
    {
        return -1;
    }else{
        data = s->data;
        return data;
    }  
}


//遍历输出栈元素



void PrintStack(Lstack* s){
    while(s != NULL)
    {
        printf("%d ",s->data);
        s = s->next;
    }
}


//销毁栈
void DestroyStack(Lstack* s){
    Lstack* p;
    while(s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    s = NULL;
}




