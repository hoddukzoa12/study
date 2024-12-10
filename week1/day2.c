#include<stdio.h>
int n[9], copy[7]; // 9명의 키와 7명의 키를 저장할 배열
int found = 0; // 정답을 찾았는지 여부를 저장

void sort() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (n[i] > n[j]) { // 오름차순 정렬
                int temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
}

void combination(int N, int R, int q) {
    if (found) return; // 이미 정답을 찾았으면 종료

    int sum = 0;
    if (R == 0) { // 7명을 모두 선택했을 때
        for (int i = 0; i < q; i++) {
            sum += copy[i];
        }
        if (sum == 100) { // 합이 100이면 정답 출력
            for (int i = 0; i < q; i++) {
                printf("%d\n", copy[i]);
            }
            found = 1; // 정답을 찾았음을 표시
        }
        return;
    }
    if (N < R) return; // 선택할 수 있는 인원이 부족한 경우

    copy[R - 1] = n[N - 1]; // 현재 난쟁이 선택
    combination(N - 1, R - 1, q); // 선택한 경우
    combination(N - 1, R, q); // 선택하지 않은 경우
}

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", &n[i]);
    }
    sort(); // 난쟁이 키 정렬
    combination(9, 7, 7); // 9명 중 7명을 선택
    return 0;
}
