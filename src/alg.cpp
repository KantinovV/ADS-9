// Copyright 2021 NNTU-CS
#include  <fstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string vihefdlhf;;
    while (!file.eof()) {
        char hytttytt = file.get();
        if (hytttytt >= 65 && hytttytt <= 90) {
            hytttytt += 32;
            vihefdlhf += hytttytt;
            continue;
        }
        if (hytttytt >= 97 && hytttytt <= 122) {
            vihefdlhf += hytttytt;
        } else {
            if (!vihefdlhf.empty()) {
                bst.addVal(vihefdlhf);
            }
            vihefdlhf.clear();
        }
    }
    bst.addVal(vihefdlhf);
    file.close();
    return bst;
}
