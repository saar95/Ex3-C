#include <stdio.h>
#include <string.h>

#define LEN 50

void shift_element(int* arr, int i) {

    while (i > 0) {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
}

void insertion_sort(int* arr, int len) {
    int temp;
    int count = 0;
    for (int i = 1; i < len; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (*(arr + j) > *(arr + i))
                count++;
        }
        temp = *(arr + i);
        shift_element(arr+i-count, count);
        *(arr + i-count) = temp;
        count = 0;
    }
}

int main(int argc, char const* argv[])
{
    int arr[LEN];
    int temp;
    for (int i = 0; i < LEN; i++) {
        scanf("%d", &temp);
        arr[i] = temp;
    }
    insertion_sort(arr, LEN);
    
    for(int i=0;i<LEN-2;i++)
        printf("%d,",*(arr+i));
    printf("%d\n",*(arr+LEN-1));
    return 0;
}