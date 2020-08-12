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
int s[MAX_N + 5];//单调递增栈
int top = -1;

int main() {
    int T;
    cin >> T;
    int t = 1;
    while (t <= T) {
        top = -1;
        memset(v, 0, sizeof(v));
        memset(s, 0, sizeof(s));
        v[0] = -10;
        int N, ans = 0;
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> v[i];
        
        s[top = 0] = 0;
        if (v[1] > v[2]) s[++top] = 1;
        for (int i = 2; i <= N; i++) {
            if (v[s[top]] >= v[i]) continue;
            if (i == N && v[i] <= v[i - 1]) continue;
            if (v[i] > v[i + 1]) s[++top] = i;
        }

        for (int i = 1; i <= N; i++) {
            if (s[i] == 0) {
                ans = i - 1;
                break;
            }
        }
        printf("Case #%d: %d\n", t, ans);
        t++;
    }

    return 0;
}
