#include <stdio.h>
#define INMAX 10

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int hight) {
  int pivot = arr[hight];
  int i = low - 1;

  for (int j = low; j < hight; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[hight]);
  return i + 1;
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }

  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main(void) {
  int arr[INMAX] = {4, 3, 9, 0, 1, 2, 100, 2, 7, -1};
  int n = 10;

  int arr_copy[n];

  for (int i = 0; i < n; i++) {
    arr_copy[i] = arr[i];
  }

  quicksort(arr, 0, n - 1);
  printArray(arr, n);
  printf("\n");
  heapsort(arr_copy, n);
  printArray(arr_copy, n);

  return 0;
}