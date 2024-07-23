/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:18-10-2022
// Description:Cette programme permet de creer aleatoirement et de les trier apres
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
#include<iomanip>
#include"Lemming.h"
#include<algorithm>
using namespace std;


void DefinirLemming(list<Lemming>& , int);
void AfficherLemming(list<Lemming>);
void TriBulles(list<Lemming> &);

int main(void) {

	list<Lemming> TroupeLemming;
	int Nb = 50;
	cout << "Mes " << Nb << " Lemmings generer aleatoirement: ";
	DefinirLemming(TroupeLemming, Nb);
	AfficherLemming(TroupeLemming);
	cout << endl<<endl<<endl << "Mes " << Nb << " Lemmings trier:                 ";
	TriBulles(TroupeLemming);
	AfficherLemming(TroupeLemming);
	return 0;
}


void DefinirLemming(list<Lemming>& TroupeLemming , int Nb) {

	for (int i = 0; i < Nb; i++) {
		TroupeLemming.push_back(Lemming());
	}
}

void AfficherLemming(list<Lemming> Troupe) {
	list<Lemming> ::iterator It;
	int compteur = 0;
	for (It = Troupe.begin(); It != Troupe.end(); It++) {
		if (compteur % 10 == 0 && compteur !=0) {
			cout << endl<<endl <<"                                       ";
		}
		cout << *It<<" <- ";
		compteur++;
	}
}
void TriBulles(list<Lemming>& Troupe) {
	list<Lemming>::iterator It1;
	list<Lemming>::iterator It2;
	Lemming intermediare;
	It1 = Troupe.begin();
	for (It1; It1 != Troupe.end(); It1++) {
		It2 = Troupe.begin();
		It2 = It2++;
		for (It2; It2 != Troupe.end(); It2++) {
			if (*It2 > *It1) {
				intermediare = *It2;
				*It2 = *It1;
				*It1 = intermediare;
			}
		}
	}
}