#include <stdio.h>
#include <stdlib.h>

int MAX_BUF_SIZE = 1000;

int StrToHex(char perevodimoe);

int main()
{
	char* input = (char*)calloc(MAX_BUF_SIZE, sizeof(char));

	fgets(input, MAX_BUF_SIZE, stdin);

	int MAX_SIZE = -1;

	for (int i = 0; input[i] != '\0'; i++)
	{
		MAX_SIZE++;
	}

	//printf("\n\n\n%d\n\n\n", MAX_SIZE);


	/*for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("<%c>", input[i]);
	}*/

	//printf("\n\n");
	//puts(input);
	

	char* output = (char*)calloc(4 * MAX_SIZE, sizeof(char));

	int buf = 0;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		buf = StrToHex(input[i]);
		//printf(">>%X ", buf);

		output[MAX_SIZE * 4 - i * 4 - 3] = buf % 2;
		buf = buf / 2;

		output[MAX_SIZE * 4 - i * 4 - 2] = buf % 2;
		buf = buf / 2;

		output[MAX_SIZE * 4 - i * 4 - 1] = buf % 2;
		buf = buf / 2;

		output[MAX_SIZE * 4 - i * 4 - 0] = buf % 2;
		buf = buf / 2;

		/*for (int j = 0; j < 4; j++)
		{
			printf("%d", output[MAX_SIZE * 4 - i * 4 - j]);
		}
		printf("\n");*/
	}

	for (int j = 0; j < MAX_SIZE * 4; j++)
	{
		printf("%d", output[MAX_SIZE * 4 - j]);
	}
}

int StrToHex(char perevodimoe)
{
	int returned = 0;

	switch (perevodimoe)
	{
	case 'A':
		returned = 10;
		break;
	case 'B':
		returned = 11;
		break;
	case 'C':
		returned = 12;
		break;
	case 'D':
		returned = 13;
		break;
	case 'E':
		returned = 14;
		break;
	case 'F':
		returned = 15;
		break;
	default:
		returned = perevodimoe - '0';
	}

	return returned;
}