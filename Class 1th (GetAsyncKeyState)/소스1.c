#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Size 5
void Shuffle(int Random[])//int * Rnadom�� ����, �ּҸ� ����.
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

int main()
{
#pragma region rand() �Լ�
	// seed ���� ���� rand�� ���� �ٲ�� �˴ϴ�.
	//srand(time(NULL));
	
	//int random = (rand() % 10) + 1;
	//printf("random : %d\n", random);
	
#pragma endregion

#pragma region ���� �Լ�
	int array[5] = { 1,2,3,4,5 };
	//srand(time(NULL)); //main ���� ����� 
	//	for (int i = 0; i < 5; i++)
	//	{
	//		int a = rand() % 4;
	//		int temp = array[a];
	//		array[a] = array[i];
	//		array[i] = temp;
	//	}
	Shuffle(array); //�ּ����� 

	for (int i = 0; i < Size; i++)
	{
		printf("array[%d]: %d\n",i,array[i]);
	}
#pragma endregion


	
	return 0;
}