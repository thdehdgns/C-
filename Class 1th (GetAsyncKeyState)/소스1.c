#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define Size 5
#define Hart 5
void Shuffle(int Random[]) //int * Rnadom�� ����, �ּҸ� ����.
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
			printf("����! %d �ѹ��� ���ߴٴ� ����̳׿�!", C);
			break;
		case 4:
			printf("����! %d ���� ���� ��������?", C);
			break;
		case 3:
			printf("����! %d ���ϼ̾��!", C);
			break;
		case 2:
			printf("����! %d�Դϴ�! �ƽ��ƽ��ϳ׿�.", C);
			break;
		case 1:
			printf("����! %d ���� �̱� �� �־��µ� �ƽ��׿� �Ф�", C);
			break;
	}
}

void hartUi(int A)
{
	printf("���� ü�� : ");
	for (int i = 0; i < A; i++)
	{
		printf("��");
	}
	printf("\n");
	return;
}

void Level()
{

}
int main()
{
#pragma region rand() �Լ�
	// seed ���� ���� rand�� ���� �ٲ�� �˴ϴ�.
	//srand(time(NULL));
	
	//int random = (rand() % 10) + 1;
	//printf("random : %d\n", random);
	
#pragma endregion

#pragma region ���� �Լ�
	//	int array[5] = { 1,2,3,4,5 };
	//	//srand(time(NULL)); //main ���� ����� 
	//	//	for (int i = 0; i < 5; i++)
	//	//	{
	//	//		int a = rand() % 4;
	//	//		int temp = array[a];
	//	//		array[a] = array[i];
	//	//		array[i] = temp;
	//	//	}
	//	Shuffle(array); //�ּ����� 
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
		//	printf("%d�� ", timePointer->tm_year + 1900);
		//	printf("%d�� ", timePointer->tm_mon + 1);
		//	printf("%d�� ", timePointer->tm_mday);
		//	switch (timePointer->tm_wday)
		//	{
		//		case 0:
		//			Week[0] = "��";
		//			break;
		//		case 1:
		//			Week[0] = "��";
		//			break;
		//		case 2:
		//			Week[0] = "ȭ";
		//			break;
		//		case 3:
		//			Week[0] = "��";
		//			break;
		//		case 4:
		//			Week[0] = "��";
		//			break;
		//		case 5:
		//			Week[0] = "��";
		//			break;
		//		case 6:
		//			Week[0] = "��";
		//			break;
		//	}
		//	printf("%s���� ",Week[0]);
		//	printf("%d�� ", timePointer->tm_hour);
		//	printf("%d�� ", timePointer->tm_min);
		//	printf("%d�� ", timePointer->tm_sec);
		

	

#pragma endregion

#pragma region Up - Down Game
		int value = 0;
		int PlayerValue = 0;
		int count = Hart;
		srand(time(NULL));
		value = (rand() % 50)+ 1;
		Sleep(1000);
		clayer();
		printf("���ڸ� ���߼���.1~50\n");
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
		printf("���� �̰�׿�! ������ %d�Դϴ�.", value);
	}

#pragma endregion

	
	return 0;
}