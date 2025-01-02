#include <stdio.h>

int dpData[301] = {0}; // 계단의 최대값
int stairs[301] = {0}; // 계단의 점수

void dp(int n) {
    dpData[0] = stairs[0]; // 첫 번째 계단의 최대값
    dpData[1] = stairs[0] + stairs[1]; // 두 번째 계단의 최대값
    dpData[2] = stairs[2] + ((stairs[0] > stairs[1]) ? stairs[0] : stairs[1]); // 세 번째 계단의 최대값

    for (int i = 3; i < n; i++) {
        dpData[i] = stairs[i] + ((dpData[i - 2] > (dpData[i - 3] + stairs[i - 1]))  // i번째 계단의 최대값
                                ? dpData[i - 2] // i-2번째 계단의 최대값
                                : (dpData[i - 3] + stairs[i - 1])); // i-3번째 계단의 최대값 + i-1번째 계단의 점수
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &stairs[i]);
    }

    dp(n);
    printf("%d\n", dpData[n - 1]); // 마지막 계단의 최대값 출력
    return 0;
}
