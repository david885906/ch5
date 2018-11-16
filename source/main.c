#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int wDesk[][13]);
void deal(const int wDesk[][13], const char *wFace[],
	const char *wSuit[]);
int main(void)
{
	const char *suit[4] = { "Hearts","Diamonds","Clubs","Spades" };
	const char *face[13] =
	{ "Ace","Deuce","Three","Four","Five","Six","Seven","Eight",
		"Nine","Ten","Jack","Queen","King"
	};
	int desk[4][13] = { 0 };
	srand(time(0));
	shuffle(desk);
	deal(desk, face, suit);
	system("pause");
	return 0;
}
void shuffle(int wDesk[][13])
{
	int row;
	int column;
	int card;
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDesk[row][column] != 0);
		wDesk[row][column] = card;
	}
}
void deal(const int wDesk[][13], const char *wFace[],
	const char *wSuit[])
{
	int card;
	int row;
	int column;
	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <=12; column++)
			{
				if (wDesk[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row],
						card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}