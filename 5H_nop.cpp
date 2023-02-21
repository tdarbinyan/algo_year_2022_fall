#include <iostream>
#include <vector>

void PrintGCS(const int* k_first_arr, const int* k_second_arr, int** dp, int n,
              int m) {
  std::vector<int> answer;
  while (n >= 1 && m >= 1) {
    if (k_first_arr[n - 1] == k_second_arr[m - 1]) {
      answer.push_back(k_first_arr[n - 1]);
      --n;
      --m;
    } else {
      (dp[n - 1][m] > dp[n][m - 1]) ? --n : --m;
    }
  }
  for (int i = answer.size() - 1; i >= 0; --i) {
    std::cout << answer[i] << " ";
  }
}

int main() {
  size_t n;
  size_t m;
  std::cin >> n;
  int* first_arr = new int[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> first_arr[i];
  }
  std::cin >> m;
  int* second_arr = new int[m];
  for (size_t i = 0; i < m; ++i) {
    std::cin >> second_arr[i];
  }
  int** dp = new int*[n + 1];
  for (size_t i = 0; i < n + 1; ++i) {
    dp[i] = new int[m + 1];
    for (size_t j = 0; j < m + 1; ++j) {
      dp[i][j] = 0;
    }
  }
  for (size_t i = 1; i <= n; ++i) {
    for (size_t j = 1; j <= m; ++j) {
      if (first_arr[i - 1] == second_arr[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  PrintGCS(first_arr, second_arr, dp, n, m);
  delete[] first_arr;
  delete[] second_arr;
  for (int i = n; i >= 0; --i) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
