#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
int solution(int price, char* grade);

void main() {
    int ans;
    int price = 10000;
    char* grade = "S";  //문자열 상수
    ans = solution(price, grade);  // 또는 ans = solution(price, "V");
    printf("%d", ans);
}

int solution(int price, char* grade) {
    int answer = 0;
    // 전달된 주소의 문자열이 "S", "G", "V" 중 하나와 같으면
    if (grade == "S") {
        answer = (int)(price * 0.95);  // 5%할인받아 95%만 내면 된다. 
    }
    if (strcmp(grade, "G") == 0) {
        answer = (int)(price * 0.9);
    }
    if (strcmp(grade, "V") == 0) {
        answer = (int)(price * 0.85);
    }
    return answer;
}
