#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N;
int S[20][20];
bool selected[20];
int minDiff = 987654321; 

void calculateDifference(int person, int startCount) {
    if (person == N / 2) {
        int startTeam = 0, linkTeam = 0;
        int startMembers[N / 2], linkMembers[N / 2];
        int startIdx = 0, linkIdx = 0;

        for (int i = 0; i < N; i++) {
            if (selected[i]) {
                startMembers[startIdx++] = i;
            } else {
                linkMembers[linkIdx++] = i;
            }
        }

        for (int i = 0; i < N / 2; i++) {
            for (int j = i + 1; j < N / 2; j++) {
                startTeam += S[startMembers[i]][startMembers[j]] + S[startMembers[j]][startMembers[i]];
            }
        }

        for (int i = 0; i < N / 2; i++) {
            for (int j = i + 1; j < N / 2; j++) {
                linkTeam += S[linkMembers[i]][linkMembers[j]] + S[linkMembers[j]][linkMembers[i]];
            }
        }

        int diff = abs(startTeam - linkTeam);

        if (minDiff > diff) {
            minDiff = diff;
        }
        return;
    }

    for (int i = startCount; i < N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            calculateDifference(person + 1, i + 1);
            selected[i] = false;
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

    calculateDifference(0, 0);

    printf("%d", minDiff);

    return 0;
}
