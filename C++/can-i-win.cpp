/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/valid-palindrome
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool canIWin(int M, int T) {
        int sum = M * (M + 1) / 2;
        if (sum < T) return false;
        if (T <= 0) return true;
        m_ = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }
private:
    vector<char> m_;
    bool canIWin(int M, int T, int state) {
        if (T <= 0) return false;
        if (m_[state]) return m_[state] == 1;
        for (int i = 0; i < M; ++i) {
            if (state & 1 << i) continue;
            if (!canIWin(M, T-(i+1), state|(1<<i))) {
                m_[state] = 1;
                return true;
            }
        }
        m_[state] = -1;
        return false;
    }
};
