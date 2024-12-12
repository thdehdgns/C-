#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define Size 5
#define Hart 5
void Shuffle(int Random[]) //int * Rnadom과 같음, 주소를 받음.
{
	srand(time(NULL));
	int a = 0;
	for (int i = 0; i < Size; i++)
	{
		a = rand() % 4;
		int temp = Random[a];
		Random[a] = Random[i];
		Random[i] = temp;
	}
}

void clayer()
{
	system("cls");
}

void victoryText(int B, int C)
{
	switch (B)
	{
		case 5:
			printf("정답! %d 한번에 맞추다니 찍신이네요!", C);
			break;
		case 4:
			printf("정답! %d 운이 정말 좋은데요?", C);
			break;
		case 3:
			printf("정답! %d 잘하셨어요!", C);
			break;
		case 2:
			printf("정답! %d입니다! 아슬아슬하네요.", C);
			break;
		case 1:
			printf("정답! %d 제가 이길 수 있었는데 아쉽네요 ㅠㅠ", C);
			break;
	}
}

void hartUi(int A)
{
	printf("남은 체력 : ");
	for (int i = 0; i < A; i++)
	{
		printf("♥");
	}
	printf("\n");
	return;
}

void Level()
{

}
int main()
{
#pragma region rand() 함수
	// seed 값에 따라서 rand의 값이 바뀌게 됩니다.
	//srand(time(NULL));
	
	//int random = (rand() % 10) + 1;
	//printf("random : %d\n", random);
	
#pragma endregion

#pragma region 셔플 함수
	//	int array[5] = { 1,2,3,4,5 };
	//	//srand(time(NULL)); //main 내에 만들기 
	//	//	for (int i = 0; i < 5; i++)
	//	//	{
	//	//		int a = rand() % 4;
	//	//		int temp = array[a];
	//	//		array[a] = array[i];
	//	//		array[i] = temp;
	//	//	}
	//	Shuffle(array); //주소줬음 
	//	
	//	for (int i = 0; i < Size; i++)
	//	{
	//		printf("array[%d]: %d\n",i,array[i]);
	//	}
#pragma endregion

#pragma region localTime
		//	const char* Week[1];
		//	time_t currentTime;
		//	time(&currentTime);
		//	struct tm * timePointer = localtime(&currentTime);
		//	
		//	printf("%d년 ", timePointer->tm_year + 1900);
		//	printf("%d월 ", timePointer->tm_mon + 1);
		//	printf("%d일 ", timePointer->tm_mday);
		//	switch (timePointer->tm_wday)
		//	{
		//		case 0:
		//			Week[0] = "일";
		//			break;
		//		case 1:
		//			Week[0] = "월";
		//			break;
		//		case 2:
		//			Week[0] = "화";
		//			break;
		//		case 3:
		//			Week[0] = "수";
		//			break;
		//		case 4:
		//			Week[0] = "목";
		//			break;
		//		case 5:
		//			Week[0] = "금";
		//			break;
		//		case 6:
		//			Week[0] = "토";
		//			break;
		//	}
		//	printf("%s요일 ",Week[0]);
		//	printf("%d시 ", timePointer->tm_hour);
		//	printf("%d분 ", timePointer->tm_min);
		//	printf("%d초 ", timePointer->tm_sec);
		

	

#pragma endregion

#pragma region Up - Down Game
		int value = 0;
		int PlayerValue = 0;
		int count = Hart;
		srand(time(NULL));
		value = (rand() % 50)+ 1;
		Sleep(1000);
		clayer();
		printf("숫자를 맞추세요.1~50\n");
	while (count > 0)
	{
		hartUi(count);
		scanf_s("%d", &PlayerValue);
		if (PlayerValue < value)
		{
			printf("Up");
			--count;
			Sleep(1000);
		}
		else if (PlayerValue > value)
		{
			printf("Down");
			--count;
			Sleep(1000);
		}
		else 
		{
			victoryText(count,value);
			Sleep(1000);
			break;
		}
		clayer();

	}
	if (count == 0)
	{
		printf("제가 이겼네요! 정답은 %d입니다.", value);
	}

#pragma endregion

	
	return 0;
}