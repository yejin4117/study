#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
int solution(int arr[][4], int n, int k);
int func_a(int a[][4], int n);
int func_b(int a[][4], int n, int del);

int solution(int arr[][4], int n, int k) {
    int answer = 0;
    int min;
    for (int i = 1; i <= k; ++i) {
        //i 변수가 1이면 첫 번째 최소값(가장 작은 값)
        min = func_a(arr, n);   //i 변수가 k이면 k번째 최소값이 된다.
        func_b(arr, n, min);    //현재 최소값을 제외하여 다음번 최소값을 찾는다.
    }
    answer = min;
    return answer;
}

int func_a(int a[][4], int n) {
    int min = 1001;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (min > a[r][c]) {
                min = a[r][c];
            }
        }
    }
    return min;
}

int func_b(int a[][4], int n, int del) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (del == a[r][c]) {
                a[r][c] = 1001;   // <-- 1001은 최소값이 될 수 없다.
                return 1;
            }
        }
    }
    return 0;
}

void main() {
    int ans;
    int num[][4] = { {5,12,4,31}, {24,13,11,2}, {43,44,19,26}, {33,65,20,21} };
    ans = solution(num, 4, 3); //3번째로 작은수
    printf("%d", ans);  //5
}
