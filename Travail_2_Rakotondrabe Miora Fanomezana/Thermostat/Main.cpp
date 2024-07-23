/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:
// Auteur:Rakotondrabe Miora Fanomezana
// Date:20-09-2022
// Description:Cette programme permet d'afficher des valeurs selon le type du variables.
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include"Thermostat.h"
using namespace std;

int main(void){
	Thermostat T;
	int Choix;
	do {
		cout << "Options\n";
		cout << " 0- Arreter le thermostat\n";
		cout << " 1- Definir le mode\n";
		cout << " 2- Ajuster la temperature\n";
		cout << " 3- Afficher le Thermostat\n";
		cout << " ..Votre choix? : ";
		cin >> Choix;
		switch (Choix) {
		case 1:
			T.ChoisirMode();
			break;
		case 2:
			T.ChoisirTemperature();
			break;
		case 3:
			cout << T << endl;
			break;
		}

	} while (Choix != 0);
	return 0;
}