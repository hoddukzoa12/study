#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int dp[51][1001]; // dp[i][j]: i번째 곡을 j 볼륨으로 연주 가능한지 여부
int V[50];

void solve(int N, int S, int M) {
    memset(dp, 0, sizeof(dp)); // dp 배열 초기화
    dp[0][S] = 1; // 시작 볼륨 설정

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i][j]) { // 현재 상태가 가능하다면
                if (j + V[i] <= M) dp[i + 1][j + V[i]] = 1; // 볼륨 증가 가능
                if (j - V[i] >= 0) dp[i + 1][j - V[i]] = 1; // 볼륨 감소 가능
            }
        }
    }

    int maxVolume = -1;
    for (int j = 0; j <= M; j++) {
        if (dp[N][j]) {
            if (j > maxVolume) maxVolume = j;
        }
    }

    printf("%d\n", maxVolume);
}

int main() {
    int N, S, M;
    scanf("%d %d %d", &N, &S, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    solve(N, S, M);
    return 0;
}
