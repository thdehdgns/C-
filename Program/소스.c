#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Size 11

int main()
{
	int a = 0;
	char T;
	const char* Cha[2];
	Cha[0] = "�Ƿ���";
	Cha[1] = "������";
	const char* dialog[Size];
	dialog[0] = "�ȳ��ϼ���";
	dialog[1] = "�ݰ����ϴ�. �� �̸��� ������ Ž������.";
	dialog[2] = "��. Ž���� �����..";
	dialog[3] = "�̰�!";
	dialog[4] = "���� ���̶�?";
	dialog[5] = "�̰� �ܼ� ���λ���� �ƴմϴ�.";
	dialog[6] = "�׷� ����..?";
	dialog[7] = "�̰��� �����ڸ� ���� ���ǰ� ��� ��ȹ���� �����Դϴ�.";
	dialog[8] = "��? �׷� ����ü ����?";
	dialog[9] = "������ �ٷ�..";
	dialog[10] = "???(���� �𸣰ڴٴ� ǥ��)";

	int count = 0;

	while (count < Size)
	{
		//�����
		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			printf("%s: %s\n", Cha[a], dialog[count]);
			if (count % 2)
			{
				a = 0;
			}
			else
			{
				a = 1;
			}
		count++;
		}
	}
	
	//	for (int i = 0; i < Size;i++)
	//	{
	// //�񵿱��
	//		//0x0000 : ������ ���� ���� ���� ȣ�� �������� �������� ���� ����
	//	
	//		//0x0001 : ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����
	//	
	//		//0x8000 : ������ ���� ���� ���� ȣ�� �������� �����ִ� ����
	//		
	//		//0x8001 : ������ ���� ���� �ְ� ȣ�� ������ ���� �ִ� ����
	//		
	//		printf("%s: %s\n",Cha[a], dialog[i]);
	//		T = _getch();
	//		if (i%2)
	//		{
	//			a = 0;
	//		}
	//		else
	//		{
	//			a = 1;
	//		}
	//	}

	printf("\n����ȭ�� ���");

	return 0;
}