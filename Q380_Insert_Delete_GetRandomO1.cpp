//
// Created by wu061 on 23/09/17.
//
/*
 * Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 */
#include<unordered_map>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class RandomizedSet {
public:

    int current_pos = 0;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hmap.find(val) != hmap.end())
            return 0;
        else {

            hmap[val] = current_pos;
            data.push_back(val);
            current_pos++;
            return 1;
        }

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hmap.find(val) != hmap.end()) {

            int pos = hmap[val];
            data[pos] = data[current_pos - 1];
            hmap[data[current_pos - 1]] = pos;
            hmap.erase(val);
            data.pop_back();
            current_pos--;

            return 1;
        }
        return 0;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];

    }

private:
    unordered_map<int, int> hmap;
    vector<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    RandomizedSet r = RandomizedSet();
    cout << r.insert(0);
    cout << r.insert(1);
    cout << r.remove(0);
    cout << r.insert(2);
    cout << r.remove(1);
    cout << r.getRandom();
}
