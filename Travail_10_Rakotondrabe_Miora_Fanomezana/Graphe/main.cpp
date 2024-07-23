/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:08-12-2022
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include"matriceAdj.cpp"
using namespace std;

int SommetGraphe(string nomFichier);
void ChargerGraphe(MatriceAdjacent& Graphe,string nomFichier);
void AfficherChemin(int source, int destination, int* route , int nombreSommet);

int main(void) {

	string nomFichier;
	int* parent;
	cout << "SECTION #1: CHARGEMENT DE LA MATRICE ADJACENCE\n"<<endl;
	cout << "Entrer le # du fichier de donnees : ";
	cin >> nomFichier;
	nomFichier = nomFichier + ".dat";
	int sommet = SommetGraphe(nomFichier);
	MatriceAdjacent graphe(sommet);
	graphe.CompleterMatrice();
	ChargerGraphe(graphe, nomFichier);
	cout << graphe;
	cout << endl<<"SECTION #3: PARCOURS EN LARGEUR\n"<<endl;
	int sommetChoisi = 0;
	cout << "Choisir le sommet source (0-"<<sommet-1<<") : ";
	cin >> sommetChoisi;
	cout << endl << "SECTION #4: AFFICHAGE\n";
	parent = graphe.Parcourlargeur(sommetChoisi);
	cout << endl << endl << "SECTION #5: QUESTION (afficher le chemain)\n";
	cout << endl << "choisir le sommet destination ? (0-" << sommet-1 << ") : ";
	int chemin = 0;
	cin >> chemin;
	AfficherChemin(sommetChoisi, chemin, parent, sommet);
	return 0;
}

int SommetGraphe(string nomFichier) {
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

void ChargerGraphe(MatriceAdjacent& Graphe, string nomFichier) {
	ifstream Donne;
	int a;
	int ligne;
	int colonne;
	Donne.open(nomFichier, ios::in);
	if (Donne) {
		Donne >> a;
		while (!Donne.eof()) {
			Donne >> ligne;
			Donne >> colonne;
			Graphe.ModifierMatrice(ligne, colonne);
		}
	}
	else
	{
		cout << " ERREUR: Impossible d'ouvrir le fichier en lecture.\n";
	}
	Donne.close();
}

void AfficherChemin(int source,int destination, int * route,int nombreSommet) {
	cout << "Chemin: " << destination;
	destination = route[destination];
	while (1 > 0) {
		if (destination == -1) {
			cout << endl << "Chemin impossible";
			break;
		}
		else if (destination != source) {
			cout << " <- " << destination;
			destination = route[destination];
		}
		else {
			cout << " <- " << source;
			break;
		}
	}
}