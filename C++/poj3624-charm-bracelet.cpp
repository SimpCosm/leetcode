/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: http://poj.org/problem?id=3624
 */

#include <iostream>
using namespace std;

// Define f[i,w] to be the maximum value that can be attained
// with weight less than or equal to w using items up to  i (first i items).
int dp0(int N, int M, int *w, int *d) {
    int **f = new int*[N+1];
    for (int i = 0; i <= N; i++)
        f[i] = new int[M+1];

    for (int j = 0; j <= M; j++)
        f[0][j] = 0;

    for (int i = 1; i <= N; i++) {
        f[i][0] = 0;

        for (int j = 1; j <= M; j++) {
            if (j < w[i]) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+d[i]);
        }
    }
}

int dp1(int N, int M, int *w, int *d) {
    int **f = new int*[N+1];
    for (int i = 0; i <= N; i++)
        f[i] = new int[M+1];

    for (int j = 0; j <= M; j++)
        f[0][j] = 0;

    for (int i = 1; i <= N; i++) {
        f[i][0] = 0;

        for (int j = w[i]; j <= M; j++) {
            f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+d[i]);
        }
    }
    return f[N][M];
}

int dp2(int N, int M, int *w, int *d) {
    int *f = new int[M+1];
    for (int j = 0; j <= M; j++)
        f[j] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= w[i]; j--) {
            f[j] = max(f[j], f[j-w[i]]+d[i]);
        }
    }

    return f[M];
}

int main() {
    int N, M;
    cin >> N >> M;
    int *w = new int[N+1], *d = new int[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> d[i];
    }

    int ret = dp1(N, M, w, d);
    cout << ret << endl;
    return 0;
}
