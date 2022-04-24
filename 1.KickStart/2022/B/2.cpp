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

bool isPalindrome(long long x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
    if (x > 0 && x < 10) return true;

    long long revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

long long solve() {
    long long ans = 0;
    //printf("%lld start!!!!!!!!!!\n", a);
    //shit!!!!!一开始用的int i，一直TLE!!!!!
    for (long long i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (isPalindrome(i)) {
                //printf("%d isPalindrome\n",i);
                ans += 1;
            }
            long long j = a / i;
            if (j != i && isPalindrome(j)) {
                //printf("%d isPalindrome\n",j);
                ans += 1;
            }
        }
    }
    return ans;
}


int main() {
    input();
    return 0;
}
