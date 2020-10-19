#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cinttypes>
using namespace std;

#define MAX_N 5000

int arr[MAX_N + 5], num[MAX_N + 5];
int used[MAX_N + 5];



void dfs(int depth, long long *ans, int n);

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        long long sum_num = 0, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            sum_num += num[i];
        }

        ans += sum_num;

        printf("Case #%d: %lf\n", t, );
    }


    return 0;
}


void dfs(int depth, int *ans, int n) {
    
    int start;
    for (int i = start; i <= n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        arr[depth].val = num[i].val;
        dfs(depth + 1, ans, n);
        used[i] = 0;
    }
}
