/*************************************************************************
	> File Name: 2.BusRoutes.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/19 07:40:52 2020
 ************************************************************************/

//此题对了一半，另一半TLE·
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
using namespace std;

#define MAX_N 1000

int64_t arr[MAX_N + 5];

int64_t get_latest_day(int N, int D);

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N, D;
        scanf("%d%d", &N, &D);
        memset(arr, 0, sizeof(arr));
        for (int j = 1; j <= N; j++) scanf("%" PRId64, &arr[j]);
        int64_t ans = 0;
        ans = get_latest_day(N, D);
        printf("Case #%d: " "%" PRId64 "\n", i, ans);
    }
    return 0;
}

int64_t get_latest_day(int N, int D) {
    //int cnt = 1;
    //printf("hello world\n");
    if (D == 1) return 1LL;
    int64_t ans = D / arr[1] * arr[1];/*初始值为能赶上1bus的最晚天数*/
    while (1) {
        int flag = 0;/*标识这一轮检查是否成功*/
        /*对后面每辆车进行检查*/
        int64_t pre_max_day = ans;
        for (int i = 2; i <= N; i++) {
            /*每辆车，对前面的最晚天数~D进行检查*/
            int64_t j = 0;
            for (j = pre_max_day; j <= D; j++) {
                if (j % arr[i] == 0)  {
                    pre_max_day = j;
                    break;
                }
            }
            if (j - 1 == D && (D % arr[i])) {
                /*表示第i辆车在此ans下不符合条件*/
                flag = 1;
                break;
            }
        }

        /*如果这一轮不是全部都符合，那就再往前推*/
        if (flag) {
            ans -= arr[1];
            //printf("第%d次修改\n", cnt++);
        } else break;
    }
    return ans;
}
