#include <iostream>
#include <iomanip>
#include <time.h>
#include "Laivu_Sudejimas.h"
using namespace std;

const int eil = 10;
const int stu = 10;
int newShot = 0;
int function = 0;
int shot2;
bool enemyHit = false;
int computerHitCount = 0;



//int laivai = 5;
int Mano_Laukas[eil][stu];
//int Ismanus_Laukas[eil][stu];


void ai_just_do_it()
{srand(time(NULL));
	
	if (enemyHit == false) {
		shot2 = rand() % 100 + 1;
		if (enemyShotCheck(shot2, Mano_Laukas, computerHitCount))
		{
			cout << "KOMPIUTERIS PATAIKE YESSSS!" << endl;
			enemyHit = false;
			
		}

		else
		{
			cout << "KOMPIUTERIS NEPATAIKE NOOOOO!" << endl;
			enemyHit = false;
		}
	}
}

bool enemyShotCheck(int shot2, int Mano_Laukas[10][10], int& computerHitCount) {
	int tempX = (shot2 - 1) / 10;
	int tempY = (shot2 - 1) % 10;
	
	if (Mano_Laukas[tempX][tempY] == 1) {
		Mano_Laukas[tempX][tempY] = 3;
		computerHitCount++;
		return true;
	}
	else if (Mano_Laukas[tempX][tempY] == 2 || Mano_Laukas[tempX][tempY] == 3) {
		hitSearch(Mano_Laukas, shot2, newShot, function);
		enemyShotCheck(shot2 + 1, Mano_Laukas, computerHitCount);
		return false;
	}
	else {
		Mano_Laukas[tempX][tempY] = 2;
		return false;
	}
}

void hitSearch(int Mano_Laukas[10][10], int shot2, int& newShot, int& function) {
	int tempX = (shot2 - 1) / 10;
	int tempY = (shot2 - 1) % 10;

	if (Mano_Laukas[tempX][tempY + 1] < 2 && (function == 1 || function == 0) && tempY != 9) {
		newShot = shot2 + 1;
		function = 1;
		return;
	}
	if (Mano_Laukas[tempX][tempY - 1] < 2 && (function == 2 || function == 0) && tempY != 0) {
		newShot = shot2 - 1;
		function = 2;
		return;
	}
	if (Mano_Laukas[tempX + 1][tempY] < 2 && (function == 3 || function == 0) && tempX != 9) {
		newShot = shot2 + 10;
		function = 3;
		return;
	}
	if (Mano_Laukas[tempX - 1][tempY] < 2 && (function == 4 || function == 0) && tempX != 0) {
		newShot = shot2 - 10;
		function = 4;
		return;
	}
}


