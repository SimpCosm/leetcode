/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/implement-trie-prefix-tree/description

* Description:
*   Implement a trie with `insert`, `search`, and `startsWith` methods.
*
 */
package main

import (
	"fmt"
)

type TrieNode struct {
	children map[string]*TrieNode
	isEnd    bool
}

type Trie struct {
	root *TrieNode
}

/** Initialize you data structure here. */
func Constructor() Trie {
    trie := Trie{
        root: &TrieNode{
            children: make(map[string]*TrieNode),
            isEnd: false,
        },
    }
	return trie
}

/** Insert a word into the trie. */
func (this *Trie) Insert(word string) {
	node := this.root
    last := len(word) - 1
	for i, c := range word {
		ch := string(c)
		if _, ok := node.children[ch]; ok {
			node = node.children[ch]
		} else {
			newNode := &TrieNode{children: make(map[string]*TrieNode), isEnd: false}
            node.children[ch] = newNode
			node = newNode
		}
        if i == last {
            node.isEnd = true
        }
	}
}

/** Return if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	node := this.root
	for _, c := range word {
		ch := string(c)
		if _, ok := node.children[ch]; ok {
			node = node.children[ch]
		} else {
			return false
		}
	}
	return node.isEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	node := this.root
	for _, c := range prefix {
		ch := string(c)
		if _, ok := node.children[ch]; ok {
			node = node.children[ch]
		} else {
			return false
		}
	}
	return true
}

func main() {
	trie := Constructor()

	trie.Insert("apple")
	if trie.Search("apple") == true {
		fmt.Println("find word apple")
	}

	if trie.Search("app") == false {
		fmt.Println("could not find word app")
	}

	if trie.StartsWith("app") == true {
		fmt.Println("find word start with app")
	}

    trie.Insert("app")
    if trie.Search("app") == true {
        fmt.Println("find word app")
    }
}
