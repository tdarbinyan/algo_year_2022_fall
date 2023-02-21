#include <iostream>

void QuickSort(int* arr, int low, int high);
int Partition(int* arr, int low, int high);
void Swap(int* a, int* b);
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << "\n";
  }
  delete[] arr;
}
void QuickSort(int* arr, int low, int high) {
  if (low < high) {
    int pi = Partition(arr, low, high);
    QuickSort(arr, low, pi);
    QuickSort(arr, pi + 1, high);
  }
}
int Partition(int* arr, int low, int high) {
  int pivot = arr[(high + low) / 2];
  while (true) {
    while (arr[low] < pivot) {
      low++;
    }
    while (arr[high] > pivot) {
      high--;
    }
    if (low >= high) {
      return high;
    }
    Swap(&arr[low++], &arr[high--]);
  }
}
void Swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
