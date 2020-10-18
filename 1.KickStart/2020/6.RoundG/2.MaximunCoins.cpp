#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 1000
long long mmap[MAX_N + 5][MAX_N + 5];
int used[MAX_N + 5][MAX_N + 5];

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        memset(mmap, 0, sizeof(mmap));
        memset(used, 0, sizeof(used));
        long long max_coins = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mmap[i][j];
            }
        }

        for (int i = n; i > 0; i--) {
            int j = 1;
            long long temp = mmap[i][j];
            for (int dx = i + 1, dy = j + 1; dx > 0 && dx <= n && dy > 0 && dy <= n && used[dx][dy] == 0; dx += 1, dy += 1) {
                used[dx][dy] = 1;
                temp += mmap[dx][dy];
            }
            max_coins = max(max_coins, temp);
        } 

        for (int j = 2; j <= n; j++) {
            int i = 1;
            long long temp = mmap[i][j];
            for (int dx = i + 1, dy = j + 1; dx > 0 && dx <= n && dy > 0 && dy <= n && used[dx][dy] == 0; dx += 1, dy += 1) {
                used[dx][dy] = 1;
                temp += mmap[dx][dy];
            } 

            max_coins = max(max_coins, temp);
        }

        printf("Case #%d: %lld\n", t, max_coins);
    }


    return 0;
}
