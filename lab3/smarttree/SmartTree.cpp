//
// Created by kamila on 16.03.18.
//
#include <memory>
#include <string>
#include <ostream>
#include <map>
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
        (const std::string &tree) {
    int i = 0;
    std::string val;
    int value;
    std::unique_ptr<SmartTree> ptr;

    if (tree[i] == '[') {
        i++;
        while (tree[i] != '[' && tree[i] != ' ') {
            val += tree[i];
            i++;
        }
        if (val != "none") {
            value = std::stoi(val);
            ptr = CreateLeaf(value);
        }
    }

    if (tree[i] == ' ') {
        i++;
        ptr->left = RestoreTree(&tree[i]);

        if (ptr->left == nullptr) {
            ptr->right = RestoreTree(&tree[i]);
        }
    }

    if (tree[i] == ']') {
        i++;
        return ptr;
    }
}








std::unique_ptr <datastructures::SmartTree> TESTRestoreTree
        (const std::string &tree){

    using namespace datastructures;
    int i =0;
    int jump =0;
    std::string val;
    int value;
    std::unique_ptr <SmartTree> *ptr = nullptr;
    std::unique_ptr <SmartTree> root;

    //create root of tree
    if (tree[i]=='['){
        i++;
        while (tree[i] != '[' || tree[i] != ' '){
            val+= tree[i];
            i++;
        }
        if (val != "none"){
            value = std::stoi( val );
            root = CreateLeaf(value);
            ptr=&(root->left);
            jump++;
            val.clear();
        }
    }


    while (i<tree.size()){

        if (tree[i]==' '){

            while(tree[i]!=']'){
                i++; //' '
                i++; //'['
                while (tree[i] != '[' || tree[i] != ' '){
                    val+= tree[i];
                    i++;
                }
                if (val != "none"){
                    value = std::stoi( val );
                    *ptr=CreateLeaf(value);
                    ptr = &((*ptr)->left);
                    jump++;
                    val.clear();
                }
            }
        }

        if (tree[i]==']'){
            i++; //']'

            ptr=&root;
            jump--;
            for (int j=1;j<=jump;j++){
                ptr = &((*ptr)->left);

            }

            while(tree[i]!=']'){

                i++; //' '
                i++; //'['
                ptr = &((*ptr)->right);
                while (tree[i] != ']' || tree[i] != ' '){
                    val+= tree[i];
                    i++;
                }
                if (val != "none"){
                    value = std::stoi( val );
                    *ptr=CreateLeaf(value);
                    ptr = &((*ptr)->left);
                    val.clear();
                }
            }
        }


    }
}