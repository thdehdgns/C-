#include <stdio.h>
#include <time.h>
#include <windows.h>
#define SIZE 20
#define Left 75
#define Right 77
#define Up 72
#define Down 80
#define Enter 13
#define Tip 7
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
int Number = 15;
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
char befordie4 = 'X';

int Rusian = 0;



char Mp1[5] = { ' ',' ',' ',' ',' ' };
char Mp2[5] = { ' ',' ',' ',' ',' ' };
char Mp3[5] = { ' ',' ',' ',' ',' ' };
char Mp4[5] = { ' ',' ',' ',' ',' ' };

char MpB1[6] = { 'X','X','X','X','X' ,'X'};
char MpB2[6] = { 'X','X','X','X','X' ,'X' };
char MpB3[6] = { 'X','X','X','X','X' ,'X' };
char MpB4[6] = { 'X','X','X','X','X' ,'X' };

int playerCount = 4;
int Acount = 0;
int Bcount = 0;
int Ccount = 0;
int Dcount = 0;


char P1Die = 'X';
char P2Die = 'X';
char P3Die = 'X';
char P4Die = 'X';





char BeforDiePlayer = ' ';

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

void TipTool()
{
	int value;
	const char* TipText[Tip];
	value = rand() % Tip;
	TipText[0] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n이거 아시나요? 2025년 1월 3일까지 Liar's bar가\n스팀에서 할인중입니다!";
	TipText[1] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n툴팁에 적을게 생각이 안나네요!";
	TipText[2] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n싱글과 멀티플레이의 게임 룰은 살짝 다르답니다.";
	TipText[3] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n이 게임에는 개성있는 캐릭터는 여러분 말고는 존재하지 않습니다.";
	TipText[4] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n당길 수 있는 방아쇠의 최대치는 5입니다. 6번째로 당기는 방아쇠는..";
	TipText[5] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n제 깃허브 주소는 https://github.com/thdehdgns 입니다!";
	TipText[6] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n한판에 소요되는 시간은..저도 잘 모르겠네요. 2인은 10분내외로 끝나지 않을까요?";


	printf("%s", TipText[value]);
}

void ShapBul(char playerBu[])
{
	int value = 0;
	
	value = rand() % 6;
	playerBu[value] = 'O';
	
}

void RussianRoulette()
{
	ShapBul(MpB1);
	ShapBul(MpB2);
	ShapBul(MpB3);
	ShapBul(MpB4);
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

void MultyLoding()
{
	TipTool();
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(800);
	}
	Sleep(1000);
	system("cls");
}

