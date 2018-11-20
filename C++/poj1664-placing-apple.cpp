/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: http://poj.org/problem?id=1664
 */

#include <iostream>
#include <cstring>
using namespace std;

int count(int m, int n) {
    if (n == 1 || m == 0) return 1;
    if (n > m) return count(m, m);
    return count(m, n-1) + count(m-n, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> M >> N;
        int k = count(M, N);
        cout << k << endl;
    }
    return 0;
}
