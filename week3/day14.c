#include<stdio.h>

int graph[1001][1001]; // 인접행렬
int DFSvisit[1001]; // DFS 방문 여부

void DFS(int V, int N){ // DFS 함수
    DFSvisit[V] = 1; // 방문했음을 표시
    for(int i = 1; i <= N; i++){ // 모든 노드에 대해
        if(graph[V][i] == 1 && DFSvisit[i] == 0){ // 연결되어 있고 방문하지 않았다면
            DFS(i, N); // 재귀적으로 방문
        }
    }
}

int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int i =1,count =0;

    for(i = 1; i <= N; i++){ 
        if(DFSvisit[i] == 0){ 
            DFS(i, N);
            count++;
        }
    }
    
    printf("%d\n", count);
}