#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

int solution(int scores[], int scores_len);
int func_a(int s[], int arr_size);
int func_b(int s[], int arr_size);
int func_c(int s[], int arr_size);

void main() {
    int ans;
    int score[] = { 50, 90, 65, 100 };
    ans = solution(score, 4);
    printf("%d", ans);  //155
}

int solution(int scores[], int scores_len) {
    int sum = func_b(scores, scores_len); // 1. 점수의 합 구하기
    int max_score = func_a(scores, scores_len); // 2. 최고 점수 구하기
    int min_score = func_c(scores, scores_len); // 3. 최저 점수 구하기
    return sum - max_score - min_score; // 4. 나머지과목 점수의 합 반환
}

int func_a(int s[], int arr_size) {
    int ret = 0;
    for (int i = 0; i < arr_size; ++i)
        if (s[i] > ret)
            ret = s[i];
    return ret;
}
int func_b(int s[], int arr_size) {
    int ret = 0;
    for (int i = 0; i < arr_size; ++i)
        ret += s[i];
    return ret;
}
int func_c(int s[], int arr_size) {
    int ret = 101;
    for (int i = 0; i < arr_size; ++i)
        if (s[i] < ret)
            ret = s[i];
    return ret;
}

void main() {

}