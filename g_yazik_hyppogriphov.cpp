#include <iostream>

struct Stack {
  char arr[200000] = {0};
  int size = 0;
};
void FuncPush(Stack* stack, char sym) {
  stack->arr[stack->size] = sym;
  stack->size++;
}
void FuncPop(Stack* stack) {
  stack->size--;
  stack->arr[stack->size] = '#';
}
int main() {
  int i = 0;
  Stack stack;
  char sym[100005];
  std::cin.getline(sym, sizeof sym);
  for (i = 0;; i++) {
    if (sym[i] == '\0') {
      break;
    }
    if (sym[i] == '(' || sym[i] == '{' || sym[i] == '[') {
      FuncPush(&stack, sym[i]);
    } else if (stack.size == 0) {
      std::cout << "NO" << std::endl;
      return 0;
    } else {
      if ((sym[i] == ')' && stack.arr[stack.size - 1] == '(') ||
          (sym[i] == '}' && stack.arr[stack.size - 1] == '{') ||
          (sym[i] == ']' && stack.arr[stack.size - 1] == '[')) {
        FuncPop(&stack);
      } else {
        std::cout << "NO" << std::endl;
        return 0;
      }
    }
  }
  if (stack.size == 0) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  std::cout << "NO" << std::endl;
}
