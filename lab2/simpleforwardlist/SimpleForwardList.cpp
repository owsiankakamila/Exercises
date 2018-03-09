//
// Created by kamila on 06.03.18.
//

#include "SimpleForwardList.h"



ForwardList *CreateNode(int value){
    ForwardList *head= new ForwardList;
    head->value=value;
    head->next= nullptr;
   return head;
}
void DestroyList(ForwardList *list){
    ForwardList *ptr= list->next;
    delete list;
    while (ptr != nullptr){
        //delete
        ptr = ptr->next;
    }


}
ForwardList *PushFront(ForwardList *list, int value){

}
void Append(ForwardList *list, ForwardList *tail){

}
