#include<iostream>
#include "StackLinkedList.h"
using namespace std;

void Stack::push(uint32_t value) {
    size++;
    node* ptr;
    ptr = new node;
    ptr->data = value;
    ptr->next = NULL;
    if(top != NULL)
        ptr->next = top;
    top = ptr;
}

uint32_t stack::pop() {
    size--;
    node* temp;
    temp = top;
    top = top->next;
    uint32_t value = temp->data;
    delete temp;
    return value;
}

bool stack::empty() {
    return top == NULL;
}

uint32_t getSize() {
    return size;
}