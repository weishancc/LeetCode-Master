/* Ref: https://www.programiz.com/dsa/merge-sort*/

#include <iostream>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

/* Merge two subarrays leftSub[left..mid] and rightSub[mid+1, right] into arr */
void merge(int arr[], int left, int mid, int right)
{
    /* Create leftSub and rightSub */
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftSub[n1], rightSub[n2];

    for (int i = 0; i < n1; i++)
        leftSub[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightSub[j] = arr[mid + 1 + j];

    /* Pick larger element among leftSub and rightSub and place them to correct position if arr;
       i, j ,k is the index of leftSub, rightSub and main array respetively */
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftSub[i] <= rightSub[j])
        {
            arr[k] = leftSub[i];
            i++;
        }
        else
        {
            arr[k] = rightSub[j];
            j++;
        }
        k++;
    }

    /* Put remaining elemtes into arr if run out of elements in either leftSub or rightSub */
    while (i < n1)
    {
        arr[k] = leftSub[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightSub[j];
        j++;
        k++;
    }
}

/* Recur to divide arr into leftSub and rightSub, then merge two subarrays */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}