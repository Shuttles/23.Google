/*************************************************************************
	> File Name: 1.BikeTour.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/19 07:14:49 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_N 1000000000 

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        long long N, K, S;
        scanf("%lld%lld%lld", &N, &K, &S);

        //处理
        long long ans_min = K + N, temp;
        temp = (K - 1) + (K - S) + (N - S + 1);
        ans_min = min(ans_min, temp);

        printf("Case #%d: %lld\n", t, ans_min);
    }


    return 0;
}
