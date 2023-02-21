#include <iostream>
#include <vector>

std::vector<int> BinaryMerge(std::vector<int> first_vector,
                             std::vector<int> second_vector) {
  std::vector<int> temp;
  int size = first_vector.size() + second_vector.size();
  int first_head = 0;
  int second_head = 0;
  while (first_head + second_head < size) {
    if (first_head != int(first_vector.size()) &&
        (second_head == int(second_vector.size()) ||
         first_vector[first_head] < second_vector[second_head])) {
      temp.push_back(first_vector[first_head]);
      first_head++;
    } else {
      temp.push_back(second_vector[second_head]);
      second_head++;
    }
  }
  return temp;
}

void MergeAllArrays(std::vector<std::vector<int>> vec_of_arr) {
  std::vector<std::vector<int>> temp_vec;
  while (int(vec_of_arr.size()) > 1) {
    temp_vec.clear();
    for (int i = 0; i < int(vec_of_arr.size()); i += 2) {
      if (i == vec_of_arr.size() - 1) {
        temp_vec.push_back(vec_of_arr[i]);
      } else {
        temp_vec.push_back(BinaryMerge(vec_of_arr[i], vec_of_arr[i + 1]));
      }
    }
    vec_of_arr = temp_vec;
  }
  for (int i = 0; i < int(vec_of_arr[0].size()); i++) {
    std::cout << vec_of_arr[0][i] << " ";
  }
}

int main() {
  int k;
  int n;
  int num;
  std::vector<std::vector<int>> vec_of_arr;
  std::vector<int> output;
  std::cin >> k;
  for (int i = 0; i < k; i++) {
    std::cin >> n;
    std::vector<int> temp;
    for (int j = 0; j < n; j++) {
      std::cin >> num;
      temp.push_back(num);
    }
    vec_of_arr.push_back(temp);
  }
  MergeAllArrays(vec_of_arr);
}
