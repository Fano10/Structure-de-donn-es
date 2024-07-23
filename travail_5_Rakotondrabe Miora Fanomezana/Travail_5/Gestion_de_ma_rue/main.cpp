/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:10-10-2022
// Description:Cette programme est une simulation de gestion d'une rue avec adresse
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
using namespace std;

void initialise(list<int> &Liste);
void Afficher(list<int>Liste, list<int>::iterator it );
int DemanderCivique(void);
bool Rechercher(list<int>Liste, list<int>::iterator it,int Civique);
void Ajouter(list<int>& Liste, list<int>::iterator it);
void Supprimer(list<int>& Liste, list<int>::iterator it);
void ResultatRecheche(list<int>& Liste, list<int>::iterator it);
bool Programme(list<int>& Liste, list<int>::iterator it);
int main(void) {

	list<int> Liste;
	list<int>::iterator it;
	bool Boucle = true;
	initialise(Liste);
	while (Boucle == true) {
		Boucle = Programme(Liste, it);
	}
	return 0;
}

void initialise(list<int> &Liste) {
	Liste.push_back(401);
	Liste.push_back(402);
	Liste.push_back(403);
	Liste.push_back(405);
	Liste.push_back(406);
}

void Afficher(list<int>Liste, list<int>::iterator it) {
	cout << "Voici la rue(" << Liste.size() <<" maisons)\n";
	for (it = Liste.begin(); it != Liste.end(); it++) {
		cout << "  " << *(it);
	}
	cout << endl;
}
int DemanderCivique(void) {
	int Civique;
	cout << "Quelle est le # civique de la maison?(entre 400 et 600)";
	cin >> Civique;
	if (Civique > 600 || Civique < 400) {
		Civique=DemanderCivique();
	}
	return Civique;
}

bool Rechercher(list<int>Liste, list<int>::iterator it , int Civique) {
	bool Trouver = false;
	it = Liste.begin();
	while (it != Liste.end() && Trouver == false) {
		if (*it == Civique) {
			Trouver = true;
		}
		it++;
	}
	return Trouver;
}

void Ajouter(list<int>& Liste, list<int>::iterator it) {
	int Civique = DemanderCivique();
	bool Verification = Rechercher(Liste, it, Civique);
	if (Verification == false) {
		it = Liste.begin();
		while(it!= Liste.end() && Verification == false) {
			if (Civique < *it) {
				Liste.insert(it, Civique);
				Verification = true;
			}
			it++;
		}
		Verification = Rechercher(Liste, it, Civique);
		if (Verification == false) {
			Liste.push_back(Civique);
		}
		cout << "La maison " << Civique << " a ete ajoutee.\n";
	}
	else {
		cout << "La maison " << Civique << " existe deja.\n";
	}
	

}

void Supprimer(list<int>& Liste, list<int>::iterator it) {
	int Civique = DemanderCivique();
	bool Verification = Rechercher(Liste, it, Civique);
	if (Verification == true) {
		it = Liste.begin();
		while(it != Liste.end()) {
			if (Civique == *it) {
				Liste.erase(it);
				break;
			}
			else {
				it++;
			}
		}
		cout << "La maison " << Civique << " a ete supprimee.\n";
	}
	else {
		cout << "La maison " << Civique << " n'existe pas dans la rue.\n";
	}
}
void ResultatRecheche(list<int>& Liste, list<int>::iterator it) {
	int Civique = DemanderCivique();
	bool Verification = Rechercher(Liste, it, Civique);
	if (Verification == true) {
		cout << "La maison " << Civique << " existe dans la rue.\n";
	}
	else {
		cout << "La maison " << Civique << " n'existe pas dans la rue.\n";
	}
}

bool Programme(list<int>& Liste, list<int>::iterator it) {
	bool Reponse = true;
	int Choix;
	cout << "\n--------------------------------------------------\n";
	cout << "\n (0)Afficher la rue";
	cout << "\n (1)Ajouter une maison";
	cout << "\n (2)Supprimer une maison";
	cout << "\n (3)Rechercher une maison";
	cout << "\n (4)Quitter la rue une maison\n";
	cout << "\n--------------------------------------------------\n";
	cout << "Votre choix : ";
	cin >> Choix;
	cout << "--------------------------------------------------\n";
	switch (Choix)
	{
		case 0 :
			Afficher(Liste, it);
			break;
		case 1 :
			Ajouter(Liste, it);
			break;
		case 2:
			Supprimer(Liste, it);
			break;
		case 3:
			ResultatRecheche(Liste, it);
			break;
		default:
			Reponse = false;
	}
	return Reponse;
}