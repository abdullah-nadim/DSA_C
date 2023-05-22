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

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Sorted Array :\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}
