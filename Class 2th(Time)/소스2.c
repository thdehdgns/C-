#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Leftt 75
#define Rightt 77
#define Up 72
#define Down 80


void exp(char input)
{
	if (input == Leftt)
	{
		printf("(ㅁO)");
	}
	else if (input == Rightt)
	{
		printf("(Oㅁ)");
	}
	else if (input == Down)
	{
		printf("(oㅁo)");
	}
	else
	{
		printf("(OㅁO)");
	}
}

int screenIndex;
HANDLE screen[2];


void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;
	// 화면 버퍼를 2개 생성합니다.
	screen[0] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);
	screen[1] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	cursor.dwSize = 1;
	cursor.dwSize = FALSE;

	
	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);

}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);
	screenIndex = !screenIndex;
	
}

void Clear()
{
	COORD position = { 0,0 };

	DWORD dword;

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &consoleInfo);
	int Squard = (consoleInfo.srWindow.Bottom- consoleInfo.srWindow.Top+1) * (consoleInfo.srWindow.Right- consoleInfo.srWindow.Left +1);

	FillConsoleOutputCharacter(screen[screenIndex], ' ', Squard, position, &dword);
}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void Render(int x, int y,const char * shape)
{
	DWORD dword;
	// x축과 y축을 설정
	COORD position = { x,y };

	// 커서 위치를 이동하는 함수
	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], shape, strlen(shape), &dword, NULL);
}

int main()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &consoleInfo);

	int left = consoleInfo.srWindow.Left;
	int right = consoleInfo.srWindow.Right;
	int top = consoleInfo.srWindow.Top;
	int bottom = consoleInfo.srWindow.Bottom;

	
	
	int x = 5;
	int y = 5;
	char input = 0;
	
	Initialize();

	while (1)
	{
		Flip();
		Clear();


		if (_kbhit)
		{
			//exp(input);
			input = _getch();
			if (input == -32)
			{
				input = _getch();
			}
			switch (input)
			{
				case Leftt:
					if (x <= left)
					{
						x += 1;
						break;
					}
					else
					{
						x--;
					
					}
					break;
				case Rightt:
					if (x >= right -4)
					{
						x -= 1;
						break;
					}
					else
					{
						x++;
					}
				
					break;
				case Up:
					if (y <= top)
					{
						y += 1;
						break;
					}
					else
					{
						y--;
					}
					break;
				case Down:
					if (y >= bottom)
					{
						y -= 1;
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
		
		}
		Render(x, y, "★");
	}
	Release();

	return 0;
}