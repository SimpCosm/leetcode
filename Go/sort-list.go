/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/sort-list/description
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

func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    // step 1: cut the list to two halves
    slow, fast := head, head
    for fast.Next != nil && fast.Next.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    // slow is last element of first half
    second := slow.Next
    slow.Next = nil

    // step 2: sort each half
    l1 := sortList(head)
    l2 := sortList(second)

    // step 3: merge
    return merge(l1, l2)
}

func merge(l1 *ListNode, l2 *ListNode) *ListNode {
    var moving = new(ListNode)
    dummy := moving
    p1, p2 := l1, l2
    for p1 != nil && p2 != nil {
        if p1.Val.(int) <= p2.Val.(int) {
            moving.Next = p1
            p1 = p1.Next
        } else {
            moving.Next = p2
            p2 = p2.Next
        }
        moving = moving.Next
    }
    if p1 != nil {
        moving.Next = p1
    } else {
        moving.Next = p2
    }
    return dummy.Next
}

func main() {
    list := New(4, 2, 1, 3)
    fmt.Println(list)
    list.Head = sortList(list.Head)
    fmt.Println(list)

    list2 := New(-1, 5, 3, 4, 0)
    fmt.Println(list2)
    list2.Head = sortList(list2.Head)
    fmt.Println(list2)
}

