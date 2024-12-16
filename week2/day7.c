#include<stdio.h>

int cup[3]={1,0,0};

void swap(int a, int b){
    int temp = cup[a];
    cup[a] = cup[b];
    cup[b] = temp;
}

int main(){
    int M;

    scanf("%d", &M);

    int X, Y;
    for(int i=0; i<M; i++){
        scanf("%d %d", &X, &Y);
        swap(X-1, Y-1);
    }

    for(int i=0; i<3; i++){
        if(cup[i] == 1){
            printf("%d\n", i+1);
            break;
        }
    }
}