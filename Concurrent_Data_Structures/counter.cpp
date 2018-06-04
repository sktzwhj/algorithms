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
