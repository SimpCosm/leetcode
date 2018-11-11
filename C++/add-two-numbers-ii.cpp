/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei
 *
 * Source: https://leetcode.com/problems/add-two-numbers-ii
 *
 */

#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    stack<int> s1, s2;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        int carry = 0;
        ListNode* pre = nullptr;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;

            ListNode* p = new ListNode(sum % 10);
            p->next = pre;
            pre = p;

            carry = sum / 10;
            sum = 0;
        }
        return pre;
    }
};
