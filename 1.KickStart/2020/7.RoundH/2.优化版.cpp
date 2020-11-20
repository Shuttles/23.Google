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

bool is_boring(long long x) {
    if (x == 0) return false;
    //int ind = ((digits(x) & 1) ? 1 : -1);//1表示奇数位 -1表示偶数位
    long long digits = 0;
    int pre = 1; //1 奇数 -1 偶数
    while (x) {
        digits += 1;
        long long tmp = x % 10;
        if (digits == 1) {
            pre = ((tmp & 1) ? 1 : -1);
        } else {
            int now = ((tmp & 1) ? 1 : -1);
            if (pre == now) return false;
            else pre = now;
        }
        
        x /= 10;
    
        if (x == 0) {
            if (tmp & 1) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        long long L, R;
        scanf("%lld%lld", &L, &R);

        //处理
        long long ans = 0;
        for (long long i = L; i <= R; ) {
            if (!is_boring(i))  {
                i++;
                continue;
            }
            printf("%lld true!\n", i);

            ans += 1;
            int temp = i % 10;
            ans += (10 - temp) / 2;
            if (temp % 2 == 0) ans -= 1;
            
            int delta = (temp == 0 ? 10 : (10 - i));
            
            if (i + delta > R) {
                for (int j = i + 1; j <= R; j++) {
                    if (!is_boring(j)) continue;
                    ans += 1;
                }
                break;
            } else {
                i += delta;
            }

        }

        printf("Case #%d: %lld\n", t, ans);
    }


    return 0;
}
