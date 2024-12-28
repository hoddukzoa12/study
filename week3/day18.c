#include <stdio.h>

int visited[100001]; // 방문 여부 및 거리 기록 배열
int queue[100001];   // 큐 배열
int min = 100000;    // 최소 시간
int count = 0;       // 최소 시간의 경우의 수
void BFS(int N, int K) {
    int front = 0;  // 큐의 앞
    int rear = 0;   // 큐의 뒤

    visited[N] = 1;       // 시작 지점 방문 표시 (1부터 시작하므로 방문 시간은 1)
    queue[rear++] = N;    // 시작 지점 큐에 추가

    while (front < rear) {   // 큐가 비어있지 않은 동안
        int current = queue[front++];  // 큐에서 하나 꺼내기

        if (current == K) {  // 목표점 도달
            if (visited[current] - 1 < min) {
                min = visited[current] - 1;
            }
            else if(visited[current] - 1 == min) {
                count++;
            }
            continue;
        }

        // 다음 위치 탐색
        if (current - 1 >= 0 && visited[current - 1] == 0) {
            visited[current - 1] = visited[current] + 1;
            queue[rear++] = current - 1;
        }
        if (current + 1 <= 100000 && visited[current + 1] == 0) {
            visited[current + 1] = visited[current] + 1;
            queue[rear++] = current + 1;
        }
        if (current * 2 <= 100000 && visited[current * 2] == 0) {
            visited[current * 2] = visited[current] + 1;
            queue[rear++] = current * 2;
        }
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);  // N, K 입력

    BFS(N, K);
    printf("%d\n", min);
    printf("%d\n", count);
    return 0;
}
