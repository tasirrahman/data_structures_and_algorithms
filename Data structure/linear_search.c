#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return i; // Return the index of the target element
    }
  }
  return -1; // Return -1 if the target element is not found
}

int main()
{
  int arr[] = {2, 4, 0, 1, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 1;

  int result = linearSearch(arr, size, target);

  if (result != -1)
  {
    printf("Element found at index %d\n", result);
  }
  else
  {
    printf("Element not found in the array\n");
  }

  return 0;
}