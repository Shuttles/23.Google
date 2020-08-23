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

int main() {
    int T;
    scanf("%d", &T);

    for (int k = 1; k <= T; k++) {
        memset(arr, 0, sizeof(arr));
        int N;
        scanf("%d", &N);
        //输入原数组
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }

        //处理
        int longest_len = 1;
        int next_ind = 0;
        for (int i = 1; i <= N; ) {
            int temp = 1;
            int diff = arr[i + 1] - arr[i];
            for (int j = i + 1; (j <= N) && ((arr[j] - arr[j - 1]) == diff); j++) {
                temp += 1;
               
                if (arr[j + 1] - arr[j] != diff) {
                    cout << "end num = " << arr[j] <<  " temp = " << temp ;
                }
            }
            longest_len = max(temp, longest_len);
            if (i + temp <= N) {
                next_ind = i + temp;
                i = next_ind;
            } else {
                i++;
            }
            cout << ", next_ind = " << i << endl;
        }

        printf("Case #%d: %d\n", k, longest_len);
    }


    return 0;
}
