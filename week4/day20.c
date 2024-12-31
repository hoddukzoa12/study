#include<stdio.h>

int dpData[1000000] = {0, };


void dp(int n){
    for (int i=2; i<=n; i++){
        dpData[i] = dpData[i-1] + 1; // 1을 빼는 경우
        
        if(n%2==0) dpData[i] = dpData[i] < dpData[i/2] + 1 ? dpData[i] : dpData[i/2] + 1; // 2로 나누는 경우

        if(n%3==0) dpData[i] = dpData[i] < dpData[i/3] + 1 ? dpData[i] : dpData[i/3] + 1; // 3으로 나누는 경우
    }
}

int main(){
    int n;

    scanf("%d", &n);    

    dp(n);
    printf("%d", dpData[n]);

    return 0;
}