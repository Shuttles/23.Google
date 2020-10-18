#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cinttypes>
using namespace std;

#define MAX_N 100000
long long x[MAX_N + 5];

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        long long w, n, ans = INT64_MAX;
        cin >> w >> n;
        for (int i = 1; i <= w; i++) cin >> x[i];

        for (int i = 1; i <= n; i++) {//将所有轮子调到i
            long long temp = 0;
            for (int j = 1; j <= w; j++) {
                long long temp0 = min(abs(x[j] - i), abs(n - x[j] + i));
                temp0 = min(temp0, abs(n - i + x[j]));
                temp += temp0;
                /*
                if (i == 9) {
                    printf("将%lld调成9,需要%lld次.\n", x[j], temp0);
                }
                */
            }
            //printf("将所有轮子调成%d， 所需次数为%lld\n", i, temp);
            //if (temp <= ans) printf("更新成功！换成%d更小！\n", i);
            ans = min(temp, ans);
        }
        printf("Case #%d: %lld\n", t, ans);
    }


    return 0;
}
