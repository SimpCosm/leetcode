/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/length-of-last-word
 *
 * Description:
 *  Given a string s consist of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *  If the last word does not exist, return 0.
 */
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int i = size-1, cnt = 0;
        while (s[i] == ' ' && i >= 0)
            i--;
        for (; i >= 0; i--) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                cnt++;
            if (s[i] == ' ')
                break;
        }
        return cnt;
    }
};
