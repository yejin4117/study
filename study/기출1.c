#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(char* shirt_size[], int shirt_size_len) {
	int* answer;
	
	int  i;
	answer = (int*)malloc(sizeof(int) * 6);

	for (i = 0; i < 6; i++) {
		answer[i] = 0;
	}
	for (i = 0; i < shirt_size_len; i++) {
		if (strcmp(shirt_size[i], "XS") == 0) {
			answer[0]++;
		}
		else if (strcmp(shirt_size[i], "S") == 0) {
			answer[1]++;
		}
		else if (strcmp(shirt_size[i], "M") == 0) {
			answer[2]++;
		}
		else if (strcmp(shirt_size[i], "L") == 0) {
			answer[3]++;
		}
		else if (strcmp(shirt_size[i], "XL") == 0) {
			answer[4]++;
		}
		else if (strcmp(shirt_size[i], "XXL") == 0) {
			answer[5]++;
		}
	}

	return answer;
}

int main() {
	int* ans;
	char* shirt_size[] = {"XS", "S", "XXL", "XS", "XL"};
	ans = solution(shirt_size, 5);
	for (int i = 0; i < 6; i++) {
		printf("%3d", ans[i]);
	}
}
