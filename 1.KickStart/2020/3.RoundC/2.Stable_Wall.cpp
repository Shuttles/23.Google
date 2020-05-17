/*************************************************************************
	> File Name: 2.Stable_Wall.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/17 21:01:51 2020
 ************************************************************************/

#include<iostream>
using namespace std;

char mmap[35][35];

int main() {
    int T;
    cin >> T;
    for (int l = 1; l <= T; l++) {
        char ans[30] = {0};
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mmap[i][j];
            }
        }





        printf("Case #%d: %d\n", l, ans);
    }

    return 0;
}
