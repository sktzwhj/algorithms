//
// Created by wu061 on 10/12/17.
//

#include<string>
#include<iostream>

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

};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        //nothing needs to be done
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next[word[i] - 'a']) {
                curr->next[word[i] - 'a'] = new TrieNode();
                if (i != word.size() - 1)
                    curr->next[word[i] - 'a']->isEnd = false;
            }
            curr = curr->next[word[i] - 'a'];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next[word[i] - 'a']) {
                return false;
            }
            curr = curr->next[word[i] - 'a'];
        }
        if (curr->isEnd)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->next[prefix[i] - 'a']) {
                return false;
            }
            curr = curr->next[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode *root = new TrieNode();


};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */