#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CPU
{
	int eax;
	int ebx;
	int ecx;
	int edx;
};

//int MAX_SIZE = 15;
#define MAX_SIZE 15

int Compare(char* argument_first, char* argument_second, struct CPU * cpu, int** record);

int main()
{
	struct CPU cpu;

	cpu.eax = 0;
	cpu.ebx = 0;
	cpu.ecx = 0;
	cpu.edx = 0;

	char* command = (char*)calloc(MAX_SIZE, sizeof(char));
	char* argument_first = (char*)calloc(MAX_SIZE, sizeof(char));
	char* argument_second = (char*)calloc(MAX_SIZE, sizeof(char));

	int* record = nullptr;

	while(1)
	{
		scanf("%s", command);

		if (strcmp(command, "mov") == 0)
		{
			int arg = Compare(argument_first, argument_second, &cpu, &record);
			*record = arg;
		}
		if (strcmp(command, "add") == 0)
		{
			int arg = Compare(argument_first, argument_second, &cpu, &record);
			*record = *record + arg;
		}
		if (strcmp(command, "sub") == 0)
		{
			int arg = Compare(argument_first, argument_second, &cpu, &record);
			*record = *record - arg;
		}
		if (strcmp(command, "ret") == 0)
		{
			free(command);
			free(argument_first);
			free(argument_second);

			return 0;
		}
		printf("eax - %d\nebx - %d\necx - %d\nedx - %d\n", cpu.eax, cpu.ebx, cpu.ecx, cpu.edx);
	}
}

int Compare(char* argument_first, char* argument_second, struct CPU* cpu, int** record)
{
	char* ptr;

	scanf("%s %s", argument_first, argument_second);

	switch (*(argument_first + 1))
	{
		case 'a':
		{
			*record = &(cpu->eax);
			break;
		}
		case 'b':
		{
			*record = &(cpu->ebx);
			break;
		}
		case 'c':
		{
			*record = &(cpu->ecx);
			break;
		}
		case 'd':
		{
			*record = &(cpu->edx);
			break;
		}
	}

	int arg = strtol(argument_second, &ptr, 0);

	if (*ptr == 'e')
	{
		switch (*(ptr + 1))
		{
			case 'a':
			{
				arg = cpu->eax;
				break;
			}
			case 'b':
			{
				arg = cpu->ebx;
				break;
			}
			case 'c':
			{
				arg = cpu->ecx;
				break;
			}
			case 'd':
			{
				arg = cpu->edx;
				break;
			}
		}
	}

	return arg;
}