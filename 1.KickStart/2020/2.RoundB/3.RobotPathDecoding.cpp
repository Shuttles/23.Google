/*************************************************************************
	> File Name: 3.RobotPathDecoding.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/19 09:42:38 2020
 ************************************************************************/

//这题也是 第一小题过了 第二小题没过
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


#define MAX_N 2000


void move(int operatenum, char *str, int *row, int *columns);
void func(char x, int *row, int *columns);

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        char str[MAX_N + 5] = {0};
        scanf("%s\n", str);
        int row = 1, columns = 1;
        move(1, str, &row, &columns);
        printf("Case #%d: %d %d\n", i, columns, row);
    }
    return 0;
}

//以下是原来写的move
/*
void move(char *str, int *row, int *columns) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '2' && str[i] <= '9') {
            //万一还是数字
            if (str[i + 2] >= '2' && str[i + 2] <= '9') {
                move(str + i + 2, row, columns);
                i += ()
            }

            //取出括号中的子串
            int n = 0;
            for (int j = i + 2; str[j] != ')'; j++) {
                n++;
            }
            char s[MAX_N] = {0};
            strncpy(s, str + i + 2, n);
            printf("s = %s\n", s);

            //进行nums次子串操作
            int nums = str[i] & 15;
            for (int j = 1; j <= nums; j++) {
                move(s, row, columns);
            }
            i += (n + 2);//一定不能忘了！！
        } else {
            func(str[i], row, columns);
        }
    }

    return ;
}
*/

void move(int operatenum, char *str, int *row, int *columns) {
    for (int l = 0; l < operatenum; l++) {
        for (int i = 0; str[i]; i++) {
            if (str[i] >= '2' && str[i] <= '9') {
                int operatenum = (str[i] & 15);
                /*取出括号中的子串*/
                int cnt = 0;
                int num = 1;
                int j = i + 2;
                //printf("Before while!\n");
                while (num) {
                    //printf("In while!\n");
                    if (str[j] == '(') num++;
                    if (str[j] == ')') num--;
                    cnt++;
                    j++;
                }
                cnt--;
                char s[MAX_N + 5] = {0};
                //printf("Before strncpy!\n");
                strncpy(s, str + i + 2, cnt);
                //printf("s = %s\n", s);
                move(operatenum, s, row, columns);
                i += (cnt + 2);//一定是+2!!!!
            } else {
                func(str[i], row, columns);
                //printf("columns = %d, row = %d\n", *columns, *row);
            }
        }
    }
    return ;
}

void func(char x, int *row, int *columns) {
    switch (x) {
        case 'N': {
            *row -= 1;
            if (*row == 0) *row = 1000000000;
        } break;
        case 'S': {
            *row += 1; 
            if (*row == 1000000001) *row = 1;
        } break;
        case 'W': {
            *columns -= 1;
            if (*columns == 0) *columns = 1000000000;
        } break;
        case 'E': {
            *columns += 1;
            if (*columns == 1000000001) *columns = 1;
        } break;
    }
    return ;
}
