#include <iostream>
#include <cstring>

int BF(char *A, char *B){
    int len1 = strlen(A);
    int len2 = strlen(B);
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (A[i] == B [j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
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

int main()
{
    char *a = "abjsasadcab";
    char *b = "cab";
    int pos = BF(a, b);
    printf("%d\n",pos);
    system("pause");
    return 0;
}