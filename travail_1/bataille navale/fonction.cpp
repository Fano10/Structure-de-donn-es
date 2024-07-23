#include"fonction.h"

void EmplacementBateau(int BateauOrdiX[3], int BateauOrdiY[3], int BateauJoueurX[3], int BateauJoueurY[3]) {
	initialize();
	for (int i = 0; i < 3; i++) {
		BateauJoueurX[i] = recupererValeurAleatoire(0, 4);
		BateauJoueurY[i] = recupererValeurAleatoire(0, 4);
		BateauOrdiX[i] = recupererValeurAleatoire(0, 4);
		BateauOrdiY[i] = recupererValeurAleatoire(0, 4);
		if (i == 1 && BateauOrdiX[i - 1] == BateauOrdiX[i] && BateauOrdiY[i - 1] == BateauOrdiY[i]) {
			do {
				BateauOrdiX[i] = recupererValeurAleatoire(0, 4);
				BateauOrdiY[i] = recupererValeurAleatoire(0, 4);
			} while (BateauOrdiX[i - 1] == BateauOrdiX[i] && BateauOrdiY[i - 1] == BateauOrdiY[i]);
		}
	}
}

void AfficherInstruction(void) {
	cout << "---Début de la partie\n";
	cout << "LEGENDE:  INCONNU : 0\n";
	cout << setw(13) << "EAU" << setw(9) << " : 8\n";
	cout << setw(16) << "BATEAU" << setw(6) << " : 9\n";
	cout << setw(15) << "COULE" << setw(7) << " : 1\n";
}

void AfficherTerrain(int TabJoueur[5][5], int TabOrdi[5][5]) {
	cout << setw(13) << "Ordinateur" << setw(10) << "Joueur\n";
	cout << setw(12) << "0 1 2 3 4" << setw(14) << "0 1 2 3 4\n" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i << setw(3);
		for (int a = 0; a < 5; a++) {
			cout << TabOrdi[i][a] << " ";
		}
		cout << setw(4);
		for (int a = 0; a < 5; a++) {
			cout << TabJoueur[i][a] << " ";
			if (a == 4) {
				cout << endl;
			}
		}
	}

}
void RemplirTableau(int TabJoueur[5][5], int TabOrdi[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int a = 0; a < 5; a++) {
			TabJoueur[i][a] = 0;
			TabOrdi[i][a] = 0;
		}
	}
}
void InstallerBateau(int TabJoueur[5][5], int TabOrdi[5][5],int BateauOrdiX[3], int BateauOrdiY[3],int BateauJoueurX[3], int BateauJoueurY[3]) {
	for (int i = 0; i < 3; i++) {
		TabJoueur[BateauJoueurY[i]][BateauJoueurX[i]] = 9;
		TabOrdi[BateauOrdiY[i]][BateauOrdiX[i]] = 9;
	}
}
void  DemanderChoixJoueur(int& cordX, int& cordY) {
	cout << "----TOUR DU JOUEUR\n";
	cout << "Entrer une coordonnee valide pour x :";
	cin >> cordX;
	cout << "Entrer une coordonnee valide pour y :";
	cin >> cordY;
}
void EtatDuTireJoueur(int cordX, int cordY, int TabOrdi[5][5], int BateauOrdiX[3], int BateauOrdiY[3], int& Boucle) {
	int Verification = 0;
	for (int i = 0; i < 3; i++) {
		if (BateauOrdiX[i] == cordX && BateauOrdiY[i] == cordY) {
			TabOrdi[cordY][cordX] = 1;
			Verification = 1;
			Boucle = Boucle + 1;
			cout << "BATEAU COULE a " << cordX << "-" << cordY << endl;
		}
	}
	if (Verification == 0) {
		TabOrdi[cordY][cordX] = 8;
		cout << "TIR A L'EAU a " << cordX << "-" << cordY << endl;
	}
}
void EtatDuTireOrdi(int cordX, int cordY, int TabJoueur[5][5], int BateauJoueurX[3], int BateauJoueurY[3], int& Boucle) {
	int Verification = 0;
	for (int i = 0; i < 3; i++) {
		if (BateauJoueurX[i] == cordX && BateauJoueurY[i] == cordY) {
			TabJoueur[cordY][cordX] = 1;
			Verification = 1;
			Boucle = Boucle + 1;
			cout << "BATEAU COULE a " << cordX << "-" << cordY << endl;
		}
	}
	if (Verification == 0) {
		TabJoueur[cordY][cordX] = 8;
		cout << "TIR A L'EAU a " << cordX << "-" << cordY << endl;
	}
}
void Victoire(int BoucleJoueur, int TabJoueur[5][5], int TabOrdi[5][5]) {
	AfficherTerrain(TabJoueur, TabOrdi);
	if (BoucleJoueur == 3) {
		cout << "Felicitation, vous avez gagné";
	}
	else {
		cout << "Ordinateur a gagné";
	}
}