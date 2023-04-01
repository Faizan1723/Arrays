#include <stdio.h>
int main()
{
    int m, n, c, d;
    printf("ENTER THE NO. OF ROWS AND COLUMNS OF THE MATICES:");
    scanf("%d%d", &m, &n);
    int first[m][n], second[m][n], sum[m][n];
    printf("ENTER THE ELEMENTS OF FIRST MATRIX:-\n");
    for (c = 0; c < m; c++)
        for (d = 0; d < n; d++)
        {
            printf("ENTER A[%d][%d]:",c+1,d+1);
            scanf("%d", &first[c][d]);
        }
    printf("ENTER THE ELEMENTS OF SECOND MATRIX:-\n");
    for (c = 0; c < m; c++)
        for (d = 0; d < n; d++)
        {
            printf("ENTER B[%d][%d]:",c+1,d+1);
            scanf("%d", &second[c][d]);
        }
    printf("SUM OF THE TWO MATRIX A AND B IS:-\n");
    for (c = 0; c < m; c++)
    {
        for (d = 0; d < n; d++)
        {
            sum[c][d] = first[c][d] + second[c][d];
            printf("%d\t", sum[c][d]);
        }
        printf("\n");
    }
    return 0;
}