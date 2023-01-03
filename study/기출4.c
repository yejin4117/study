#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
int solution(int price, char* grade);

void main() {
    int ans;
    int price = 10000;
    char* grade = "S";  //���ڿ� ���
    ans = solution(price, grade);  // �Ǵ� ans = solution(price, "V");
    printf("%d", ans);
}

int solution(int price, char* grade) {
    int answer = 0;
    // ���޵� �ּ��� ���ڿ��� "S", "G", "V" �� �ϳ��� ������
    if (grade == "S") {
        answer = (int)(price * 0.95);  // 5%���ι޾� 95%�� ���� �ȴ�. 
    }
    if (strcmp(grade, "G") == 0) {
        answer = (int)(price * 0.9);
    }
    if (strcmp(grade, "V") == 0) {
        answer = (int)(price * 0.85);
    }
    return answer;
}
