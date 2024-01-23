#include <iostream>
#include <cstring>


void GetNext(char *B, int *next){
    int len = strlen(B);
    if (len == 1)
    {
        next[0] = -1;
        return;
    }
    else
    {
        next[0] = -1;
        next[1] = 0;
        int j = 1;
        int k = 0;
        while (j + 1 < len)
        {
            if(k == -1 || B[k] == B[j])
            {
                next[j + 1] = k + 1; 
                j++;
                k++;
            }
            else
            {
                k = next[k];
            }
        }  
    }
    
}

int kmp(char *A, char *B){
    if (A == NULL || B == NULL)
    {
        return -1;
    }
    else
    {
        int i = 0;
        int j = 0;
        int len1 = strlen(A);
        int len2 = strlen(B);
        int next[len2];
        GetNext(B, next);
        while (i < len1 && j < len2)
        {
            if (A[i] == B[j] || j == -1)
            {
                i++;
                j++;
            }
            else
            {
                j = next [j];
            }
        }
         if (j == len2)
         {
            return i - j;
         }
         else
         {
            return -1;
         }
    }
}



int main()
{
    char *a = "abjsasadcab";
    char *b = "cab";
    int pos = kmp(a, b);
    printf("%d\n",pos);
    system("pause");
    return 0;
}