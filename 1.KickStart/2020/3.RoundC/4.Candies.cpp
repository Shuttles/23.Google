/*************************************************************************
	> File Name: 4.Candies.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/17 20:10:17 2020
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 200000
int arr[MAX_N + 5];

int getSweetness(int l, int r) {
    int ans = 0;
    int flag = 1;
    for (int i = l, cnt = 1; i <= r; cnt++, i++) {
        if (flag) {
            ans += arr[i] * cnt;
        } else {
            ans -= arr[i] * cnt;
        }
        flag = (flag == 1 ? 0 : 1);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int l = 1; l <= T; l++) {
        int ans = 0;
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= q; i++) {
            char op;
            int a, b;
            cin >> op >> a >> b;
            switch (op) {
                case 'Q': {
                    int temp =  getSweetness(a, b);
                    ans += temp;
                } break;
                case 'U': {
                    arr[a] = b;
                } break;
            }
        }

        printf("Case #%d: %d\n", l, ans);
    }

    return 0;
}
