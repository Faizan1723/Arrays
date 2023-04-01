#include <stdio.h>
#include <stdlib.h>
void array_sort(int *array, int size)
{
    int b;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                b = array[i];
                array[i] = array[j];
                array[j] = b;
            }
        }
    }
}
void array_merge(int *array1, int *array2, int size1, int size2)
{
    int i = 0, j = 0, k = 0;
    int size3 = size1 + size2;
    int array3[size3];
    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            array3[k] = array1[i];
            i++;
            k++;
        }
        else if (array2[j] < array1[i])
        {
            array3[k] = array2[j];
            j++;
            k++;
        }
        else
        {
            array3[k] = array1[j];
            i++;
            j++;
            k++;
        }
    }
    while (i < size1)
    {
        array3[k] = array1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        array3[k] = array2[j];
        j++;
        k++;
    }

    printf("\nTHE MERGED ARRAY IS:-\n");
    for (int i = 0; i < size3; i++)
    {
        printf("%d ", array3[i]);
    }
}
int main()
{
    int size1, size2;
    printf("ENTER THE SIZE OF ARRAY1: ");
    scanf("%d", &size1);
    int array1[size1];
    printf("ENTER THE ELEMENTS OF ARRAY1:-\n");
    for (int i = 0; i < size1; i++)
    {
        printf("ENTER ARRAY1[%d]: ", i);
        scanf("%d", &array1[i]);
    }
    printf("ENTER THE SIZE OF ARRAY2: ");
    scanf("%d", &size2);
    int array2[size2];
    printf("ENTER THE ELEMENTS OF ARRAY2:-\n");
    for (int i = 0; i < size2; i++)
    {
        printf("ENTER ARRAY2[%d]: ", i);
        scanf("%d", &array2[i]);
    }

    array_sort(array1, size1);
    array_sort(array2, size2);
    printf("SORTED ARRAY1 IS:\n");
    for (int i = 0; i < size1; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\nSORTED ARRAY2 IS:\n");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", array2[i]);
    }

    array_merge(array1, array2, size1, size2);
    return 0;
}