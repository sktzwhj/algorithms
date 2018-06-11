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
#include <thread>
#include <functional>
#include <mutex>


bool DEBUG = true;
std::mutex output_lock;
std::mutex cnt_lock;


template<typename T>
class stack_node {
public:
    stack_node(T val) {
        value_ = val;
        next_ = NULL;
    }

    ~stack_node() {
        delete next_;
    }

    T value_;
    stack_node<T> *next_;
};

template<typename T>
class concurrent_stack {
public:
    concurrent_stack() {
        head_.store(NULL);
        size_.store(0);
    }

    bool push(T val) {
        stack_node<T> *curr;
        do {
            curr = new stack_node(val);
            curr->next_ = head_;
            //curr->next = head; head = curr
        } while (!std::atomic_compare_exchange_strong(&head_, &curr->next_, curr));
        //need to consider the lock for size as well.
        int size;
        int size_inc;
        do {
            size = size_;
            size_inc = size + 1;
            //curr->next = head; head = curr
        } while (!std::atomic_compare_exchange_strong(&size_, &size, size_inc));
        if (DEBUG) {
            std::unique_lock<std::mutex> ol(output_lock);
            std::cout << "push " << val << std::endl;
            std::cout << "stack size = " << size_inc << std::endl;
        }
    }

    T top() {
        stack_node<T> *top;
        T top_val;
        do {
            top = head_;
            if (top == NULL) exit(1);
            else top_val = top->value_;
            //curr->next = head; head = curr;
        } while (!std::atomic_compare_exchange_strong(&head_, &top, top));
        if (DEBUG) {
            std::unique_lock<std::mutex> ol(output_lock);
            std::cout << "top value = " << top_val << std::endl;
        }
        return top_val;
    }


    void pop() {
        //head_ = head_ -> next
        stack_node<T> *top;
        do {
            top = head_.load();
            //curr->next = head; head = curr;
            if (top == NULL) return;

        } while (!std::atomic_compare_exchange_strong(&head_, &top, top->next_));
        int size;
        int size_dec;
        do {
            size = size_;
            size_dec = size - 1;
            //curr->next = head; head = curr
        } while (!std::atomic_compare_exchange_strong(&size_, &size, size_dec));
        if (DEBUG) {
            std::unique_lock<std::mutex> ol(output_lock);
            std::cout << "pop " << std::endl;
            std::cout << "stack size = " << size_dec << std::endl;
        }
        //delete top;

    }

private:
    std::atomic<stack_node<T> *> head_;
    std::atomic<int> size_;
};

#define THREAD_NUM 8

int main() {
    concurrent_stack s = concurrent_stack<int>();
    std::thread t_push[THREAD_NUM];
    std::thread t_pop[THREAD_NUM];
    std::thread t_top[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++) {
        t_push[i] = std::thread(std::bind(&concurrent_stack<int>::push, &s, i));
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t_pop[i] = std::thread(std::bind(&concurrent_stack<int>::pop, &s));
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t_top[i] = std::thread(std::bind(&concurrent_stack<int>::top, &s));
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t_push[i].join();
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t_pop[i].join();
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        t_top[i].join();
    }
}