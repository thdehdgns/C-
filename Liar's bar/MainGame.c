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
	printf("AI%d�� ������",Num);
	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000);
	}
	printf("\n");
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

void Dvide() //�� �����ֱ�
{
	DvideCard(Player, 0, 5);
	DvideCard(Com1, 5, 10);
	DvideCard(Com2, 10, 15);
	DvideCard(Com3, 15, 20);
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
			break;
		}
	}

	if (C1count != 1) //for������ ���� �ȳ����� ��
	{
		if (AiChoice <= 50)
		{
			printf("AI�� ����� ���̾�� �����߽��ϴ�!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				printf("����� ����߽��ϴ�.\n");
				playerDie = 1;
				//��� �Լ�
			}
			else
			{
				printf("AI1�� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
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
			break;
		}
	}

	if (C2count != 1) //for������ ���� �ȳ����� ��
	{
		if (AiChoice <= 50)
		{
			printf("AI2�� Com��(��) ���̾�� �����߽��ϴ�!\n");
			if (BeforCard != MainPlayCard && BeforCard != 'J')
			{
				if (C1Die != 'O')//c1�� ���� �ʾ��� ��
				{
					printf("Com1�� ����߽��ϴ�.\n");
					Loding(2);
					for (int i = 10; i < 15; i++)
					{
						if (Com2[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com2[i];
							Com2[i] = 'X';
							printf("AI�� ī�带 �½��ϴ�.\n");
							break;
						}
					}
					//��� �Լ�
					C1Die = 'O';
				}
				else if (C1Die == 'O' && C3Die != 'O')//C1�� �װ� C3�� �����ʾ��� ��
				{
					printf("Com3�� ����߽��ϴ�.\n");
					Loding(2);
					for (int i = 10; i < 15; i++)
					{
						if (Com2[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com2[i];
							Com2[i] = 'X';
							printf("AI�� ī�带 �½��ϴ�.\n");
							break;
						}
					}
					//��� �Լ�
					C3Die = 'O';
				}
				else if (C1Die == 'O' && C3Die == 'O')//C1�� �װ� C3�� �׾��� ��
				{
					printf("����� ����߽��ϴ�.");
					playerDie = 1;
				}
			}
			else
			{
				printf("Com2�� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
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
				if (C2Die != 'O') //C2�� ������� ��
				{
					printf("Com2�� ����߽��ϴ�.\n");
					Loding(3);
					for (int i = 15; i < 20; i++)
					{
						if (Com3[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com3[i];
							Com3[i] = 'X';
							printf("AI�� ī�带 �½��ϴ�.\n");
							break;
						}
					}
					//��� �Լ�
					C2Die = 'O';
				}
				else if (C2Die == 'O' && C1Die  == 'O') //C2�� �װ� C1�� ������� ��
				{
					printf("Com1�� ����߽��ϴ�.\n");
					Loding(3);
					for (int i = 15; i < 20; i++)
					{
						if (Com3[i] != 'X')
						{
							BeforCard = CurrentCard;
							CurrentCard = Com3[i];
							Com3[i] = 'X';
							printf("AI�� ī�带 �½��ϴ�.\n");
							break;
						}
					}
					//��� �Լ�
					C1Die = 'O';
				}
				else if (C2Die == 'O' && C1Die == 'O') //C1 C2�Ѵ� �װ� ����� ������� ��
				{
					printf("����� ����߽��ϴ�.\n");
					playerDie = 1;
				}
			}
			else//���� �÷��̾ ���̾ �ƴҶ�
			{
				printf("Com3�� ����߽��ϴ�.\n");
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
					printf("AI�� ī�带 �½��ϴ�.\n");
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
	printf(" �ѤѤѤѤѤѤѤѤѤѤѤ�\n");
	printf("��                      ��\n");
	printf("��       ����� ��      ��\n");
	printf("��                      ��\n");
	printf(" �ѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
	printf("---------------------------\n\n");
	for (int i = 0; i < Pcount; i++)
	{
		printf("%d: [%c]  ",i,Player[i]);
	}
	printf(" 5: ���̾� ����\n");
	printf("\n---------------------------\n\n");
	printf("������ ���ڽ��ϱ�?\n");
	while (1)
	{
		scanf_s("%d", &Choice);
		if (Choice == 5)
		{
			if (BeforCard != 'X')
			{
				printf("���̾� ����\n");
				//���� �� 
				if (BeforCard != MainPlayCard && BeforCard !='J')
				{
					if (C2Die != 'O')
					{
						printf("Com2�� ����߽��ϴ�!");
						C2Die = 'O';
					}
					else if (C2Die == 'O' && C1Die != 'O')
					{
						printf("Com1�� ����߽��ϴ�!");
						C1Die = 'O';
					}
					else if (C2Die == 'O' && C1Die == 'O')
					{
						printf("Com3�� ����߽��ϴ�!");
						C3Die = 'O';
					}
				}
				else
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
				printf("�ٽ� ������ �ּ���.\n");
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
	DeakShp(HomeDeak); //Ȩ���� �������� ����
	Dvide();
	LiveTurn();
	return 0;
}