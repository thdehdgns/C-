#include <stdio.h>
#include <windows.h>
	enum State
	{
		IDLE,
		ATTACK,
		DIE
	};
	// ���������� �߰��� �ִ� ����� ���� �����ϰ� �Ǹ�
	// �� ������ �ִ� ����� ���� ����� ������ ���� 1�� ����.
	enum TextColor
	{
		Black,
		DARK_Blue,
		DARK_GREEN,
		DARK_SKY_BLUE,
		DARK_RED,
		DARK_PURPLE,
		DARK_YELLOW,
		GRAY,
		DARK_GRAY,
		BLUE,
		GREEN,
		SKY_BLUE,
		RED,
		PURPLE,
		YELLOW,
		WHITE
	};
int main()
{
#pragma region ������
	// ������ ��� ���� ����� ��ȣ �̸���
	// �����Դϴ�.
	
	//	enum State state = DIE;
	//	switch (state)
	//	{
	//	case IDLE:
	//		printf("���");
	//		break;
	//	case ATTACK:
	//		printf("������");
	//		break;
	//	case DIE:
	//		printf("����");
	//		break;
	//	default:
	//		break;
	//	}

#pragma endregion
	enum TextColor color = 0;
	
	int count = 0;
	
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), count++ % 15);
		printf(" ��\n");

		//system("pause");

		Sleep(500);
		system("cls");
	}

	return 0;
}