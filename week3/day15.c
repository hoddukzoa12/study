#include <stdio.h>
#include <string.h>

int table[50][50];      // 배추밭 인접 행렬 (최대 크기 50x50)
int DFSvisit[50][50];   // DFS 방문 여부
int dy[4] = {0, 0, 1, -1}; // 방향 배열
int dx[4] = {1, -1, 0, 0};

// DFS 함수
void DFS(int Y, int X, int N, int M) {
    DFSvisit[Y][X] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = Y + dy[i];
        int nx = X + dx[i];

        // 유효 범위 체크 및 조건 만족 시 DFS 탐색
        if (ny >= 0 && ny < N && nx >= 0 && nx < M && 
            table[ny][nx] == 1 && DFSvisit[ny][nx] == 0) {
            DFS(ny, nx, N, M);
        }
    }
}

int main() {
    int T; // 테스트 케이스 수
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);

        // 배열 초기화
        memset(table, 0, sizeof(table));
        memset(DFSvisit, 0, sizeof(DFSvisit));

        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            table[Y][X] = 1;
        }

        int count = 0; // 필요한 지렁이 수

        // 배추밭 탐색
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (table[i][j] == 1 && DFSvisit[i][j] == 0) {
                    DFS(i, j, N, M);
                    count++;
                }
            }
        }

        // 결과 출력
        printf("%d\n", count);
    }

    return 0;
}
