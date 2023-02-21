#include <iostream>

void Swap(int* a, int* b);
int FindingNumOrder(int* arr, int low, int high);
int main() {
  int n, k;
  int arr[10000000] = {0};
  std::cin >> n >> k;
  std::cin >> arr[0] >> arr[1];
  int left = 0, right = n - 1;
  for (int i = 2; i < n; i++) {
    arr[i] = (arr[i - 1] * 123 + arr[i - 2] * 45) % 10004321;
  }
  while (true) {
    int mid = FindingNumOrder(arr, left, right);
    if (mid == k - 1) {
      std::cout << arr[k - 1];
      return 0;
    }
    if (mid > k - 1) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
}
int FindingNumOrder(int* arr, int low, int high) {
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
