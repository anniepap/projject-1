#ifndef __STACKLINKEDLIST_H__
#define __STACKLINKEDLIST_H__

class node {
    int data;
    node* next;
};

class Stack {
	uint32_t size;
    node* top;   
public:
    Stack() {
    	size = 0;
        top = NULL;
    }
    void push(); 
    void pop();  
    bool empty();
    uint32_t getSize();
};

#endif