#include <iostream>
#include <string>

struct Node {
  std::string first_key;
  std::string second_key;
  Node* left;
  Node* right;
};
void DeleteTree(Node* root);
Node* LeftRotate(Node* node);
Node* RightRotate(Node* node);
Node* TreeSplay(Node* root, std::string key);
Node* AddNode(std::string first_key, std::string second_key);
Node* InsertNode(Node* root, std::string first_key, std::string second_key);
int main() {
  int n;
  int q;
  std::string first_key;
  std::string second_key;
  std::string quest;
  std::cin >> n;
  std::cin >> first_key >> second_key;
  Node* root = AddNode(first_key, second_key);
  root = InsertNode(root, second_key, first_key);
  for (int i = 1; i < n; i++) {
    std::cin >> first_key >> second_key;
    root = InsertNode(root, first_key, second_key);
    root = InsertNode(root, second_key, first_key);
  }
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> quest;
    root = TreeSplay(root, quest);
    std::cout << root->second_key << "\n";
  }
  DeleteTree(root);
  return 0;
}
void DeleteTree(Node* root) {
  if (root->left != nullptr) {
    DeleteTree(root->left);
  }
  if (root->right != nullptr) {
    DeleteTree(root->right);
  }
  delete root;
}
Node* AddNode(std::string first_key, std::string second_key) {
  Node* node = new Node;
  node->first_key = first_key;
  node->second_key = second_key;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}
Node* RightRotate(Node* node) {
  Node* swapnode = node->left;
  node->left = swapnode->right;
  swapnode->right = node;
  return swapnode;
}
Node* LeftRotate(Node* node) {
  Node* swapnode = node->right;
  node->right = swapnode->left;
  swapnode->left = node;
  return swapnode;
}
Node* TreeSplay(Node* root, std::string key) {
  if (root == nullptr || root->first_key == key) {
    return root;
  }
  if (root->first_key > key) {
    if (root->left == nullptr) {
      return root;
    }
    if (root->left->first_key > key) {
      root->left->left = TreeSplay(root->left->left, key);
      root = RightRotate(root);
    } else if (root->left->first_key < key) {
      root->left->right = TreeSplay(root->left->right, key);
      if (root->left->right != nullptr) {
        root->left = LeftRotate(root->left);
      }
    }
    if (root->left == nullptr) {
      return root;
    }
    return RightRotate(root);
  }
  if (root->right == nullptr) {
    return root;
  }
  if (root->right->first_key > key) {
    root->right->left = TreeSplay(root->right->left, key);
    if (root->right->left != nullptr) {
      root->right = RightRotate(root->right);
    }
  } else if (root->right->first_key < key) {
    root->right->right = TreeSplay(root->right->right, key);
    root = LeftRotate(root);
  }
  if (root->right == nullptr) {
    return root;
  }
  return LeftRotate(root);
}
Node* InsertNode(Node* root, std::string first_key, std::string second_key) {
  if (root == nullptr) {
    return AddNode(first_key, second_key);
  }
  root = TreeSplay(root, first_key);
  if (root->first_key == first_key) {
    return root;
  }
  Node* newnode = AddNode(first_key, second_key);
  if (root->first_key > first_key) {
    newnode->right = root;
    newnode->left = root->left;
    root->left = nullptr;
  } else {
    newnode->left = root;
    newnode->right = root->right;
    root->right = nullptr;
  }
  return newnode;
}
