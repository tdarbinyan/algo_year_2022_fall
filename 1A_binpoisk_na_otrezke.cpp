#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
  do {
    long int middle = (end - begin) / 2;
    if (*(begin + middle) == target) {
      return true;
    }
    if (*(begin + middle) < target) {
      begin += middle;
      begin++;
    } else {
      end = begin + middle;
    }
  } while (end > begin);
  return false;
}
int main() {
  int num;
  int arr[100000];
  int query;
  int i;
  int j;
  int t;
  std::cin >> num;
  for (int iter = 0; iter < num; iter++) {
    std::cin >> arr[iter];
  }
  std::cin >> query;
  for (int iter = 0; iter < query; iter++) {
    std::cin >> i >> j >> t;
    if (BinarySearch(&arr[i], &arr[j], t)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
