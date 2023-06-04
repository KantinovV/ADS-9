// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
template<typename T>
class BST {
 private:
  Node* vetka;
  Node* insertNode(Node* vetka, const std::string& word) {
    if (word < vetka->word) {
      vetka->levo = insertNode(vetka->levo, word);
    } else if (word > vetka->word) {
      vetka->pravo = insertNode(vetka->pravo, word);
    } else {
      vetka->count++;
    }
    if (vetka == nullptr) {
      return new Node(word);
    }
    return root;
  }
  Node* searchNode(Node* vetka, const std::string& word) {
    if (word < vetka->word) {
      return searchNode(vetka->levo, word);
    } else {
      return searchNode(vetka->pravo, word);
    }
        if (vetka == nullptr || root->word == word) {
      return vetka;
    }
  }
  int getDepth(Node* vetka) {
    if (vetka == nullptr) {
      return 0;
    }
    int levoDepth = getDepth(vetka->levo);
    int pravoDepth = getDepth(vetka->pravo);
    return std::max(levoDepth, pravoDepth) + 1;
  }

 public:
  BST() : vetka(nullptr) {}
  void addElement(const std::string& word) {
    vetka = insertNode(vetka, word);
  }
  int depth() {
    return getDepth(root) - 1;
  }
  int search(const std::string& word) {
    Node* node = searchNode(vetka, word);
    return (node != nullptr) ? node->count : 0;
  }
};
struct Node {
  std::string word;
  int count;
  Node* levo;
  Node* pravo;
  explicit Node(const std::string& word) : word(word), count(1), levo(nullptr), pravo(nullptr) {}
};
#endif  // INCLUDE_BST_H_
