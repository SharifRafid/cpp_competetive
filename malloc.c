#include <stdio.h>

int main()
{
    int a, last;

    int *arr, arrSize = 0;
    scanf("%d", &a);

    arr = (int*) malloc(sizeof(int) * arrSize);

    while (1)
    {
        scanf("%d", &last);
        arrSize ++;
        arr = (int*) realloc(arr, arrSize * sizeof(int));
        arr[arrSize-1] = last;
        if(last>a){
            break;
        }
    }

    int sum = a, count = 0;
    for(int i = 0; i < arrSize; i++){
        sum+=arr[i];
        count++;
        if(sum > last){
            break;
        }
    }
    printf("%d\n", count);
    return 0;
}