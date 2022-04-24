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

#define EPS 1e-6
#define Pi 3.14159265358979323846
int T, R, a, b;

double solve();

void input() {
    cin >> T;
    for (int z = 1; z <= T; z++) {
        cin >> R >> a >> b;
        double ans = solve();
        printf("Case #%d: %lf\n", z, ans);
    }
    return ;
}

double solve() {
    double ans = Pi * R * R;
    int r = R * a;
    bool flag = true;
    while (r != 0) {
        ans += Pi * r * r;
        if (flag) {
            r = r / b;
            flag = false;
        } else {
            r = r * a;
            flag = true;
        }
    }

    return ans;
}


int main() {
    input();
    return 0;
}
