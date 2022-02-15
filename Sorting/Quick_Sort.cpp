/* Ref: https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html */

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

int Partition(int arr[], int front, int end)
{
    int pivot = arr[end];
    int i = front - 1; // i is the last index of left array whose element is smallter than pivot

    for (int j = front; j < end; j++) // j iterates the element which is about to be compared with pivot
    {
        /* When element is smallter than pivot, i moves one step ahead; then exchange this smallter element
           w/ the current element */
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    /* Move i for one step ahead for inserting pivot to middle */
    i++;
    swap(&arr[i], &arr[end]);

    return i;
}

void QuickSort(int arr[], int front, int end)
{
    if (front >= end)
        return;
    else
    {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}