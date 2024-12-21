#include<stdio.h>

int N;
int A[100];
int operator[4];
int max = -1000000000;
int min = 1000000000;

// 연산을 수행하는 함수
int calculate(int a, int b, int op){
    if(op == 0){
        return a + b;
    }else if(op == 1){
        return a - b;
    }else if(op == 2){
        return a * b;
    }else if(op == 3){
        if(a < 0){
            return -(-a / b); // 음수 나눗셈 처리
        }
        return a / b;
    }
    return 0;
}

// DFS를 이용하여 모든 경우 탐색
void dfs(int idx, int result){
    if(idx == N){
        if(result > max){
            max = result;
        }
        if(result < min){
            min = result;
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        if(operator[i] > 0){
            operator[i]--;
            dfs(idx + 1, calculate(result, A[idx], i));
            operator[i]++;
        }
    }
}

int main(){
    // 입력 받기
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < 4; i++){
        scanf("%d", &operator[i]);
    }
    
    // DFS 시작
    dfs(1, A[0]);

    // 결과 출력
    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}
