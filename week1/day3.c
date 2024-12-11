#include<stdio.h>
#define MAX_N 1000
#define MAX_T 100000

int triangle[MAX_N + 1]; 
int num[MAX_T];

void Tn() {
    for (int i = 1; i <= MAX_N; i++) {
        triangle[i] = i * (i + 1) / 2;
    }
}

int isSum(int n) {
    for (int i = 1; i <= MAX_N && triangle[i] < n; i++) {
        for (int j = i; j <= MAX_N && triangle[i] + triangle[j] < n; j++) {
            for (int k = j; k <= MAX_N && triangle[i] + triangle[j] + triangle[k] <= n; k++) {
                if (triangle[i] + triangle[j] + triangle[k] == n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
// void combination(int N, int R, int q,int j) {
//     if (found) return; 

//     int sum = 0;
//     if (R == 0) { 
//         for (int i = 0; i < q; i++) {
//             sum += Tn(copy[i]);
//         }
//         if (sum == num[j]) { 
//             found = 1; // 정답을 찾았음을 표시
//         }
//         return;
//     }
//     if (N < R) return; 

//     copy[R - 1] = N; 
//     combination(N - 1, R - 1, q, j); // 선택한 경우
//     combination(N - 1, R, q, j); // 선택하지 않은 경우
// }


int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &num[i]);
    }
    Tn();
    for(int i=0;i<T;i++){
        if(isSum(num[i])){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}