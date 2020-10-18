#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_N 100

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int sum_k = 0, sum_s = 0, ans = 0;
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'K' && s[i] != 'S') continue;
            if (s[i] == 'K') {
                if (i + 4 > s.size()) break;
                if ((s[i + 1] == 'I') && (s[i + 2] == 'C') && (s[i + 3] == 'K')) {
                    //cout << "KICK ind = " << i << endl;
                    sum_k += 1;
                    i += 2;
                }
            }
            if (s[i] == 'S') {
                if (i + 5 > s.size()) break;
                if ((s[i + 1] == 'T') && (s[i + 2] == 'A') && (s[i + 3] == 'R') && (s[i + 4] == 'T')) {
                    //cout << "START ind = " << i << endl;
                    sum_s += 1;
                    ans += sum_k;
                    i += 4;
                }
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }


    return 0;
}
