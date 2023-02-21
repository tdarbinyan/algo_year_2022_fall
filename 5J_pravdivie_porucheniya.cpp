#include <iostream>
#include <vector>

void PrintBackpack(const int* k_weight_arr, const int kWeight, int** dp,
                   const int kCount, std::vector<int>* ans) {
  if (kCount == 0 || kWeight < 0 || dp[kCount][kWeight] == 0) {
    return;
  }
  if (dp[kCount][kWeight] == dp[kCount - 1][kWeight]) {
    PrintBackpack(k_weight_arr, kWeight, dp, kCount - 1, ans);
  } else {
    PrintBackpack(k_weight_arr, kWeight - k_weight_arr[kCount - 1], dp,
                  kCount - 1, ans);
    ans->push_back(kCount);
  }
}

int main() {
  int n;
  int max_weight;
  std::cin >> n >> max_weight;
  int* weight = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> weight[i];
  }
  int* cost = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> cost[i];
  }
  int** dp = new int*[n + 1];
  for (int i = 0; i < n + 1; ++i) {
    dp[i] = new int[max_weight + 1];
    for (int j = 0; j < max_weight; ++j) {
      dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= max_weight; ++j) {
      if (j >= weight[i - 1]) {
        dp[i][j] =
            std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + cost[i - 1]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  std::vector<int> answer;
  PrintBackpack(weight, max_weight, dp, n, &answer);
  for (size_t i = 0; i < answer.size(); ++i) {
    std::cout << answer[i] << " ";
  }
  delete[] weight;
  delete[] cost;
  for (int i = n; i >= 0; --i) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
