#include <stdio.h>
#include <stdlib.h>

void Sort(int *array, int array_length)
{
    int max_index = 0;

    for(int i = 0; i < array_length; i++)
    {
        max_index = 0;
        for(int y = 0; y < array_length - i; y++)
        {
            if(array[y] > array[max_index])
            {
                max_index = y;
            }
        }
        int tmp = array[array_length - 1 -i];
        array[array_length - 1- i] = array[max_index];
        array[max_index] = tmp;
    }
}

int main(void)
{
    int *array = malloc(sizeof(int));

    if(!array)
    {
        perror("malloc failed!");
        return 1;
    }

    int array_length = 0;
    printf("Please insert your numbers (No-Number to Quit): \n");

    while(1)
    {
        int input;
        if (scanf("%d", &input) != 1) {
            break;
        }

        *(array + array_length) = input;
        array_length++;

        printf("Array: ");
        for(int i = 0; i < array_length; i++)
        {
            printf("%d ", *(array + i));
        }
        printf("\n");

        int *new_array = realloc(array, sizeof(int)*(array_length+1));
        if (!new_array)
        {
            perror("realloc failed");
            free(array);
            return 1;
        }
        array = new_array;
    }

    if (array_length == 0) {
        printf("No numbers entered.\n");
        free(array);
        return 0;
    }

    Sort(array, array_length);

    printf("Sorted Array: ");

    for(int i = 0; i < array_length; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");

    free(array);
    return 0;
}
