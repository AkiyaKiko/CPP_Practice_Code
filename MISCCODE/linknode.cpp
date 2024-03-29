#include<iostream>

struct LinkNode{
    /* data */
    int val;
    LinkNode *next;
    LinkNode(int x):val(x),next(nullptr) {};
};

struct linkList {
    int length = 0;
    LinkNode *head;
    LinkNode *tail;
    linkList(LinkNode *head, LinkNode *tail):head(head),tail(tail){};
};

void InitLinkList (linkList *list, int head_Val_Acc) {
    LinkNode *head_new = new LinkNode(head_Val_Acc);
    list->head = head_new;
    list->tail = list->head;
    list->length++;
}

void tailInsertNode(linkList *list, int val_Acc) {
    LinkNode *new_Node = new LinkNode(val_Acc);
    list->tail->next = new_Node;
    list->tail = list->tail->next;
    list->length++;
}

void indexInsertNode(linkList *list, int val_New, int index) {
    if (index > (list->length-1)){std::cout << "index out of the range" << std::endl;}
    else{
        LinkNode *new_Node = new LinkNode(val_New);
        LinkNode *pointer = list->head;
        for(int i = 0; i < index; ++i){
            pointer = pointer->next;
        }
        new_Node->next = pointer->next->next->next;
        pointer->next->next = new_Node;

    }
    

}

void printLinkList(linkList *list) {
    LinkNode *pointer = list->head;
    if (pointer == nullptr) {
        std::cout << "null" << std::endl;
        return;
    }
    while (pointer != nullptr) {
        std::cout << pointer->val << std::endl;
        pointer = pointer->next;
    }
}

int main () {
    linkList *lList = new linkList(nullptr,nullptr);
    int headVal = 5;
    InitLinkList(lList, headVal);
    tailInsertNode(lList, 6);
    indexInsertNode(lList, 1, 4);
    // std::cout << lList->length << std::endl;
    printLinkList(lList);
    return 0;
}