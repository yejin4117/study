#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int solution(int scores[], int scores_len);

int solution(int scores[], int scores_len) {
    int count = 0;
    for (int i = 0; i < scores_len; i++)
        if (650 <= scores[i] && scores[i] < 800)
            count += 1;
    return count;
}

void main() {
    int ans;
    int num[] = { 600, 900, 780, 660, 800, 600, 500, 720, 860, 700 };
    ans = solution(num, 10);
    printf("%d", ans);
}