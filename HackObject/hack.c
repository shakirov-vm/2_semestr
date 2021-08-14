#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "hack.h"

// Launch: make weak -> go -> compile -> run -> go

int main(int argc, char** argv)
{
	char* input = argv[1];

	FILE* potok = fopen(input, "rb");
	if (potok == NULL) ErrorOpen(input);

	size_t size_file = FileSize(input);
	if (size_file == 0) return(EMPTY_FILE);

	char* text = (char*) calloc (size_file, sizeof(char));
	if (text == NULL) return(NOMEMALLOC);

	size_t read = fread(text, sizeof(char), size_file, potok);
	if (read != size_file) return(FEWREAD);

	fclose(potok);

	size_t len = strlen(replaceable);

	for(int i = 0; i < size_file; i++)
	{
		if (text[i] == 'H')
		{
			if (strncmp((text + i), replaceable, len) == 0) 
				snprintf(text + i, len + 1, "%s", our);
		}
	}

	potok = fopen(input, "wb");
	if (potok == NULL) ErrorOpen(input);

	size_t write = fwrite(text, sizeof(char), size_file, potok);
	if (read != write) return(FEWWRITE);

	fclose(potok);

	return 0;
}

size_t FileSize(char* input)
{
	struct stat buff;
	stat(input, &buff);

	return buff.st_size;
}

void ErrorOpen(char* input)
{
	char answer[100];

	sprintf(answer, "Problem file: %s\n", input);

	perror(answer);
	exit(UNOPEN);
}