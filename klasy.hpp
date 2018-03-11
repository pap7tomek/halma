#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include<stdlib.h> 
#include<Windows.h>
#include<math.h>
class plansza {
	char znak[16][16];
	int x[19][2];
	int o[19][2];
public:
	void pokaz();
	plansza();
	friend class gracz;
};
class gracz
{
protected:
	char pion;
	plansza *k;
	class droga
	{
		int rzad;
		int kolumna;
	public:
		~droga();
		droga *nast;
		droga(int a, int b) :rzad(a), kolumna(b), nast(NULL) {};
		int getrzad();
		void setrzad(int k);
		int getkolumna();
		void setkolumna(int k);
	};
public:
	gracz(char a, plansza *j) :pion(a), k(j) {};
	char getpion();
	int czyjest(int rz, int kol);
	int czypusty(int rz, int kol);
	void zmiana(int rz, int kol, int nrz, int nkol);
	int niezadaleko(int rz, int kol, int nrz, int nkol);
	int bliskiruch(int rz, int kol, int tmprz, int tmpkol);
	int dalekiruch(int rz, int kol, int tmprz, int tmpkol);
	int czymaruch(int rz, int kol);
	int przesuniecie(int rz, int kol, int nrz, int nkol);
	int podstawowyskok(int rz, int kol, int nrz, int nkol);
	int sprawdzdroge(int rz, int kol, droga *glowa);
	virtual int przeskoki(int *rz, int *kol, droga *glowa);
	int czymaskok(int rz, int kol, droga *glowa);
	virtual int ruch();
	int sprwygrana(plansza *k);
};
class graczczlowiek:public gracz
{
public:
	graczczlowiek(char a, plansza *k) :gracz(a, k) {};
	int przeskoki(int *rz, int *kol, droga * glowa);
	int ruch();
};
class komputer :public gracz
{
public:
	komputer(char a, plansza *k) :gracz(a, k) {};
	int przeskoki(int *rz, int *kol, droga * glowa);
	int ruch();
};
class menu
{
public:
	void start();
};
class gra {
	plansza t;
public:
	int rozgrywka(int x);
};