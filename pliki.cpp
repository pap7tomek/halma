#include "pliki.hpp"
#include "klasy.hpp"
#include "funkcje.hpp"
#include <fstream>
#include <time.h>
#include <iomanip>
#pragma warning(disable : 4996) 
using namespace std;
void wyswietl(fstream &plik, int a)
{
	if (a < 10)
	{
		plik << "0";//dodawanie 0 ¿eby data ³adnie wyglada³a
	}
	plik << a;
}
void czas(fstream &plik, struct tm *newtime)
{
	wyswietl(plik, newtime->tm_mday);
	plik << "-";
	wyswietl(plik, newtime->tm_mon);
	plik << "-";
	int rok = ((newtime->tm_year) - 100);
	plik << rok;
	plik << " ";
	wyswietl(plik, newtime->tm_hour);
	plik << ":";
	wyswietl(plik, newtime->tm_min);
	plik << ":";
	wyswietl(plik, newtime->tm_sec);
	plik << " ";//wypisywanie daty i godziny
}
struct tm *zegar()
{
	struct tm *newtime;//pobieranie czasu
	time_t aclock;
	time(&aclock);
	newtime = localtime(&aclock);
	return newtime;
}
void log(char *kto, char*zkim)
{
	int spr = sprawdzenie();
	fstream plik;
	plik.open("log.txt", ios::app);
	if (plik.is_open())
	{
		struct tm *newtime = zegar();//wczytanie czasu
		plik << spr << " ";//wpisanie indexu do pliku
		czas(plik, newtime);//wpisanie daty i godziny do pliku
		plik <<" "<<kto<<" "<<zkim<< endl;// kto z kim gra³
	}
	else
	{
		cout << "NIE DA SIE ZAPISAC LOGU" << endl;
	}
	plik.close();
}

int sprawdzenie()
{
	fstream plik;
	plik.open("log.txt", ios::in);
	if (plik.is_open())
	{
		int index;
		char data[30];
		char data2[30];
		char kto[30];
		char zkim[30];
		int licznik = 0;
		while (plik >> index >> data >> data2 >> kto >> zkim)//wczytywanie danych aby ustaliæ index w pliku
		{
			licznik++;
		}
		plik.close();
		return licznik;
	}
	else
	{
		plik.close();
		return 0;
	}
}
int sprwyniki()
{
	fstream plik;
	plik.open("wynik.txt", ios::in);
	if (plik.is_open())
	{
		int index;
		double czastrw;
		char kto[30];
		char zkim[30];
		int licznik = 0;
		while (plik >> index >> czastrw >> kto >> zkim)//wczytywanie danych aby ustaliæ index w pliku
		{
			licznik++;
		}
		plik.close();
		return licznik;
	}
	else
	{
		plik.close();
		return 0;
	}
}

void wynik(double ile,char *kto, char*zkim, char pion)
{
	int spr = sprwyniki();
	fstream plik;
	plik.open("wynik.txt", ios::app);//dodawanie do pliku
	if (plik.is_open())
	{

		plik << spr << " " << ile << " " << kto << " " << zkim << " " << pion << endl;//wpisywanie wyniku index czas kto i z kim gra³
	}
	else
	{
		cout << "NIE DA SIE ZAPISAC WYNIKU" << endl;
	}
	plik.close();
}
int wypiszwynik()
{
	system("cls");
	cout << "INDEX   CZAS   KTO WYGRAL   KTO PRZEGRAL   PION ZWYCIEZCY" << endl<<endl;
	fstream plik;
	plik.open("wynik.txt", ios::in);
	if (plik.is_open())
	{
		int spr;
		double ile;
		char kto[10];
		char zkim[10];
		char pion;
		while (plik >> spr >> ile >> kto >> zkim >> pion)//wpisywanie wyniku index czas kto i z kim gra³
		{
			cout << setw(5) << spr << " " << setw(6) << ile << " " << setw(12) << kto << " " << setw(14) << zkim << " " << setw(16) << pion << endl;
		};
	}
	else
	{
		cout << "NIE DA SIE WCZYTAC WYNIKU" << endl;
	}
	cout << endl;
	plik.close();
	return 1;
}

