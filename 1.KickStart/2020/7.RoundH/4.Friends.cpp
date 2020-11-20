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

#define MAX_N 100

struct node {
    string name;
    int friends[MAX_N + 5];
}

node arr[MAX_N + 5];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, Q;
        scanf("%d%d", &N, &Q);
        for (int i = 1; i <= N; i++) {
            cin >> arr[i].name;
        }

        //处理
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (!is_friend(i, j)) continue;
                arr[i].friend[j] = 1;
                arr[j].friend[i] = 1;
            }
        }

        /*
        for (int i = 1; i <= N; i++) {
            cout << i << " " << arr[i].name << endl;
            
        }*/

        
        printf("Case #%d:", t);

        for (int i = 1; i <= Q; i++) {
            int x, y, ans = 2;
            cin >> x >> y;
            
            ans = query(x, y);
          
            if (i != Q) cout << " ";
            cout << ans;
        }
        cout << endl;
        
    }


    return 0;
}

int query(int x, int y) {
    if (arr[x].friends[y])  return 2;
    else {
        int chain = 0;
        int used[MAX_N + 5] = {0};//1表示访问过了
        queue<node> q;
        q.push(arr[x]);
        for (int i = 1; i <= MAX_N; i++) {
            if (!arr[x].friends[i]) continue;
            q.push(arr[x].friends[i]);
        }
        while (!q.empty()) {
            
        }

    }

}
