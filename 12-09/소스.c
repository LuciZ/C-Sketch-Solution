#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};
typedef struct personscore pscore;

void printhead();
void printscore(FILE* f);
void appendscore(FILE* f, int cnt);
void searchById(FILE* f, int id);

int main()
{
	char fname[] = "score.bin";
	FILE* f;
	int cnt = 0;
	long offset = 0;
	pscore score = { 0 };

	// if((f = fopen(fname, "a+")) == NULL)
	if (fopen_s(&f, fname, "a+") != 0)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	printscore(f);
	offset = (long) sizeof(pscore);			// ����ü �ϳ��� ũ��
	fseek(f, -offset, SEEK_CUR);			// ������ ���� �����Ϳ��� �� �л���ŭ �ڷ� �̵�

	fread(&score, sizeof(pscore), 1, f);	// �� �л�(������ �л�)�� ����

	// ���� ������ �ڷ��� ��ȣ�� ã�� ���Ͽ�
	cnt = score.number;
	printf("\n���� ������ ��ȣ�� %d�� �Դϴ�.\n\n", cnt);

	while (1)
	{
		int command;

		puts("�л� ��ȣ �˻� : 1, �л� �߰� : 2, ���� : 0 �Է� >>");
		scanf(" %d", &command);

		if (command == 1)
		{
			int id;
			puts("�˻��� �л� ��ȣ�� �Է� >>");
			scanf("%d", &id);
			searchById(f, id);
		}
		else if (command == 2)
		{
			// ���� ����
			getchar();
			fseek(f, 0L, SEEK_END);
			appendscore(f, cnt);
			printscore(f);
		}
		else if (command == 0)
		{
			break;
		}
		else
		{
			puts("�ٽ� �Է��Ͻÿ�");
		}
	}
	fclose(f);

	return 0;
}

int fileSize(FILE* f)
{
	fseek(f, 0, SEEK_END);
	return ftell(f);
}

void searchById(FILE* f, int id)
{
	pscore score;
	long offset = (long) sizeof(pscore);			// ����ü �ϳ��� ũ��

	// ���� ó��
	if (id <= 0 || fileSize(f) <= offset * (id - 1))
	{
		puts("���ϴ� ��ȣ�� �л��� �����ϴ�.");
		return;
	}

	fseek(f, offset * (id - 1), SEEK_SET);			// ������ ó�� �����Ϳ��� �л� ��ȣ��ŭ �ڷ� �̵�

	fread(&score, sizeof(pscore), 1, f);			// �� �л�(������ �л�)�� ����

	printhead();
	fprintf(stdout, "%6d%18s%8d%8d%8d\n", score.number, score.name, score.mid, score.final, score.quiz);
	fprintf(stdout, "%s\n", "---------------------------------------------------------");
}

void appendscore(FILE* f, int cnt)
{
	pscore score;
	char line[80];
	printf("�߰��� �̸��� ����(�߰�, �⸻, ����)�� �Է��ϼ���.\n\n");
	fgets(line, 80, stdin);
	while (!feof(stdin))
	{
		sscanf_s(line, "%s %d %d %d", score.name, 40, &score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
}

void printhead()
{
	printf("\n������ ���� ������ >>\n");
	fprintf(stdout, "%s\n", "---------------------------------------------------------");
	fprintf(stdout, "%8s%15s%10s%8s%8s\n", "��ȣ", "�̸�", "�߰�", "�⸻", "����");
	fprintf(stdout, "%s\n", "---------------------------------------------------------");
}

void printscore(FILE* f)
{
	pscore score;
	rewind(f);
	printhead();
	fread(&score, sizeof(pscore), 1, f);
	while (!feof(f))
	{
		// ǥ����¿� ����
		fprintf(stdout, "%6d%18s%8d%8d%8d\n", score.number, score.name, score.mid, score.final, score.quiz);
		fread(&score, sizeof(pscore), 1, f);
	}
	fprintf(stdout, "%s\n", "---------------------------------------------------------");
}