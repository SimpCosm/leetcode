/*
* Copyright (C) 2018 all rights reserved.
*
* Author: Houmin Wei <houmin.wei@outlook.com>
*
* Source: https://leetcode.com/problems/insertion-sort-list/description
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

func insertionSortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    // r is the first element of resulting sorted list
    var r *ListNode
    p := head
    for p != nil {
        cur := p
        p = p.Next
        if r == nil || cur.Val.(int) < r.Val.(int) {
            cur.Next = r
            r = cur
        } else {
            // insert currenct element into proper position in non-empty sorted list
            t := r
            for t != nil {
                if (t.Next == nil || cur.Val.(int) < t.Next.Val.(int)) {
                    cur.Next = t.Next
                    t.Next = cur
                    break
                }
                t = t.Next
            }
        }
    }
    return r
}


func main() {
    list := New(4, 2, 1, 3)
    fmt.Println(list)
    list.Head = insertionSortList(list.Head)
    fmt.Println(list)

    list2 := New(-1, 5, 3, 4, 0)
    fmt.Println(list2)
    list2.Head = insertionSortList(list2.Head)
    fmt.Println(list2)
}

