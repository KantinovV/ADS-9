// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string dobavit;
  std::string liniy;
  std::string tekst;
  while (std::getline(file, liniy)) {
    tekst = tekst + liniy + " ";
  }
  for (auto a : tekst) {
    if (isalpha(a)) {
      a = tolower(a);
      dobavit += a;
    } else {
      tree.addElement(dobavit);
      dobavit = "";
    }
  }
  file.close();
  return tree;
}
