#include <stdio.h> 
#include <iostream>
using namespace std;

void Parray(int arr[], int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/* Swaps two array elements */
void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
/******************************************/
/* To heapify(min) subtree root @ index i */
/* Arguments - */
/* ARR[] - Input array */
/* N - Size of the array */
/* I - Index of the heap's root */
/******************************************/
void min_heapify(int arr[], int n, int i)
{
    int smallest = i;    /* smallest as root */
    int l = (2 * i) + 1; /* left */
    int r = (2 * i) + 2; /* right */

    /* If left child is smaller than root */
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    /* If right child is smaller than smallest so far*/
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    /* If smallest is not root */
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);

        /* Recursively heapify the sub-tree */
        min_heapify(arr, n, smallest);
    }
}
void max_heapify(int array[], int n, int i)
{
    int lar = i; /* largest as root */
    int left = (2 * i) + 1; /* left */
    int right = (2 * i) + 2; /* right */

    /* If left child is larger than root */
    if (left < n && array[left] > array[lar])
        lar = left;

    /* If right child is larger than largest so far*/
    if (right < n && array[right] > array[lar])
        lar = right;

    /* If largest is not root */
    if (lar != i)
    {
        swap(&array[i], &array[lar]);
        max_heapify(array, n, lar); /* Recursively heapify the sub-tree */
    }
}
void (*heapify) (int arr[], int n, int i);
void heap_sort(int arr[], int n)
{
    /* Build heap (rearrange elements) */
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printf("Build heap @index #%d\n", i);
        heapify(arr, n, i);
        Parray(arr, n);
    }

    /* One by one extract an element from heap */
    for (int i = n - 1; i >= 0; i--)
    {
        /* Move current root to end */
        printf("Move current root %d to end\n", arr[0]);
        swap(&arr[0], &arr[i]);
        Parray(arr, i);
        if (i)
            printf("Build heap rearranging elements\n");

        /* call max heapify on the reduced heap */
        heapify(arr, i, 0);
        Parray(arr, i);
    }
}


int main()
{
    int arr[20];
    int n;
    cout << "how much variables you want to sort:";
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cout << "enter #" << i << ":";
        cin >> arr[i];
        cout << endl;
    }

    heapify = max_heapify;


    printf("Original array is \n");
    Parray(arr, n);
    heap_sort(arr, n);

    printf("Sorted array is \n");
    Parray(arr, n);
}