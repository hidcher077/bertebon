#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
  int length;
  input(NULL, &length);
  return 0;
}

int sum_numbers(int *buffer, int length) {
  int sum = 0;

  int new_arr[10];
  int cnt = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      new_arr[cnt++] = buffer[i];
      sum += buffer[i];
    }
  }

  printf("%d\n", sum);
  return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
  int div = sum_numbers(buffer, length);
  int new_arr[10];
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      new_arr[i] += buffer[i];
    }
  }
  output(new_arr, length);
  return 0;
}

void input(int *buffer, int *length) {
  char end;
  if (scanf("%d%c", length, &end) == 2 && end == '\n' && *length <= 10) {
    for (int i = 0; i < *length; i++) {
      if (scanf("%d%c", &buffer[i], &end) == 2 ||
          (i < *length - 1 && end == ' ') || (i == *length - 1 && end == '\n'))
        sum_numbers(buffer, *length);
    }
  } else {
    printf("n/a");
  }
}

void output(int *a, int n) {
  for (int i = 0; i < n - 1; i++)
    printf("%d ", a[i]);
  printf("%d", a[n - 1]);
}