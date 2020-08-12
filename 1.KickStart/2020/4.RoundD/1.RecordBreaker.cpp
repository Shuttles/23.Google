/*************************************************************************
	> File Name: 1.Countdown.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/17 19:03:04 2020
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX_N 200000
int v[MAX_N + 5];

int main() {
    int T;
    cin >> T;
    int t = 1;
    while (t <= T) {
        memset(v, 0, sizeof(v));
        int N, ans = 0;
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> v[i];
        
        if (v[1] > v[2]) ans++;
        for (int i = 2; i <= N; i++) {
            int flag = 1;
            if ((i - N) && v[i] <= v[i + 1]) continue;
            for (int j = 1; j < i; j++) {
                if (v[j] >= v[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans++;
        }
        printf("Case #%d: %d\n", t, ans);
        t++;
    }

    return 0;
}
