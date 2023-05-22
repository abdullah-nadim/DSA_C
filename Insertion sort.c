#include <stdio.h>

int main() {
    int n;
    printf("Enter Array size: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = arr[i];

        while (arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
    printf("Sorted Array :\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}
