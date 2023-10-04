#include <stdio.h>

#define MAX_SIZE 100

void bubble_sort(int * arr, int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void insertion_sort(int * arr, int size) {
  int temp, j;
  for (int i = 1; i < size; i++) {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

void selection_sort(int * arr, int size) {
  int min_index, temp;
  for (int i = 0; i < size - 1; i++) {
    min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
  }
}

void merge_sort(int * arr, int left, int right) {
  if (left >= right) return;
  int mid = left + (right - left) / 2;
  merge_sort(arr, left, mid);
  merge_sort(arr, mid + 1, right);
  int left_size = mid - left + 1;
  int right_size = right - mid;
  int left_arr[left_size], right_arr[right_size];
  for (int i = 0; i < left_size; i++) left_arr[i] = arr[left + i];
  for (int j = 0; j < right_size; j++) right_arr[j] = arr[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < left_size && j < right_size) {
    if (left_arr[i] <= right_arr[j]) {
      arr[k++] = left_arr[i++];
    } else {
      arr[k++] = right_arr[j++];
    }
  }
  while (i < left_size) arr[k++] = left_arr[i++];
  while (j < right_size) arr[k++] = right_arr[j++];
}

void quick_sort(int * arr, int left, int right) {
  while (left < right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
      if (arr[j] <= pivot) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    int pivot_index = i + 1;

    if (pivot_index - 1 - left < right - pivot_index - 1) {
      quick_sort(arr, left, pivot_index - 1);
      left = pivot_index + 1;
    } else {
      quick_sort(arr, pivot_index + 1, right);
      right = pivot_index - 1;
    }
  }
}

int main() {
  int size, choice;
  int arr[MAX_SIZE];

  while (1) {
    printf("Enter array size: ");
    scanf("%d", & size);
    
    for (int i = 0; i < size; i++)
      {
      printf("Enter %d'st element : ", i+1 );
      scanf("%d", & arr[i]);
      }
    printf("\nSelect sort to execute:\n1. Bubble sort\n2. Insertion sort\n3. Selection sort\n4. Merge sort\n5. Quick sort\n6. Return to main menu\n");
    printf("\nEnter your choice : ");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      bubble_sort(arr, size);
      break;
    case 2:
      insertion_sort(arr, size);
      break;
    case 3:
      selection_sort(arr, size);
      break;
    case 4:
      merge_sort(arr, 0, size - 1);
      break;
    case 5:
      quick_sort(arr, 0, size - 1);
      break;
    case 6:
      return 0;
    default:
      printf("Invalid choice.\n");
      break;
    }

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++)
      printf("%d ", arr[i]);
    printf("\n");
  }

  return 0;
}

