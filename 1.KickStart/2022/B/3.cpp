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

//这种题以前ks也出过！！但就是不会做！！找不到套路！！！
int T;
long long a;

long long solve();

void input() {
    cin >> T;
    for (int z = 1; z <= T; z++) {
        cin >> a;
        long long ans = solve();
        printf("Case #%d: %lld\n", z, ans);
    }
    return ;
}

long long solve() {
    long long ans = 0;
    return ans;
}


int main() {
    input();
    return 0;
}
