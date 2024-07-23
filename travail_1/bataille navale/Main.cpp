		/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:
// Auteur:Rakotondrabe Miora Fanomezana
// Date:09-11-2022
// Description:Cette programme simule un jeu de bataille navale simplifié
////////////////////////////////////////////////////////////////////////////////////////////

		/*Partie inclusion*/
#include<iostream>//pour l'utilisation de cin et de cout
#include<iomanip>//pour la manipulation de la sortie d'affichage
#include"hasard.h"//Pour le nombre aleatoire
#include"fonction.h"//pour les fonctions
using namespace std;



int main(void) {
	setlocale(LC_CTYPE, "fr-FR");//mettre en francais
	//declaration des variables

	const int X = 5;
	const int Y = 5;
	int BateauOrdiX[3];
	int BateauOrdiY[3];
	int BateauJoueurX[3];
	int BateauJoueurY[3];

	int TabJoueur[Y][X];
	int TabOrdi[Y][X];
	int ChoixJoueurX;
	int ChoixJoueurY;


	int ChoixOrdiX;
	int ChoixOrdiY;
	int BoucleJoueur = 0;
	int BoucleOrdi = 0;
	int Tour = 0;
	//--------------------------------------------------------------------
	initialize();
	EmplacementBateau(BateauOrdiX,BateauOrdiY,BateauJoueurX,BateauJoueurY);
	RemplirTableau(TabJoueur, TabOrdi);
	InstallerBateau(TabJoueur, TabOrdi,BateauOrdiX,BateauOrdiY,BateauJoueurX,BateauJoueurY);
	AfficherInstruction();
	do {
		AfficherTerrain(TabJoueur, TabOrdi);
		if (Tour % 2 == 0) {
			DemanderChoixJoueur(ChoixJoueurX, ChoixJoueurY);
			EtatDuTireJoueur(ChoixJoueurX, ChoixJoueurY, TabOrdi,BateauOrdiX,BateauOrdiY, BoucleJoueur);
		}
		else {
			cout << "----TOUR DE L' ORDINATEUR\n";
			ChoixOrdiX = recupererValeurAleatoire(0, 4);
			ChoixOrdiY = recupererValeurAleatoire(0, 4);
			EtatDuTireOrdi(ChoixOrdiX, ChoixJoueurY, TabJoueur,BateauOrdiX,BateauJoueurY ,BoucleOrdi);
		}
		Tour = Tour + 1;
	} while (BoucleJoueur < 3&& BoucleOrdi<3);
	cout << "------FIN DE LA PARTIE---------------\n";
	Victoire(BoucleJoueur, TabJoueur, TabOrdi);
	return 0;;
}