#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

int solution(int visitor[], int n);
int* func_a(int arr[], int arr_size, int num);
int func_b(int a, int b);
int func_c(int arr[], int arr_size);

void main() {
    int ans;
    int v[] = { 4, 7, 2, 9, 3 };
    ans = solution(v, 5);
    printf("%d", ans);  //2
}

int* func_a(int arr[], int arr_size, int num) {
    int* ret = (int*)malloc(sizeof(int) * (arr_size - 1));
    int idx = 0;
    for (int i = 0; i < arr_size; ++i)
        if (arr[i] != num)
            ret[idx++] = arr[i];
    return ret;
}

// 두 값의 차이(뺄셈의 결과)를 반환하는 함수
int func_b(int a, int b) {
    if (a >= b)
        return a - b;
    else
        return b - a;
}

int func_c(int arr[], int arr_size) {
    int ret = -1;
    for (int i = 0; i < arr_size; ++i)
        if (ret < arr[i])
            ret = arr[i];
    return ret;
}

int solution(int visitor[], int n) {
    //1. 가장 많은 방문객 수 
    int max_first = func_c(visitor, n);
    //2. 최고값 제거된 배열을 받음 
    int* visitor_removed = func_a(visitor, n, max_first);
    //3. 두번째 가장 많은 방문객 수 
    int max_second = func_c(visitor_removed, n - 1);
    //4. 구한 값의 차이 구하기 
    int answer = func_b(max_first, max_second);
    return answer;
}