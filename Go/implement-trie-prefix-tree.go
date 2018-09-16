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

type Trie struct {
	children map[string]*Trie
	isEnd    bool
}

/** Initialize you data structure here. */
func Constructor() Trie {
	trie := Trie{
		children: make(map[string]*Trie),
		isEnd:    false,
	}
	return trie
}

/** Insert a word into the trie. */
func (this *Trie) Insert(word string) {
	node := this
	last := len(word) - 1
	for i, c := range word {
		ch := string(c)
		newNode, ok := node.children[ch]
		if !ok {
			newNode = &Trie{children: make(map[string]*Trie), isEnd: false}
			node.children[ch] = newNode
		}
		node = newNode
		if i == last {
			node.isEnd = true
		}
	}
}

/** Return if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	node := this
	for _, c := range word {
		ch := string(c)
		newNode, ok := node.children[ch]
		if !ok {
			return false
		}
		node = newNode
	}
	return node.isEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	node := this
	for _, c := range prefix {
		ch := string(c)
		newNode, ok := node.children[ch]
		if !ok {
			return false
		}
		node = newNode
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
