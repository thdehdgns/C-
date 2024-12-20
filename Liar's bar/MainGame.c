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

void Maincard()	//���۽� ���̾�ī�� ���ϴ� �Լ�
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


void DeakShp(char HomeDeak[]) //Ȩ���� ���� �Լ�
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
	for (int i = 5; i < 10; i++)
	{
		if (Com1[i] == CurrentCard)
		{
			BeforCard = CurrentCard;
			CurrentCard = Com1[i];
			Com1[i] = 'X';
			printf("���� ī�� %c", CurrentCard);
			break;
		}
		else
		{
			//���̾� ���� Ȥ�� �ٸ� ī�峻��
			printf("������");
			break;
		}
	}
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
				printf("���̾� ����");
				//���� �� �˾Ƽ� ������� ����
				break;
			}
			else if (BeforCard == 'X')
			{
				printf("���� ������ ������ �� �����ϴ�.\n");
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
				printf("�ٽ� ������ �ּ���.\n");
			}
		}
		
	}
	
}

int main()
{	
	Maincard();
	DeakShp(HomeDeak); //Ȩ���� �������� ����
	Dvide();
	Turn();
	Com1Turn();

}