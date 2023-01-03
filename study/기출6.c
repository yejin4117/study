#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int* func_a(int arr[], int arr_len);
int func_b(int arr[], int arr_len);
int func_c(int arr[], int arr_len);
int solution(int arr[], int arr_len);

int solution(int arr[], int arr_len) {
    int* counter = func_a(arr, arr_len);
    int max_cnt = func_b(counter, 1001);
    int min_cnt = func_c(counter, 1001);
    return max_cnt / min_cnt;
}

//자연수가 저장된 배열을 전달받아 
//각 자연수가 몇번 등장하는지를 구하여 counter 배열 리턴 
int* func_a(int arr[], int arr_len) {
    int* counter = (int*)malloc(sizeof(int) * 1001); //   int count[1001] 배열 생성
    for (int i = 0; i < 1001; i++) // 배열 초기화
        counter[i] = 0;
    for (int i = 0; i < arr_len; i++)
        counter[arr[i]]++;  // 전달받은 배열 속 자연수의 개수를 저장 
    return counter;
}

// 배열 요소중 가장 큰 값을 찾아 반환하는 함수 
int func_b(int arr[], int arr_len) {
    int ret = 0;
    for (int i = 0; i < arr_len; i++) { // 전달받은 배열 arr의 길이만큼 반복
        if (ret < arr[i]) // arr 배열 [i]번 요소의 값이 ret값보다 크면
            ret = arr[i]; // ret 변수에 arr 배열 [i] 번 요소의 값을 저장
    }
    return ret;
}

//배열 요소 중 가장 작은 값을 찾아 반환하는 함수 
int func_c(int arr[], int arr_len) {
    const int INF = 1001; // 별의미 없는 코드
    int ret = INF; // INF 대신 1001로 적어도 되며 자연수 최대값
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] != 0 && ret > arr[i])
            // arr[i] 이 0인 경우는 빈도가 0이므로  해당숫자는 제외시킨다.
            ret = arr[i];
    }
    return ret;
}

void main() {
    int ans;
    int arr[6] = { 1, 2, 2, 1, 1, 1 };
    ans = solution(arr, 6);
    printf("배수 %d", ans);
}
