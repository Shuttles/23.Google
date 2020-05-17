/*************************************************************************
	> File Name: 3.Perfect_Subarray.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/17 19:37:56 2020
 ************************************************************************/

#include<iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5];
bool is_square(int n) {
    return int(sqrt(n)) * int(sqrt(n)) == n ? true : false;
}

int main() {
    int T;
    cin >> T;
    for (int l = 1; l <= T; l++) {
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = i; j <= n; j++) {
                sum += arr[j];
                if (is_square(sum)) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", l, ans);
    }
    return 0;
}
