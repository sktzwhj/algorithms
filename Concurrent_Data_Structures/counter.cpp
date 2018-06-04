//
// Created by wu061 on 4/06/18.
//

//a shared counter implemented by combining tree.

//the simplest counter, sequential

#include <mutex>
#include <thread>
#include <iostream>

class counter {
public:
    counter() {
        count = 0;
    }

    int increase() {
        int old_val = count;
        count = old_val + 1;
        return old_val;
    }

private:
    int count;
};


class counter_lock {
public:
    counter_lock() {
        count = 0;
    }

    int increase() {
        cnt_lock.lock();
        int old_val = count;
        count = count + 1;
        cnt_lock.unlock();
        return old_val;
    }

    int get_count() {
        return count;
    }

private:
    int count;
    std::mutex cnt_lock;
};
/*
 * class combing_tree {
private:

};

 */

class counter_combing_tree {
public:
    counter_combing_tree() {
        count = 0;
    }

    int get_count() {
        return count;
    }

private:
    int count;
};

enum node_status {
    IDLE, FIRST, SECOND, RESULT, ROOT
};

class combining_tree {
    class node {
    public:
        node() {
            node_count = 0;
            locked = false;
        }

        int pre_combining() {
            __sync_bool_compare_and_swap(&this->locked, false, true);
        }

    private:
        int node_count;
        bool locked;
        std::mutex node_lock;
        node_status status;
        //active thread: first value, passive thread: second value
        int first_value, second_value;
        //result fetched by the active thread.
        int result;
    };

public:
    combining_tree(int n_thread) {
        /*
         * n_thread is the max number of threads which are supported by the combining tree. we assume n_thread must be
         * power of 2 here. we can use an array to store the complete binary tree.
         */
        tree = new node[2 * n_thread];
    }



private:
    node *tree;

};

int main()
{
    counter_lock c;
    std::thread t[10000];
    for(int i = 0; i < 10000; i++) {
        t[i] = std::thread(std::bind(&counter_lock::increase, &c));
    }
    //std::thread t2(std::bind(&counter_lock::increase, &c));
    //std::thread t3(std::bind(&counter_lock::increase, &c));
    for(int i = 0; i < 10000; i++) {
        t[i].join();
    }
    std::cout<<c.get_count()<<std::endl;
}
