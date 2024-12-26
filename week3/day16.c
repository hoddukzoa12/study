#include<stdio.h>
#include<string.h>

// 집 배열과 방문 여부를 저장할 배열
int home[25][25]; // 입력받은 집의 지도
int visit[25][25]; // 방문 여부 확인 배열

// 방향 이동을 위한 배열 (동, 서, 남, 북)
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

// 단지 내 집의 수를 저장할 배열
int complex[25*25] = {0,}; // 최대 단지 수만큼 크기 할당
int count = 0; // 단지의 개수

// 깊이 우선 탐색 (DFS) 함수
void DFS(int Y, int X, int N) {
    visit[Y][X] = 1; // 현재 위치 방문 처리
    complex[count]++; // 현재 단지의 집 수 증가

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int ny = Y + dy[i]; // 새로운 y 좌표
        int nx = X + dx[i]; // 새로운 x 좌표

        // 지도 범위를 벗어나지 않고, 집이 있으며, 방문하지 않은 경우
        if (ny >= 0 && ny < N && nx >= 0 && nx < N && home[ny][nx] == 1 && visit[ny][nx] == 0) {
            DFS(ny, nx, N); // 해당 위치로 이동하여 DFS 수행
        }
    }
}

int main() {
    int N; // 지도의 크기 (N x N)
    scanf("%d", &N); // 지도 크기 입력

    // 지도 데이터 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &home[i][j]); // 한 자리씩 입력받음
        }
    }

    // 방문 배열 초기화
    memset(visit, 0, sizeof(visit));

    // 모든 위치를 탐색하며 단지 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (home[i][j] == 1 && visit[i][j] == 0) { // 집이 있으며 방문하지 않은 경우
                DFS(i, j, N); // 새로운 단지를 탐색
                count++; // 단지 개수 증가
            }
        }
    }

    // 단지의 총 개수 출력
    printf("%d\n", count);

    // 단지 내 집의 수를 오름차순으로 정렬
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (complex[i] > complex[j]) {
                int temp = complex[i];
                complex[i] = complex[j];
                complex[j] = temp;
            }
        }
    }

    // 각 단지의 집 수 출력
    for (int i = 0; i < count; i++) {
        printf("%d\n", complex[i]);
    }

    return 0;
}
