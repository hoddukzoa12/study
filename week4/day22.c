#include<stdio.h>

int dp[1001]={0,};

void makeDP(int n){
    dp[0]=1; // 1번째 타일의 경우의 수
    dp[1]=2; // 2번째 타일의 경우의 수
    for(int i=2; i<n; i++){ // 2번째부터 n-1번째까지
        dp[i]=(dp[i-1]+dp[i-2])%10007; // i번째 타일의 경우의 수
    }
}

int main(){
    int n;
    scanf("%d", &n); // n 입력

    makeDP(n); // n번째 타일까지의 경우의 수 계산
    printf("%d\n", dp[n-1]); // n번째 타일의 경우의 수 출력

    return 0;
}