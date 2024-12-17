#include <stdio.h>

int seed[2];           // 준현과 성민의 초기 자금
int stock[2] = {0, 0}; // 각자의 주식 보유량
int count[2] = {0, 0}; // 성민이의 상승/하락 카운트
int c_price = 0;       // 성민이의 현재 기준 가격

// 준현이의 BNP 전략
void Jun(int price) {
    while (seed[0] >= price) {
        seed[0] -= price;
        stock[0]++;
    }
}

// 성민이의 TIMING 전략
void Sung(int price) {
    if (c_price == 0) c_price = price; // 첫 번째 주가를 초기 기준으로 설정

    if (c_price > price) { // 가격이 하락한 경우
        c_price = price;
        count[0]++;
        count[1] = 0;

        if (count[0] == 3) { // 3일 연속 하락 시 전량 매수
            while (seed[1] >= price) {
                seed[1] -= price;
                stock[1]++;
            }
        }
    } else if (c_price < price) { // 가격이 상승한 경우
        c_price = price;
        count[1]++;
        count[0] = 0;

        if (count[1] == 3) { // 3일 연속 상승 시 전량 매도
            seed[1] += stock[1] * price;
            stock[1] = 0;
        }
    }
}

int main() {
    int N = 14; // 입력이 항상 14일로 주어짐
    int price[14]; // 주식 가격 배열

    // 초기 자금 입력
    scanf("%d", &seed[0]);
    seed[1] = seed[0]; // 성민이의 자금도 동일하게 설정

    // 주식 가격 입력
    for (int i = 0; i < N; i++) {
        scanf("%d", &price[i]);
    }

    // 주식 거래 수행
    for (int i = 0; i < N; i++) {
        Jun(price[i]);
        Sung(price[i]);
    }

    // 최종 자산 계산
    int final_jun = seed[0] + stock[0] * price[N - 1];
    int final_sung = seed[1] + stock[1] * price[N - 1];

    // 결과 출력
    if (final_jun > final_sung) {
        printf("BNP");
    } else if (final_jun < final_sung) {
        printf("TIMING");
    } else {
        printf("SAMESAME");
    }

    return 0;
}
