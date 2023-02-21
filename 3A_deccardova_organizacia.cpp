#include <iostream>
#include <vector>

struct Node {
  int prior;
  int index;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int prior, int index) {
    this->prior = prior;
    this->index = index;
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
  }
};
void DeleteTree(Node* treap);
Node* LinearBuild(Node* last, int prior, int index) {
  if (index == 1) {
    Node* node = new Node(prior, index);
    return node;
  }
  if (prior > last->prior) {
    Node* node = new Node(prior, index);
    node->left = last->right;
    if (last->right != nullptr) {
      last->right->parent = node;
    }
    node->parent = last;
    last->right = node;
    return node;
  }
  if (last->parent == nullptr) {
    last->parent = new Node(prior, index);
    last->parent->left = last;
    return last->parent;
  }
  return LinearBuild(last->parent, prior, index);
}
void DeleteTree(Node* treap) {
  if (treap->left != nullptr) {
    DeleteTree(treap->left);
  }
  if (treap->right != nullptr) {
    DeleteTree(treap->right);
  }
  delete treap;
}
Node* GetToRoot(Node* treap) {
  while (treap != nullptr && treap->parent != nullptr) {
    treap = treap->parent;
  }
  return treap;
}
int main() {
  std::vector<Node*> order_of_treap;
  Node* treap = nullptr;
  int n;
  int a;
  int b;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a >> b;
    treap = LinearBuild(treap, b, i);
    order_of_treap.push_back(treap);
  }
  std::cout << "YES"
            << "\n";
  for (int i = 0; i < n; i++) {
    if (order_of_treap[i]->parent != nullptr) {
      std::cout << order_of_treap[i]->parent->index << " ";
    } else {
      std::cout << 0 << " ";
    }
    if (order_of_treap[i]->left != nullptr) {
      std::cout << order_of_treap[i]->left->index << " ";
    } else {
      std::cout << 0 << " ";
    }
    if (order_of_treap[i]->right != nullptr) {
      std::cout << order_of_treap[i]->right->index << "\n";
    } else {
      std::cout << 0 << "\n";
    }
  }
  DeleteTree(GetToRoot(treap));
}
