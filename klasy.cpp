#include <fstream>
#include "klasy.hpp"
#include "funkcje.hpp"
#include "pliki.hpp"
using namespace std;
void plansza::pokaz()//wyswietlanie planszy
{
	system("cls");
	cout<<("     |");
	for (int i = 0;i < 16;i++)
	{
		if (i > 9)
		{
			cout << "  ";
			koloruj(i, 9);
			cout << " |";
		}
		else
		{
			cout << "  ";
			koloruj(i, 9);
			cout<< "  |";
		}
	}
	cout << endl;
	for (int i = 0;i < 17;i++)
	{
		cout << "-----+";
	}
	cout<<endl;
	for (int i = 0;i < 16;i++)
	{
		if (i > 9)
		{
			cout << " ";
			koloruj(i, 9);
			cout << "  |";
		}
		else
		{
			cout << "  ";
			koloruj(i, 9);
			cout << "  |";
		};
		for (int n = 0;n < 16;n++)
		{
			if ((i == 11 && n == 1)|| (i == 12 && n == 2) || (i == 13 && n == 3) || (i == 14 && n == 4) || (i == 15 && n == 4) || (i == 0 && n == 10) || (i == 1 && n == 10) || (i == 2 && n == 11) || (i == 3 && n == 12)|| (i == 4 && n == 13))
			{
				if (znak[i][n] == 'o')
				{
					cout << "  ";
					koloruj(znak[i][n], 5);
					cout << "  ";
					koloruj('|', 4);
					continue;
				}
				else if (znak[i][n] == 'x')
				{
					cout << "  ";
					koloruj(znak[i][n], 3);
					cout << "  ";
					koloruj('|', 4);
					continue;
				}
				else
				{
					cout << "     ";
					koloruj('|', 4);
					continue;
				}
			}
			if (znak[i][n] == 'o' || znak[i][n] == 'x')
			{	
				if (znak[i][n] == 'o')
				{
					cout<<"  ";
					koloruj(znak[i][n],5);
					cout<<"  |";
				}
				if (znak[i][n] == 'x')
				{
					cout<<"  ";
					koloruj(znak[i][n], 3);
					cout<<"  |";
				}
			}
			else
			{
				cout<<"     |";
			}
		}
		cout<<endl;
		if (i == 10)
		{
			cout << "-----";
			koloruj("-------------", 4);
			for (int j = 0;j < 83;j++)
			{
				cout << "-";
			}
			cout << "+" << endl;
		}
		else if (i == 4)
		{
			for (int j = 0;j < 89;j++)
			{
				cout << "-";
			}
			koloruj("------------", 4);
			cout << "+" << endl;
		}
		else
		{
			for (int j = 0;j < 101;j++)
			{
				cout<<"-";
			}
			cout<<"+"<<endl;
		}
		
	}
}
plansza::plansza()//wypelnianie planszy i wygranej
{
	for (int i = 0;i < 16;i++)
	{
		for (int j = 0;j < 16;j++)
			znak[i][j] = ' ';
	}
	for (int i = 0;i < 5;i++)
	{
		znak[15][i] = 'x';
	}
	for (int i = 0;i < 5;i++)
	{
		znak[14][i] = 'x';
	}
	for (int i = 0;i < 4;i++)
	{
		znak[13][i] = 'x';
	}
	for (int i = 0;i < 3;i++)
	{
		znak[12][i] = 'x';
	}
	for (int i = 0;i < 2;i++)
	{
		znak[11][i] = 'x';
	}
	for (int i = 15;i > 10;i--)
	{
		znak[0][i] = 'o';
	}
	for (int i = 15;i > 10;i--)
	{
		znak[1][i] = 'o';
	}
	for (int i = 15;i > 11;i--)
	{
		znak[2][i] = 'o';
	}
	for (int i = 15;i > 12;i--)
	{
		znak[3][i] = 'o';
	}
	for (int i = 15;i > 13;i--)
	{
		znak[4][i] = 'o';
	}
	int licznik = 0;
	//wypelnienie tablic wygranych
	for (int i = 15;i > 10;i--)
	{
		x[licznik][0] = 0;
		x[licznik][1] = i;
		licznik++;
	}
	for (int i = 15;i > 10;i--)
	{
		x[licznik][0] = 1;
		x[licznik][1] = i;
		licznik++;
	}
	for (int i = 15;i > 11;i--)
	{
		x[licznik][0] = 2;
		x[licznik][1] = i;
		licznik++;
	}
	for (int i = 15;i > 12;i--)
	{
		x[licznik][0] = 3;
		x[licznik][1] = i;
		licznik++;
	}
	for (int i = 15;i > 13;i--)
	{
		x[licznik][0] = 4;
		x[licznik][1] = i;
		licznik++;
	}
	licznik = 0;
	for (int i = 0;i < 5;i++)
	{
		o[licznik][0] = 15;
		o[licznik][1] = i;
		licznik++;
	}
	for (int i = 0;i < 5;i++)
	{
		o[licznik][0] = 14;
		o[licznik][1] = i;
		licznik++;
	}
	for (int i = 0;i < 4;i++)
	{
		o[licznik][0] = 13;
		o[licznik][1] = i;
		licznik++;
	}
	for (int i = 0;i < 3;i++)
	{
		o[licznik][0] = 12;
		o[licznik][1] = i;
		licznik++;
	}
	for (int i = 0;i < 2;i++)
	{
		o[licznik][0] = 11;
		o[licznik][1] = i;
		licznik++;
	}
}
char gracz::getpion()//zwraca pion x lub o
{
	return pion;
}
int gracz::czyjest(int rz, int kol)//sprawdzenie czy trafiono w swoj pion
{
	if (k->znak[rz][kol] == pion)
		return 1;
	else return 0;
}
int gracz::czypusty(int rz, int kol)//sprawdzenie czy miejsce skoku jest puste
{
	if (k->znak[rz][kol] == ' ')
		return 1;
	else return 0;
}
int gracz::ruch()// ruch faza wstepna
{
	return 0;
}
int gracz::sprwygrana(plansza *k)//sprawdza czy jest wygrana
{
	int rzad;
	int kolumna;
	int licznik = 0;
	if (pion == 'x')
	{
		for (int i = 0;i < 19;i++)
		{
			rzad = k->x[i][0];
			kolumna = k->x[i][1];
			if (k->znak[rzad][kolumna] == 'x')
				licznik++;
			else
				break;
		}
	}
	else
	{
		for (int i = 0;i < 19;i++)
		{
			rzad = k->o[i][0];
			kolumna = k->o[i][1];
			if (k->znak[rzad][kolumna] == 'o')
				licznik++;
			else
				break;
		}
	};
	if (licznik == 19)
	{
		return 1;// je¿eli jest 19 pionków w przeciwnej bazie zwraca 1
	}
	else
	{
		return 0;// je¿eli liczba pionów w bazie przeciwnika jest inna ni¿ 19 zwraca 0
	}
}
void gracz::zmiana(int rz, int kol, int nrz, int nkol)
{
	k->znak[rz][kol] = ' ';//stare miejsce pozostaje puste
	k->znak[nrz][nkol] = pion;//nowe zostaje wypelnione pionem
}
int gracz::niezadaleko(int rz, int kol, int nrz, int nkol)//podstawowe sprawdzenie ruchu
{
	if ((abs(nrz - rz) > 2) && (abs(nkol - kol) > 2))// jezeli odleglosc jest wieksza od dwoch zwraca 0
		return 1;
	else
		return 0;
}
int gracz::czymaruch(int rz, int kol)
{
	int suma=0;
	suma += bliskiruch(rz, kol, -1, -1);
	suma += bliskiruch(rz, kol, -1, 0);
	suma += bliskiruch(rz, kol, -1, 1);
	suma += bliskiruch(rz, kol,	0, -1);
	suma += bliskiruch(rz, kol, 0, 1);
	suma += bliskiruch(rz, kol, 1, -1);
	suma += bliskiruch(rz, kol, 1, 1);
	suma += bliskiruch(rz, kol, 1, 0);
	//sprawdzanie wszystkich miejsc s¹siednich w ko³o pionka
	suma += dalekiruch(rz, kol, -1, -1);
	suma += dalekiruch(rz, kol, -1, 0);
	suma += dalekiruch(rz, kol, -1, 1);
	suma += dalekiruch(rz, kol, 0, -1);
	suma += dalekiruch(rz, kol, 0, 1);
	suma += dalekiruch(rz, kol, 1, -1);
	suma += dalekiruch(rz, kol, 1, 1);
	suma += dalekiruch(rz, kol, 1, 0);
	//sprawdzanie wszystkich mozliwosci skoku
	return suma;//zwraca liczbe mo¿liwych ruchów
}
int gracz::przesuniecie(int rz, int kol, int nrz, int nkol)
{
	if ((abs(nrz - rz) < 2) && (abs(nkol - kol) < 2))//przesuniecie pionka na sasiednie miejsce o ile to mozliwe
		return 1;
	else
		return 0;
}
int gracz::podstawowyskok(int rz, int kol, int nrz, int nkol)
{
	int tmprz;
	int tmpkol;
	if (abs(nrz - rz) == 2 || abs(nkol - kol) == 2)//czy chociez jedna jest rowna dwa
	{
		if (abs(nrz - rz) > 2)
			return 0;	//za daleko
		if (abs(nkol - kol) > 2)
			return 0;	//za daleko
		if (rz == (nrz + 1) || rz == (nrz - 1) || kol == (nkol + 1) || kol == (nkol - 1))
			return 0; //za blisko
		//szukanie miejsca w którym powinien byæ przeskakiwany pionek
		if (rz > nrz)
		{
			tmprz = rz - 1;
		}
		else if (rz == nrz)
		{
			tmprz = rz;
		}
		else
		{
			tmprz = rz + 1;
		}
		if (kol > nkol)
		{
			tmpkol = kol - 1;
		}
		else if (kol == nkol)
		{
			tmpkol = kol;
		}
		else
		{
			tmpkol = kol + 1;
		}
		if (k->znak[tmprz][tmpkol] == 'x' || k->znak[tmprz][tmpkol] == 'o')// czy jest pomiedzy pionek
		{
			return 1;//je¿eli jest to zwraca jeden 
		}
		else return 0;
	}
	return 0;
}
int gracz::sprawdzdroge(int rz, int kol, droga * glowa)//sprawdza czy ju¿ czasem nie by³o siê na tym miejscu w tym ruchu
{
	droga *wsk = glowa;
	while (wsk != NULL)
	{
		if (wsk->getrzad() == rz&&wsk->getkolumna() == kol)
			return 1;//je¿eli ju¿ siê tam by³o to zwraca 1
		wsk = wsk->nast;
	}
	return 0;//je¿eli nie to zwraca 0
}
int gracz::przeskoki(int *rz, int *kol, droga * glowa)//metoda u¿yta w klasach dziedzicz¹cych komputer i graczczlowiek
{
	return 0;
}
int gracz::czymaskok(int rz, int kol, droga *glowa)//sprawdza czy po skoku ma sie dalsze skoki
{
	int suma = 0;
	//dodaje do sumy wszystkie mo¿liwe skoki
	suma += dalekiruch(rz, kol, -1, -1);
	suma += dalekiruch(rz, kol, -1, 0);
	suma += dalekiruch(rz, kol, -1, 1);
	suma += dalekiruch(rz, kol, 0, -1);
	suma += dalekiruch(rz, kol, 0, 1);
	suma += dalekiruch(rz, kol, 1, -1);
	suma += dalekiruch(rz, kol, 1, 1);
	suma += dalekiruch(rz, kol, 1, 0);
	droga *wsk = glowa;
	int nrzad;
	int nkolumna;
	//odejmuje pozycje na których ju¿ byliœmy w danym ruchu
	while (wsk != NULL)
	{
		nrzad = wsk->getrzad();
		nkolumna = wsk->getkolumna();
		suma -= podstawowyskok(rz,kol,nrzad,nkolumna);
		wsk = wsk->nast;
	}
	return suma;//zwraca liczbê mo¿liwych skoków
}
int gracz::bliskiruch(int rz, int kol, int tmprz, int tmpkol)//sprawdzanie czy jest mozliwoœæ zrobienia ruchu na s¹siednie miejsce
{
	int pomrz = rz + tmprz;
	int pomkol = kol + tmpkol;
	if (pomrz < 16 && pomrz >= 0 && pomkol < 16 && pomkol >= 0 && k->znak[pomrz][pomkol] == ' ')
		return 1;//je¿eli tak zwraca 1
	return 0;//je¿eli nie zwraca 0
}
int gracz::dalekiruch(int rz, int kol, int tmprz, int tmpkol)//sprawdzanie czy jest mozliwoœæ zrobienia skoku
{
	if (rz + tmprz + tmprz < 16 && rz + tmprz + tmprz >= 0 && kol + tmpkol + tmpkol < 16 && kol + tmpkol + tmpkol >= 0 && (k->znak[rz + tmprz][kol + tmpkol] == 'o' || k->znak[rz + tmprz][kol + tmpkol] == 'x') && k->znak[rz + tmprz + tmprz][kol + tmpkol + tmpkol] == ' ')
		return 1;
	return 0;
}
int gra::rozgrywka(int x)
{
	char a;
	char b;
	if (rand() % 2)//losowanie pionkow
	{
		a = 'x';
		b = 'o';
	}
	else
	{
		a = 'o';
		b = 'x';
	}
	if (x == 1)// gracz na gracza
	{
		log("czlowiek", "czlowiek");
		time_t start, finish;
		double elapsed_time;
		time(&start);
		while (1)
		{
			graczczlowiek gracz1(a, &t);
			graczczlowiek gracz2(b, &t);
			gracz *wsk;
			wsk = &gracz1;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion()<<endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "czlowiek", "czlowiek", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
			wsk = &gracz2;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion() << endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "czlowiek", "czlowiek", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
		}
	}
	if (x == 2)//gracz na komputer
	{
		log("czlowiek", "komputer");
		time_t start, finish;
		double elapsed_time;
		time(&start);
		while (1)
		{
			graczczlowiek gracz1(a, &t);
			komputer gracz2(b, &t);
			gracz *wsk;
			wsk = &gracz1;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion() << endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "czlowiek", "komputer", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
			wsk = &gracz2;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion() << endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "komputer", "czlowiek", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
		}
	}
	if (x == 3)//komputer na komputer
	{
		log("komputer", "komputer");
		time_t start, finish;
		double elapsed_time;
		time(&start);
		while (1)
		{
			komputer gracz1(a, &t);
			komputer gracz2(b, &t);
			gracz *wsk;
			wsk = &gracz1;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion() << endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "komputer", "komputer", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
			wsk = &gracz2;//polimorfizm
			wsk->ruch();
			if (wsk->sprwygrana(&t))//po ca³ym ruchu sprawdzenie czy wygra³
			{
				t.pokaz();
				cout << "Wygral " << wsk->getpion() << endl;
				time(&finish);
				elapsed_time = difftime(finish, start);
				wynik(elapsed_time, "komputer", "komputer", wsk->getpion());
				break;//przerwanie je¿eli gracz wygra³
			}
		}
	}
	if (x == 4)
	{
		wypiszwynik();
	}
	cout << "Wcisnij enter" << endl;
	clear();
	system("cls");
	return 1;
}

