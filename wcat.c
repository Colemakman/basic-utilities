#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	if (argc < 2) {
		return 0;
	}

	//char **path = (**char)malloc((argc-1)*sizeof(char*));

	char *s = malloc(400);
	for (int i = 1; i < argc; i++) {

		FILE *text = fopen(argv[i], "r");
		if (text == NULL) {
			printf("wcat: cannot open file\n");
			return 1;	
		}

		while (fgets(s, 400, text) != NULL) {
			printf("%s", s);
		}

		fclose(text);
	}

	free(s);
	
	return 0;
}
