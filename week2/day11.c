#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N; // 인원 수
int S[20][20]; // 능력치
int visited[20]; // 선정된 팀원
int min_diff = INT_MAX; // 최대값

void calculate_team_difference() { // 팀 능력치 차이 계산
    int start_team = 0, link_team = 0;

    for (int i = 0; i < N; i++) { // 팀 능력치 계산
        for (int j = 0; j < N; j++) {
            if (visited[i] && visited[j]) { // 스타트 팀원이면
                start_team += S[i][j];
            } else if (!visited[i] && !visited[j]) { // 링크 팀원이면
                link_team += S[i][j];
            }
        }
    }

    int diff = abs(start_team - link_team); // 능력치 차이 계산
    if (diff < min_diff) {
        min_diff = diff;
    }
}

void make_team(int idx, int count) { // 팀 능력치 차이 계산
    if (count == N / 2) { // 팀이 완성되면
        calculate_team_difference();
        return;
    }

    for (int i = idx; i < N; i++) { // 팀원 선택
        if (!visited[i]) {
            visited[i] = 1;
            make_team(i + 1, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    make_team(0, 0);
    printf("%d\n", min_diff);

    return 0;
}
