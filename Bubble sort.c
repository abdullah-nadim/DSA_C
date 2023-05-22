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
        int starting_index = i;

        for (int j = 0; j < (n - 1) - i; j++) {
            int current_index = j;


            if (arr[current_index] > arr[current_index + 1]) {
                int temp = arr[current_index + 1];
                arr[current_index + 1] = arr[current_index];
                arr[current_index] = temp;

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
