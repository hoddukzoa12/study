#include <stdio.h>
int num[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 족보를 계산하는 함수 (땡과 끗 계산)
int calculate_score(int x, int y) {
    if (x == y) {
        return 10 + x; // "땡" 처리
    } else {
        return (x + y) % 10; // "끗" 처리
    }
}

// 사용된 카드를 표시하는 함수
void used_card(int x, int y) {
    int count = 0; // 몇 개의 카드를 사용했는지 추적
    for (int i = 0; i < 20; i++) {
        if (num[i] == x && count == 0) { // 첫 번째 값 제거
            num[i] = 0;
            count++;
        } else if (num[i] == y && count == 1) { // 두 번째 값 제거
            num[i] = 0;
            count++;
            break; // 두 개 제거 후 루프 종료
        }
    }
}

// 영학이가 이길 확률 계산 함수
float calculate_probability(int a, int b) {
    used_card(a, b);
    int total_cases = 0;
    int lose_cases = 0;

    int my_score = calculate_score(a, b);
    for (int i = 0; i < 20; i++) {
        if (num[i] == 0) continue;
        for (int j = i + 1; j < 20; j++) { // j는 항상 i+1부터 시작
            if (num[j] == 0) continue;
            total_cases++;
            int your_score = calculate_score(num[i], num[j]);
            if (my_score <= your_score) {
                lose_cases++;
            }
        }
    }
    printf("total_cases: %d\n", total_cases);
    printf("lose_cases: %d\n", lose_cases);
    // 확률 계산
    return (float)(total_cases - lose_cases) / total_cases;
}

int main() {
    int a, b;

    // 입력 받기
    scanf("%d %d", &a, &b);

    // 확률 계산
    float result = calculate_probability(a, b);

    // 결과 출력
    printf("%.3f\n", result);

    return 0;
}
