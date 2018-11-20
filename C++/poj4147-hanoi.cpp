/*
 * Copyright (C) 2018 all rights reserved.
 *
 * Author: Houmin Wei <houmin.wei@outlook.com>
 *
 * Source: http://bailian.openjudge.cn/practice/4147
 */

#include <iostream>
#include <cstring>
using namespace std;

void moveOneDisk(int n, char from, char via, char to) {
    cout << n << ':' << from << "->" << to << endl;
}

void moveNDisk(int n, char from, char via, char to) {
    if (n <= 0) return;
    moveNDisk(n-1, from, to, via);
    moveOneDisk(n, from, via, to);
    moveNDisk(n-1, via, from, to);
}

int main() {
    int n;
    char from, via, to;
    cin >> n >> from >> via >> to;
    moveNDisk(n, from, via, to);

    return 0;
}
