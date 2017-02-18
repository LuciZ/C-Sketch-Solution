#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const char* readFileName, *searchString;
	FILE* readFile;
	char buffer[1000];
	int rowCount = 1;

	if (argc < 3)
	{
		puts("���� : srcfile string");
		return 0;
	}

	readFileName = argv[1];
	searchString = argv[2];

	// read file
	if ((readFile = fopen(readFileName, "r")) == NULL)
	{
		printf("cannot open file %s\n", readFileName);
		return 0;
	}

	printf("ã�� �ܾ� %s, ���� : %d\n", searchString, strlen(searchString));

	puts("\n�˻� ���� ��� : -->\n");

	// �� �پ� �о��
	while (!feof(readFile))
	{
		fgets(buffer, 1000, readFile);

		if (strstr(buffer, searchString) != NULL)
		{
			printf("%d : %s", rowCount, buffer);
		}

		++rowCount;
	}

	fclose(readFile);
}