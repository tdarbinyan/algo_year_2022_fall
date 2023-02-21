#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Heap {
  std::vector<uint64_t> arr;
};
// complete
void HeapifyForwardMax(Heap* heap, int index) {
  int parent = (index - 1) / 2;
  if (heap->arr[parent] < heap->arr[index]) {
    std::swap(heap->arr[parent], heap->arr[index]);
    HeapifyForwardMax(heap, parent);
  }
}
// complete
void HeapifyBackMax(Heap* heap, int index) {
  int left_child = 2 * index + 1;
  int right_child = 2 * index + 2;
  if (right_child < int(heap->arr.size())) {
    if (left_child < int(heap->arr.size()) &&
        heap->arr[left_child] > heap->arr[right_child] &&
        heap->arr[index] < heap->arr[left_child]) {
      std::swap(heap->arr[left_child], heap->arr[index]);
      HeapifyBackMax(heap, left_child);
    } else if (right_child < int(heap->arr.size()) &&
               heap->arr[index] < heap->arr[right_child]) {
      std::swap(heap->arr[right_child], heap->arr[index]);
      HeapifyBackMax(heap, right_child);
    }
  } else if (left_child < int(heap->arr.size()) &&
             heap->arr[index] < heap->arr[left_child]) {
    std::swap(heap->arr[left_child], heap->arr[index]);
    HeapifyBackMax(heap, left_child);
  }
}
// complete
void HeapInsertMax(Heap* heap, uint64_t num) {
  heap->arr.push_back(num);
  HeapifyForwardMax(heap, heap->arr.size() - 1);
  std::cout << "ok"
            << "\n";
}
// complete
void HeapGetMax(Heap* heap) {
  if (heap->arr.empty()) {
    std::cout << "error"
              << "\n";
  } else {
    std::cout << heap->arr[0] << "\n";
  }
}
// complete
void HeapExtractMax(Heap* heap) {
  if (heap->arr.empty()) {
    std::cout << "error"
              << "\n";
  } else {
    std::cout << heap->arr[0] << "\n";
    heap->arr[0] = heap->arr[heap->arr.size() - 1];
    heap->arr.pop_back();
    if (!heap->arr.empty()) {
      HeapifyBackMax(heap, 0);
    }
  }
}
// complete;
void HeapGetMin(Heap* heap) {
  if (heap->arr.empty()) {
    std::cout << "error"
              << "\n";
  } else {
    uint64_t minindex = heap->arr.size() / 2;
    for (int i = 1 + int(heap->arr.size()) / 2; i < int(heap->arr.size());
         ++i) {
      if (heap->arr[i] < heap->arr[minindex]) {
        minindex = i;
      }
    }
    std::cout << heap->arr[minindex] << "\n";
  }
}
// complete
void HeapExtractMin(Heap* heap) {
  if (heap->arr.empty()) {
    std::cout << "error"
              << "\n";
  } else {
    uint64_t minindex = heap->arr.size() / 2;
    for (int i = 1 + int(heap->arr.size()) / 2; i < int(heap->arr.size());
         ++i) {
      if (heap->arr[i] < heap->arr[minindex]) {
        minindex = i;
      }
    }
    std::cout << heap->arr[minindex] << "\n";
    heap->arr[minindex] = heap->arr[heap->arr.size() - 1];
    heap->arr.pop_back();
    if (!heap->arr.empty()) {
      HeapifyForwardMax(heap, minindex);
      HeapifyBackMax(heap, minindex);
    }
  }
}

void HeapClear(Heap* heap) {
  heap->arr.clear();
  std::cout << "ok"
            << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Heap heap;
  std::string s;
  int n, num;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> s;
    if (s == "insert") {
      std::cin >> num;
      HeapInsertMax(&heap, num);
    } else if (s == "get_max") {
      HeapGetMax(&heap);
    } else if (s == "extract_max") {
      HeapExtractMax(&heap);
    } else if (s == "get_min") {
      HeapGetMin(&heap);
    } else if (s == "extract_min") {
      HeapExtractMin(&heap);
    } else if (s == "clear") {
      HeapClear(&heap);
    } else if (s == "size") {
      std::cout << heap.arr.size() << "\n";
    }
  }
}
