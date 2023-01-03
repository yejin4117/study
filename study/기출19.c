#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
int solution(int price[], int price_len, int money);

int solution(int price[], int price_len, int money) {
    int answer = 0;
    for (int i = 0; i < price_len; ++i) {
        answer += price[i];
    }
    answer = money - answer;
    if (answer < 0) answer = -1;

    return answer;
}

void main() {
    int ans;
    int price[] = { 2100, 3200, 2100, 800 };
    ans = solution(price, 4, 10000);
    printf("%d", ans);
}
