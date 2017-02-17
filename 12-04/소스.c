#include <stdio.h>
#include <stdlib.h>

char toUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		ch += 'A' - 'a';
	}

	return ch;
}

int main(int argc, char *argv[])
{
	const char* readFileName;
	FILE* readFile;

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

	puts("������ ���� ���� ��� :-->");

	// �� ���ھ� ���
	while (!feof(readFile))
	{
		putchar(fgetc(readFile));
	}

	fseek(readFile, 0, SEEK_SET);

	puts("\n��ȯ�� ���� ���� ��� :-->");

	// �� ���ھ� �о�ͼ� �빮�ڷ� ��ȯ �� ���
	while (!feof(readFile))
	{
		putchar(toUpper(fgetc(readFile)));
	}

	fclose(readFile);
}