#include <algorithm>
#include <iostream>

int main() {
  int n, k, arr[100000] = {0}, i = 0, current = 0, t = 0;
  std::cin >> n >> k;
  for (i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::sort(arr + 0, arr + n);
  int right = arr[n - 1];
  right -= arr[0];
  int left = 0;
  int dist = (right + left) / 2;
  while (right - left >= 1) {
    current = arr[0] + dist;
    t = 1;
    for (i = 0; i < n; i++) {
      if (current < arr[i]) {
        t++;
        current = arr[i] + dist;
      }
    }
    if (t <= k) {
      right = dist;
    } else {
      left = dist + 1;
    }
    dist = (right + left) / 2;
  }
  std::cout << right << std::endl;
  return 0;
}
