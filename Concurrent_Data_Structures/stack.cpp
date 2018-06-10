//
// Created by wu061 on 10/06/18.
//

//shared stack. for a general and industry-level implementation, one would better refer to Intel TBB library.
//the STL lib would not provide the concurrent data structure feature as a whole to ensure the general use.
//the requirements of concurrent data structures mostly depend on specific applications.

/*
 * it would be easy to use lock to implement a stack. however, locks may make it inefficient when we are only use in
 * single-thread scenarios. A lock-free solution is to use CAS to modify the head of the stack. However, it may lead
 * to a typical problem named 'ABA' which means that the entire stack (except the head) has changed before CAS opeations
 * are actually tried by the threads.
 */

#include <iostream>
#include <atomic>

template <typename T> class stack_node {
public:
    stack_node(T val) {
        value_ = val;
        next_ = NULL;
    }

    ~stack_node() {
        delete next_;
    }

    T value_;
    stack_node* next_;
};

template <typename T> class concurrent_stack {
public:
    concurrent_stack() {
        head_ = NULL;
    }

    bool push(T val) {
        stack_node* curr;
        do {
            curr = new stack_node(val);
            curr->next_ = head_;
            //curr->next = head; head = curr;

        } while(!std::atomic_compare_exchange_strong(&head_, &curr->next_, curr));
        ++size_;
        //need to consider the lock for size as well.
    }

    void pop() {
        __sync_val_compare_and_swap(&head_, head_, head_->next_);
    }

private:
    std::atomic<stack_node*> head_;
    int size_;
};