#include<stdio.h>

int dpData[301] = {0, };
int stairs[301] = {0, };

void dp(int n){
    int count = 0;
    for(int i=2; i<=n; i++){
        if(count ==3) dpData[i] = dpData[i-3] + stairs[i-1] + stairs[i]; // 3칸 연속으로 밟는 경우
        else{
            dpData[i] = dpData[i-1] + stairs[i];
            count ++; // 1칸 연속으로 밟는 경우
            if(i-2>=0){
                dpData[i] = dpData[i] > dpData[i-2] + stairs[i] ? dpData[i] : dpData[i-2] + stairs[i]; // 2칸 연속으로 밟는 경우
                count = 0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i; i<n; i++){
        scanf("%d", &stairs[i]);
    }

    dp(n);
    printf("%d", dpData[n]);
} 