#include <cctype>
#include <iostream>

struct Stack {
  int arr[200000] = {0};
  int size = 0;
};
void FuncPush(Stack* stack, int num) {
  stack->arr[stack->size] = num;
  stack->size++;
}
void FuncPop(Stack* stack, int cnt) {
  for (int i = 0; i < cnt; i++) {
    stack->size--;
    stack->arr[stack->size] = 0;
  }
}
int main() {
  Stack stack;
  char symb[200000];
  int i = 0, current = 0, tmp1, tmp2;
  std::cin.getline(symb, sizeof symb);
  while (symb[i] != '\0') {
    if (isdigit(symb[i]) != 0) {
      current = current * 10 + int(symb[i]) - int('0');
    } else if (symb[i] == ' ' && isdigit(symb[i - 1]) != 0) {
      FuncPush(&stack, current);
      current = 0;
    } else if (stack.size >= 2) {
      tmp1 = stack.arr[stack.size - 1];
      tmp2 = stack.arr[stack.size - 2];
      if (symb[i] == '+') {
        FuncPop(&stack, 2);
        FuncPush(&stack, tmp2 + tmp1);
      } else if (symb[i] == '-') {
        FuncPop(&stack, 2);
        FuncPush(&stack, tmp2 - tmp1);
      } else if (symb[i] == '*') {
        FuncPop(&stack, 2);
        FuncPush(&stack, tmp2 * tmp1);
      }
    }
    i++;
  }
  std::cout << stack.arr[0];
  return 0;
}
