#include <iostream>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void InsertSort(int arr[], int size)
{
    int key; // To be inserted element
    int j;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position;
           otherwise, insert the key to one position head of smaller element */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, size);
    printArray(arr, size);

    return 0;
}