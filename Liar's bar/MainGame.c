#include <stdio.h>
#include <time.h>
#include <windows.h>
#define SIZE 20
char MainPlayCard = ' ';
char CurrentCard = ' ';
int MainTurn = 0;
char HomeDeak[SIZE] = {'Q','Q','Q','Q','Q','Q',
					'K','K','K','K','K','K', 
					'A','A','A','A','A','A','J','J'};
char Player[5] = { ' ', ' ', ' ', ' ', ' '};
int Pcount = 5;
char Com1[5] = { ' ', ' ', ' ', ' ', ' ' };
int C1count = 5;
char Com2[5] = { ' ', ' ', ' ', ' ', ' ' };
int C2count = 5;
char Com3[5] = { ' ', ' ', ' ', ' ', ' ' };
int C3count = 5;

char BeforCard = 'X';

void Maincard()	//시작시 라이어카드 정하는 함수
{
	srand(time(NULL));
	int Card = 0;
	Card = rand() % 3 + 1;
	switch (Card)
	{
	case 1:
		MainPlayCard = 'Q';
		break;
	case 2:
		MainPlayCard = 'K';
		break;
	case 3:
		MainPlayCard = 'A';
		break;
	default:
		break;
	}
}


void DeakShp(char HomeDeak[]) //홈덱을 섞는 함수
{
	srand(time(NULL));
	int value = 0;
	for (int i = 0; i < SIZE; i++)
	{
		value = rand() % 18;
		int temp = HomeDeak[value];
		HomeDeak[value] = HomeDeak[i];
		HomeDeak[i] = temp;
	}
}

void DvideCard(char tile[], int Min, int Max) //패 나누는 함수
{
	for (int i = Min; i < Max; i++)
	{
		tile[i] = HomeDeak[i];
	}
}

void Dvide() //패 나눠주기
{
	DvideCard(Player, 0, 5);
	DvideCard(Com1, 5, 10);
	DvideCard(Com2, 10, 15);
	DvideCard(Com3, 15, 20);
}

void Com1Turn() //1번 ai턴
{
	for (int i = 5; i < 10; i++)
	{
		if (Com1[i] == CurrentCard)
		{
			BeforCard = CurrentCard;
			CurrentCard = Com1[i];
			Com1[i] = 'X';
			printf("현재 카드 %c", CurrentCard);
			break;
		}
		else
		{
			//라이어 지목 혹은 다른 카드내기
			printf("제작중");
			break;
		}
	}
}

void Turn()	//플레이어 턴
{
	int Choice = 0;
	int Mycard = 0;
	int count = 0;
	printf("Main Card : %c\n\n\n", MainPlayCard);
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("ㅣ                      ㅣ\n");
	printf("ㅣ       당신의 패      ㅣ\n");
	printf("ㅣ                      ㅣ\n");
	printf(" ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
	printf("---------------------------\n\n");
	for (int i = 0; i < Pcount; i++)
	{
		printf("%d: [%c]  ",i,Player[i]);
	}
	printf(" 5: 라이어 지목\n");
	printf("\n---------------------------\n\n");
	printf("무엇을 내겠습니까?\n");
	while (1)
	{
		scanf_s("%d", &Choice);
		if (Choice == 5)
		{
			if (BeforCard != 'X')
			{
				printf("라이어 지목");
				//지목 후 알아서 만들겠지 내가
				break;
			}
			else if (BeforCard == 'X')
			{
				printf("아직 상대방을 지목할 수 없습니다.\n");
			}
		}
		else
		{
			if (Player[Choice] != 'X')
			{
				CurrentCard = Player[Choice];
				if (MainTurn != 0)
				{
					BeforCard = Player[Choice];
				}
				Player[Choice] = 'X';
				MainTurn++;
				break;
			}
			else if (Player[Choice] == 'X')
			{
				printf("다시 선택해 주세요.\n");
			}
		}
		
	}
	
}

int main()
{	
	Maincard();
	DeakShp(HomeDeak); //홈덱을 랜덤으로 섞음
	Dvide();
	Turn();
	Com1Turn();

}