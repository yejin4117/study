#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
int solution(int number);

int solution(int number) {
    int count = 0;
    for (int i = 1; i <= number; i++) {
        int current = i;
        while (current != 0) {
            if (current % 10 == 3 || current % 10 == 6 || current % 10 == 9) {
                count++; // 3, 6, 9가 있으면 개수 증가
            }
            current /= 10;
        } // while 종료
    } // for 종료
    return count;
}


void main() {
    int ans;
    ans = solution(13);  // 13은 4번 침
    printf("%d", ans);
}