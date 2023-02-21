#include <iostream>
#include <string>

struct Stack {
  int arr[200000] = {0};
  int size = 0;
  int head = 0;
};
struct Queue {
  int arr[200000] = {0};
  Stack min;
  int size = 0;
  int head = 0;
};
void Enqueue(Queue* queue, int num);
void Dequeue(Queue* queue);
void Front(Queue* queue);
void Clear(Queue* queue);
void Min(Queue* queue);

void StackPush(Stack* stack, int num);
void StackClear(Stack* stack);
void StackPop(Stack* stack);
int main() {
  int i = 0, num = 0, m;
  std::string comm;
  Queue queue;
  std::cin >> m;
  for (i = 0; i < m; i++) {
    std::cin >> comm;
    if (comm == "enqueue") {
      std::cin >> num;
      Enqueue(&queue, num);
    } else if (comm == "front") {
      Front(&queue);
    } else if (comm == "min") {
      Min(&queue);
    } else if (comm == "clear") {
      Clear(&queue);
    } else if (comm == "size") {
      std::cout << queue.size << std::endl;
    } else if (comm == "dequeue") {
      Dequeue(&queue);
    }
  }
  return 0;
}
void Enqueue(Queue* queue, int num) {
  queue->arr[queue->size + queue->head] = num;
  while (queue->min.arr[queue->min.head + queue->min.size - 1] > num &&
         queue->min.size != 0) {
    StackPop(&queue->min);
  }
  StackPush(&queue->min, num);
  queue->size++;
  std::cout << "ok" << std::endl;
}
void StackPush(Stack* stack, int num) {
  stack->arr[stack->size + stack->head] = num;
  stack->size++;
}
void StackPop(Stack* stack) {
  stack->size--;
  stack->arr[stack->size + stack->head] = 0;
}
void Dequeue(Queue* queue) {
  if (queue->size > 0) {
    if (queue->arr[queue->head] == queue->min.arr[queue->min.head]) {
      queue->min.head++;
      queue->min.size--;
    }
    std::cout << queue->arr[queue->head] << std::endl;
    queue->size--;
    queue->head++;
  } else {
    std::cout << "error" << std::endl;
  }
}
void Min(Queue* queue) {
  if (queue->size > 0) {
    std::cout << queue->min.arr[queue->min.head] << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}
void Clear(Queue* queue) {
  for (int i = queue->head; i < queue->size + queue->head; i++) {
    queue->arr[i] = 0;
  }
  queue->size = 0;
  StackClear(&queue->min);
  std::cout << "ok" << std::endl;
}
void Front(Queue* queue) {
  if (queue->size > 0) {
    std::cout << queue->arr[queue->head] << std::endl;
  } else {
    std::cout << "error" << std::endl;
  }
}
void StackClear(Stack* stack) {
  for (int i = stack->head; i < stack->size + stack->head; i++) {
    stack->arr[i] = 0;
  }
  stack->size = 0;
}
