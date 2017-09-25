//
// Created by wuhuijun on 9/25/17.
//

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
#include<vector>

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual ~Iterator();

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int peekValue = 0;
    bool peekValid = 0;

    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!peekValid) {
            peekValue = Iterator::next();
            peekValid = 1;
        }
        return peekValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (peekValid) {
            peekValid = 0;
            return peekValue;
        } else {
            return Iterator::next();
        }

    }

    bool hasNext() const {
        if (peekValid || Iterator::hasNext())
            return 1;
        else
            return 0;
    }
};