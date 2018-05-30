//
// Created by owsikami on 30.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

namespace tree{

    template <class Element>
    typedef struct node{
        Element key;
        std::unique_ptr<node> right, left;
    }Node;

    template <class Element>
    Node * NewNode(Element key ){
        Node * new_node = (Node *)malloc(sizeof(Node));
        new_node->key= key;
        new_node->right =new_node->left=nullptr;

        return new_node;
}

    template <class Element>
    class Tree {
    public:
        Tree():head(nullptr){}
        Tree(Element x):head(NewNode(x)){}

        void Insert(const Element &e);
        bool Find(const Element &e);
        size_t Depth();
        size_t Size();
        Element Value();

    private:
        Node * head;

    };

    template <class Element>
    bool Tree<Element>::Find(const Element &e) {
        Node * temp = head;

        while(temp!= nullptr){
            if( temp->key==e){
                return true;
            }

            else if(temp->key<e){
                //right
                temp=temp->right.get();


            }
            else{ // >e
                temp=temp->left.get();
                //left

            }
        }

        return false;
    }



    //make uniqe <tree> v
    template <class Element>
    void Tree<Element>::Insert(const Element &e) {

    }
}



#endif //JIMP_EXERCISES_TREE_H
