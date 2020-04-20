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
using namespace std;

#define MAX_N 100
int arr[MAX_N + 5];

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        memset(arr, 0, sizeof(arr));
        int N;
        scanf("%d", &N);
        /*输入每个checkpoint高度*/
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[j]);
        }

        /*判断*/
        int ans = 0;
        for (int j = 2; j < N; j++) {
            if (arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) 
                ans += 1;
        }
        printf("Case #%d: %d\n", i, ans);
    }


    return 0;
}