void MpDvide()
{
	DvideCard(Mp1, 0, 5);
	DvideCard(Mp2, 5, 10);
	DvideCard(Mp3, 10, 15);
	DvideCard(Mp4, 15,20);
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
				if (BeforCard != MainPlayCard)
				{
					if (BeforCard == 'J')
					{
						printf("\n\n당신은 잘못 지목하였습니다.\n\n");
						playerDie = 1;
						return 0;
					}
					else if(C1Die != 'O'&& C2Die != 'O'&& C3Die != 'O')
					{
						LiarKill();
						printf("          한번 더 선택해주세요.\n");
					}
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
				BeforCard = Player[Choice];
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

void MultyPlayerDie(char Players)
{
	Rusian = 1;
	if (Players == 'A')
	{
		if (MpB1[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Acount);
			P1Die = 'O';
			BeforDiePlayer = 'A';
			playerCount--;
			BeforPlayer = 'A';
		}
		else
		{
			printf("다행이 [A]플레이어는 총알을 피했습니다!\n");
			Acount++;
		}

	}
	else if (Players == 'B')
	{
		if (MpB2[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Bcount);
			P2Die = 'O';
			BeforDiePlayer = 'B';
			playerCount--;
			BeforPlayer = 'B';
		}
		else
		{
			printf("다행이 [B]플레이어는 총알을 피했습니다!\n");
			Bcount++;
		}


	}
	else if (Players == 'C')
	{
		if (MpB3[Ccount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Ccount);
			P3Die = 'O';
			BeforDiePlayer = 'C';
			playerCount--;
			BeforPlayer = 'C';
		}
		else
		{
			printf("다행이 [C]플레이어는 총알을 피했습니다!\n");
			Ccount++;
		}


	}
	else if (Players == 'D')
	{
		if (MpB4[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Dcount);
			P4Die = 'O';
			BeforDiePlayer = 'D';
			playerCount--;
			BeforPlayer = 'D';
		}
		else
		{
			printf("다행이 [D]플레이어는 총알을 피했습니다!\n");
			Dcount++;
		}


	}
}

void MultyLiarkill(char Players)
{
	Rusian = 1;
	if (BeforPlayer == 'A')
	{
		printf("[A]플레이어는 라이어가 맞았습니다!\n");
		if (MpB1[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Acount+1);
			P1Die = 'O';
			BeforDiePlayer = 'A';
			playerCount--;
			BeforPlayer = 'A';
		}
		else
		{
			printf("다행이 [A]플레이어는 총알을 피했습니다!\n");
			Acount++;
		}

	}
	else if (BeforPlayer == 'B')
	{
		printf("[B]플레이어는 라이어가 맞았습니다!\n");
		if (MpB2[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Bcount + 1);
			P2Die = 'O';
			BeforDiePlayer = 'B';
			playerCount--;
			BeforPlayer = 'B';
		}
		else
		{
			printf("다행이 [B]플레이어는 총알을 피했습니다!\n");
			Bcount++;
		}
		

	}
	else if (BeforPlayer == 'C')
	{
		printf("[C]플레이어는 라이어가 맞았습니다!\n");
		if (MpB3[Ccount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Ccount + 1);
			P3Die = 'O';
			BeforDiePlayer = 'C';
			playerCount--;
			BeforPlayer = 'C';
		}
		else
		{
			printf("다행이 [C]플레이어는 총알을 피했습니다!\n");
			Ccount++;
		}
		

	}
	else if (BeforPlayer == 'D')
	{
		printf("[D]플레이어는 라이어가 맞았습니다!\n");
		if (MpB4[Acount] == 'O')
		{
			printf("[%d] 번째 구멍에 총알이있었습니다!", Dcount + 1);
			P4Die = 'O';
			BeforDiePlayer = 'D';
			playerCount--;
			BeforPlayer = 'D';
		}
		else
		{
			printf("다행이 [D]플레이어는 총알을 피했습니다!\n");
			Dcount++;
		}
		
		
	}
}

void MultyPlayGame(char Players[],char IndexPlayer,int min, int max,int Count) //필요한 정보 : 플레이어의 패, 플레이어의 순서
{
	char T = 0;
	system("cls");
	printf("[%c] Player의 턴\n\n", IndexPlayer);
	printf("방아쇠를 당긴 횟수 [%d]\n\n", Count);
	int Choice = 0;
	printf("Main Card : %c\n\n\n", MainPlayCard);
	printf("            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf("           ㅣ                      ㅣ\n");
	printf("           ㅣ   [%c]플레이어의 패   ㅣ\n",IndexPlayer);
	printf("           ㅣ                      ㅣ\n");
	printf("            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
	printf("--------------------------------------------------------\n\n");
	for (int i = min; i < max; i++)
	{
		printf("%d: [%c]  ", i, Players[i]);
	}
	printf(" 99 : 라이어 지목\n");
	printf("\n--------------------------------------------------------\n\n");
	printf("          무엇을 내겠습니까?\n");
	while (1)
	{
		scanf_s("%d", &Choice);
		if (Choice == 99)
		{
			if (MainTurn == 0)
			{
				printf("아직 라이어를 지목할 수 없습니다.\n");
			}
			else if (BeforCard != MainPlayCard || BeforDiePlayer == BeforPlayer)
			{
				if (BeforDiePlayer == BeforPlayer)
				{
					printf("방금 라이어가 지목당해서 죽었어요!\n");
				}
				else if (BeforCard == 'J')
				{
					printf("잘못 지목하여 사망하셨습니다!\n");
					MultyPlayerDie(IndexPlayer);
					Sleep(1000);
					system("cls");
					printf("다음 플레이어분은 엔터를 눌러주세요\n");
					T = _getch();
					return 0;
				}
				else if(BeforDiePlayer != BeforPlayer)
				{
					printf("[%c] 플레이어가 라이어로 지목당하였습니다!\n",IndexPlayer);
					MultyLiarkill(IndexPlayer);
					T = _getch();
					system("cls");
					printf("엔터를 눌러 넘어가주세요.\n");
					T = _getch();
					return 0;
				}
				
				
			}
			else
			{
				printf("잘못 지목하셨습니다!\n");
				printf("[%c]플레이어가 낸 카드는...[%c]입니다!\n",BeforPlayer,BeforCard);
				MultyPlayerDie(IndexPlayer);
				T = _getch();
				system("cls");
				printf("다음 플레이어분은 엔터를 눌러주세요\n");
				T = _getch();
				return 0;
			}
		}
		else if (Choice < min || Choice > max)
		{
			printf("잘못 선택하셨어요! 다시 고르세요.\n");
		}
		else
		{
			if (Players[Choice] != 'X')
			{
				BeforCard = Players[Choice];
				Players[Choice] = 'X';
				MainTurn++;
				BeforPlayer = IndexPlayer; //이전 플레이어 
				break;
			}
			else
			{
				printf("다시 선택해 주세요.\n");
			}
		}

	}
	
	Choice = 0;
	system("cls");
	printf("다음 플레이어분은 엔터를 눌러주세요\n");
	T = _getch();
	return 0;
}


void MultyGame()
{
	MultyLoding();
	while (1)
	{
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (P1Die != 'O')
		{
			MultyPlayGame(Mp1, 'A', 0, 5,Acount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (P2Die != 'O')
		{
			MultyPlayGame(Mp2, 'B', 5, 10, Bcount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (P3Die != 'O')
		{
			MultyPlayGame(Mp3, 'C', 10, 15, Ccount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (P4Die != 'O')
		{
			MultyPlayGame(Mp4, 'D', 15, 20, Dcount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		
	}
	
}

void Multy2playerGame()
{
	MultyLoding();
	while (1)
	{
		if (P1Die != 'O')
		{
			MultyPlayGame(Mp1, 'A', 0, 5, Acount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (P2Die != 'O')
		{
			MultyPlayGame(Mp2, 'B', 5, 10, Bcount);
		}
		if (Rusian >= 1)
		{
			Rusian = 0;
			return 0;
		}
		if (playerCount <= 3)
		{
			if (P1Die != 'O')
			{
				system("cls");
				printf("%c 플레이어가 승리하였습니다!.\n", 'A');
				Sleep(1000);

			}
			else if (P2Die != 'O')
			{
				system("cls");
				printf("%c 플레이어가 승리하였습니다!.\n", 'B');
				Sleep(1000);
			}
			
			return 0;
		}
	}

}
void BulletReste()
{
	Acount = 0;
	Bcount = 0;
	Ccount = 0;
	Dcount = 0;

	MpB1[6] =  'X','X','X','X','X' ,'X' ;
	MpB2[6] =  'X','X','X','X','X' ,'X' ;
	MpB3[6] =  'X','X','X','X','X' ,'X' ;
	MpB4[6] =  'X','X','X','X','X' ,'X' ;
	RussianRoulette();
}
void PlayerDieRest()
{
	playerCount = 4;

	P1Die = 'X';
	P2Die = 'X';
	P3Die = 'X';
	P4Die = 'X';

	befordie1 = 'X';
	befordie2 = 'X';
	befordie3 = 'X';
	befordie4 = 'X';
}
void GameReset()
{
	HomeDeak[SIZE] ='Q','Q','Q','Q','Q','Q',
					'K','K','K','K','K','K',
					'A','A','A','A','A','A','J','J'  ;

    Player[5] =  ' ', ' ', ' ', ' ', ' ' ;
	Pcount = 5;
	playerDie = 0;
	Com1[5] =  ' ', ' ', ' ', ' ', ' ' ;
	C1Die = 'X';
	C1count = 5;
	Com2[5] =  ' ', ' ', ' ', ' ', ' ' ;
	C2Die = 'X';
	C2count = 5;
	Com3[5] =  ' ', ' ', ' ', ' ', ' ' ;
	C3Die = 'X';
	C3count = 5;
	BeforPlayer = 'p';
	BeforCard = 'X';
	MainTurn = 0;

	Mp1[5] =  ' ',' ',' ',' ',' ' ;
	Mp2[5] =  ' ',' ',' ',' ',' ' ;
	Mp3[5] =  ' ',' ',' ',' ',' ' ;
	Mp4[5] =  ' ',' ',' ',' ',' ' ;

	

	BeforDiePlayer = ' ';

	DeakShp(HomeDeak); //홈덱을 랜덤으로 섞음
	Dvide();
	
	MpDvide();
	Maincard();
}
void Load(const char* filename)
{
	char buffer[10000] = { 0, };
	FILE* file = fopen(filename, "r");
	fread(buffer, 1, 10000, file);
	printf("%s", buffer);
	fclose(file);
}
void Setting()
{
	enum TextColor color = 0;
	int input = 0;
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Number);
		Load("Color.txt");
		printf("엔터를 눌러 적용하기.");
		input = getch();
		if (input == -32)
		{
			input = _getch();
		}
		switch (input)
		{
		case Down:
			Number--;
			if (Number <= -1) Number = 15;
			system("cls");
			break;
		case Up:
			Number++;
			if (Number >= 15) Number = 0;
			system("cls");
			break;
		case Enter:
			system("cls");
			return 0;
		default:
			system("cls");
			break;
		}
	}
}

void ChoicePlayers()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Number);
	int input = 0;
	int Num = 0;
	printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
	printf("             -------------------------------------------\n\n");
	printf("                               - 싱글 -\n\n");
	printf("                                 2 인\n\n");
	printf("                                 3 인\n\n");
	printf("                                 4 인\n\n");
	printf("                                 설정\n\n");
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
			if (Num >= 5) Num = 0;
			system("cls");
			printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
			printf("             -------------------------------------------\n\n");
			break;
		case Up:
			Num--;
			if (Num <= -1) Num = 4;
			system("cls");
			printf("             -------------------------------------------\n\n\n\n\n                             Liar's Bar\n\n\n\n\n");
			printf("             -------------------------------------------\n\n");
			break;
		case Enter:
			if (Num == 0)
			{
				PlayerDieRest();
				GameReset();
				system("cls");
				SinggleGame();
				printf("이전 카드는 [%c]입니다.", BeforCard);
				return 0;
			}
			else if (Num == 1)
			{
				BulletReste();
				PlayerDieRest();
				GameReset();
				system("cls");
				while (1)
				{
					if (playerCount <= 3)
					{
						if (P1Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'A');
							Sleep(1000);
							break;
						}
						else if (P2Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'B');
							Sleep(1000);

							break;

						}
					}
					else
					{
						GameReset();
						Multy2playerGame();
						system("cls");
					}
				}
				
			}
			else if (Num == 2)
			{
				printf("아직 업데이트 중입니다.");
				Sleep(500);
				system("cls");
			}
			else if (Num == 3)
			{
				BulletReste();
				PlayerDieRest();
				GameReset();
				system("cls");
				while (1)
				{
					if (playerCount <= 1)
					{
						if (P1Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'A');
							Sleep(1000);
							break;

						}
						else if (P2Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'B');
							Sleep(1000);

							break;

						}
						else if (P3Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'C');
							Sleep(1000);

							break;

						}
						else if (P4Die != 'O')
						{
							system("cls");
							printf("%c 플레이어가 승리하였습니다!.\n", 'D');
							Sleep(1000);
							break;

						}
					}
					else
					{
						GameReset();
						MultyGame();
						system("cls");
					}
				}
			}
			else if (Num == 4)
			{
				system("cls");
				Setting();
				
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
			printf("                                 2 인\n\n");
			printf("                                 3 인\n\n");
			printf("                                 4 인\n\n");
			printf("                                 설정\n\n");
		}
		else if (Num == 1)
		{
			printf("                                 싱글\n\n");
			printf("                               - 2 인 -\n\n");
			printf("                                 3 인\n\n");
			printf("                                 4 인\n\n");
			printf("                                 설정\n\n");
		}
		else if (Num == 2)
		{
			printf("                                 싱글\n\n");
			printf("                                 2 인\n\n");
			printf("                               - 3 인 -\n\n");
			printf("                                 4 인\n\n");
			printf("                                 설정\n\n");

		}
		else if(Num ==3)
		{
			printf("                                 싱글\n\n");
			printf("                                 2 인\n\n");
			printf("                                 3 인\n\n");
			printf("                               - 4 인 -\n\n");
			printf("                                 설정\n\n");

		}
		else if (Num == 4)
		{
			printf("                                 싱글\n\n");
			printf("                                 2 인\n\n");
			printf("                                 3 인\n\n");
			printf("                                 4 인\n\n");
			printf("                               - 설정 -\n\n");

		}
	}
	

}



int main()
{	
	srand(time(NULL));
	ChoicePlayers();
	return 0;
}