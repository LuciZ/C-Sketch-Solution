#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const char* readFileName1, *readFileName2;
	FILE* readFile1, *readFile2;

	if (argc < 3)
	{
		puts("���� : file1 file2");
		return 0;
	}

	readFileName1 = argv[1];
	readFileName2 = argv[2];

	// read file
	if ((readFile1 = fopen(readFileName1, "r")) == NULL)
	{
		printf("cannot open file %s\n", readFileName1);
		return 0;
	}

	// read file
	if ((readFile2 = fopen(readFileName2, "r")) == NULL)
	{
		printf("cannot open file %s\n", readFileName2);
		return 0;
	}

	// �� ���ھ� �о�ͼ� ��
	while (!feof(readFile1) || !feof(readFile2))
	{
		if (feof(readFile1) || feof(readFile2) || fgetc(readFile1) != fgetc(readFile2))
		{
			puts("������ �ٸ��ϴ�.");
			return 0;
		}
	}

	puts("������ �����ϴ�.");

	fclose(readFile1);
	fclose(readFile2);
}