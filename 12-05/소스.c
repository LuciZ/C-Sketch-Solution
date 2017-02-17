#include <stdio.h>
#include <stdlib.h>

int isAlpha(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isNotAlpha(char ch)
{
	return ch == 0 || ch == ' ' || ch == '\t' || ch == '\n';
}

int main(int argc, char *argv[])
{
	const char* readFileName;
	FILE* readFile;
	char buffer[1000];
	// ���� ����
	int rowCount = 0, wordCount = 0, characterCount = 0;

	if (argc < 2)
	{
		puts("���� : filename");
		return 0;
	}

	readFileName = argv[1];

	// read file
	if ((readFile = fopen(readFileName, "r")) == NULL)
	{
		printf("cannot open file %s\n", readFileName);
		return 0;
	}

	// �� �پ� �о��
	while (!feof(readFile))
	{
		fgets(buffer, 1000, readFile);

		// ��� ���ڵ��� �˻�
		for (int i = 0; buffer[i]; ++i)
		{
			// ����
			if (isAlpha(buffer[i]))
			{
				++characterCount;
			}
			// �ڿ� ���� ���ڰ� ������ �ܾ�
			if (isAlpha(buffer[i]) && isNotAlpha(buffer[i + 1]))
			{
				++wordCount;
			}
		}

		++rowCount;
	}

	printf("���� �� : %d, �ܾ� �� : %d, �� �� : %d\n", characterCount, wordCount, rowCount);

	fclose(readFile);
}