#include<stdio.h>

int cup[3]={1,0,0}; // 공이 있는 컵의 위치를 나타내는 배열

void swap(int a, int b){ // X와 Y의 위치를 바꾸는 함수
    int temp = cup[a];
    cup[a] = cup[b];
    cup[b] = temp;
}

int main(){
    int M;

    scanf("%d", &M); // 섞는 횟수 입력

    int X, Y; // X와 Y 입력
    for(int i=0; i<M; i++){ // M번 섞기
        scanf("%d %d", &X, &Y);
        swap(X-1, Y-1);
    }

    for(int i=0; i<3; i++){ // 공공이 있는 컵의 위치 출력
        if(cup[i] == 1){
            printf("%d\n", i+1);
            break;
        }
    }
}