gracz::droga::~droga()//destruktor drogi
{
	delete nast;
}

int gracz::droga::getrzad()//zwraca rz¹d
{
	return rzad;
}

void gracz::droga::setrzad(int k)//ustawia rz¹d
{
	rzad = k;
}

int gracz::droga::getkolumna()//zwraca kolumne
{
	return kolumna;
}

void gracz::droga::setkolumna(int k)//ustawia kolumne
{
	kolumna = k;
}

int komputer::przeskoki(int * rz, int * kol, droga * glowa)//metoda która ma za zadanie umo¿liwiæ dalesz skakanie komuterowi
{
	droga *wsk = glowa;
	int rzad;
	int kolumna;
	do
	{
		rzad = losujblisko(*rz);//losuje rz¹d
		kolumna = losujblisko(*kol);//losuje kolumne
	} while (sprawdzdroge(rzad, kolumna, glowa)&&podstawowyskok(*rz,*kol,rzad,kolumna));
	//sprawdza czy wylosowane liczby maja szanse skoku
	if (!podstawowyskok(*rz, *kol, rzad, kolumna))//drugie sprawdzenie szansy skoku
		return 0;
	if (sprawdzdroge(rzad, kolumna, glowa))//sprawdzenie czy czasem coœ siê nie powtórzy³o
		return 0;
	*rz = rzad;//zmiana wartoœci wskaŸnikowej rzêdu
	*kol = kolumna;//zmiana wartoœci wskaŸnikowej kolumny
	while (wsk->nast != NULL)
		wsk = wsk->nast;//ustawienie wsk na ostatni element drogi
	wsk->nast = new droga(rzad, kolumna);//dodanie nowego elementu na koniec listy
	return 1;//zwrócenie 1 skok siê uda³
}

int komputer::ruch()
{
	k->pokaz();//wyœwietlenie planszy
	cout << "Ruch " << getpion()<<endl;
	Sleep(1000);//zapauzowanie na sekundê bo by to wszystko za szybko dzia³a³o 
	int rzad;
	int kolumna;
	do//pobieranie rzedu i kolumny
	{
		//cout << "Ruch " << pion << "\nPodaj rzad i kolumne" << endl;
		rzad = losuj();
		kolumna = losuj();
	} while (!czyjest(rzad, kolumna) || !czymaruch(rzad, kolumna));//dopóki nie znajdzie pionka który jest i który ma ruch 
	int nrzad;
	int nkolumna;
	do//pobieranie nowego rzedu i nowej kolumny
	{
		nrzad = losujblisko(rzad);//losuje rzad blisko
		nkolumna = losujblisko(kolumna);//losuje kolumne blisko
	} while (!czypusty(nrzad, nkolumna));//dopóki nie trafi na puste miejsce
	if (przesuniecie(rzad, kolumna, nrzad, nkolumna))//ruch o jeden o ile mozliwy
	{
		zmiana(rzad, kolumna, nrzad, nkolumna);
		return 1;
	}
	droga *glowa = new droga(rzad, kolumna);//zapisanie wspórzêdnej poczatkowej pionka
	droga *wsk = glowa;
	int a = 0;//sprawdzacz
	int pomrzad;
	int pomkolumna;
	if (podstawowyskok(rzad, kolumna, nrzad, nkolumna))// zwykly skok
	{
		a = 1;//ruch wykonany prawidlowo
		wsk->nast = new droga(nrzad, nkolumna);//wspórzêdna skoku
		zmiana(rzad, kolumna, nrzad, nkolumna);//skok
		while (czymaskok(nrzad, nkolumna, glowa))//sprawdzanie czy moze dalej skakac
		{
			if (rand() % 2)//losowanie czy chce dalej skakac
			{
				pomrzad = nrzad;
				pomkolumna = nkolumna;
				if (przeskoki(&nrzad, &nkolumna, glowa))//skakanie
				{
					zmiana(pomrzad, pomkolumna, nrzad, nkolumna);//skok
					continue;//powrót do sprawdzenia czy mo¿liwy skok
				}
				else
				{
					continue;//powrót do zapytania
				}
			}
			else
			{
				break;//nie chcê skakaæ
			}
		};
		if (glowa != NULL)//czyszczenie drogi
		{
			delete glowa;
			glowa = NULL;
		}
		return 1;//koniec ruchu
	}
	if (a == 0)//informacja o zlym ruchu 
	{
		if (glowa != NULL)//czyszczenie drogi
		{
			delete glowa;
			glowa = NULL;
		}
		ruch();//ponowny ruch
	}
	return 0;
}

