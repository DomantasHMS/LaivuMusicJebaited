#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int k_eil = 10;
const int k_stul = 10;
int laivai = 5;
int AI_Laukas[k_eil][k_stul];

bool H_V()
{
	int x = rand() % 2;
	if (x == 0)return false;
	else
		return true;
}

void AI_Cleer()
{
	for (int i = 0; i < k_eil; i++)
	{
		for (int j = 0; j < k_stul; j++)
		{
			AI_Laukas[i][j] = 0;
		}
	}
}

void AI_Show()
{
	for (int i = 0; i < k_eil; i++)
	{
		for (int j = 0; j < k_stul; j++)
		{
			cout << AI_Laukas[i][j] << " ";
		}
		cout << endl;
	}
}

void AI_Des()
{
	int HV;
	int x;
	int y;

	HV = H_V();

	if (HV == 0)
	{

		int x = rand() % 8 + 1;
		int y = rand() % 9 + 1;
		AI_Laukas[y - 1][x - 1] = 1;
		AI_Laukas[y - 1][x] = 1;
	}
	else
	{

		int x = rand() % 9 + 1;
		int y = rand() % 8 + 1;
		AI_Laukas[y - 1][x - 1] = 1;
		AI_Laukas[y][x - 1] = 1;
	}

}

void AI_Submarin()
{
AI_LOOP:
	int HV;
	int x;
	int y;

	HV = H_V();
	if (HV == 0)
	{
		int x = rand() % 7 + 1;
		int y = rand() % 9 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y - 1][x] == 0 && AI_Laukas[y - 1][x + 1] == 0 && AI_Laukas[y - 1][x + 2] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y - 1][x] = 1;
			AI_Laukas[y - 1][x + 1] = 1;
		}
		else
		{
			goto AI_LOOP;
		}
	}
	else
	{

		int x = rand() % 9 + 1;
		int y = rand() % 7 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y][x - 1] == 0 && AI_Laukas[y + 1][x - 1] == 0 && AI_Laukas[y + 2][x - 1] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y][x - 1] = 1;
			AI_Laukas[y + 1][x - 1] = 1;
		}
		else
		{
			goto AI_LOOP;
		}
	}
}


void AI_Battleship()
{
AI_LOOP:
	int HV;
	int x;
	int y;

	HV = H_V();
	if (HV == 0)
	{

		int x = rand() % 6 + 1;
		int y = rand() % 9 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y - 1][x] == 0 && AI_Laukas[y - 1][x + 1] == 0 && AI_Laukas[y - 1][x + 2] == 0 && AI_Laukas[y - 1][x + 3] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y - 1][x] = 1;
			AI_Laukas[y - 1][x + 1] = 1;
			AI_Laukas[y - 1][x + 2] = 1;
		}
		else
		{
			goto AI_LOOP;
		}
	}
	else
	{

		int x = rand() % 9 + 1;
		int y = rand() % 6 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y][x - 1] == 0 && AI_Laukas[y + 1][x - 1] == 0 && AI_Laukas[y + 2][x - 1] == 0 && AI_Laukas[y + 3][x - 1] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y][x - 1] = 1;
			AI_Laukas[y + 1][x - 1] = 1;
			AI_Laukas[y + 2][x - 1] = 1;
		}
		else
		{
			goto AI_LOOP;
		}
	}
}

void AI_Carrier()
{
AI_LOOP:
	int HV;
	int x;
	int y;

	HV = H_V();
	if (HV == 0)
	{

		int x = rand() % 5 + 1;
		int y = rand() % 9 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y - 1][x] == 0 && AI_Laukas[y - 1][x + 1] == 0 && AI_Laukas[y - 1][x + 2] == 0 && AI_Laukas[y - 1][x + 3] == 0 && AI_Laukas[y - 1][x + 4] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y - 1][x] = 1;
			AI_Laukas[y - 1][x + 1] = 1;
			AI_Laukas[y - 1][x + 2] = 1;
			AI_Laukas[y - 1][x + 3] = 1;
		}
		else
		{

			goto AI_LOOP;
		}
	}
	else
	{

		int x = rand() % 9 + 1;
		int y = rand() % 5 + 1;
		if (AI_Laukas[y - 1][x - 1] == 0 && AI_Laukas[y][x - 1] == 0 && AI_Laukas[y + 1][x - 1] == 0 && AI_Laukas[y + 2][x - 1] == 0 && AI_Laukas[y + 3][x - 1] == 0 && AI_Laukas[y + 4][x - 1] == 0)
		{
			AI_Laukas[y - 1][x - 1] = 1;
			AI_Laukas[y][x - 1] = 1;
			AI_Laukas[y + 1][x - 1] = 1;
			AI_Laukas[y + 2][x - 1] = 1;
			AI_Laukas[y + 3][x - 1] = 1;
		}
		else
		{
			goto AI_LOOP;
		}
	}
}

int main()
{
	srand(time(NULL));
	AI_Cleer();
	AI_Des();
	AI_Submarin();
	AI_Submarin();
	AI_Battleship();
	AI_Carrier();
	AI_Show();
}
