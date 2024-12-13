#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Left 75
#define Right 77
#define Up 72
#define Down 80
void Position(int x, int y)
{
	// x��� y���� ����
	COORD position = { x,y };

	// Ŀ�� ��ġ�� �̵��ϴ� �Լ�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

void exp(char input)
{
	if (input == Left)
	{
		printf("(��O)");
	}
	else if (input == Right)
	{
		printf("(O��)");
	}
	else if (input == Down)
	{
		printf("(o��o)");
	}
	else
	{
		printf("(O��O)");
	}
}

int main()
{
	int x = 5;
	int y = 5;
	char input = 0;
	Position(x, y);
	while (1)
	{
		Position(x, y);
		exp(input);
		input = _getch();
		if (input == -32)
		{
			input = _getch();
		}
		switch (input)
		{
			case Left:
				if (x <= 0)
				{
					x = 1;
					break;
				}
				else
				{
					x--;
					
				}
				break;
			case Right:
				if (x >= 75)
				{
					x = 74;
					break;
				}
				else
				{
					x++;
				}
				
				break;
			case Up:
				if (y <= 0)
				{
					y = 1;
					break;
				}
				else
				{
					y--;
				}
				break;
			case Down:
				if (y >= 25)
				{
					y = 23;
					break;
				}
				else {
					y++;
				}
				break;
			default:
				printf("%d",input);
				break;
		}
		
		system("cls");
	}
	
	return 0;
}