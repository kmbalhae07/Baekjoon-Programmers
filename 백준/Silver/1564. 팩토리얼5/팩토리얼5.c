#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    long long int result = 1;

    for (int i = 2; i <= N; i++) {
        result *= i;

        while (result % 10 == 0) {
            result /= 10;
        }

        result %= 1000000000000;
    }

    result %= 100000;
    printf("%05lld\n", result);

    return 0;
}
