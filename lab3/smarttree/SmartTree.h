//
// Created by kamila on 16.03.18.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <iostream>
#include <memory>
#include <map>

namespace datastructures{

    struct SmartTree{
        std::unique_ptr <SmartTree> left;
        std::unique_ptr <SmartTree> right;
        int value;
    };

    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);
    std::unique_ptr <SmartTree> HelpRestoreTree(const std::string &tree, int* pint);
}



#endif //JIMP_EXERCISES_SMARTTREE_H
