#include <iostream>
#include <cstring>
using namespace std;

//串的定长存储


#define Maxsize 100

typedef struct sstring
{
   char ch[Maxsize + 1];
   int length;
}sstring;

//生成一个其值等于 str 的串 Str


void StrInsert(sstring* Str, char str[]){
    int i = 0;
    while (str[i] != '\0')
    {
        Str->length++;
        i++;
    }
    for(i = 0; i< Str->length; i++)
    {
        Str->ch[i] = str[i];
    }
    return ;
}


//连接字符串1和2，并存在字符串3中

void StrConcat(sstring* str1, sstring* str2, sstring* str){
    str->length = str1->length + str2->length;
    int i;
    for(i = 0; i < str1->length; i++)
    {
        str->ch[i] = str1->ch[i];
    }
    for(i = str1->length; i < str->length; i++)
    {
        str->ch[i] = str2->ch[i - str1->length];
    }
}


void StrPrint(sstring* str){
    int i;
    while(str->ch[i] != '\0')
    {
        printf("%c",str->ch[i]);
        i++;
    }
    return ;
}



//串的堆分配存储



typedef struct String
{
    char* s;
    int length;
    int strsize;//分配存储空间大小
}String;



//初始化


void CreateStr(String* str){
    str->length = 0;
    str->s = (char*)malloc(Maxsize*sizeof(char));
    str->strsize = Maxsize;
}


//生成一个值等于字符串常量 str 的串 str1


void stringInsert(String* ch, char *str){
    int len;
    while (str[len] != '\0')
    {
        len++;
    }
    if(ch->length < len){
        ch->s = (char*)malloc(sizeof(char));
        ch->strsize = len;
    }
    ch->length = len;

    for ( int i = 0; i < len; i++)
    {
        ch->s[i] = str[i];
    }
    return ;
}


//字符串拼接


void StringConcat(String* str, String* str1, String* str2){
    if(str->strsize < str1->strsize + str2->strsize){
        str->s = (char*)realloc(str->s,(str1->length + str2->length)* sizeof(char));
        str->strsize = str1->length + str2->length;
    }
    str->length = str1->length + str2->length;
    int i = 0;
    for ( i = 0; i < str1->length; i++)
    {
        str->s[i] = str1->s[i];
    }
    for( i = str1->length;i < str->length ;i++)
    {
        str->s[i] = str2->s[i-str1->length];
    }
}



//打印字符串


void StringPrint(String* ch){
    int i = 0;
    while(ch->s[i] != '\0')
    {
        printf("%c", ch->s[i]);
        i++;
    }
    return ;
}




//块链存储



//两个子串先分成块，再连接
//将两个串先分别转换成块存储  , 将已经分好的块进行连接




#define CHUNKSIZE 4


//存储结构

typedef struct  Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk* next;
}Chunk;



//初始化赋值

Chunk* ChunkInit(char* arr){
    Chunk* H;
    Chunk* temple;
    Chunk* tail;
    H = (Chunk*)malloc(sizeof(Chunk));
    tail = H;
    //计算需要块链的个数
    int num = strlen(arr)/CHUNKSIZE;
    int mod = strlen(arr)%CHUNKSIZE;
    if(mod != 0){
        num++;
    }
    int i,j;
    for(i = 0; i<num; i++)
    {
        temple = (Chunk*)malloc(sizeof(Chunk));
        j= 0;
        while(j < CHUNKSIZE&& arr[j])
        {
            temple->ch[j] = arr[i * CHUNKSIZE + j];
            j++;
        }
        tail->next = temple;
        tail = temple;
    }
    //如果最后一个块没填满，通常用'#'补上
    if ((mod != 0))
    {
        int res = CHUNKSIZE - mod;
        for (int cnt = 0; i < res; i++)
        {
           tail->ch[mod + cnt] = '#';
        }
    }
    tail->next = NULL;
    return H;
}


//打印块链字符串


void PrintChunk(Chunk* H){
    Chunk* cur;
    cur = H->next;
    int i;
    while (cur != NULL)
    {
         for(i = 0; i < CHUNKSIZE; i++)
        {
            if(cur->ch[i] == NULL){
                break;
            }else{
                printf("%d", cur->ch[i]);
            }
        }
          cur = cur->next;
    } 
}    



//连接字符串s , t(先分块，再连接)


void ConcatChunk(Chunk* s, Chunk* t){
    while(s->next){
        s = s->next;
    }
    s->next = t->next;
    return ;
}
 



//连接字符串s , t,先连接，再分块存储



typedef struct  chunk
{
    char ch[CHUNKSIZE];
    struct chunk* next;
}chunk;

//赋值
chunk* chunkInit(char *arr){
    chunk* H;
    H = (chunk*)malloc(sizeof(chunk));
    chunk* temple, *tail;
    tail = H;
    tail->next = NULL;
    int len = strlen(arr);
    int num = len/CHUNKSIZE;
    int mod = len%CHUNKSIZE;
    int i,j;
    for(i = 0; i < num; i++){
        temple = new chunk;
        j = 0;
        while (j < CHUNKSIZE && arr[i * CHUNKSIZE + j])
        {
            temple->ch[j] = arr[i * CHUNKSIZE + j];
            j++;
        }
        tail->next = temple;
        tail = temple;
        if((i * CHUNKSIZE + j) == len && (CHUNKSIZE - mod) != 0){
            int res = CHUNKSIZE - mod;
            for (int cnt = 0; cnt < res; cnt++)
            {
                tail->ch[j + cnt] = '#';
            }
        }
    }
    tail->next = NULL;
    return H;
}





int main()
{
  
    



}