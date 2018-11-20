/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: https://leetcode.com/problems/n-queens
 */
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ret;
        vector<bool> row(n, false);
        vector<bool> lefttop(2*n-1, false);
        vector<bool> righttop(2*n-1, false);
        queen(0, n, board, ret, row, lefttop, righttop);
        return ret;
    }

    void queen(int column, int n, vector<string>& board, vector<vector<string>>& ret, vector<bool>& row, vector<bool>& lefttop, vector<bool>& righttop) {
        if (column == n) {
            ret.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (row[i] || lefttop[column-i+n-1] || righttop[i+column]) continue;
            row[i] = true;
            lefttop[column-i+n-1] = true;
            righttop[i+column] = true;
            board[i][column] = 'Q';
            queen(column+1, n, board, ret, row, lefttop, righttop);
            board[i][column] = '.';
            row[i] = false;
            lefttop[column-i+n-1] = false;
            righttop[i+column] = false;
        }
    }
};
