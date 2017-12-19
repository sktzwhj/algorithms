//
// Created by wuhuijun on 12/19/17.
//

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<assert.h>

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
        existWord.insert(word);
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
    bool search(const string word) {
        //cout<<"word"<<word<<endl;
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            //cout<<i<<endl;
            for (int j = 0; j < 26; j++) {
                if(!curr)
                    return false;
                if ((curr->next[j])&&(j != word[i] - 'a')) {
                    string tmp_word(word);
                    tmp_word[i] = 'a' + j;
                    //cout << word << endl;
                    if (existWord.count(tmp_word) > 0)
                        return true;
                }
            }
            curr = curr->next[word[i] - 'a'];
        }
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
    set<string> existWord;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        wordTrie = Trie();
        for (string word:dict) {
            wordTrie.insert(word);
            //cout << "insert" << word << endl;
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return wordTrie.search(word);
    }

private:
    Trie wordTrie;

};