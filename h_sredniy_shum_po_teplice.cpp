#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  int n = 0, q = 0, l, r;
  long double arr[300005] = {0};
  long double mult = 0, exponent;
  std::cin >> n;
  arr[0] = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    arr[i] = pow(arr[i], double(1) / double(10000));
    arr[i] *= arr[i - 1];
  }
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> l >> r;
    mult = arr[r + 1] / arr[l];
    exponent = r - l + 1;
    std::cout << std::fixed << std::setprecision(10)
              << pow(pow(mult, 1 / exponent), 10000) << std::endl;
  }
}
