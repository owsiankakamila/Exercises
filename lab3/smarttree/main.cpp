//
// Created by kamila on 16.03.18.
//

#include "SmartTree.h"
using namespace datastructures;
int main(){
    std::unique_ptr <SmartTree> x;
    std::unique_ptr <SmartTree> root= CreateLeaf(8);
    std::unique_ptr <SmartTree> child= CreateLeaf(9);
    x= InsertLeftChild(std::move(root),std::move(child));
    std::string y ="lal";
    int z =5;
    y += std::to_string(x->value);

    std::cout<<DumpTree(x);
    return 0;
}