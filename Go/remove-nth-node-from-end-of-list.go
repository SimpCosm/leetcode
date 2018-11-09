/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description
*
* Description:
*   Given a linked list, remove the n-th node from the end of list and return its head.
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

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    fast, slow := head, head
    for i := 0; i < n; i++ {
        fast = fast.Next
    }
    // in case we remove the first element
    if fast == nil {
        return head.Next
    }
    for fast.Next != nil {
        fast, slow = fast.Next, slow.Next
    }
    // slow.Next should be deleted
    slow.Next = slow.Next.Next

    return head
}

func main() {
    list := New(1, 2, 3, 4, 5)
    fmt.Println(list)
    list.Head = removeNthFromEnd(list.Head, 2)
    fmt.Println(list)

    list2 := New(1, 2, 3, 4, 5)
    fmt.Println(list2)
    list2.Head = removeNthFromEnd(list2.Head, 5)
    fmt.Println(list2)
}
