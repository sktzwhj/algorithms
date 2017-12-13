//
// Created by wu061 on 13/12/17.
//

#include<unordered_map>
#include<iostream>

using namespace std;

class CacheNode {
public:
    CacheNode(int node_key, int value, CacheNode *pre_node, CacheNode *next_node) {
        key = node_key;
        val = value;
        prev = pre_node;
        next = next_node;
    }

    int key, val;
    CacheNode *prev = NULL, *next = NULL;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        keyMap = unordered_map<int, CacheNode *>();
        head = new CacheNode(0, 0, NULL, NULL);
        tail = new CacheNode(0, 0, NULL, NULL);
        head->next = tail;
        tail->prev = head;
        cacheCapacity = capacity;
    }

    int get(int key) {
        cout << "get " << key << endl;
        if (keyMap.find(key) != keyMap.end()) {
            int retValue = keyMap[key]->val;
            CacheNode *keyNext = keyMap[key]->next;
            keyMap[key]->prev->next = keyNext;
            keyNext->prev = keyMap[key]->prev;
            CacheNode *headNext = head->next;
            keyMap[key]->prev = head;
            head->next = keyMap[key];
            headNext->prev = keyMap[key];
            keyMap[key]->next = headNext;
            return retValue;
        } else
            return -1;

    }

    void put(int key, int value) {
        cout << "put" << " " << key << " " << value << endl;
        if (currentSize < cacheCapacity && keyMap.find(key) == keyMap.end()) {
            keyMap[key] = new CacheNode(key, value, head, head->next);
            CacheNode *headNext = head->next;
            head->next = keyMap[key];
            headNext->prev = keyMap[key];
            currentSize++;
        } else {
            if (cacheCapacity > 0) {
                if (keyMap.find(key) == keyMap.end()) {
                    CacheNode *tmp = tail->prev;
                    keyMap.erase(tmp->key);
                    tmp->key = key;
                    tmp->val = value;
                    tmp->prev->next = tail;
                    tail->prev = tmp->prev;
                    CacheNode *tmpHeadNext = head->next;
                    tmp->next = tmpHeadNext;
                    head->next = tmp;
                    tmp->prev = head;
                    tmpHeadNext->prev = tmp;
                    keyMap[key] = tmp;
                } else {
                    keyMap[key]->val = value;
                    CacheNode *keyNext = keyMap[key]->next;
                    keyMap[key]->prev->next = keyNext;
                    keyNext->prev = keyMap[key]->prev;
                    CacheNode *headNext = head->next;
                    head->next = keyMap[key];
                    keyMap[key]->prev = head;
                    keyMap[key]->next = headNext;
                    headNext->prev = keyMap[key];
                }

            }
        }

    }

private:
    CacheNode *head, *tail;
    unordered_map<int, CacheNode *> keyMap;
    int currentSize = 0;
    int cacheCapacity = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */