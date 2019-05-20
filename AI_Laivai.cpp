#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include "AI_Laivai.h"

using namespace std;

const int k_eil = 10;
const int k_stul = 10;
int laivai = 5;
int AI_Laukas[k_eil][k_stul];
int AI_Laukas_sk[k_eil][k_stul];

void query(int x, int y)
{
	int temp;
	int tempy=0;
	{
		if (AI_Laukas_sk[x - 1][y - 1] != 0)
		{
			temp = AI_Laukas_sk[x - 1][y - 1];
			cout << "PEW PATAIKEI!\n";
			AI_Laukas_sk[x - 1][y - 1] = 0;
			AI_Laukas[x - 1][y - 1] = 1;
			for (int i = 0; i < k_eil; i++)
			{
				for (int j = 0; j < k_stul; j++)
				{
					if (AI_Laukas_sk[i][j] == temp )
					{
						tempy++;
					}
					
					
				}
			}
			if (tempy == 0)
					{
						laivai--;
					}
		}
		else
		{
			cout << "NOPEW NEPATAIKEI!\n"; 
			AI_Laukas[x - 1][y - 1] = 2;
		}
			
	}
}

bool win()
{
	if (laivai < 1)
		return true;
	else
		return false;
}

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

void AI_Cleer_Nr()
{
	for (int i = 0; i < k_eil; i++)
	{
		for (int j = 0; j < k_stul; j++)
		{
			AI_Laukas_sk[i][j] = 0;
		}
	}
}

bool AI_for_Cikl()
{
	int n = 0;
	for (int i = 0; i < k_eil; i++)
	{
		for (int j = 0; j < k_stul; j++)
		{
			if (AI_Laukas_sk[i][j] == 31)n++;
		}
	}
	if (n >= 3)return true;
	else return false;
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
		AI_Laukas_sk[y - 1][x - 1] = 2; AI_Laukas_sk[y - 1][x] = 2;
	}
	else
	{

		int x = rand() % 9 + 1;
		int y = rand() % 8 + 1;
		AI_Laukas[y - 1][x - 1] = 1;
		AI_Laukas[y][x - 1] = 1;
		AI_Laukas_sk[y - 1][x - 1] = 2; AI_Laukas_sk[y][x - 1] = 2;
	}

}

void AI_Submarin()
{
AI_LOOP:
	int HV;
	int n;
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
			n = AI_for_Cikl();
			if (n == 0)
			{
				AI_Laukas_sk[y - 1][x - 1] = 31; AI_Laukas_sk[y - 1][x] = 31; AI_Laukas_sk[y - 1][x + 1] = 31;
			}
			else
			{
				AI_Laukas_sk[y - 1][x - 1] = 32; AI_Laukas_sk[y - 1][x] = 32; AI_Laukas_sk[y - 1][x + 1] = 32;
			}
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
			n = AI_for_Cikl();
			if (n == 0)
			{
				AI_Laukas_sk[y - 1][x - 1] = 31; AI_Laukas_sk[y][x - 1] = 31; AI_Laukas_sk[y + 1][x - 1] = 31;
			}
			else
			{
				AI_Laukas_sk[y - 1][x - 1] = 32; AI_Laukas_sk[y][x - 1] = 32; AI_Laukas_sk[y + 1][x - 1] = 32;
			}
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
			AI_Laukas_sk[y - 1][x - 1] = 4;
			AI_Laukas_sk[y - 1][x] = 4;
			AI_Laukas_sk[y - 1][x + 1] = 4;
			AI_Laukas_sk[y - 1][x + 2] = 4;
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
			AI_Laukas_sk[y - 1][x - 1] = 4;
			AI_Laukas_sk[y][x - 1] = 4;
			AI_Laukas_sk[y + 1][x - 1] = 4;
			AI_Laukas_sk[y + 2][x - 1] = 4;
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
			AI_Laukas_sk[y - 1][x - 1] = 5;
			AI_Laukas_sk[y - 1][x] = 5;
			AI_Laukas_sk[y - 1][x + 1] = 5;
			AI_Laukas_sk[y - 1][x + 2] = 5;
			AI_Laukas_sk[y - 1][x + 3] = 5;
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
			AI_Laukas_sk[y - 1][x - 1] = 5;
			AI_Laukas_sk[y][x - 1] = 5;
			AI_Laukas_sk[y + 1][x - 1] = 5;
			AI_Laukas_sk[y + 2][x - 1] = 5;
			AI_Laukas_sk[y + 3][x - 1] = 5;
		}
		else
		{
			goto AI_LOOP;
		}
	}
}


