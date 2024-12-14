#include <stdio.h>

int num[50][50] = {0, };

void findsquare(int N, int M) {
    int max = 1; // 최소 크기 정사각형은 1x1

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 1; i + k < N && j + k < M; k++) { // 변 길이 k+1
                if (num[i][j] == num[i + k][j] &&
                    num[i][j] == num[i][j + k] &&
                    num[i][j] == num[i + k][j + k]) {
                    if (max < k + 1) { 
                        max = k + 1;
                    }
                }
            }
        }
    }

    printf("%d\n", max * max); // 가장 큰 정사각형 크기 출력
}

int main() {
    int N, M;

    // N, M 입력
    scanf("%d %d", &N, &M);

    // 숫자 배열 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &num[i][j]); // 한 자리 숫자 입력
        }
    }

    // 가장 큰 정사각형 찾기
    findsquare(N, M);
    return 0;
}
