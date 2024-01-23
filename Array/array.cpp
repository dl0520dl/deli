#include <stdio.h>
#include <stdlib.h>




int main()
{   
    int arr[10] = {1,2,3,4,5,6};
    for (int i = 0; i < 5; i++)
    {   
         printf("%d", arr[i]);
         printf("\n");
    }

    int* p = arr;
    for(int i = 0; i < 5; i++)
    {
        printf("%d",*(p+i));
    }
    system("pause");
    
}
