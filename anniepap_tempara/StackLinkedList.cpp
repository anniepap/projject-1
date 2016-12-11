#include<iostream>
#include "StackLinkedList.h"
using namespace std;

void Stack::push(uint32_t id) {
    size++;
    node* ptr;
    ptr = new node();
    ptr->id = id;
    ptr->next = NULL;
    if(top_ != NULL)
        ptr->next = top_;
    top_ = ptr;
}

uint32_t Stack::pop() {
    size--;
    node* temp;
    temp = top_;
    top_ = top_->next;
    uint32_t value = temp->id;
    delete temp;
    return value;
}

uint32_t Stack::top() {
	return top_->id;
}

bool Stack::isEmpty() {
    return top_ == NULL;
}

uint32_t Stack::getSize() {
    return size;
}