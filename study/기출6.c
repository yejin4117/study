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

//�ڿ����� ����� �迭�� ���޹޾� 
//�� �ڿ����� ��� �����ϴ����� ���Ͽ� counter �迭 ���� 
int* func_a(int arr[], int arr_len) {
    int* counter = (int*)malloc(sizeof(int) * 1001); //   int count[1001] �迭 ����
    for (int i = 0; i < 1001; i++) // �迭 �ʱ�ȭ
        counter[i] = 0;
    for (int i = 0; i < arr_len; i++)
        counter[arr[i]]++;  // ���޹��� �迭 �� �ڿ����� ������ ���� 
    return counter;
}

// �迭 ����� ���� ū ���� ã�� ��ȯ�ϴ� �Լ� 
int func_b(int arr[], int arr_len) {
    int ret = 0;
    for (int i = 0; i < arr_len; i++) { // ���޹��� �迭 arr�� ���̸�ŭ �ݺ�
        if (ret < arr[i]) // arr �迭 [i]�� ����� ���� ret������ ũ��
            ret = arr[i]; // ret ������ arr �迭 [i] �� ����� ���� ����
    }
    return ret;
}

//�迭 ��� �� ���� ���� ���� ã�� ��ȯ�ϴ� �Լ� 
int func_c(int arr[], int arr_len) {
    const int INF = 1001; // ���ǹ� ���� �ڵ�
    int ret = INF; // INF ��� 1001�� ��� �Ǹ� �ڿ��� �ִ밪
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] != 0 && ret > arr[i])
            // arr[i] �� 0�� ���� �󵵰� 0�̹Ƿ�  �ش���ڴ� ���ܽ�Ų��.
            ret = arr[i];
    }
    return ret;
}

void main() {
    int ans;
    int arr[6] = { 1, 2, 2, 1, 1, 1 };
    ans = solution(arr, 6);
    printf("��� %d", ans);
}
