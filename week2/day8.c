#include<stdio.h>

int seed[2];
int stock[2]={0,0};
int count[2]={0,0};
int c_price=0;; // 현재 가격격
void Jun(int price){
    if(seed[0] > price){
        while(seed[0] > price){
            seed[0] -= price;
            stock[0]++;
        }
    }
}

void Sung(int price){
    if(c_price == 0) c_price = price;
    if(c_price > price){
        c_price = price;
        count[0] ++ ;
        if(count[1]!=0) count[1] = 0;
        if(stock[0] == 3 && stock[1] == 0){
        while(seed[1] > price){
            seed[1] -= price;
            stock[1]++;
            count[0] = 0;
        }
    }
    }
    else if(c_price < price){
        c_price = price;
        count[1] ++;
        if(count[0]!=0) count[0] = 0;
        if(count[1] == 3 && stock[1] != 0){
            seed[1] += stock[1]*c_price;
            count[1] = 0;
        }

    }
}

int main(){
    int N;
    scanf("%d", &N);
    seed[0] = N;
    seed[1] = N;
    for(int i=0; i<14; i++){
        int price;
        scanf("%d", &price);
        Jun(price);
        Sung(price);
    }
    if(seed[0]+stock[0]*c_price>seed[1]+stock[1]*c_price){
        printf("BNF");
    }
    else if(seed[0]+stock[0]*c_price<seed[1]+stock[1]*c_price){
        printf("TIMING");
    }
    else{
        printf("SAMESAME");
    }
    return 0;
}