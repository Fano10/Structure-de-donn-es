/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:
// Auteur:Rakotondrabe Miora Fanomezana
// Date:20-09-2022
// Description:Cette programme permet de regler et d'afficher un thermostat
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include "thermostat.h"
using namespace std;


template <class T>
void Afficher(T Variable) {
	cout << Variable << endl;
}

int main(void) {
	int I = 25;
	float F = 3.14;
	string S = "Riche";
	thermostat T;
	cout << "Afficher INT : ";
	Afficher<int>(I);
	cout << "Afficher FLOAT : ";
	Afficher<float>(F);
	cout << "Afficher STRING : ";
	Afficher<string>(S);
	Afficher<thermostat>(T);
	return 0;
}
