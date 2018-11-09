/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/merge-tow-sorted-lists/description
*
* Description:
*   Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    str += "]"
	return str
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    var head, cur *ListNode
    head, cur = new(ListNode), new(ListNode)
    head = cur
    for l1 != nil && l2 != nil {
        if l1.Val.(int) <= l2.Val.(int) {
            cur.Next = l1
            l1 = l1.Next
        } else {
            cur.Next = l2
            l2 = l2.Next
        }
        cur = cur.Next
    }
    if l1 != nil {
        cur.Next = l1
    }
    if l2 != nil {
        cur.Next = l2
    }
    return head.Next
}

func main() {
    list1, list2 := New(1, 2, 4), New(1, 3, 4)
    fmt.Println(list1, list2)
    list1.Head = mergeTwoLists(list1.Head, list2.Head)
    fmt.Println(list1)
}
