#include <stdio.h>

void rearrange(int *arr, int size) {
    int *i, *j;
    int temp;

    for(i = arr; i < arr + size; i++) {

        if((*i) % 2 != 0) {

            j = i + 1;

            while(j < arr + size && (*j) % 2 != 0) {
                j++;
            }

            if(j < arr + size) {

                temp = *j;

                while(j > i) {
                    *j = *(j - 1);
                    j--;
                }

                *i = temp;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *ptr;

    printf("Original Array:\n");

    for(ptr = arr; ptr < arr + size; ptr++) {
        printf("%d ", *ptr);
    }

    rearrange(arr, size);

    printf("\n\nRearranged Array:\n");

    for(ptr = arr; ptr < arr + size; ptr++) {
        printf("%d ", *ptr);
    }

    return 0;
}