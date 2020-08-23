/*************************************************************************
	> File Name: 1.BikeTour.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/19 07:14:49 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 200000
int arr[MAX_N + 5];
int dp[MAX_N + 5] = {1};

int main() {
    int T;
    scanf("%d", &T);

    for (int k = 1; k <= T; k++) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        int N;
        scanf("%d", &N);
        //输入原数组
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }

        //处理
        int longest_len = 1;
        int diff = arr[2] - arr[1];
        for (int i = 2; i <= N; i++) {    
            if (arr[i] - arr[i - 1] == diff) {//如果ith项和前一项构成等差数列
                dp[i] = dp[i - 1] + 1;
            } else {//如果不构成等差数列
                dp[i] = 1;
                diff = arr[i] - arr[i - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dp[i]);
        }

        printf("Case #%d: %d\n", k, ans + 1);
    }


    return 0;
}
