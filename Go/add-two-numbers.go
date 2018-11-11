/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/add-two-numbers
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

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := new(ListNode)
    tail := head
    sum, carry := 0, 0
    for l1 != nil || l2 != nil {
        a, b := 0, 0
        var tl1, tl2 *ListNode
        if l1 != nil {
            a = l1.Val.(int)
            tl1 = l1.Next
        }
        if l2 != nil {
            b = l2.Val.(int)
            tl2 = l2.Next
        }
        sum = a + b + carry
        p := new(ListNode)
        p.Val = sum % 10
        tail.Next = p
        tail = p
        carry = sum / 10
        l1, l2 = tl1, tl2
    }
    if carry != 0 {
        p := new(ListNode)
        p.Val = carry
        tail.Next = p
        tail = p
    }
    return head.Next
}

func main() {
    l1 := New(2, 4, 3)
    l2 := New(5, 6, 4)
    fmt.Print(l1, l2)
    l1.Head = addTwoNumbers(l1.Head, l2.Head)
    fmt.Print(l1)

}

