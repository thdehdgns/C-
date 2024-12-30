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
	printf("AI%d�� ������",Num);
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000);
	}
	printf("\n");
}

void SinggleLoding()
{
	printf("���� ������");
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}
	printf("\n�и� ��������");
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(500);
	}
	printf("\nAI 1[�غ�Ϸ�!]");
	Sleep(1500);
	printf("\nAI 2[�غ�Ϸ�!]");
	Sleep(500);
	printf("\nAI 3[�غ�Ϸ�!]");
	Sleep(500);
	printf("\n���� �غ�Ϸ�!");
	Sleep(1000);
	system("cls");
}

void Maincard()	//���۽� ���̾�ī�� ���ϴ� �Լ�
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
	TipText[0] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�̰� �ƽó���? 2025�� 1�� 3�ϱ��� Liar's bar��\n�������� �������Դϴ�!";
	TipText[1] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n������ ������ ������ �ȳ��׿�!";
	TipText[2] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�̱۰� ��Ƽ�÷����� ���� ���� ��¦ �ٸ���ϴ�.";
	TipText[3] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�� ���ӿ��� �����ִ� ĳ���ʹ� ������ ����� �������� �ʽ��ϴ�.";
	TipText[4] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n��� �� �ִ� ��Ƽ��� �ִ�ġ�� 5�Դϴ�. 6��°�� ���� ��Ƽ��..";
	TipText[5] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�� ����� �ּҴ� https://github.com/thdehdgns �Դϴ�!";
	TipText[6] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n���ǿ� �ҿ�Ǵ� �ð���..���� �� �𸣰ڳ׿�. 2���� 10�г��ܷ� ������ �������?";


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

void DeakShp(char HomeDeak[]) //Ȩ���� ���� �Լ�
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

void DvideCard(char tile[], int Min, int Max) //�� ������ �Լ�
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

void Dvide() //�� �����ֱ�
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
		printf("����� ����߽��ϴ�.\n");
		playerDie = 1;
		//��� �Լ�
	}
	else if (BeforPlayer == 'A')
	{
		printf("AI[1]�� ����߽��ϴ�.\n");
		befordie1 = 'O';
		befordie2 = 'X';
		befordie3 = 'X';
		C1Die = 'O';
	}
	else if (BeforPlayer == 'B')
	{
		printf("AI[2]�� ����߽��ϴ�.\n");
		C2Die = 'O';
		befordie3 = 'X';
		befordie2 = 'O';
		befordie1 = 'X';

	}
	else if (BeforPlayer == 'C')
	{
		printf("AI[3]�� ����߽��ϴ�.\n");
		C3Die = 'O';
		befordie3 = 'O';
		befordie2 = 'X';
		befordie1 = 'X';

	}
}

