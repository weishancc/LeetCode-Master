#include <iostream>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void SelectSort(int arr[], int size)
{
    int minIndex; // Index of min element

    for (int i = 0; i < size - 1; i++)
    {
        /* Find the minimum element in unsorted array */
        minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        swap(&arr[minIndex], &arr[i]);
    }
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectSort(arr, size);
    printArray(arr, size);

    return 0;
}