#include <fstream>
#include "funkcje.hpp"
#include "klasy.hpp"
void clear()
{
	while (getchar() != '\n');
}
int liczba()
{
	int zmienna;
	while (!(cin>>zmienna) || zmienna < 0 || zmienna>15 || getchar() != '\n')
	{
		cout<<"Blad\nPodaj liczbe jeszcze raz\n";
		std::cin.clear();
		std::cin.sync();
		while (getchar() != '\n');

	}
	return zmienna;
}

int losuj()
{
	return rand() % 16;
}

int losujblisko(int liczba)
{
	do
	{
		liczba = liczba - 2 + (rand() % 5);
	} while (liczba < 0 || liczba>15);
	
	return liczba;
}

int liczbazakres(int a, int b)
{
	int liczba;
	while (!(cin>>liczba) || liczba<a || liczba>b || getchar() != '\n')
	{
		cout << "Bledna dana" << endl;
		std::cin.clear();
		std::cin.sync();
		while (getchar() != '\n');
	}
	return liczba;
}

int losujkolor()
{
	return ((rand() % 10)+1);
}
