#include <stdio.h>
#define INMAX 10

void readArray(int *arr) {
  for (int i = 0; i < 10; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("n/a\n");
      return;
    }
  }
}

void bubbleSort(int *arr) {
  int done;
  int pos;
  while (done != 1) {
    done = 1;
    pos = 0;
    for (int i = 0; i < 10 - 1; i++) {
      if (arr[pos] > arr[pos + 1]) {
        int temp = arr[pos];
        arr[pos] = arr[pos + 1];
        arr[pos + 1] = temp;
        done = 0;
      }
      pos++;
    }
  }
}

void printArray(int *arr) {
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
}

int main(void) {
  int arr[INMAX];
  readArray(arr);
  bubbleSort(arr);
  printArray(arr);

  return 0;
}