#include <iostream>
#include <string>

struct Stack {
  int arr[200000] = {0};
  int min[200000] = {0};
  int size = 0;
};
void FuncPush(Stack* stack, int num) {
  stack->arr[stack->size] = num;
  if (stack->size == 0 || num < stack->min[stack->size - 1]) {
    stack->min[stack->size] = num;
  } else {
    stack->min[stack->size] = stack->min[stack->size - 1];
  }
  stack->size++;
  std::cout << "ok" << std::endl;
}
void FuncMin(Stack* stack) {
  if (stack->size > 0) {
    std::cout << stack->min[stack->size - 1] << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}
void FuncBack(Stack* stack) {
  if (stack->size > 0) {
    std::cout << stack->arr[stack->size - 1] << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}
void FuncClear(Stack* stack) {
  for (int i = 0; i < stack->size; i++) {
    stack->arr[i] = 0;
    stack->min[i] = 0;
  }
  stack->size = 0;
  std::cout << "ok" << std::endl;
}
void FuncPop(Stack* stack) {
  if (stack->size > 0) {
    stack->size--;
    std::cout << stack->arr[stack->size] << std::endl;
    stack->arr[stack->size] = 0;
  } else {
    std::cout << "error" << std::endl;
  }
}
int main() {
  int i = 0, num = 0, m;
  std::string comm;
  Stack data;
  std::cin >> m;
  for (i = 0; i < m; i++) {
    std::cin >> comm;
    if (comm == "push") {
      std::cin >> num;
      FuncPush(&data, num);
    } else if (comm == "back") {
      FuncBack(&data);
    } else if (comm == "min") {
      FuncMin(&data);
    } else if (comm == "clear") {
      FuncClear(&data);
    } else if (comm == "size") {
      std::cout << data.size << std::endl;
    } else if (comm == "pop") {
      FuncPop(&data);
    }
  }
  return 0;
}
