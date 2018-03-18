//
// Created by wuhuijun on 3/19/18.
//

#include <string>
#include <iostream>

using namespace std;

class TrieNode {
    //no need to store the letters

public:
    TrieNode() {
        isEnd = true;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    };

    TrieNode *next[26];
    bool isEnd;
    int sum = 0;

};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        //nothing needs to be done
    }

    /** Inserts a word into the trie. */
    //remember to deal with the overwrite
    void insert(string word, int val) {
        TrieNode *curr = root;
        pair<bool, int> search_ret = search(word);
        bool overwrite = search_ret.first;
        int value_gap = (overwrite) ? (val - search_ret.second) : 0;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next[word[i] - 'a']) {
                curr->next[word[i] - 'a'] = new TrieNode();
                if (i != word.size() - 1)
                    curr->next[word[i] - 'a']->isEnd = false;
            }
            if (overwrite)curr->sum += value_gap;
            else curr->sum += val;

            curr = curr->next[word[i] - 'a'];
        }


        if (overwrite)curr->sum += value_gap;
        else curr->sum += val;
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    pair<bool, int> search(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next[word[i] - 'a']) {
                return make_pair(false, -1);
            }
            curr = curr->next[word[i] - 'a'];
        }
        if (curr->isEnd)
            return make_pair(true, curr->sum);
        else
            return make_pair(false, -1);
    }

    int get_sum(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr)
                curr = curr->next[word[i] - 'a'];
            else
                return 0;
        }
        if (curr)
            return curr->sum;
        else
            return 0;
    }

private:
    TrieNode *root = new TrieNode();


};


class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        prefix_tree = Trie();
    }

    void insert(string key, int val) {
        prefix_tree.insert(key, val);
    }

    int sum(string prefix) {
        return prefix_tree.get_sum(prefix);
    }

private:
    Trie prefix_tree;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */


int main() {
    MapSum s = MapSum();
    s.insert("apple", 3);
    cout << s.sum("ap") << endl;
    s.insert("app", 2);
    cout << s.sum("ap") << endl;
}