#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include<stdlib.h> 
#include<Windows.h>
using namespace std;
void clear();
template <typename Typ, typename Typ2>
Typ koloruj(Typ a, Typ2 b)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, b);
	cout << a;
	SetConsoleTextAttribute(hOut, 7);
	return a;
}
int liczba();
int losuj();
int losujblisko(int liczba);
int liczbazakres(int a, int b);
int losujkolor();