void menu::start()
{
	/*menu*/
	koloruj("Witamy w grze HALMA\t\t Autor: Tomasz Postek", losujkolor());
	cout << endl<<endl;
	koloruj("Prosze wybrac tryb", losujkolor());
	cout << endl;
	koloruj(1, losujkolor());
	koloruj(".Gracz na gracza",losujkolor());
	cout << endl;
	koloruj(2, losujkolor());
	koloruj(".Gracz na komputer", losujkolor()); 
	cout << endl;
	koloruj(3, losujkolor());
	koloruj(".Komputer na komputer", losujkolor());
	cout << endl;
	koloruj(4, losujkolor());
	koloruj(".Wyniki", losujkolor());
	cout<< endl;
	int a = liczbazakres(1, 4);//wybór liczby
	gra zaczynamy;
	if (zaczynamy.rozgrywka(a))
	{
		start();//je¿eli zaczynamy.rozgrywka zwróci 1 (ktoœ wygra lub przy wynikach wcisnie enter) wracamy do menu 
	}
}

int graczczlowiek::przeskoki(int * rz, int * kol, droga * glowa)
{
	droga *wsk = glowa;
	int rzad;
	int kolumna;
	while (wsk->nast != NULL)
	{
		wsk = wsk->nast;//ustawienie na ostatni element
	}
	cout << "Aktualny pionek rzad: " << wsk->getrzad() << " kolumna: " << wsk->getkolumna() << endl;//wypisanie aktualnie u¿ywanych wspó³rzêdnych
	cout << "Podaj nowy rzad: ";
	rzad = liczba();//podawanie nowego rzêdu
	cout << "Podaj nowa kolumne: ";
	kolumna = liczba();//podawanie nowej kolumny
	if (sprawdzdroge(rzad, kolumna, glowa) || !podstawowyskok(*rz, *kol, rzad, kolumna))
	{
		cout << "Bledny ruch\n";
		Sleep(1000);
	}
	if (!podstawowyskok(*rz, *kol, rzad, kolumna))
		return 0;
	if (sprawdzdroge(rzad, kolumna, glowa))
		return 0;
	*rz = rzad;
	*kol = kolumna;
	wsk = glowa;
	while (wsk->nast != NULL)
		wsk = wsk->nast;
	wsk->nast = new droga(rzad, kolumna);
	return 1;
}

