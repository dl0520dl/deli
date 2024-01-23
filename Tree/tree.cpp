#include <iostream>
#include <cstring>

typedef int Elemtype;

//二叉排序树

//存储结构

typedef struct BitreeNode
{
    Elemtype data;
    struct BitreeNode *lchild, *rchild;
}BitreeNode, *Bitree;



//递归查找二叉排序树T中是否存在key


//指针f指向T的双亲，其初始调用值为NULL
//若查找成功，则指针p指向该数据元素结点，并返回TRUE
//否则指针p指向查找路径上访问的最后一个结点并返回FALSE

bool TreeSearch(Bitree T,int key, Bitree f, Bitree *p){
    if(!T){
        *p = f;
        return false;
    }else if(key == T->data){
        *p = T;
        return true;
    }else if(key < T->data){
        return TreeSearch(T->lchild, key, T, p);
    }else if (key > T->data)
    {
        return TreeSearch(T->rchild, key, T, p);
    }
}

//插入值为key的节点


//当二叉排序树T中不存在关键字等于key的数据元素时
//插入key并返回TRUE，否则返回FALSE


bool TreeInsert(Bitree* T, int key){
    Bitree p, s;
    if(!TreeSearch(*T, key, NULL, &p)){
        s = (Bitree)malloc(sizeof(BitreeNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;
        if (!p)
        {
            *T = s;
        }else if(key < p->data){
            p->lchild = s;
        }else{
            p->rchild = s;
        }
        return true;
        }
    else{
        return false;
    }
}


//删除操作

//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，
//并返回TRUE;否则返回FALSE

bool TreeDelete(Bitree *T, int key){
    if (!(*T))
    {
        return false;
    }else{
        if (key == (*T)->data)
        {
            return Delete(T);
        }else if (key < (*T)->data)
        {
            return TreeDelete(&((*T)->lchild), key);
        }else{
            return TreeDelete(&((*T)->rchild), key);
        }
    }
    
}


//从二叉排序树中删除结点p，并重接它的左或右子树

bool Delete(Bitree *p){
	Bitree q, s;
	if ((*p)->lchild == NULL)
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }else if ((*p)->rchild == NULL)
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }else 
    {
        q = *p;
        s = (*p)->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p)
        {
            q->rchild = s->lchild;
        }else 
        {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return true;
}