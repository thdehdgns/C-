#include <stdio.h>
#include <time.h>
#include <windows.h>
#define SIZE 20
#define Left 75
#define Right 77
#define Up 72
#define Down 80
#define Enter 13
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
char BeforPlayer = 'p';
char BeforCard = 'X';

char befordie1 = 'X';
char befordie2 = 'X';
char befordie3 = 'X';


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

void SinggleLoding()
{
	printf("덱을 섞는중");
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}
	printf("\n패를 나누는중");
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}
	printf("\nAI 1[준비완료!]");
	Sleep(1500);
	printf("\nAI 2[준비완료!]");
	Sleep(500);
	printf("\nAI 3[준비완료!]");
	Sleep(500);
	printf("\n게임 준비완료!");
	Sleep(1000);
	system("cls");
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

void LiarKill()
{
	if (BeforPlayer == 'P')
	{
		printf("당신은 사망했습니다.\n");
		playerDie = 1;
		//사망 함수
	}
	else if (BeforPlayer == 'A')
	{
		printf("AI[1]가 사망했습니다.\n");
		befordie1 = 'O';
		befordie2 = 'X';
		befordie3 = 'X';
		C1Die = 'O';
	}
	else if (BeforPlayer == 'B')
	{
		printf("AI[2]가 사망했습니다.\n");
		C2Die = 'O';
		befordie3 = 'X';
		befordie2 = 'O';
		befordie1 = 'X';

	}
	else if (BeforPlayer == 'C')
	{
		printf("AI[3]가 사망했습니다.\n");
		C3Die = 'O';
		befordie3 = 'O';
		befordie2 = 'X';
		befordie1 = 'X';

	}
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
			BeforPlayer = 'A';
			break;
		}
	}

	if (C1count != 1) //for문에서 답이 안나왔을 때
	{
		if (AiChoice <= 50)
		{
			printf("AI가 %c을 라이어로 지목했습니다!\n",BeforPlayer);
			if (BeforCard != MainPlayCard)
			{
				if (BeforCard == 'J')
				{
					printf("AI1가 잘못지명하여 사망했습니다.\n");
					C1Die = 'O';
					befordie1 = 'O';
					befordie2 = 'X';
					befordie3 = 'X';
				}
				else
				{
					LiarKill();
				}
			}
			else if (BeforPlayer == 'C' && befordie3 == 'O')
			{
				printf("AI1가 잘못지명하여 사망했습니다.\n");
				C1Die = 'O';
				befordie1 = 'O';
				befordie2 = 'X';
				befordie3 = 'X';
			}
			else if (BeforPlayer == 'B' && befordie2 == 'O')
			{
				printf("AI1가 잘못지명하여 사망했습니다.\n");
				C1Die = 'O';
				befordie1 = 'O';
				befordie2 = 'X';
				befordie3 = 'X';
			}
			else if(BeforCard == MainPlayCard || BeforCard == 'J')
			{
				printf("AI1가 잘못지명하여 사망했습니다.\n");
				C1Die = 'O';
				befordie1 = 'O';
				befordie2 = 'X';
				befordie3 = 'X';
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
					BeforPlayer = 'A';
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
			BeforPlayer = 'B';
			break;
		}
	}

	if (C2count != 1) //for문에서 답이 안나왔을 때
	{
		if (AiChoice <= 50)
		{
			printf("AI2가 라이어를 지목했습니다!\n");
			if (BeforCard != MainPlayCard)
			{
				if (BeforCard == 'J')
				{
					printf("Com2가 잘못 지명하여 사망했습니다.\n");
					C2Die = 'O';
					befordie1 = 'X';
					befordie2 = 'O';
					befordie3 = 'X';
				}
				else
				{
					LiarKill();
				}
			}
			else if (BeforPlayer == 'A' && befordie1 == 'O')
			{
				printf("Com2가 잘못 지명하여 사망했습니다.\n");
				C2Die = 'O';
				befordie1 = 'X';
				befordie2 = 'O';
				befordie3 = 'X';
			}
			else if (BeforPlayer == 'C' && befordie3 == 'O')
			{
				printf("Com2가 잘못 지명하여 사망했습니다.\n");
				C2Die = 'O';
				befordie1 = 'X';
				befordie2 = 'O';
				befordie3 = 'X';
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
					BeforPlayer = 'B';
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
			BeforPlayer = 'C';
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
				if (BeforCard == 'J')
				{
					printf("Com3가 사망했습니다.\n");
					C3Die = 'O';
					befordie1 = 'X';
					befordie2 = 'X';
					befordie3 = 'O';
				}
				else
				{
					LiarKill();
				}
			}
			else if (BeforPlayer == 'A' && befordie1 == 'O')
			{
				printf("Com3가 사망했습니다.\n");
				C3Die = 'O';
				befordie1 = 'X';
				befordie2 = 'X';
				befordie3 = 'O';
			}
			else if (BeforPlayer == 'B' && befordie2 == 'O')
			{
				printf("Com3가 사망했습니다.\n");
				C3Die = 'O';
				befordie1 = 'X';
				befordie2 = 'X';
				befordie3 = 'O';
			}
			else if (BeforCard == MainPlayCard || BeforCard == 'J')
			{
				printf("Com3가 사망했습니다.\n");
				C3Die = 'O';
				befordie1 = 'X';
				befordie2 = 'X';
				befordie3 = 'O';
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
					BeforPlayer = 'C';
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
	printf("            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("           ㅣ                      ㅣ\n");
	printf("           ㅣ       당신의 패      ㅣ\n");
	printf("           ㅣ                      ㅣ\n");
	printf("            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
	printf("--------------------------------------------------------\n\n");
	for (int i = 0; i < Pcount; i++)
	{
		printf("%d: [%c]  ",i,Player[i]);
	}
	printf(" 5: 라이어 지목\n");
	printf("\n--------------------------------------------------------\n\n");
	printf("          무엇을 내겠습니까?\n");
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
					LiarKill();
					printf("          한번 더 선택해주세요.\n");
				}
				else if(BeforPlayer == 'A' && befordie1 == 'O')
				{
					printf("\n\n당신은 잘못 지목하였습니다.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforPlayer == 'B' && befordie2 == 'O')
				{
					printf("\n\n당신은 잘못 지목하였습니다.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforPlayer == 'C' && befordie3 == 'O')
				{
					printf("\n\n당신은 잘못 지목하였습니다.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforCard == MainPlayCard || BeforCard == 'J')
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
				BeforPlayer = 'P';
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

void SinggleGame()
{
	SinggleLoding();
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

void MultyGame()
{
	//제작중
	printf("제작중입니다.\n");
	Sleep(1000);
}

void ChoicePlayers()
{
	int input = 0;
	int Num = 0;
	printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
	printf("             -------------------------------------------\n\n");
	printf("                               - 싱글 -\n\n");
	printf("                                  2인\n\n");
	printf("                                  4인\n\n");
	while (1)
	{
		
		input = getch();
		if (input == -32)
		{
			input = _getch();
		}
		switch (input)
		{
		case Down:
			Num++;
			if (Num >= 3) Num = 2;
			system("cls");
			printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
			printf("             -------------------------------------------\n\n");
			break;
		case Up:
			Num--;
			if (Num <= -1) Num = 0;
			system("cls");
			printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
			printf("             -------------------------------------------\n\n");
			break;
		case Enter:
			if (Num == 0)
			{
				system("cls");
				SinggleGame();
				printf("이전 카드는 [%c]입니다.", BeforCard);
				return 0;
			}
			else if (Num == 1)
			{	
				MultyGame();
			}
			else if (Num == 2)
			{
				MultyGame();
			}
		default:
			system("cls");
			printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
			printf("             -------------------------------------------\n\n");
			break;
		}

		if (Num == 0)
		{
			printf("                               - 싱글 -\n\n");
			printf("                                  2인\n\n");
			printf("                                  4인\n\n");
		}
		else if (Num == 1)
		{
			printf("                                 싱글\n\n");
			printf("                                - 2인 -\n\n");
			printf("                                  4인\n\n");
		}
		else
		{
			printf("                                 싱글\n\n");
			printf("                                  2인\n\n");
			printf("                                - 4인 -\n\n");
		}
	}
	

}



int main()
{	
	srand(time(NULL));
	Maincard();
	DeakShp(HomeDeak); //홈덱을 랜덤으로 섞음
	Dvide();
	ChoicePlayers();
	return 0;
}