#include <stdio.h>

int main() {
    int king, queen, look, bishop, night, poon;
    scanf("%d %d %d %d %d %d", &king, &queen, &look, &bishop, &night, &poon);
    printf("%d %d %d %d %d %d", 1-king, 1-queen, 2-look, 2-bishop, 2-night, 8-poon);
}