int graczczlowiek::ruch()
{
	k->pokaz();//wyœwietlenie planszy
	int rzad;
	int kolumna;
	do//pobieranie rzedu i kolumny
	{
		cout << "Ruch " << pion << endl;
		cout << "Podaj rzad: ";
		rzad = liczba();
		cout << "Podaj kolumne: ";
		kolumna = liczba();
		if (!czyjest(rzad, kolumna))// czy tu jest pionek
		{
			cout << "Tu nie ma twojego pionka szukaj dalej" << endl;
		}
		else if (!czymaruch(rzad, kolumna))//czy ma ruch
		{
			cout << "Ten pionek nie ma ruchu" << endl;
		}
	} while (!czyjest(rzad, kolumna) || !czymaruch(rzad, kolumna));//dopóki nie znajdzie pionka który ma ruch
	int nrzad;
	int nkolumna;
	do//pobieranie nowego rzedu i nowej kolumny
	{
		cout << "Podaj nowy rzad: ";
		nrzad = liczba();
		cout << "Podaj nowa kolumne: ";
		nkolumna = liczba();
		if (!czypusty(nrzad, nkolumna))
		{
			cout << "To miejsce nie jest puste" << endl;
		}
	} while (!czypusty(nrzad, nkolumna));//miejsce musi byæ puste
	if (przesuniecie(rzad, kolumna, nrzad, nkolumna))//ruch o jeden o ile mozliwy
	{
		zmiana(rzad, kolumna, nrzad, nkolumna);
		return 1;
	}
	droga *glowa = new droga(rzad, kolumna);
	droga *wsk = glowa;
	int a = 0;//sprawdzacz
	int pomrzad;
	int pomkolumna;
	if (podstawowyskok(rzad, kolumna, nrzad, nkolumna))// zwykly skok
	{
		a = 1;//ruch wykonany prawidlowo
		wsk->nast = new droga(nrzad, nkolumna);
		zmiana(rzad, kolumna, nrzad, nkolumna);
		while (czymaskok(nrzad, nkolumna, glowa))
		{
			k->pokaz();
			cout << "Czy chcesz skoczyc?(t)ak ,inne nie ";//pyta czy gracz chce skoczyæ
			if (getchar() == 't'&&getchar() == '\n')
			{
				pomrzad = nrzad;
				pomkolumna = nkolumna;
				if (przeskoki(&nrzad, &nkolumna, glowa))//je¿eli mo¿e tam skoczyæ to skacze
				{
					zmiana(pomrzad, pomkolumna, nrzad, nkolumna);
					continue;
				}
				else
				{
					continue;//jak nie wraca do pytania
				}
			}
			else
			{
				clear();
				break;
			}
		};
		if (glowa != NULL)//czyszczenie drogi
		{
			delete glowa;
		}
		return 1;
	}
	if (a == 0)//informacja o z³ym ruchu 
	{
		cout<<"Zly ruch ";
		if (glowa != NULL)
		{
			delete glowa;
		}
		Sleep(2000);
		ruch();//ponowny ruch
	}
	return 0;
}

