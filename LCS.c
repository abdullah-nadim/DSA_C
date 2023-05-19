#include <stdio.h>
#include<stdbool.h>

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int lcs(char X[], char Y[], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (X[m - 1] == Y[n - 1])
    {
        return 1 + lcs(X, Y, m - 1, n - 1);
    }
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}


int main()
{
    char S1[100] ;
    char S2[100] ;
    printf("Enter First string: \n");
    scanf("%s",&S1);
    fflush(stdin);
    printf("Enter Second string: \n");
    scanf("%s",&S2);
    int m = strlen(S1);
    int n = strlen(S2);
    printf("Length of LCS is %d" ,lcs(S1, S2, m, n));
    return 0;
}
