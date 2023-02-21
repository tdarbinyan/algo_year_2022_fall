#include <algorithm>
#include <iostream>

int main() {
  int arr[100000], left_min[100000], right_min[100000];
  int n = 0, q = 0;
  int l, r;
  int i = 0;
  std::cin >> n;
  for (i = 0; i < n; i++) {
    std::cin >> arr[i];
    if ((i == 0) || (arr[i] < left_min[i - 1])) {
      left_min[i] = arr[i];
    } else {
      left_min[i] = left_min[i - 1];
    }
  }
  for (i = n; i > 0; i--) {
    if ((i == n) || (arr[i - 1] < right_min[i])) {
      right_min[i - 1] = arr[i - 1];
    } else {
      right_min[i - 1] = right_min[i];
    }
  }
  std::cin >> q;
  for (i = 0; i < q; i++) {
    std::cin >> l >> r;
    std::cout << std::min(left_min[l - 1], right_min[r - 1]) << std::endl;
  }
}
