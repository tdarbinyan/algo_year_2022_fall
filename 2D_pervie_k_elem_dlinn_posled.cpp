#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Heap {
  std::vector<uint64_t> arr;
};
void HeapifyForward(Heap* heap, int index) {
  int parent = (index - 1) / 2;
  if (heap->arr[parent] < heap->arr[index]) {
    std::swap(heap->arr[parent], heap->arr[index]);
    HeapifyForward(heap, parent);
  }
}
void HeapifyBack(Heap* heap, int index) {
  int left_child = 2 * index + 1;
  int right_child = 2 * index + 2;
  if (right_child < int(heap->arr.size())) {
    if (left_child < int(heap->arr.size()) &&
        heap->arr[left_child] > heap->arr[right_child] &&
        heap->arr[index] < heap->arr[left_child]) {
      std::swap(heap->arr[left_child], heap->arr[index]);
      HeapifyBack(heap, left_child);
    } else if (right_child < int(heap->arr.size()) &&
               heap->arr[index] < heap->arr[right_child]) {
      std::swap(heap->arr[right_child], heap->arr[index]);
      HeapifyBack(heap, right_child);
    }
  } else if (left_child < int(heap->arr.size()) &&
             heap->arr[index] < heap->arr[left_child]) {
    std::swap(heap->arr[left_child], heap->arr[index]);
    HeapifyBack(heap, left_child);
  }
}
void HeapInsert(Heap* heap, uint64_t num) {
  heap->arr.push_back(num);
  HeapifyForward(heap, heap->arr.size() - 1);
}
uint64_t HeapGetMax(Heap* heap) { return uint64_t(heap->arr[0]); }
void HeapExtractMax(Heap* heap) {
  heap->arr[0] = heap->arr[heap->arr.size() - 1];
  heap->arr.pop_back();
  if (!heap->arr.empty()) {
    HeapifyBack(heap, 0);
  }
}
int main() {
  Heap heap;
  int n, k;
  int x, y;
  uint64_t num;
  std::cin >> n >> k >> num >> x >> y;
  int heap_size = std::min(n, k);
  uint64_t* sort_arr = new uint64_t[heap_size];
  for (int i = 0; i < n; i++) {
    num = (num * x + y) % 1073741824;
    if (int(heap.arr.size()) < heap_size) {
      HeapInsert(&heap, num);
    } else if (num < heap.arr[0]) {
      heap.arr[0] = num;
      HeapifyBack(&heap, 0);
    }
  }
  for (int i = 1; i <= heap_size; i++) {
    sort_arr[heap_size - i] = HeapGetMax(&heap);
    HeapExtractMax(&heap);
  }
  for (int i = 0; i < heap_size; i++) {
    std::cout << sort_arr[i] << " ";
  }
  delete[] sort_arr;
}
