/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/reorder-list/description
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

func reorderList(head *ListNode)  {
    if head == nil || head.Next == nil {
        return
    }

    // find the middle
    fast, slow := head, head
    for fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    second := slow.Next
    slow.Next = nil

    // reverse the second part
    var pre *ListNode
    cur := second
    for cur != nil {
        tmp := cur.Next
        cur.Next = pre
        pre = cur
        cur = tmp
    }

    // merge two part
    p1, p2 := head, pre
    for p1 != nil && p2 != nil {
        tp1, tp2 := p1.Next, p2.Next
        p1.Next, p2.Next = p2, tp1
        p1, p2 = tp1, tp2
    }
}

func main() {
    list := New(1, 2, 3, 4)
    fmt.Println(list)
    reorderList(list.Head)
    fmt.Println(list)

    list2 := New(1, 2, 3, 4, 5)
    fmt.Println(list2)
    reorderList(list2.Head)
    fmt.Println(list2)
}

