/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/merge-k-sorted-lists/description
*
*/
package main

import (
    "fmt"
    "strings"
)

type ListNode struct {
    Val     interface{}
    Next    *ListNode
}

type List struct {
    Head    *ListNode
    Tail    *ListNode
    Size    int
}

func New(values ...interface{}) *List {
    list := &List{}
    if len(values) > 0 {
        list.Add(values...)
    }
    return list
}

func (list *List) Add(values ...interface{}) {
    for _, v := range values {
        newNode := &ListNode{Val: v}
        if list.Size == 0 {
            list.Head = newNode
            list.Tail = newNode
        } else {
            list.Tail.Next = newNode
            list.Tail = newNode
        }
        list.Size++
    }
}

func (list *List) String() string {
    str := "SinglyLinkedList:\t["
	values := []string{}
	for element := list.Head; element != nil; element = element.Next {
        values = append(values, fmt.Sprintf("%v", element.Val))
	}
	str += strings.Join(values, ", ")
    str += "]\n"
	return str
}

func mergeKLists(lists []*ListNode) *ListNode {
    var head, cur *ListNode
    head, cur = new(ListNode), new(ListNode)
    head = cur
    
    if l1 != nil {
        cur.Next = l1
    }
    if l2 != nil {
        cur.Next = l2
    }
    return head.Next
}

func main() {
    list1, list2, list3 := New(1, 4, 5), New(1, 3, 4), New(2, 6)
    fmt.Print(list1, list2, list3)
    lists := []*ListNode{list1.Head, list2.Head, list3.Head}
    list1.Head = mergeKLists(lists)
    fmt.Print(list1)
}
