#include <bits/stdc++.h>
using namespace std;

void GetNext(string B, int *next){
    int len = B.size();
    if (len == 1){
        next[0] = -1;
        return;
    }
    else{
        next[0] = -1;
        next[1] = 0;
        int j = 1;
        int k = 0;
        while (j + 1 < len){
            if(k == -1 || B[k] == B[j]){
                next[j + 1] = k + 1; 
                j++;
                k++;
            }
            else{
                k = next[k];
            }
        }  
    }
}

int kmp(string A, string B){
    if (A.size() == 0 || B.size() == 0){
        return -1;
    }
    else{
        int i = 0;
        int j = 0;
        int len1 = A.size();
        int len2 = B.size();
        int next[len2];
        GetNext(B, next);
        while (i < len1 && j < len2)
        {
            if (A[i] == B[j] || j == -1){
                i++;
                j++;
            }
            else{
                j = next [j];
            }
        }
         if (j == len2){
            return i - j;
         }
         else{
            return -1;
         }
    }
}

int main()
{
    char *a = "abjsasadcab";
    char *b = "cab";
    int pos = kmp(a, b);
    cout << pos << endl;
    return 0;
}