#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

int solution(int data[], int data_len);

void main() {
    int ans;
    int num[] = { 1,2,3,4,5,6,7,8,9,10 };
    ans = solution(num, 10);
    printf("%d", ans);
}

int solution(int data[], int data_len) {
    double total = 0;
    for (int i = 0; i < data_len; i++)
        total += data[i];
    int cnt = 0;
    double average = total / data_len;
    for (int i = 0; i < data_len; i++)
        if (data[i] <= average)
            cnt += 1;
    return cnt;
}