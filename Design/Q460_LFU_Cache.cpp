//
// Created by wu061 on 19/12/17.
//

#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

/*
 * if we want to make it O(1) time complexity, a hash table can be used to track the items.
 * since maintaining a sort order of frequency requires at least O(logn) complexity.
 * to achieve O(1), we can store the list with the same frequency together as a list.
 * every time a node is accessed, move it to the front of the list.
 */


class LFUCache {
public:
    LFUCache(int capacity) {
        cacheCapacity = capacity;
        currentSize = 0;
    }

    int get(int key)
    {
        if(keyNodeMap.find(key) == keyNodeMap.end()) return -1;

        int value = keyNodeMap[key].first;
        int itemFreq = keyNodeMap[key].second;

        freqLists[itemFreq].erase(keyPosMap[key]);
        freqLists[itemFreq + 1].push_back(key);
        keyPosMap[key] = --freqLists[itemFreq + 1].end();
        keyNodeMap[key].second++;
        if(freqLists[minFreq].size()==0)
            minFreq++;
        return value;
    }

    void put(int key, int value) {
        if(cacheCapacity <= 0) return;

        int old_value = get(key);
        if(old_value != -1)
        {
            keyNodeMap[key].first = value;
            return;
        }

        if(currentSize >= cacheCapacity)
        {
            int toEvict = freqLists[minFreq].front();
            keyPosMap.erase(toEvict);
            keyNodeMap.erase(toEvict);
            freqLists[minFreq].pop_front();
            currentSize--;
        }

        keyNodeMap[key] = {value,1};
        freqLists[1].push_back(key);
        minFreq = 1;
        keyPosMap[key] = --freqLists[1].end();
        currentSize++;

    }

private:
    int cacheCapacity;
    int currentSize;
    int minFreq;
    unordered_map<int, pair<int,int>> keyNodeMap;
    unordered_map<int, std::list<int>> freqLists;
    unordered_map<int, std::list<int>::iterator> keyPosMap;
};



int main()
{
    LFUCache obj = LFUCache(1);
    int param_1 = obj.get(100);
    obj.put(100,1);
    obj.put(10,1);
    param_1 = obj.get(100);
}
