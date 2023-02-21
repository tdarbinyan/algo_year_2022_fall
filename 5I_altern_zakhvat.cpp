#include <iostream>
#include <vector>

void FindLAS(int* arr, int** dp, int count, int answer) {
  std::vector<int> result;
  for (int i = answer; i > 0; --i) {
    for (int j = count - 1; j >= 0; --j) {
      if ((dp[j][0] == i || dp[j][1] == i) && dp[j][0] < i + 1 &&
          dp[j][1] < i + 1) {
        result.push_back(arr[j]);
        break;
      }
    }
  }

  for (int i = answer - 1; i >= 0; --i) {
    std::cout << result[i] << " ";
  }
}
int main() {
  int count;
  std::cin >> count;

  int* arr = new int[count];
  int** dp = new int*[count];
  for (int i = 0; i < count; ++i) {
    dp[i] = new int[2];
    dp[i][0] = 1;
    dp[i][1] = 1;

    std::cin >> arr[i];
    for (int j = 0; j < i; ++j) {
      if (dp[i][1] < dp[j][0] + 1 && arr[j] > arr[i]) {
        dp[i][1] = dp[j][0] + 1;
      }
      if (dp[i][0] < dp[j][1] + 1 && arr[j] < arr[i]) {
        dp[i][0] = dp[j][1] + 1;
      }
    }
  }

  int answer = std::max(dp[count - 1][0], dp[count - 1][1]);
  std::cout << answer << std::endl;

  FindLAS(arr, dp, count, answer);

  delete[] arr;

  for (int i = 0; i < count; ++i) {
    delete[] dp[i];
  }
  delete[] dp;

  return 0;
}
