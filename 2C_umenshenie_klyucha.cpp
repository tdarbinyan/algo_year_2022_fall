#include <iostream>
#include <string>
#include <vector>

struct Heap {
  std::vector<int64_t> arr;
  std::vector<uint64_t> request;
};
void HeapifyForward(Heap* heap, int index) {
  int parent = (index - 1) / 2;
  if (heap->arr[parent] > heap->arr[index]) {
    std::swap(heap->arr[parent], heap->arr[index]);
    std::swap(heap->request[parent], heap->request[index]);
    HeapifyForward(heap, parent);
  }
}
void HeapifyBack(Heap* heap, int index) {
  int left_child = 2 * index + 1, right_child = 2 * index + 2;
  if (right_child < int(heap->arr.size())) {
    if (left_child < int(heap->arr.size()) &&
        heap->arr[left_child] < heap->arr[right_child] &&
        heap->arr[index] > heap->arr[left_child]) {
      std::swap(heap->arr[left_child], heap->arr[index]);
      std::swap(heap->request[left_child], heap->request[index]);

      HeapifyBack(heap, left_child);
    } else if (right_child < int(heap->arr.size()) &&
               heap->arr[index] > heap->arr[right_child]) {
      std::swap(heap->arr[right_child], heap->arr[index]);
      std::swap(heap->request[right_child], heap->request[index]);
      HeapifyBack(heap, right_child);
    }
  } else if (left_child < int(heap->arr.size()) &&
             heap->arr[index] > heap->arr[left_child]) {
    std::swap(heap->arr[left_child], heap->arr[index]);
    std::swap(heap->request[left_child], heap->request[index]);
    HeapifyBack(heap, left_child);
  }
}
void HeapInsert(Heap* heap, int num, int req) {
  heap->arr.push_back(num);
  heap->request.push_back(req);
  HeapifyForward(heap, heap->arr.size() - 1);
}
void HeapGetMin(Heap* heap) { std::cout << heap->arr[0] << "\n"; }
void HeapExtractMin(Heap* heap) {
  heap->arr[0] = heap->arr[heap->arr.size() - 1];
  heap->request[0] = heap->request[heap->request.size() - 1];
  heap->arr.pop_back();
  heap->request.pop_back();
  if (!heap->arr.empty()) {
    HeapifyBack(heap, 0);
  }
}
void HeapDecreaseKey(Heap* heap, unsigned int num, int delta) {
  for (int i = 0; i < int(heap->request.size()); i++) {
    if (heap->request[i] == num) {
      heap->arr[i] -= delta;
      HeapifyForward(heap, i);
      return;
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Heap heap;
  std::string s;
  int n, num, delta;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> s;
    if (s == "insert") {
      std::cin >> num;
      HeapInsert(&heap, num, i);
    } else if (s == "getMin") {
      HeapGetMin(&heap);
    } else if (s == "extractMin") {
      HeapExtractMin(&heap);
    } else if (s == "decreaseKey") {
      std::cin >> num >> delta;
      HeapDecreaseKey(&heap, num, delta);
    }
  }
}
