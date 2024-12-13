#include<stdio.h>
#define MIN_COUNT 0
char wb[50][50]={0,};
char pattern1[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};
char pattern2[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};
void findwb(int a,int b){
    int min=MIN_COUNT;
    for(int i=0;i<a-7;i++){
        for(int j=0;j<b-7;j++){
            int cnt1=0;
            int cnt2=0;
            for(int x=0;x<8;x++){
                for(int y=0;y<8;y++){
                    if(wb[i+x][j+y]!=pattern1[x][y]){
                        cnt1++;
                    }
                    if(wb[i+x][j+y]!=pattern2[x][y]){
                        cnt2++;
                    }
                }
            }
            if(cnt1<cnt2){
                min=cnt1;
            }
            else{
                min=cnt2;
            }
        }
    }
    printf("%d",min);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    for( int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%c",wb[i][j]);
        }
    }
    findwb(a,b);
}