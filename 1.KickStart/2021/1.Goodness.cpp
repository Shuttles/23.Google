/*************************************************************************
	> File Name: 1.Goodness.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月21日 星期日 12时07分12秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int T, n, k;
string str;
#define IS_ODD(a) ((a) & 1)
#define IS_EVEN(a) (!((a) & 1))

long long solve();

void input() {
    cin >> T;
    for (int z = 1; z <= T; z++) {
        cin >> n >> k >> str;
        long long ans = solve();
        printf("Case #%d: %lld\n", z, ans);
    }
    return ;
}

long long solve() {
    long long sum = 0, op;
    for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
        if (str[i] != str[j]) sum++;
    }
    op = abs(k - sum);
    return op;
}


int main() {
    input();
    return 0;
}
