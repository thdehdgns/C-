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
int playerDie = 0;
char Com1[5] = { ' ', ' ', ' ', ' ', ' ' };
char C1Die = 'X';
int C1count = 5;
char Com2[5] = { ' ', ' ', ' ', ' ', ' ' };
char C2Die = 'X';
int C2count = 5;
char Com3[5] = { ' ', ' ', ' ', ' ', ' ' };
char C3Die = 'X';
int C3count = 5;

char BeforCard = 'X';

void Loding(int Num)
{
	printf("AI%d가 생각중",Num);
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000);
	}
	printf("\n");
}

void Maincard()	//시작시 라이어카드 정하는 함수
{
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
	int AiChoice = rand() % 10;
	Loding(1);
	for (int i = 5; i < 10; i++)
	{
		if (Com1[i] == CurrentCard || Com1[i] == 'J')
		{
			BeforCard = CurrentCard;
			CurrentCard = Com1[i];
			Com1[i] = 'X';
			C1count = 1;
			printf("AI가 카드를 냈습니다.\n");
			break;
		}
	}

	if (C1count != 1) //for문에서 답이 안나왔을 때
	{
		if (AiChoice <= 50)
		{
			printf("AI가 당신을 라이어로 지목했습니다!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				printf("당신은 사망했습니다.\n");
				playerDie = 1;
				//사망 함수
			}
			else
			{
				printf("AI1가 사망했습니다.\n");
				C1Die = 'O';
			}
		}
		else if (AiChoice >= 51)
		{
			for (int i = 5; i < 10; i++)
			{
				if (Com1[i] != 'X')
				{
					BeforCard = CurrentCard;
					CurrentCard = Com1[i];
					Com1[i] = 'X';
					printf("AI가 카드를 냈습니다.\n");
					break;
				}
			}
		}
		
	}
	C1count = 0;
	
}
void Com2Turn() //2번 ai턴
{
	int AiChoice = rand() % 10;
	Loding(2);
	for (int i = 10; i < 15; i++)
	{
		if (Com2[i] == CurrentCard || Com2[i] == 'J')
		{
			BeforCard = CurrentCard;
			CurrentCard = Com2[i];
			Com2[i] = 'X';
			C2count = 1;
			printf("AI가 카드를 냈습니다.\n");
			break;
		}
	}

	if (C2count != 1) //for문에서 답이 안나왔을 때
	{
		if (AiChoice <= 50)
		{
			printf("AI2가 Com을(를) 라이어로 지목했습니다!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				if (C1Die != 'O')//c1이 죽지 않았을 때
				{
					printf("Com1은 사망했습니다.\n");
					Loding(2);
					for (int i = 10; i < 15; i++)
					{
						if (Com2[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com2[i];
							Com2[i] = 'X';
							printf("AI가 카드를 냈습니다.\n");
							break;
						}
					}
					//사망 함수
					C1Die = 'O';
				}
				else if (C1Die == 'O' && C3Die != 'O')//C1은 죽고 C3가 죽지않았을 때
				{
					printf("Com3은 사망했습니다.\n");
					Loding(2);
					for (int i = 10; i < 15; i++)
					{
						if (Com2[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com2[i];
							Com2[i] = 'X';
							printf("AI가 카드를 냈습니다.\n");
							break;
						}
					}
					//사망 함수
					C3Die = 'O';
				}
				else if (C1Die == 'O' && C3Die == 'O')//C1도 죽고 C3도 죽었을 때
				{
					printf("당신은 사망했습니다.");
					playerDie = 1;
				}
			}
			else
			{
				printf("Com2가 사망했습니다.\n");
				C2Die = 'O';
			}
		}
		else if (AiChoice >= 51)
		{
			for (int i = 10; i < 15; i++)
			{
				if (Com2[i] != 'X')
				{
					BeforCard = CurrentCard;
					CurrentCard = Com2[i];
					Com2[i] = 'X';
					printf("AI가 카드를 냈습니다.\n");
					break;
				}
			}
		}

	}
	C1count = 0;

}
void Com3Turn() //3번 ai턴
{
	int AiChoice = rand() % 10;
	Loding(3);
	for (int i = 15; i < 20; i++)
	{
		if (Com3[i] == CurrentCard || Com3[i] == 'J')
		{
			BeforCard = CurrentCard;
			CurrentCard = Com3[i];
			Com3[i] = 'X';
			C3count = 1;
			printf("AI가 카드를 냈습니다.\n");
			break;
		}
	}

	if (C3count != 1) //for문에서 답이 안나왔을 때
	{
		if (AiChoice <= 50)
		{
			printf("AI3가 Com을(를) 라이어로 지목했습니다!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				if (C2Die != 'O') //C2가 살아있을 때
				{
					printf("Com2은 사망했습니다.\n");
					Loding(3);
					for (int i = 15; i < 20; i++)
					{
						if (Com3[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com3[i];
							Com3[i] = 'X';
							printf("AI가 카드를 냈습니다.\n");
							break;
						}
					}
					//사망 함수
					C2Die = 'O';
				}
				else if (C2Die == 'O' && C1Die  == 'O') //C2가 죽고 C1이 살아있을 때
				{
					printf("Com1은 사망했습니다.\n");
					Loding(3);
					for (int i = 15; i < 20; i++)
					{
						if (Com3[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com3[i];
							Com3[i] = 'X';
							printf("AI가 카드를 냈습니다.\n");
							break;
						}
					}
					//사망 함수
					C1Die = 'O';
				}
				else if (C2Die == 'O' && C1Die == 'O') //C1 C2둘다 죽고 당신이 살아있을 떄
				{
					printf("당신은 사망했습니다.\n");
					playerDie = 1;
				}
			}
			else//이전 플레이어가 라이어가 아닐때
			{
				printf("Com3가 사망했습니다.\n");
				C3Die = 'O';
			}
		}
		else if (AiChoice >= 51)
		{
			for (int i = 15; i < 20; i++)
			{
				if (Com3[i] != 'X')
				{
					BeforCard = CurrentCard;
					CurrentCard = Com3[i];
					Com3[i] = 'X';
					printf("AI가 카드를 냈습니다.\n");
					break;
				}
			}
		}

	}
	C1count = 0;

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
				printf("라이어 지목\n");
				//지목 후 
				if (BeforCard != MainPlayCard && BeforCard !='J')
				{
					if (C2Die != 'O')
					{
						printf("Com2은 사망했습니다!");
						C2Die = 'O';
					}
					else if (C2Die == 'O' && C1Die != 'O')
					{
						printf("Com1은 사망했습니다!");
						C1Die = 'O';
					}
					else if (C2Die == 'O' && C1Die == 'O')
					{
						printf("Com3은 사망했습니다!");
						C3Die = 'O';
					}
				}
				else
				{
					printf("\n\n당신은 잘못 지목하였습니다.\n\n");
					playerDie = 1;
					return 0;
				}
				Choice = 0;
			}
			else if (BeforCard == 'X')
			{
				printf("아직 상대방을 지목할 수 없습니다.\n");
				Choice = 0;
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
			else
			{
				printf("다시 선택해 주세요.\n");
			}
		}
		
	}
	Choice = 0;
}

void LiveTurn()
{
	while (playerDie == 0)
	{
		Turn();
		if (C1Die != 'O' && playerDie == 0)
		{
			Com1Turn();

		}
		if (C2Die != 'O' && playerDie == 0)
		{
			Com2Turn();
		}
		if (C3Die != 'O' && playerDie == 0)
		{
			Com3Turn();
		}
		if (C1Die == 'O' && C2Die == 'O'&&C3Die == 'O')
		{
			printf("\n\nWin!");
			return 0;
		}
	}
}

int main()
{	
	srand(time(NULL));
	Maincard();
	DeakShp(HomeDeak); //홈덱을 랜덤으로 섞음
	Dvide();
	LiveTurn();
	return 0;
}