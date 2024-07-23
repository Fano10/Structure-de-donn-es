/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:22-11-2022
// Description:Cette programme permet de gerer une prisme a l'aide d'un arbre
////////////////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Prisme.h"
#include "arbreBST.cpp"

using namespace std;

void chargerPrismes(BinarySearchTree<Prisme>& prismes);
void supprimerPiresCas(BinarySearchTree<Prisme>& prismes);
Prisme creerRecherche();
void rechercherPrisme(BinarySearchTree<Prisme>& prismes, Prisme prismeRecherche);
void rechercherPrisme(BinarySearchTree<Prisme>& prismes);
void imprimerPrismes(BinarySearchTree<Prisme>& prismes);

int main(int argc, char *argv[])
{
	
	BinarySearchTree<Prisme> prismes;
	chargerPrismes(prismes);

	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #1 : Impression de l'arbre dans un fichier" << endl;
	cout << "----------------------------------------------------" << endl;
	imprimerPrismes(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #2 : Recherche d'une valeur" << endl;
	cout << "----------------------------------------------------" << endl;
	rechercherPrisme(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #3 : Suppression des pires cas" << endl;
	cout << "----------------------------------------------------" << endl;
	supprimerPiresCas(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #4 : Recherche du meilleur cas selon des criteres" << endl;
	cout << "----------------------------------------------------" << endl;
	rechercherPrisme(prismes, creerRecherche());

    system("PAUSE");
    return EXIT_SUCCESS;
}

/* 
	A FAIRE :	Charger tous les prismes a partir du fichier "prismes.dat"
				Inserer dans l'arbre dans l'ordre de lecture
*/
void chargerPrismes(BinarySearchTree<Prisme>& prismes)
{
	string numero;
	int Longeur;
	int Largeur;
	int Profondeur;
	ifstream DonnePrismes("prismes.dat");
	if (DonnePrismes) {
		for (int i = 0; i < 12; i++) {
			DonnePrismes >> numero >> Longeur >> Largeur >> Profondeur;
			prismes.insert(Prisme(numero, Largeur, Longeur, Profondeur));
		}
	}
	else {
		cout << " ERREUR: Impossible d'ouvrir le fichier en lecture.\n";
	}
	DonnePrismes.close();

}

/* 
	A FAIRE :	Completer la surcharge de l'operateur << dans l'arbre afin d'afficher tous les prismes en ordre croissant de volume dans le fichier
				(Refererence : methode parcours dans la theorie)
*/
void imprimerPrismes(BinarySearchTree<Prisme>& prismes)
{
	ofstream out ("prismes.txt");
	out << prismes;
	out.close();
}

/* 
	A FAIRE :	Supprime les pires cas de l'arbre
				Attention de ne pas supprimer plus de prismes que ceux contenus dans l'arbre!!!
*/
void supprimerPiresCas(BinarySearchTree<Prisme>& prismes)
{
	int choix;
	Prisme Minimum("Pirecas",1,1,1);
	cout << "Combien de pires cas doivent etre supprimer? ";
	cin >> choix;
	cout << endl;
	for (int i = 0; i < choix; i++) {
		Minimum = prismes.findMin();
		cout << "Suppresion du pire cas #"<<i+1<<endl;
		cout << Minimum<<endl;
		prismes.remove(Minimum);
	}
}

/* 
	A FAIRE :	Recherche le MEILLEUR prisme qui correspond aux criteres minimums de la recherche
				Si le meilleur prisme ne correspond pas, on passe au meilleur suivant
				Si il correspond, on l'affiche
				Attention de ne pas planter si on vide completement l'arbre  (vos criteres sont trop eleves !??!)
*/
void rechercherPrisme(BinarySearchTree<Prisme>& prismes, Prisme prismeRecherche)
{
	bool boucle = true;
	int i = 1;
	Prisme Maximum("Meilleurcas",1,1,1);
	do {
		cout << "Verification du prisme #" << i << endl;
		if (prismes.isEmpty()==true) {
			cout << "Le prisme avec le profil demande n'existe pas"<<endl;
			boucle = false;
		}
		else {
			Maximum = prismes.findMax();
			if (Maximum.getLargeur() >= prismeRecherche.getLargeur() && Maximum.getLongueur() >= prismeRecherche.getLongueur() && Maximum.getProfondeur() >= prismeRecherche.getProfondeur()) {
				cout <<endl<< "Voici le meilleur prisme trouve" << endl;
				cout << Maximum;
				boucle = false;
			}
			else {
				prismes.remove(Maximum);
			}
		}
		i++;
	} while (boucle);
}

/* 
	A FAIRE :	Recherche d'un prisme par VOLUME
				Attention de valider les valeurs possibles de la recherche!!!
*/
void rechercherPrisme(BinarySearchTree<Prisme>& prismes)
{
	int choix;
	cout << "Entrer un volume a rechercher (valeur positive) : ";
	cin >> choix;
	if (choix < 0) {
		choix = choix * -1;
		cout << "Volume invalide. Valeur positive seulement : " << choix << endl;
	}
	Prisme Recherche("Recherche",choix,1,1);
	if (prismes.contains(Recherche)) {
		cout << "Ce profil existe bien"<<endl;
	}
	else {
		cout <<"Un prisme avec le profil n'existe pas"<<endl;
	}
}

// Celle la est complete!
Prisme creerRecherche()
{
	Prisme p("RECHERCHE", 0, 0, 0);
	int valeur;

	cout << "Entrer vos critères de recherche  (0 = aucun)" << endl;
	cout << "  Entrer la largeur minimum : ";
	cin >> valeur;
	p.setLargeur(valeur);

	cout << "  Entrer la longueur minimum : ";
	cin >> valeur;
	p.setLongueur(valeur);

	cout << "  Entrer la profondeur minimum : ";
	cin >> valeur;
	p.setProfondeur(valeur);

	return p;
}
