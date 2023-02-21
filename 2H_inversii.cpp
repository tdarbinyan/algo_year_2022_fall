#include <iostream>

void MergeArrays(int* arr, int low, int high, int mid, int* ans);
void MergeSort(int* arr, int low, int high, int* ans);
int main() {
  int arr[100000];
  int num;
  int ans = 0;
  std::cin >> num;
  for (int i = 0; i < num; i++) {
    std::cin >> arr[i];
  }
  MergeSort(arr, 0, num - 1, &ans);
  std::cout << ans;
}
void MergeSort(int* arr, int low, int high, int* ans) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    MergeSort(arr, low, mid, ans);
    MergeSort(arr, mid + 1, high, ans);
    MergeArrays(arr, low, high, mid + 1, ans);
  }
}
void MergeArrays(int* arr, int low, int high, int mid, int* ans) {
  int temp[100000];
  int left = low;
  int merge_index = low;
  int middle_index = mid;
  while (left < mid && middle_index <= high) {
    if (arr[left] <= arr[middle_index]) {
      temp[merge_index++] = arr[left++];
    } else {
      temp[merge_index++] = arr[middle_index++];
      *ans += mid - left;
    }
  }
  while (left < mid) {
    temp[merge_index++] = arr[left++];
  }
  while (middle_index <= high) {
    temp[merge_index++] = arr[middle_index++];
  }
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i];
  }
}
