/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:10-12-2022
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<queue>
#include"Carte.cpp"
#include"Dijkstra.cpp"
using namespace std;


int NombreSommet(string nomFichier);
void ChargerCarte(Carte& carte, string nomFichier);
enum type_route { ROUXVILLE, FORTESSE_ROUTE_DU_DUC, THRESHOLD, RIFLLIAN, DOMAINE_PENHALIGON, KELVIN,RADLEBB,SPECULARIUM,COLLINES_BOISEES,MER_EFFROI,SULESCU };

int main(void) {

	string nomFichier = "route.dat";
	int nombreSommet = NombreSommet(nomFichier);
	Carte carte(nombreSommet);
	carte.CompleterMatrice();
	ChargerCarte(carte, nomFichier);
	cout << carte;
	int** Matrice = carte.getMatrice();
	Dijkstra dijkstra(Matrice,nombreSommet, ROUXVILLE, SULESCU);
	dijkstra.Parcourir();
	cout << dijkstra;
	return 0;
}

int NombreSommet(string nomFichier) {
	ifstream Donne;
	int Sommet = 0;
	Donne.open(nomFichier, ios::in);
	if (Donne) {
		Donne >> Sommet;
	}
	else {
		cout << " ERREUR: Impossible d'ouvrir le fichier en lecture.\n";
	}
	Donne.close();
	return Sommet;
}


void ChargerCarte(Carte& carte, string nomFichier) {
	ifstream Donne;
	int a;
	char ligneChar;
	int ligne;
	char colonneChar;
	int colonne;
	int valeur;
	Donne.open(nomFichier, ios::in);
	if (Donne) {
		Donne >> a;
		while (!Donne.eof()) {
			Donne >> ligneChar;
			Donne >> colonneChar;
			Donne >> valeur;
			ligne = ((int)ligneChar) - 65;
			colonne = ((int)colonneChar) - 65;
			carte.ModifierMatrice(ligne, colonne, valeur);
			
		}
	}
	else
	{
		cout << " ERREUR: Impossible d'ouvrir le fichier en lecture.\n";
	}
	Donne.close();
}