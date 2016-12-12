#ifndef __STACKLINKEDLIST_H__
#define __STACKLINKEDLIST_H__

#include "../Part1/defines.h"

struct node {
    uint32_t id;
    node* next;
};

class Stack {
	uint32_t size;
    node* top_;   
public:
    Stack() {
    	size = 0;
        top_ = NULL;
    }
    void push(uint32_t); 
    uint32_t pop(); 
   	uint32_t top(); 
    bool isEmpty();
    uint32_t getSize();
};

#endif
