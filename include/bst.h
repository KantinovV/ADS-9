// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

struct Node {
  std::string word;
  int count;
  Node* levo;
  Node* pravo;
  explicit Node(const std::string& word) : word(word), count(1), levo(nullptr), pravo(nullptr) {}
};
template<typename T>
class BST {
 private:
  Node* root;
  Node* insertNode(Node* root, const std::string& word) {
    if (word < root->word) {
      root->levo = insertNode(root->levo, word);
    } else if (word > root->word) {
      root->pravo = insertNode(root->pravo, word);
    } else {
      root->count++;
    }
    if (root == nullptr) {
      return new Node(word);
    }
   
    return root;
  }
  Node* searchNode(Node* root, const std::string& word) {
    if (root == nullptr || root->word == word) {
      return root;
    }
    if (word < root->word) {
      return searchNode(root->levo, word);
    } else {
      return searchNode(root->pravo, word);
    }
  }
  int datitiDepth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int levoDepth = datitiDepth(root->levo);
    int pravoDepth = datitiDepth(root->pravo);
    return std::max(levoDepth, pravoDepth) + 1;
  }
 public:
  BST() : root(nullptr) {}
   int depth() {
    return datitiDepth(root) - 1;
  }
   int sortirovka(const std::string& word) {
    Node* node = searchNode(root, word);
    return (node != nullptr) ? node->count : 0;
  }
  void addElement(const std::string& word) {
    root = insertNode(root, word);
  }
};
#endif  // INCLUDE_BST_H_
