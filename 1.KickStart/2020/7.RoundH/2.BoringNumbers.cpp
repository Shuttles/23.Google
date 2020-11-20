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
#include <cmath>
using namespace std;

#define MAX_N 18

//1111111110000  找最后一个1
long long digits(long long x) {
    long long head = 1, tail = MAX_N;
    while (head < tail) {
        //printf("head = %lld, tail = %lld, ", head, tail);
        long long mid_digit = (head + tail + 1) >> 1;
        long long mid = pow(10, mid_digit - 1);
        //printf("mid_digit = %lld, mid = %lld\n", mid_digit, mid);
        if (x / mid < 1)  {
            //printf("x / mid --> %lld / %lld < 1 \n", x, mid);
            tail = mid_digit - 1;
        }
        else {
            //printf("x / mid --> %lld / %lld >= 1 \n", x, mid);
            head = mid_digit;
        }
    }
    return head;
}

bool is_boring(long long x) {
    if (x == 0) return false;
    //printf("digits(%lld) = %lld\n", x, digits(x));
    int ind = ((digits(x) & 1) ? 1 : -1);//1表示奇数位 -1表示偶数位
    while (x) {
        long long tmp = x % 10;
        if (ind == 1) {
            if (!(tmp & 1)) {
                return false;
            }
        } else {
            if (tmp & 1) {
                return false;
            }
        }
        ind = -ind;
        x /= 10;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        long long L, R;
        scanf("%lld%lld", &L, &R);

        //处理
        long long ans = 0;
        for (long long i = L; i <= R; i++) {
            if (!is_boring(i)) continue;
            //printf("%lld true!\n", i);
            ans += 1;

        }

        printf("Case #%d: %lld\n", t, ans);
    }


    return 0;
}
