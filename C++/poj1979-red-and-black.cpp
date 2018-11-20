/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: http://poj.org/problem?id=1979
 */

#include <iostream>
#include <cstring>
using namespace std;

char board[20][20];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int dfs(int w, int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= w) return 0;
    if (board[x][y] == '#') return 0;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int x1 = x+dir[i][0], y1 = y+dir[i][1];
        board[x][y] = '#';
        cnt += dfs(w, n, x1, y1);
    }
    return cnt;
}

int main() {
    int w, h;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) return 0;
        int startX, startY;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
                if (board[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }

        int cnt = dfs(w, h, startX, startY);
        cout << cnt << endl;
    }
    return 0;
}
