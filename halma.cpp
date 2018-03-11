#include <fstream>
#include <iostream>
#include <stdio.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include "klasy.hpp"
#include "funkcje.hpp"
#include "pliki.hpp"
using namespace std;
int main()
{
	srand(time(NULL));
	menu nowa;
	nowa.start();
	return 0;
}