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

int T;
string now, corret;

long long solve();

void input() {
    cin >> T;
    for (int z = 1; z <= T; z++) {
        cin >> corret >> now;
        long long ans = solve();
        if (ans != -1) {
            printf("Case #%d: %lld\n", z, ans);
        } else {
            printf("Case #%d: IMPOSSIBLE\n", z);
        }
    }
    return ;
}

long long solve() {
    long long ans = 0;
    if (now.size() < corret.size()) return -1;
    int i = 0, j = 0;
    while (i < corret.size() && j < now.size()) {
        //printf("A loop begin!\n");
        //printf("i = %d, j = %d\n", i, j);
        while (j < now.size() && corret[i] != now[j]) {
            //printf("i = %d. j = %d, corret[%d](%c) != now[%d](%c)\n", i, j, i, corret[i], j, now[j]);
            j++;
            ans++;
        }
        if (j >= now.size()) {
            return -1;
        }
        i++;
        j++;
    }

    //一开始是直接ans += (now,size() - j)　一直WA
    //后来加了if，就过了
    if (j < now.size()) {
        ans += (now.size() - j);
    }
    if (i < corret.size()) {
        return -1;
    }
    return ans;
}


int main() {
    input();
    return 0;
}
