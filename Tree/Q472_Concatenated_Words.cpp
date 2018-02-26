//
// Created by wu061 on 26/02/18.
//

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/*
 * Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
 *
 * Idea: This problem seems to be a good fit to trie. We can first build a trie for all words. If the components of a
 * word can be found in the trie (not as a whole), it is  a concatenated word.
 */


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
    void insert(string &word) {
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

    /** Returns all the possible match lengths of a word in the trie. */
    vector<int> search(string &word) {
        vector<int> match_lens;
        TrieNode *curr = root;
        int len = 0;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->next[word[i] - 'a']) {
                return match_lens;
            }
            curr = curr->next[word[i] - 'a'];
            len++;
            if (curr->isEnd) match_lens.push_back(len);
        }
        return match_lens;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix) {
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
    TrieNode dummy;
    TrieNode *root = &dummy;
};


class Solution {
public:
    bool concatCheck(Trie &t, string word) {
        //cout<<"word:"<<word<<endl;
        if (word.length() == 0) return true;
        vector<int> match_lens = t.search(word);
        if (match_lens.size() == 0) return false;
        reverse(match_lens.begin(), match_lens.end());
        for (int len:match_lens) {
            //cout<<"len="<<len<<endl;
            if (concatCheck(t, word.substr(len, word.length() - len))) return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        Trie wordTrie;
        vector<string> res;
        //to accelerate the computation, we can sort the words according to their length first
        sort(words.begin(), words.end(), [](const string &left, const string &right) {
            return left.length() < right.length();
        });
        for (string word:words) {
            if (word.length() > 0 && concatCheck(wordTrie, word)) res.push_back(word);
            wordTrie.insert(word);
        }
        return res;
    }
};

int main() {
    string a[] = {"a", "aa", "aaa"};
    vector<string> input = vector<string>(a, a + 3);
    Solution s = Solution();
    for (auto e:s.findAllConcatenatedWordsInADict(input)) cout << e << endl;
}