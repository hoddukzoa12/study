#include<stdio.h>

int graph[1001][1001]; // 인접행렬
int DFSvisit[1001]; // DFS 방문 여부
int BFSvisit[1001]; // BFS 방문 여부
int queue[1001]; // BFS 큐

void DFS(int V, int N){ // DFS 함수
    printf("%d ", V); // 방문한 노드 출력
    DFSvisit[V] = 1; // 방문했음을 표시
    for(int i = 1; i <= N; i++){ // 모든 노드에 대해
        if(graph[V][i] == 1 && DFSvisit[i] == 0){ // 연결되어 있고 방문하지 않았다면
            DFS(i, N); // 재귀적으로 방문
        }
    }
}

void BFS(int V, int N){ // BFS 함수
    int front = 0; // 큐의 앞
    int rear = 0; // 큐의 뒤
    printf("%d ", V); // 방문한 노드 출력
    BFSvisit[V] = 1; // 방문했음을 표시
    queue[rear++] = V; // 큐에 넣기
    while(front < rear){   // 큐가 비어있지 않은 동안
        V = queue[front++]; // 큐에서 하나 꺼내기
        for(int i = 1; i <= N; i++){ // 모든 노드에 대해
            if(graph[V][i] == 1 && BFSvisit[i] == 0){ // 연결되어 있고 방문하지 않았다면
                printf("%d ", i); // 방문한 노드 출력
                BFSvisit[i] = 1; // 방문했음을 표시
                queue[rear++] = i; // 큐에 넣기
            }
        }
    }
}

int main(){
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(V, N);
    printf("\n");
    BFS(V, N);
    printf("\n");
    return 0;
}