#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

void minHeapify(int arr[], int n, int i)
{
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] < arr[smallest])
    smallest = left;

  if (right < n && arr[right] < arr[smallest])
    smallest = right;

  if (smallest != i)
  {
    swap(&arr[i], &arr[smallest]);
    minHeapify(arr, n, smallest);
  }
}

void heapSortMax(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    maxHeapify(arr, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(&arr[0], &arr[i]);
    maxHeapify(arr, i, 0);
  }
}

void heapSortMin(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    minHeapify(arr, n, i);

  for (int i = n - 1; i > 0; i--)
  {
    swap(&arr[0], &arr[i]);
    minHeapify(arr, i, 0);
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int arrMax[] = {12, 11, 13, 5, 6, 7};
  int nMax = sizeof(arrMax) / sizeof(arrMax[0]);

  int arrMin[] = {12, 11, 13, 5, 6, 7};
  int nMin = sizeof(arrMin) / sizeof(arrMin[0]);

  heapSortMax(arrMax, nMax);
  printf("Sorted array (Max Heap): \n");
  printArray(arrMax, nMax);

  heapSortMin(arrMin, nMin);
  printf("Sorted array (Min Heap): \n");
  printArray(arrMin, nMin);

  return 0;
}