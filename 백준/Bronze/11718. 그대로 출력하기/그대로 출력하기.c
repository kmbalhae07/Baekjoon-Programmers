#include <stdio.h>
#include <string.h>

int main() {
	char input[105];
	int newline_count = 0;
	int ch, count = 0;

	do {
		ch = getchar();

		if (ch == EOF) {
			break;
		}
		else if(ch == 10) {
			break;
		}
		else {
			ungetc(ch, stdin);

			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = '\0';

			printf("%s\n", input);
		}
	} while (1);

	return 0;
}
