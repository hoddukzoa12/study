#include<stdio.h>

int bingo[5][5];

void find_num(int num){ // 빙고판에서 숫자 찾아서 0으로 바꾸기
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(bingo[i][j] == num){
                bingo[i][j] = 0;
            }
        }
    }
}

int find_line(){ // 빙고 줄 찾기
    int line = 0;

    for(int i=0; i<5; i++){ // 가로
        int check = 0;
        for(int j=0; j<5; j++){
            if(bingo[i][j] == 0){
                check++;
            }
        }
        if(check == 5){
            line++;
        }
    }

    for(int i=0; i<5; i++){ // 세로
        int check = 0;
        for(int j=0; j<5; j++){
            if(bingo[j][i] == 0){
                check++;
            }
        }
        if(check == 5){
            line++;
        }
    }

    int check = 0;
    for(int i=0; i<5; i++){ // 대각선
        if(bingo[i][i] == 0){
            check++;
        }
    }
    if(check == 5){
        line++;
    }

    check = 0;
    for(int i=0; i<5; i++){ // 대각선
        if(bingo[i][4-i] == 0){
            check++;
        }
    }
    if(check == 5){
        line++;
    }
    return line;
}

int find_bingo(int num){ // 빙고판에서 숫자 찾아서 줄 찾기
    find_num(num);
    return find_line();
}

int main(){
    for(int i=0; i<5; i++){ // 빙고판 입력
        for(int j=0; j<5; j++){
            scanf("%d", &bingo[i][j]);
        }
    }

    int num[25];


    for(int i=0;i<5;i++){ // 숫자 입력
        for(int j=i*5;j<i*5+5;j++){
            scanf("%d", &num[j]);
        }
    }

    for(int i=0;i<25;i++){ // 빙고판에서 숫자 찾아서 줄 찾기
        if( find_bingo(num[i])>=3){
            printf("%d",i+1);
            break;
        }
    }
}