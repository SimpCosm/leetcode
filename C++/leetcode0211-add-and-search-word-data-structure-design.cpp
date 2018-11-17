/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Description:
 *  Design a data structure that supports the following two operations:
 *  ```
 *  void addWord(word)
 *  bool search(word)
 *  ```
 *  search(word) can search a literal word or a regular expression string containing only letters `a-z` or `.`. A `.` means it can represent any one letter.
 *
 *  For example:
 *  ```
 *  addWord("bad")
 *  addWord("dad")
 *  addWord("mad")
 *  search("pad") -> false
 *  search("bad") -> true
 *  search(".ad") -> true
 *  search("b..") -> true
 *  ```
 *
 *  Note:
 *      You may assume that all words are consit of lowercase letters `a-z`
 */

#include <string>
#include <unordered_map>
using namespace std;

class WordDictionary {
public:
    struct TrieNode {
        bool isString = false;
        unordered_map<char, TrieNode*> leaves;
    };

    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new TrieNode();
        root_->isString = true;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto *p = root_;
        for (const auto& c : word) {
            if (p->leaves.find(c) == p->leaves.cend()) {
                p->leaves[c] = new TrieNode;
            }
            p = p->leaves[c];
        }
        p->isString = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root_, 0);
    }

    bool searchWord(string word, TrieNode *node, int s) {
        if (s == word.length()) {
            return node->isString;
        }

        if (node->leaves.find(word[s]) != node->leaves.end()) {
            return searchWord(word, node->leaves[word[s]], s+1);
        } else if (word[s] == '.') {
            for (const auto& i : node->leaves) {
                if (searchWord(word, i.second, s+1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    TrieNode *root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

