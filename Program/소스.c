#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Size 11

int main()
{
	int a = 0;
	char T;
	const char* Cha[2];
	Cha[0] = "의뢰인";
	Cha[1] = "남도일";
	const char* dialog[Size];
	dialog[0] = "안녕하세요";
	dialog[1] = "반갑습니다. 제 이름은 남도일 탐정이죠.";
	dialog[2] = "네. 탐정님 사건은..";
	dialog[3] = "이건!";
	dialog[4] = "무슨 일이라도?";
	dialog[5] = "이건 단순 살인사건이 아닙니다.";
	dialog[6] = "그럼 뭐죠..?";
	dialog[7] = "이것은 피해자를 향한 악의가 담긴 계획적인 살인입니다.";
	dialog[8] = "네? 그럼 도대체 누가?";
	dialog[9] = "범인은 바로..";
	dialog[10] = "???(전혀 모르겠다는 표정)";

	int count = 0;

	while (count < Size)
	{
		//동기식
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
	// //비동기식
	//		//0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	//	
	//		//0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	//	
	//		//0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	//		
	//		//0x8001 : 이전에 누른 적이 있고 호출 시점에 눌려 있는 상태
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

	printf("\n다음화에 계속");

	return 0;
}