int cpu_hit()
{
	return computerHitCount;
}

	void Cleer()
	{
		for (int i = 0; i < eil; i++)
		{
			for (int j = 0; j < stu; j++)
			{
				Mano_Laukas[i][j] = 0;
			}
		}
	}

	void Showww()
	{
		for (int i = 0; i < eil; i++)
		{
			for (int j = 0; j < stu; j++)
			{
				cout << Mano_Laukas[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Destroyer()
	{
		char HV;
		int x;
		int y;
		cout << "[H/V] ? \n :";
		cin >> HV;
		if (HV == 'H' || HV == 'V')cout << "\n kryptis pasirinkta teisingai :) \n";
		else
		{
			cout << "Kadangi blogai pasirinkote uz jus paimiau krypti [H]\n";
			HV = 'H';
		}
		if (HV == 'H')
		{
			cout << "pasirinkite kordinates x asi [1-9] ir paspauskite [ENTER] ir y asi [1-10] ir [ENTER] \n ";
			cin >> x >> y;
			Mano_Laukas[y - 1][x - 1] = 1;
			Mano_Laukas[y - 1][x] = 1;
		}
		else
		{
			cout << "pasirinkite kordinates x asi [1-10] ir paspauskite [ENTER] ir y asi [1-9] ir [ENTER] \n ";
			cin >> x >> y;
			Mano_Laukas[y - 1][x - 1] = 1;
			Mano_Laukas[y][x - 1] = 1;
		}

	}

	void Submarine()
	{
	loop:
		char HV;
		int x;
		int y;
		cout << "[H/V] ? \n :";
		cin >> HV;
		if (HV == 'H' || HV == 'V')cout << "\n kryptis pasirinkta teisingai :) \n";
		else
		{
			cout << "Kadangi blogai pasirinkote uz jus paimiau krypti [H]\n";
			HV = 'H';
		}
		if (HV == 'H')
		{
			cout << "pasirinkite kordinates x asi [1-8] ir paspauskite [ENTER] ir y asi [1-10] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y - 1][x] == 0 && Mano_Laukas[y - 1][x + 1] == 0 && Mano_Laukas[y - 1][x + 2] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y - 1][x] = 1;
				Mano_Laukas[y - 1][x + 1] = 1;
			}
			else
			{
				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
		else
		{
			cout << "pasirinkite kordinates x asi [1-10] ir paspauskite [ENTER] ir y asi [1-8] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y][x - 1] == 0 && Mano_Laukas[y + 1][x - 1] == 0 && Mano_Laukas[y + 2][x - 1] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y][x - 1] = 1;
				Mano_Laukas[y + 1][x - 1] = 1;
			}
			else
			{
				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
	}

	void Battleship()
	{
	loop:
		char HV;
		int x;
		int y;
		cout << "[H/V] ? \n :";
		cin >> HV;
		if (HV == 'H' || HV == 'V')cout << "\n kryptis pasirinkta teisingai :) \n";
		else
		{
			cout << "Kadangi blogai pasirinkote uz jus paimiau krypti [H]\n";
			HV = 'H';
		}
		if (HV == 'H')
		{
			cout << "pasirinkite kordinates x asi [1-7] ir paspauskite [ENTER] ir y asi [1-10] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y - 1][x] == 0 && Mano_Laukas[y - 1][x + 1] == 0 && Mano_Laukas[y - 1][x + 2] == 0 && Mano_Laukas[y - 1][x + 3] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y - 1][x] = 1;
				Mano_Laukas[y - 1][x + 1] = 1;
				Mano_Laukas[y - 1][x + 2] = 1;
			}
			else
			{
				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
		else
		{
			cout << "pasirinkite kordinates x asi [1-10] ir paspauskite [ENTER] ir y asi [1-7] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y][x - 1] == 0 && Mano_Laukas[y + 1][x - 1] == 0 && Mano_Laukas[y + 2][x - 1] == 0 && Mano_Laukas[y + 3][x - 1] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y][x - 1] = 1;
				Mano_Laukas[y + 1][x - 1] = 1;
				Mano_Laukas[y + 2][x - 1] = 1;
			}
			else
			{
				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
	}

	void Carrier()
	{
	loop:
		char HV;
		int x;
		int y;
		cout << "[H/V] ? \n :";
		cin >> HV;
		if (HV == 'H' || HV == 'V')cout << "\n kryptis pasirinkta teisingai :) \n";
		else
		{
			cout << "Kadangi blogai pasirinkote uz jus paimiau krypti [H]\n";
			HV = 'H';
		}
		if (HV == 'H')
		{
			cout << "pasirinkite kordinates x asi [1-6] ir paspauskite [ENTER] ir y asi [1-10] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y - 1][x] == 0 && Mano_Laukas[y - 1][x + 1] == 0 && Mano_Laukas[y - 1][x + 2] == 0 && Mano_Laukas[y - 1][x + 3] == 0 && Mano_Laukas[y - 1][x + 4] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y - 1][x] = 1;
				Mano_Laukas[y - 1][x + 1] = 1;
				Mano_Laukas[y - 1][x + 2] = 1;
				Mano_Laukas[y - 1][x + 3] = 1;
			}
			else
			{

				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
		else
		{
			cout << "pasirinkite kordinates x asi [1-10] ir paspauskite [ENTER] ir y asi [1-6] ir [ENTER] \n ";
			cin >> x >> y;
			if (Mano_Laukas[y - 1][x - 1] == 0 && Mano_Laukas[y][x - 1] == 0 && Mano_Laukas[y + 1][x - 1] == 0 && Mano_Laukas[y + 2][x - 1] == 0 && Mano_Laukas[y + 3][x - 1] == 0 && Mano_Laukas[y + 4][x - 1] == 0)
			{
				Mano_Laukas[y - 1][x - 1] = 1;
				Mano_Laukas[y][x - 1] = 1;
				Mano_Laukas[y + 1][x - 1] = 1;
				Mano_Laukas[y + 2][x - 1] = 1;
				Mano_Laukas[y + 3][x - 1] = 1;
			}
			else
			{
				cout << "Pasirinkote laivo kordinates per arti kito laivo, laivai turi buti 1 langelio atstumu";
				goto loop;
			}
		}
	}


