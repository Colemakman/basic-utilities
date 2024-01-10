#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 400

int search_and_print(const char *search_term, FILE *input) {
	char buffer[BUFFER_SIZE];

	while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
		if (strstr(buffer, search_term) != NULL) {
			printf("%s", buffer);
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		return 1;
	}

	const char *search_term = argv[1];

	if (argc == 2) {
		return search_and_print(search_term, stdin);
	}	
	
	for (int i = 2; i < argc; i++) {

		FILE *text = fopen(argv[i], "r");
		if (text == NULL) {
			printf("wgrep: cannot open file\n");
			return 1;
		}

		search_and_print(search_term, text);
		fclose(text);
	}

	return 0;
}
