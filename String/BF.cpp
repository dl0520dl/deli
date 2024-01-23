#include <bits/stdc++.h>
using namespace std;

int BF(string A, string B){
    int len1 = A.size();
    int len2 = B.size();
    int i = 0, j = 0;
    while (i < len1 && j < len2){
        if (A[i] == B [j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == len2){
        return i - j;
    }
    else{
        return -1;
    }
}

int main()
{
    string a = "abjsasadcab";
    string b = "cab";
    int pos = BF(a, b);
    cout << pos << endl;
    return 0;
}