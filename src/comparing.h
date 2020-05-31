#include "types.h"

int* generate_array(int size, int from, int to) {
  int* result = new int[size];
  for (int i = 0; i < size; i++) {
    result[i] = from + (rand() % static_cast<int>(to - from + 1));
  }
  return result;
}

bool is_sorted(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

bool is_sorted_decreasing(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      return false;
    }
  }
  return true;
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout<<arr[i];
    if (i < n - 1) {
      cout<<", ";
    }
  }
  cout<<endl;
}
