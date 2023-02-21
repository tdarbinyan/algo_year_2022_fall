#include <iostream>

int main() {
  int num, arr[100000], right = 0, left = 0, middle, iter = 0;
  std::cin >> num;
  for (iter = 0; iter < num; iter++) {
    std::cin >> arr[iter];
  }
  left = 0;
  right = num - 1;
  while (iter > 0) {
    middle = (right + left + 1) / 2;  // beb
    if (right == middle) {
      if (arr[right] > arr[left]) {
        std::cout << 0;
        iter = -1;
      } else {
        std::cout << left + 1;
        iter = -1;
      }
    } else if (arr[right] < arr[middle]) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return 0;
}
