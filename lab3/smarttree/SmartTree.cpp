//
// Created by kamila on 16.03.18.
//
#include <memory>
#include <string>
#include <ostream>
#include "SmartTree.h"


using std::make_unique;

std::unique_ptr <datastructures::SmartTree> datastructures::CreateLeaf(int value){
    auto leaf = make_unique<SmartTree>();
    leaf->value=value;
    leaf->left= nullptr;
    leaf->right= nullptr;

    return leaf;
}

std::unique_ptr <datastructures::SmartTree> datastructures::InsertLeftChild
        (std::unique_ptr<datastructures::SmartTree> tree,
         std::unique_ptr<datastructures::SmartTree> left_subtree){

    tree->left= std::move(left_subtree);
    return tree; //dlaczego przy tree->left wyrzuca blad
}

std::unique_ptr <datastructures::SmartTree> datastructures::InsertRightChild
        (std::unique_ptr<datastructures::SmartTree> tree,
         std::unique_ptr<datastructures::SmartTree> right_subtree){
    tree->right= move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder
        (const std::unique_ptr<datastructures::SmartTree> &unique_ptr,
         std::ostream *out){
    if (unique_ptr!= nullptr){
        PrintTreeInOrder(unique_ptr->left, out);
        *out <<unique_ptr->value<<", ";
        PrintTreeInOrder(unique_ptr->right, out);

    }

}
std::string datastructures::DumpTree
        (const std::unique_ptr<datastructures::SmartTree> &tree){
    std::string str;

    str+= "[" + std::to_string(tree->value);

    str+=" ";

    //[left.]
    if (tree->left != nullptr){
        str+=DumpTree(tree->left);
    }
    else{

        str+="[none]";
    }
    //[.left]

    str+=" ";

    //[right.]
    if (tree->right != nullptr){
        str+=DumpTree(tree->right);

    }
    else{
        str+="[none]";
    }
    //[.right]

    str+="]";

    return str;
}

std::unique_ptr <datastructures::SmartTree> datastructures::RestoreTree
        (const std::string &tree){

}