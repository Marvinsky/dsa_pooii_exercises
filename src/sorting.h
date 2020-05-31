
#include "types.h"
//int INT_MAX = std::numeric_limits<int>::min();
//int INT_MIN = std::numeric_limits<int>::max();

void imprimir(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout<<arr[i];
    if (i < n - 1) {
      cout<<",\t";
    }
  }
  cout<<"\n";
}

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int indexOfSmallest = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[indexOfSmallest]) {
        indexOfSmallest = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[indexOfSmallest];
    arr[indexOfSmallest] = temp;
  }
}

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j + 1 < n - i; j++) {
      if (arr[j] > arr[j+1]) {
        //swap
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp;
    *yp = temp; 
}

void bubble_sort_optimized(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    bool swapped = false;
    for (int j = 0; j + 1 < n - i; j++) {
      if (arr[j] > arr[j+1]) {
        //swap
        swap(&arr[j], &arr[j+1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

void merge(int arr[], int from, int middle, int to) {
  int length_left = middle - from + 1;
  int length_right = to - middle;
  int *left = new int[length_left];
  int *right = new int[length_right];

  for (int i = 0; i < length_left; i++) {
    left[i] = arr[from + i];
  }
  for (int i = 0; i < length_right; i++) {
    right[i] = arr[middle + i + 1];
  }
  
  /*
  left[length_left] = INT_MAX;
  right[length_right] = INT_MAX;
  
  int left_pointer = 0;
  int right_pointer = 0;
  for (int i = from; i <= to; i++) {
    if (left[left_pointer] > right[right_pointer]) {
      arr[i] = right[right_pointer];
      right_pointer++;
    } else {
      arr[i] = left[left_pointer];
      left_pointer++;
    }
  }*/
  
  int left_pointer = 0;
  int right_pointer = 0;
  int k = from;
  while (left_pointer < length_left && right_pointer < length_right) {
    if (left[left_pointer] <= right[right_pointer]) {
      arr[k] = left[left_pointer];
      left_pointer++;
    } else {
      arr[k] = right[right_pointer];
      right_pointer++;
    }
    k++;
  }

  while (left_pointer < length_left) {
    arr[k] = left[left_pointer];
    left_pointer++;
    k++;
  }

  while (right_pointer < length_right) {
    arr[k] = right[right_pointer];
    right_pointer++;
    k++;
  }
}

void merge_sort(int arr[], int from, int to) {
  if (from < to) {
    int middle = (from + to)/2;
    merge_sort(arr, from, middle);
    merge_sort(arr, middle + 1, to);
    merge(arr, from, middle, to);
  }
}

void mergesort_executor(int arr[], int n) {
  merge_sort(arr, 0, n - 1);
}

int partition(int arr[], int from, int to) {
  int pivot = arr[to];
  int wall = from;
  for (int i = from; i < to; i++) {
    if (arr[i] <= pivot) {
      int temp = arr[wall];
      arr[wall] = arr[i];
      arr[i] = temp;
      wall++;
    }
  }
  arr[to] = arr[wall];
  arr[wall] = pivot;
  return wall;
}

void quicksort(int arr[], int from, int to) {
  if (from < to) {
    int index_pivot = partition(arr, from, to);
    quicksort(arr, from, index_pivot - 1);
    quicksort(arr, index_pivot + 1, to);
  }
}

void quicksort_executor(int arr[], int n) {
  quicksort(arr, 0, n - 1);
}

int median_of_three(int arr[], int first, int middle, int last) {
  int array[] = {arr[first], arr[middle], arr[last]};
  selection_sort(array, 3);
  if (arr[1] == arr[first]) {
    return first;
  } else if (arr[1] == arr[middle]) {
    return middle;
  } else {
    return last;
  }
}

int partition_medium(int arr[], int from, int to) {
  int index_of_pivot = median_of_three(arr, from, (from + to)/2, to);
  int pivot = arr[index_of_pivot];
  if (index_of_pivot != to) {
    arr[index_of_pivot] = arr[to];
  }
  int wall = from;
  for (int i = from; i < to; i++) {
    if (arr[i] <= pivot) {
      int temp = arr[wall];
      arr[wall] = arr[i];
      arr[i] = temp;
      wall++;
    }
  }
  arr[to] = arr[wall];
  arr[wall] = pivot;
  return wall;
}

void quicksort_medium(int arr[], int from, int to) {
  if (from < to) {
    int index_pivot = partition_medium(arr, from, to);
    quicksort_medium(arr, from, index_pivot - 1);
    quicksort_medium(arr, index_pivot + 1, to);
  }
}

void quicksort_executor_medium(int arr[], int n) {
  quicksort_medium(arr, 0, n - 1);
}