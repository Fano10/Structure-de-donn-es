		/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:
// Auteur:Rakotondrabe Miora Fanomezana
// Date:09-11-2022
// Description:Cette programme permet de permuter des nombres dans un tableau et l'afficher
////////////////////////////////////////////////////////////////////////////////////////////

		/*Inclusions des fichier*/
#include<iostream>
using namespace std;

void Permuter1(int *T, int PosA, int PosB);
void Permuter2(int T[], int PosA, int PosB);
void Permuter3(int& PosA, int& PosB);
void Permuter4(int* PosA, int* PosB);
void Afficher1(int *T, int PosA, int PosB);
void Afficher2(int T[], int PosA, int PosB);
void Afficher3(int &PosA, int &PosB);
void Afficher4(int* PosA, int* PosB);
int* Recherche(int* T, int Taille, int Valeur);

int main(void){
	int Tableau[] = {1,3,4,5,8,7,0,2,6,9};
	Permuter1(Tableau,2,5);
	Permuter2(Tableau, 3, 6);
	Permuter3(Tableau[1], Tableau[9]);
	Permuter4(Tableau + 4,Tableau+7);
	Afficher1(Tableau,0,7);
	Afficher2(Tableau, 2, 8);
	Afficher3(*(Tableau + 5), Tableau[6]);
	Afficher4(&Tableau[3],&Tableau[8]);
	int* Valeur = Recherche(Tableau, 10, 8);
	cout << "valeur: " << *Valeur << endl;
	*Valeur = 10;
	Afficher4(Tableau, Tableau+9);
	return 0;
}

void Permuter1(int* T, int PosA, int PosB) {
	int Intermediaire = *(T+PosA);
	*(T + PosA) = *(T + PosB);
	*(T + PosB) = Intermediaire;
}
void Permuter2(int T[], int PosA, int PosB) {
	int Intermediaire = T[PosA];
	T[PosA] = T[PosB];
	T[PosB] = Intermediaire;
}
void Permuter3(int& PosA, int& PosB) {
	int Intermediaire = PosA;
	PosA = PosB;
	PosB = Intermediaire;
}
void Permuter4(int* PosA, int* PosB) {
	int Intermediaire = *PosA;
	*PosA = *PosB;
	*PosB = Intermediaire;
}

void Afficher1(int* T, int PosA, int PosB) {
	cout << "AFFICHER #1 : ";
	for (PosA; PosA <= PosB; PosA++) {
		cout << *(T + PosA) << ",";
	}
	cout << endl;

}
void Afficher2(int T[], int PosA, int PosB) {
	cout << "AFFICHER #2 : ";
	for (PosA; PosA <= PosB; PosA++) {
		cout << T[PosA] << ",";
	}
	cout << endl;
}

void Afficher3(int& PosA, int& PosB) {
	cout << "AFFICHER #3 : ";
	cout << PosA << "," << PosB << ","<< endl;
}

void Afficher4(int* PosA, int* PosB) {
	cout << "AFFICHER #4 : ";
	while (PosA != PosB) {
		cout << *PosA << ",";
		PosA = PosA + 1;
	}
	cout << *PosB << "," << endl;
}

int* Recherche(int* T, int Taille, int Valeur) {
	int*Reponse =NULL;
	for (int i = 0; i < Taille; i++) {
		if (*(T+i)==Valeur) {
			Reponse = (T + i);
		}
	}
	return Reponse;
}