void Com1Turn() //1�� ai��
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
			printf("AI�� ī�带 �½��ϴ�.\n");
			BeforPlayer = 'A';
			break;
		}
	}

	if (C1count != 1) //for������ ���� �ȳ����� ��
	{
		if (AiChoice <= 50)
		{
			printf("AI�� %c�� ���̾�� �����߽��ϴ�!\n",BeforPlayer);
			if (BeforCard != MainPlayCard)
			{
				if (BeforCard == 'J')
				{
					printf("AI1�� �߸������Ͽ� ����߽��ϴ�.\n");
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
				printf("AI1�� �߸������Ͽ� ����߽��ϴ�.\n");
				C1Die = 'O';
				befordie1 = 'O';
				befordie2 = 'X';
				befordie3 = 'X';
			}
			else if (BeforPlayer == 'B' && befordie2 == 'O')
			{
				printf("AI1�� �߸������Ͽ� ����߽��ϴ�.\n");
				C1Die = 'O';
				befordie1 = 'O';
				befordie2 = 'X';
				befordie3 = 'X';
			}
			else if(BeforCard == MainPlayCard || BeforCard == 'J')
			{
				printf("AI1�� �߸������Ͽ� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
					BeforPlayer = 'A';
					break;
				}
			}
		}
		
	}
	C1count = 0;
	
}
void Com2Turn() //2�� ai��
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
			printf("AI�� ī�带 �½��ϴ�.\n");
			BeforPlayer = 'B';
			break;
		}
	}

	if (C2count != 1) //for������ ���� �ȳ����� ��
	{
		if (AiChoice <= 50)
		{
			printf("AI2�� ���̾ �����߽��ϴ�!\n");
			if (BeforCard != MainPlayCard)
			{
				if (BeforCard == 'J')
				{
					printf("Com2�� �߸� �����Ͽ� ����߽��ϴ�.\n");
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
				printf("Com2�� �߸� �����Ͽ� ����߽��ϴ�.\n");
				C2Die = 'O';
				befordie1 = 'X';
				befordie2 = 'O';
				befordie3 = 'X';
			}
			else if (BeforPlayer == 'C' && befordie3 == 'O')
			{
				printf("Com2�� �߸� �����Ͽ� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
					BeforPlayer = 'B';
					break;
				}
			}
		}

	}
	C1count = 0;

}
void Com3Turn() //3�� ai��
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
			printf("AI�� ī�带 �½��ϴ�.\n");
			BeforPlayer = 'C';
			break;
		}
	}

	if (C3count != 1) //for������ ���� �ȳ����� ��
	{
		if (AiChoice <= 50)
		{
			printf("AI3�� Com��(��) ���̾�� �����߽��ϴ�!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				if (BeforCard == 'J')
				{
					printf("Com3�� ����߽��ϴ�.\n");
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
				printf("Com3�� ����߽��ϴ�.\n");
				C3Die = 'O';
				befordie1 = 'X';
				befordie2 = 'X';
				befordie3 = 'O';
			}
			else if (BeforPlayer == 'B' && befordie2 == 'O')
			{
				printf("Com3�� ����߽��ϴ�.\n");
				C3Die = 'O';
				befordie1 = 'X';
				befordie2 = 'X';
				befordie3 = 'O';
			}
			else if (BeforCard == MainPlayCard || BeforCard == 'J')
			{
				printf("Com3�� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
					BeforPlayer = 'C';
					break;
				}
			}
		}

	}
	C1count = 0;

}
void Turn()	//�÷��̾� ��
{
	int Choice = 0;
	int Mycard = 0;
	int count = 0;
	printf("Main Card : %c\n\n\n", MainPlayCard);
	printf("            �ѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("           ��                      ��\n");
	printf("           ��       ����� ��      ��\n");
	printf("           ��                      ��\n");
	printf("            �ѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
	printf("--------------------------------------------------------\n\n");
	for (int i = 0; i < Pcount; i++)
	{
		printf("%d: [%c]  ",i,Player[i]);
	}
	printf(" 5: ���̾� ����\n");
	printf("\n--------------------------------------------------------\n\n");
	printf("          ������ ���ڽ��ϱ�?\n");
	while (1)
	{
		scanf_s("%d", &Choice);
		if (Choice == 5)
		{
			if (BeforCard != 'X')
			{
				printf("���̾� ����\n");
				//���� �� 
				if (BeforCard != MainPlayCard)
				{
					if (BeforCard == 'J')
					{
						printf("\n\n����� �߸� �����Ͽ����ϴ�.\n\n");
						playerDie = 1;
						return 0;
					}
					else if(C1Die != 'O'&& C2Die != 'O'&& C3Die != 'O')
					{
						LiarKill();
						printf("          �ѹ� �� �������ּ���.\n");
					}
				}
				else if(BeforPlayer == 'A' && befordie1 == 'O')
				{
					printf("\n\n����� �߸� �����Ͽ����ϴ�.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforPlayer == 'B' && befordie2 == 'O')
				{
					printf("\n\n����� �߸� �����Ͽ����ϴ�.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforPlayer == 'C' && befordie3 == 'O')
				{
					printf("\n\n����� �߸� �����Ͽ����ϴ�.\n\n");
					playerDie = 1;
					return 0;
				}
				else if (BeforCard == MainPlayCard || BeforCard == 'J')
				{
					printf("\n\n����� �߸� �����Ͽ����ϴ�.\n\n");
					playerDie = 1;
					return 0;
				}
				Choice = 0;
			}
			else if (BeforCard == 'X')
			{
				printf("���� ������ ������ �� �����ϴ�.\n");
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
				printf("�ٽ� ������ �ּ���.\n");
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
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Acount);
			P1Die = 'O';
			BeforDiePlayer = 'A';
			playerCount--;
			BeforPlayer = 'A';
		}
		else
		{
			printf("������ [A]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Acount++;
		}

	}
	else if (Players == 'B')
	{
		if (MpB2[Acount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Bcount);
			P2Die = 'O';
			BeforDiePlayer = 'B';
			playerCount--;
			BeforPlayer = 'B';
		}
		else
		{
			printf("������ [B]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Bcount++;
		}


	}
	else if (Players == 'C')
	{
		if (MpB3[Ccount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Ccount);
			P3Die = 'O';
			BeforDiePlayer = 'C';
			playerCount--;
			BeforPlayer = 'C';
		}
		else
		{
			printf("������ [C]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Ccount++;
		}


	}
	else if (Players == 'D')
	{
		if (MpB4[Acount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Dcount);
			P4Die = 'O';
			BeforDiePlayer = 'D';
			playerCount--;
			BeforPlayer = 'D';
		}
		else
		{
			printf("������ [D]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Dcount++;
		}


	}
}

void MultyLiarkill(char Players)
{
	Rusian = 1;
	if (BeforPlayer == 'A')
	{
		printf("[A]�÷��̾�� ���̾ �¾ҽ��ϴ�!\n");
		if (MpB1[Acount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Acount+1);
			P1Die = 'O';
			BeforDiePlayer = 'A';
			playerCount--;
			BeforPlayer = 'A';
		}
		else
		{
			printf("������ [A]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Acount++;
		}

	}
	else if (BeforPlayer == 'B')
	{
		printf("[B]�÷��̾�� ���̾ �¾ҽ��ϴ�!\n");
		if (MpB2[Acount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Bcount + 1);
			P2Die = 'O';
			BeforDiePlayer = 'B';
			playerCount--;
			BeforPlayer = 'B';
		}
		else
		{
			printf("������ [B]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Bcount++;
		}
		

	}
	else if (BeforPlayer == 'C')
	{
		printf("[C]�÷��̾�� ���̾ �¾ҽ��ϴ�!\n");
		if (MpB3[Ccount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Ccount + 1);
			P3Die = 'O';
			BeforDiePlayer = 'C';
			playerCount--;
			BeforPlayer = 'C';
		}
		else
		{
			printf("������ [C]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Ccount++;
		}
		

	}
	else if (BeforPlayer == 'D')
	{
		printf("[D]�÷��̾�� ���̾ �¾ҽ��ϴ�!\n");
		if (MpB4[Acount] == 'O')
		{
			printf("[%d] ��° ���ۿ� �Ѿ����־����ϴ�!", Dcount + 1);
			P4Die = 'O';
			BeforDiePlayer = 'D';
			playerCount--;
			BeforPlayer = 'D';
		}
		else
		{
			printf("������ [D]�÷��̾�� �Ѿ��� ���߽��ϴ�!\n");
			Dcount++;
		}
		
		
	}
}

void MultyPlayGame(char Players[],char IndexPlayer,int min, int max,int Count) //�ʿ��� ���� : �÷��̾��� ��, �÷��̾��� ����
{
	char T = 0;
	system("cls");
	printf("[%c] Player�� ��\n\n", IndexPlayer);
	printf("��Ƽ踦 ��� Ƚ�� [%d]\n\n", Count);
	int Choice = 0;
	printf("Main Card : %c\n\n\n", MainPlayCard);
	printf("            �ѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("           ��                      ��\n");
	printf("           ��   [%c]�÷��̾��� ��   ��\n",IndexPlayer);
	printf("           ��                      ��\n");
	printf("            �ѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
	printf("--------------------------------------------------------\n\n");
	for (int i = min; i < max; i++)
	{
		printf("%d: [%c]  ", i, Players[i]);
	}
	printf(" 99 : ���̾� ����\n");
	printf("\n--------------------------------------------------------\n\n");
	printf("          ������ ���ڽ��ϱ�?\n");
	while (1)
	{
		scanf_s("%d", &Choice);
		if (Choice == 99)
		{
			if (MainTurn == 0)
			{
				printf("���� ���̾ ������ �� �����ϴ�.\n");
			}
			else if (BeforCard != MainPlayCard || BeforDiePlayer == BeforPlayer)
			{
				if (BeforDiePlayer == BeforPlayer)
				{
					printf("��� ���̾ ������ؼ� �׾����!\n");
				}
				else if (BeforCard == 'J')
				{
					printf("�߸� �����Ͽ� ����ϼ̽��ϴ�!\n");
					MultyPlayerDie(IndexPlayer);
					Sleep(1000);
					system("cls");
					printf("���� �÷��̾���� ���͸� �����ּ���\n");
					T = _getch();
					return 0;
				}
				else if(BeforDiePlayer != BeforPlayer)
				{
					printf("[%c] �÷��̾ ���̾�� ������Ͽ����ϴ�!\n",IndexPlayer);
					MultyLiarkill(IndexPlayer);
					T = _getch();
					system("cls");
					printf("���͸� ���� �Ѿ�ּ���.\n");
					T = _getch();
					return 0;
				}
				
				
			}
			else
			{
				printf("�߸� �����ϼ̽��ϴ�!\n");
				printf("[%c]�÷��̾ �� ī���...[%c]�Դϴ�!\n",BeforPlayer,BeforCard);
				MultyPlayerDie(IndexPlayer);
				T = _getch();
				system("cls");
				printf("���� �÷��̾���� ���͸� �����ּ���\n");
				T = _getch();
				return 0;
			}
		}
		else if (Choice < min || Choice > max)
		{
			printf("�߸� �����ϼ̾��! �ٽ� ������.\n");
		}
		else
		{
			if (Players[Choice] != 'X')
			{
				BeforCard = Players[Choice];
				Players[Choice] = 'X';
				MainTurn++;
				BeforPlayer = IndexPlayer; //���� �÷��̾� 
				break;
			}
			else
			{
				printf("�ٽ� ������ �ּ���.\n");
			}
		}

	}
	
	Choice = 0;
	system("cls");
	printf("���� �÷��̾���� ���͸� �����ּ���\n");
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
				printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'A');
				Sleep(1000);

			}
			else if (P2Die != 'O')
			{
				system("cls");
				printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'B');
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

	DeakShp(HomeDeak); //Ȩ���� �������� ����
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
		printf("���͸� ���� �����ϱ�.");
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
	printf("                               - �̱� -\n\n");
	printf("                                 2 ��\n\n");
	printf("                                 3 ��\n\n");
	printf("                                 4 ��\n\n");
	printf("                                 ����\n\n");
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
				printf("���� ī��� [%c]�Դϴ�.", BeforCard);
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
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'A');
							Sleep(1000);
							break;
						}
						else if (P2Die != 'O')
						{
							system("cls");
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'B');
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
				printf("���� ������Ʈ ���Դϴ�.");
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
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'A');
							Sleep(1000);
							break;

						}
						else if (P2Die != 'O')
						{
							system("cls");
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'B');
							Sleep(1000);

							break;

						}
						else if (P3Die != 'O')
						{
							system("cls");
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'C');
							Sleep(1000);

							break;

						}
						else if (P4Die != 'O')
						{
							system("cls");
							printf("%c �÷��̾ �¸��Ͽ����ϴ�!.\n", 'D');
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
			printf("                               - �̱� -\n\n");
			printf("                                 2 ��\n\n");
			printf("                                 3 ��\n\n");
			printf("                                 4 ��\n\n");
			printf("                                 ����\n\n");
		}
		else if (Num == 1)
		{
			printf("                                 �̱�\n\n");
			printf("                               - 2 �� -\n\n");
			printf("                                 3 ��\n\n");
			printf("                                 4 ��\n\n");
			printf("                                 ����\n\n");
		}
		else if (Num == 2)
		{
			printf("                                 �̱�\n\n");
			printf("                                 2 ��\n\n");
			printf("                               - 3 �� -\n\n");
			printf("                                 4 ��\n\n");
			printf("                                 ����\n\n");

		}
		else if(Num ==3)
		{
			printf("                                 �̱�\n\n");
			printf("                                 2 ��\n\n");
			printf("                                 3 ��\n\n");
			printf("                               - 4 �� -\n\n");
			printf("                                 ����\n\n");

		}
		else if (Num == 4)
		{
			printf("                                 �̱�\n\n");
			printf("                                 2 ��\n\n");
			printf("                                 3 ��\n\n");
			printf("                                 4 ��\n\n");
			printf("                               - ���� -\n\n");

		}
	}
	

}



int main()
{	
	srand(time(NULL));
	ChoicePlayers();
	return 0;
}