#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>
#include "Laivu_Sudejimas.h"
#include "AI_Laivai.h"
#pragma comment(lib, "Winmm.lib")

using namespace std;

const int eilute = 10;
const int stulp = 10;
//int maxships = 10;
int Kovos_Laukas[eilute][stulp];

class saudymas {
public:
	int xcord;
	int ycord;


	void aim_n_fire()
	{
		cout << "Pasirinkite kur norite sauti X:[1-10], Y:[1-10] \n x:";
		cin >> xcord;
		cout << " || y:";
		cin >> ycord;
		cout << endl;
		query(xcord, ycord);
		AI_Show();
	}
	};
	

	class AI_saudymas {
	public:
		

		void suvis() {
			ai_just_do_it();
		}


		};



void Clear()
{
	for (int i = 0; i < eilute; i++)
	{
		for (int j = 0; j < stulp; j++)
		{
			Kovos_Laukas[i][j] = 0;
		}
	}
}

void Show()
{
	for (int i = 0; i < eilute; i++)
	{
		for (int j = 0; j < stulp; j++)
		{
			cout << Kovos_Laukas[i][j] << " ";
		}
		cout << endl;
	}
}

/*int LaivuSkaic()
{
	int c = 0;
	for (int i = 0; i < eilute; i++)
	{
		for (int j = 0; j < stulp; j++)
		{
			if (Kovos_Laukas[i][j] == 1)
				c++;
		}
	}
	return c;
}*/

/*void SetShips()
{
	int s = 0;
	while (s < maxships)
	{
		int x = rand() % eilute;
		int y = rand() % stulp;
		if (Kovos_Laukas[x][y] != 1)
		{
			s++;
			Kovos_Laukas[x][y] = 1;
		}
	}
}*/

/*bool Puolimas(int x, int y)
{
	if (Kovos_Laukas[x][y] == 1)
	{
		Kovos_Laukas[x][y] = 2;
		return true;
	}
	return false;
}*/

void Pagalba()
{
	cout << "		Sveiki atvyke i pagalba ?\n";
	cout << "Jusu pataikytas suvis : 1 \n Jusu nepataikytas suvis : 2 \n\n Kompiuterio pataikyras suvis 3 \n Kompiuterio nepataikytas suvis 2 \n\n";



	cout << "Jus turite padeti 5 laivus \n";
	cout << "Destroyer  "<< (char)254u << (char)254u <<" ilgis-2 "<<endl;
	cout << "Submarina  "<< (char)254u << (char)254u << (char)254u << " ilgis-3 " << endl;
	cout << "Cruiser    " << (char)254u << (char)254u << (char)254u << " ilgis-3 " << endl;
	cout << "Battleship " << (char)254u << (char)254u << (char)254u << (char)254u << " ilgis-4 " << endl;
	cout << "Carrier    " << (char)254u << (char)254u << (char)254u << (char)254u << (char)254u << " ilgis-5 " << endl;

	cout << "\n\n Laivus galite sudeti Horizontaliai nuo kaires i desine [V]\n\n";
	cout << "			" << (char)254u << (char)254u << (char)254u << (char)254u << (char)254u << endl;
	cout << endl << "Arba vertikaliai is virsaus i apacia [H]\n\n";
	cout << (char)254u << endl << (char)254u << endl << (char)254u << endl << (char)254u << endl << (char)254u << endl;
	//cout << (char)254u;
}

void Menu()
{
	cout << "		Laivu Musis\n\n" << "Pradeti Zaidima: F\n\n" << "Pagalba: P \n ";
}


int main()
{
	
MENIU:
	int hitai;
	char F_ar_P;
	saudymas kulka;
	AI_saudymas pist;
	srand(time(NULL));
	

	Menu();
	cin >> F_ar_P;
	
	if (F_ar_P == 'P' || F_ar_P == 'p')
	{
		Pagalba();
	}
	cin.get();
	cin.get();
	AI_Cleer();
	AI_Cleer_Nr();
	AI_Des();
	AI_Submarin();
	AI_Submarin();
	AI_Battleship();
	AI_Carrier();
	AI_Cleer();
	AI_Show();
	cout << endl;
	//system("cls");
	Cleer();
	Showww();
	Destroyer();
	Showww();
	Submarine();
	Showww();
	Submarine();
	Showww();
	Battleship();
	Showww();
	Carrier();
	Showww();
	cout << "\n";
	Clear();
	
	while (1)
	{
		AI_Show();
		kulka.aim_n_fire();
		if (win() == 1)
		{
			system("cls");
			PlaySound("C:\\Dev\\jeb.wav", NULL, SND_LOOP | SND_ASYNC);
			cin.get();
			cout << "YOU WIN!!!";
			cin.get();
			cin.get();
			system("cls");
			goto MENIU;
		}
		cout << "\n\n\n";

		pist.suvis();
		Showww();
		hitai = cpu_hit();
		if (hitai == 16)
		{
			system("cls");
			PlaySound("C:\\Dev\\jeb.wav", NULL, SND_LOOP | SND_ASYNC);
			cin.get();
			cout << "YOU LOSE!!!";
			cin.get();
			cin.get();
			system("cls");
			goto MENIU;
		}
		cin.get();
		cin.get();
		system("cls");
	}
	
	system("pause");

	return 0;
}