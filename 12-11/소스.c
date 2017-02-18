#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char* writeFileName = "prime.txt";
	FILE* writeFile;
	// �����佺�׳׽��� ü
	int isNotPrime[1001] = { 0 };
	int rowCount = 0;

	writeFile = fopen(writeFileName, "w");

	// �����佺�׳׽��� ü ����
	for (int i = 2; i * i <= 1000; ++i)
	{
		for (int j = i * i; j <= 1000; j += i)
		{
			isNotPrime[j] = 1;
		}
	}

	for (int i = 2; i <= 1000; ++i)
	{
		if (isNotPrime[i] == 0)
		{
			printf("%4d", i);
			fprintf(writeFile, "%4d", i);

			++rowCount;
		}

		if (rowCount == 20)
		{
			putchar('\n');
			fputc('\n', writeFile);
			rowCount = 0;
		}
	}

	fclose(writeFile);
}