#pragma once
#include <iostream>
#include "list_node.h"
//#include <catch2/catch_test_macros.hpp>
//#include <catch2/catch_session.hpp>

class List {
public:

    List();
    virtual ~List();

    bool Empty();

    unsigned long Size();

    void PushFront(int value);
    
    void PushBack(int value);

    int PopFront();
   
    int PopBack();
    
    void Clear();
    
private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;

    ListNode* extractPrev(ListNode* node);





};
