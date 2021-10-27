/*************************************************************************
	> File Name: 1.Goodness.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月21日 星期日 12时07分12秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 300

struct Point {
    int x, y;
};

queue<struct Point> q;

int T, m, n, sx, sy, max_h;
int g[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];
int dnext[4][2] = {
    {0, 1}, {1, 0},
    {0, -1}, {-1, 0}
};

long long solve();

void input() {
    cin >> T;
    for (int z = 1; z <= T; z++) {
        max_h = 0;//一定不能忘！！
        memset(visited, 0, sizeof(visited));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if (g[i][j] > max_h) {
                    max_h = g[i][j];
                    sx = i;
                    sy = j;
                }
            }
        }
        long long ans = solve();
        printf("Case #%d: %lld\n", z, ans);
    }
    return ;
}

long long solve() {
    long long ans = 0;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        Point temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = temp.x + dnext[i][0];
            int dy = temp.y + dnext[i][1];
            if (dx < 1 || dx > n || dy < 1 || dy > m) continue;
            if (visited[dx][dy]) continue;
            //点存在并且没访问过
            //printf("(%d, %d)存在并且没访问过, g[%d][%d] = %d\n", dx, dy, dx, dy, g[dx][dy]);
            q.push({dx, dy});
            visited[dx][dy] = true;

            long long diff = g[temp.x][temp.y] - g[dx][dy] - 1;
            if (diff > 0) {
                ans += (diff);
                g[dx][dy] += diff;
            } else if (diff < 0) {
                int tmp = g[dx][dy] - g[temp.x][temp.y] - 1;
                ans += tmp;
                g[temp.x][temp.y] += tmp;
            }
        }
    }

    return ans;
}


int main() {
    input();
    return 0;
}
