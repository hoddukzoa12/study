#include<stdio.h>

int N; // N일
int T[15]={0,}; // 상담일
int P[15]={0,}; // 상담금

int profit(int day, int sum){ // day일에 sum금을 벌었을 때 최대 이익
    if(day == N){ // N일이 되면
        return sum; 
    }
    if(day > N){ // N일을 넘어가면
        return 0;
    }

    int a = profit(day+T[day], sum+P[day]); // day일에 상담을 하는 경우
    int b = profit(day+1, sum); // day일에 상담을 하지 않는 경우

    if(a>b){ // 더 큰 값을 반환
        return a;
    }else{ 
        return b;
    }
}

int main(){

    scanf("%d", &N);

    for(int i=0;i<N;i++){ // 상담일과 상담금 입력
        scanf("%d %d", &T[i], &P[i]);
    }

    printf("%d", profit(0,0));
    return 0;
}