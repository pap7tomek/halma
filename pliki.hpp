#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
void log(char *kto, char *zkim);
int sprawdzenie();
struct tm *zegar();
void wynik(double ile, char *kto, char*zkim, char pion);
int sprwyniki();
int wypiszwynik();


