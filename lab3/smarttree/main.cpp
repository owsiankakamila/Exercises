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
    std::string tree="[99 [100 [1234 [none] [none]] [4321 [none] [none]]] ";
    std::string val;

    for (int i=0;i<tree.size();i++){
        i++;
        while (tree[i] != '[' && tree[i] != ' ') {
            val += tree[i];
            std::cout<<val<<std::endl;
            i++;
        }
    }



    return 0;
}