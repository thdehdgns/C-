#include <stdio.h>	
#define SIZE 1000000

void Load(const char * filename)
{
	char buffer[SIZE] = { 0, };
	FILE* file = fopen(filename, "r");
	fread(buffer, 1, SIZE, file);
	printf("%s",buffer);
	fclose(file);
}

int main()
{

#pragma region ���� ����

	// "w" write : ������ ���� ���� �����մϴ�.
	//FILE* file = fopen("data.txt", "w");

	//fputs("Level:\n", file);
	//fputs("Health:\n", file);

	//fclose(file);
#pragma endregion

#pragma region ���� �б�

	
	// "r" read : ������ �б����� ����ϴ� ����Դϴ�.
	
	
	// ù ��° �Ű����� : ���� �����͸� ������ �޸� ������ ������ ����
	// �� ��° �Ű����� : �� ������ �׸��� ũ��
	// �� ��° �Ű����� : �����͸� �о�� �����׸��� ��
	// �� ��° �Ű����� : �����͸� �о�� ������ ������ ����

	Load("Miraidon.TXT");


#pragma endregion

	return 0;
}