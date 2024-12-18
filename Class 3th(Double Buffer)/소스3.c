#include <stdio.h>
#include <windows.h>
	enum State
	{
		IDLE,
		ATTACK,
		DIE
	};
	// 열거형에서 중간에 있는 상수의 값을 변경하게 되면
	// 그 다음에 있는 상수의 값이 변경된 값에서 부터 1씩 증가.
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
#pragma region 열거형
	// 고유한 상수 값에 연결된 기호 이름의
	// 집합입니다.
	
	//	enum State state = DIE;
	//	switch (state)
	//	{
	//	case IDLE:
	//		printf("대기");
	//		break;
	//	case ATTACK:
	//		printf("공격중");
	//		break;
	//	case DIE:
	//		printf("죽음");
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
		printf(" ★\n");

		//system("pause");

		Sleep(500);
		system("cls");
	}

	return 0;
}