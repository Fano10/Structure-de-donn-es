/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:18-10-2022
// Description:Cette programme est une simulation du jeu Lemming
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include"Hasard.h"
#include"Lemming.h"
using namespace std;


void definirAttroupement(list<Lemming>& , int );
void AfficherLemmingListe(list<Lemming>);
void AvancerPassage(queue<Lemming>&, list<Lemming>);
void AfficherLemmingFile(queue<Lemming>);
vector<Lemming> GlisserPente(queue<Lemming>&, queue<Lemming>);
void AfficherLemmingGlisserPente(queue<Lemming> , vector<Lemming>);
void Echelle(queue<Lemming>, list<Lemming>&, stack<Lemming>&);
bool VerificationVecteurUnique(vector<int> , int);
void TrierVecteur(vector<int>&);
vector<Lemming> Sprint(list<Lemming>, queue<Lemming>&);
void AfficherLemmingSprint(queue<Lemming> , vector<Lemming>);
void Liberte(queue<Lemming>, queue<Lemming>&, list<Lemming>&);
void AfficherLemmingLiberte(queue<Lemming> , list<Lemming>);

int main(void) {
	//Etape 1 : l´attroupement :
	list<Lemming> LemmingAttroupement;
	cout << "ETAPE #1 : L´attroupement\n";
	definirAttroupement(LemmingAttroupement, 20);
	AfficherLemmingListe(LemmingAttroupement);

	//Etape 2 : Le passage sombre :
	queue<Lemming> LemmingPassageSombre;
	cout << "\nETAPE #2 : Le passage sombre\n";
	AvancerPassage(LemmingPassageSombre, LemmingAttroupement);
	AfficherLemmingFile(LemmingPassageSombre);

	//Etape 3 : La pente : 
	queue<Lemming> LemmingPente;
	cout << "\nETAPE #3 : La pente\n";
	vector<Lemming> MourirPente = GlisserPente(LemmingPente, LemmingPassageSombre);
	AfficherLemmingGlisserPente(LemmingPente, MourirPente);

	//Etape 4 : L echelle : 
	list<Lemming> ListeLemmingEchelle;
	stack<Lemming> PileLemmingEchelle;
	cout << "\nETAPE #4 : L echelle\n";
	Echelle(LemmingPente, ListeLemmingEchelle, PileLemmingEchelle);
	AfficherLemmingListe(ListeLemmingEchelle);

	// Etape 5 : Le sprint : 
	queue<Lemming> LemmingSprint;
	cout << "\nETAPE #5 : Le sprint\n";
	vector<Lemming> MourirSprint = Sprint(ListeLemmingEchelle, LemmingSprint);
	AfficherLemmingSprint(LemmingSprint , MourirSprint);

	// Etape 6 : Liberte : 
	queue<Lemming> LemmingLiberte;
	list<Lemming> LemmingDisparue;
	cout << "\nETAPE #6: La liberte\n";
	Liberte(LemmingSprint, LemmingLiberte, LemmingDisparue);
	AfficherLemmingLiberte(LemmingLiberte, LemmingDisparue);
	return 0;
}

void definirAttroupement(list<Lemming>& LemmingAttroupement , int Nb){

	for (int i = 0; i < Nb; i++) {
		LemmingAttroupement.push_back(Lemming());
	}
}

void AfficherLemmingListe(list<Lemming> ListeLemming) {
	list<Lemming>::iterator It;
	cout << "LISTE(" << ListeLemming.size() << ") : ";
	for(It = ListeLemming.begin(); It != ListeLemming.end() ; It++){
		cout << *It <<" <- ";
	}
	cout << endl <<endl;
}

void AvancerPassage(queue<Lemming>& LemmingPassageSombre, list<Lemming> LemmingAttroupement) {

	list<Lemming>::iterator It;
	for (It = LemmingAttroupement.begin(); It != LemmingAttroupement.end(); It++ ) {
		LemmingPassageSombre.push(*It);
	}
}void AfficherLemmingFile(queue<Lemming> FileLemming) {
	cout << "FILE(" << FileLemming.size() << ") : ";
	cout << FileLemming.front() << " <-- " << FileLemming.back();
	cout << endl <<endl;
}

vector<Lemming>GlisserPente(queue<Lemming>&LemmingPente, queue<Lemming> LemmingPassageSombre) {
	initialize();
	vector<Lemming> Mourir;
	bool Continuer;
	int Hasard[5];
	for (int i = 0; i < 5; i++) {
		Hasard[i] = recupererValeurAleatoire(1, 99); //Pour le 5 % de chance de mourir
	}
	int taille = LemmingPassageSombre.size();
	for (int i = 0; i < taille; i++) {
		Continuer = true;
		for (int i = 0; i < 5; i++) {
			if(Hasard[i] == LemmingPassageSombre.front().getId()){
				Mourir.push_back(LemmingPassageSombre.front()); // mettre dans un vecteur les lemmings qui n'ont pas survecu
				LemmingPassageSombre.pop();
				Continuer = false;
				break;
			}
		}
		if (Continuer == true) {
			LemmingPente.push(LemmingPassageSombre.front());
			LemmingPassageSombre.pop();
		}
	}
	return Mourir;

}

void AfficherLemmingGlisserPente(queue<Lemming> LemmingPente, vector<Lemming> Mourir) {
	if (Mourir.size() != 0) {
		for (int i = 0; i < Mourir.size(); i++) {
			cout << "Le lemming ";
			cout << Mourir[i].getId() << " ";
			cout << "glisse et meurt\n";
		}
	}
	else {
		cout << "Tous les Lemmings ont survecu\n";
	}
	AfficherLemmingFile(LemmingPente);

}

void Echelle(queue<Lemming> LemmingPente, list<Lemming>& ListeLemmingEchelle, stack<Lemming>& PileLemmingEchelle) {

	for (int i = 0; i < 10; i++) {
		PileLemmingEchelle.push(LemmingPente.front()); // Les 10 Lemmings qui font l'échelle
		LemmingPente.pop();
	}
	int Taille = LemmingPente.size();
	for (int i = 0; i < Taille; i++) {
		ListeLemmingEchelle.push_back(LemmingPente.front()); // Les restes de Lemmings qui montent sur l'échelle
		LemmingPente.pop();
	}
	for (int i = 0; i < 10; i++) {
		ListeLemmingEchelle.push_back(PileLemmingEchelle.top()); // On tire les 10 Lemmings qui ont fait l'échelle par une corde
		PileLemmingEchelle.pop();
	}

}

bool VerificationVecteurUnique(vector<int> Indice, int Hasard) {
	int Taille = Indice.size();
	bool Verifier = true;
	if (Taille > 0) {
		for (int i = 0; i < Taille; i++) {
			if (Hasard == Indice[i]) {
				Verifier = false;
			}
		}
	}
	return Verifier;
}
void TrierVecteur(vector<int>& Indice) {
	int intermediaire;
	int Taille = Indice.size();
	for (int i = 0; i < Taille; i++) {
		for (int a = i + 1; a < Taille; a++) {
			if (Indice[i] > Indice[a]) {
				intermediaire = Indice[i];
				Indice[i] = Indice[a];
				Indice[a] = intermediaire;
			}
		}
	}
}
vector<Lemming> Sprint(list<Lemming> ListeLemmingEchelle, queue<Lemming>& LemmingSprint) {
	int IndiceVecteur = 0;
	int Hasard;
	bool Verifier;
	int boucle = 0;
	int DecisionFinale;
	vector <int> Indice;
	vector <Lemming> Mourir;
	list<Lemming> ::iterator It;
	initialize();
	while (boucle < 5){
		Hasard = recupererValeurAleatoire(0, (ListeLemmingEchelle.size()-1));
		Verifier = VerificationVecteurUnique(Indice, Hasard); // Assurer que les nombres dans le vecteurs ne se répètent pas
		if (Verifier == true) {
			Indice.push_back(Hasard);                         //Mettre les indice(c'est la position du Lemming dans la liste depuis le front de la liste) 
			boucle = boucle + 1;							  //des 5 Lemmings choisis aux Hasards dans un vecteur						
		}
	}
	TrierVecteur(Indice);// Trier les indices des 5 lemmings en ordre croissant
	boucle = 0;
	for (It = ListeLemmingEchelle.begin(); It != ListeLemmingEchelle.end(); It++) { // Mettre les Lemmings survivants dans une file 
		if (IndiceVecteur < Indice.size() && boucle == Indice[IndiceVecteur]) {
			DecisionFinale = recupererValeurAleatoire(0, 1);
			if (DecisionFinale == 0) { // Le Lemming choisit par hasad sera vivant
				LemmingSprint.push(*It);
			}
			else {						//Sinon 
				Mourir.push_back(*It);
			}
			IndiceVecteur = IndiceVecteur + 1;
		}
		else {
			LemmingSprint.push(*It);
		}
		boucle = boucle + 1;
	}
	return Mourir;
}

void AfficherLemmingSprint(queue<Lemming> LemmingSprinte, vector<Lemming> Mourir) {
	if (Mourir.size() != 0) {
		for (int i = 0; i < Mourir.size(); i++) {
			cout << "Le lemming ";
			cout << Mourir[i].getId();
			cout << " est victime du piege! \n";
		}
	}
	else {
		cout << "Tous les Lemmings restants ont survecu\n";
	}
	AfficherLemmingFile(LemmingSprinte);
}

void Liberte(queue<Lemming>Lemmingsprint, queue<Lemming>& LemmingLiberte, list<Lemming>& LemmingDisparu) {
	initialize();
	vector<int> Mourir;
	bool Verification;
	int Taille = Lemmingsprint.size();
	for (int i = 0; i < Taille; i++) {
		Verification = true;
		Mourir.clear();
		for (int i = 0; i < 20; i++) { // 20% de mourir pour chaque Lemming
			Mourir.push_back(recupererValeurAleatoire(0, 99)); 
		}
		for (int i = 0; i < 20; i++) {
			if (Lemmingsprint.front().getId() == Mourir[i]) { //Les Lemming qui tombent dans la dosse sans fond
				LemmingDisparu.push_back(Lemmingsprint.front());
				Verification = false;
				Lemmingsprint.pop();
				break;
			}
		}
		if (Verification == true) {
			LemmingLiberte.push(Lemmingsprint.front()); // Les Lemmings qui sont liberés
			Lemmingsprint.pop();
		}

	}
}

void AfficherLemmingLiberte(queue<Lemming> LemmingLiberte, list<Lemming> LemmingDisparu) {
	if (LemmingDisparu.size() != 0) {
		list<Lemming>::iterator It;
		for (It = LemmingDisparu.begin(); It != LemmingDisparu.end(); It++) {
			cout << "Le lemming ";
			cout << It->getId() ;
			cout << " echappe la liane et tombe dans la dosse sans fond\n";
		}
		AfficherLemmingListe(LemmingDisparu);
		cout << endl;
	}
	else {
		cout << "Tous les Lemmings restants sont libres\n";
	}
	AfficherLemmingFile(LemmingLiberte);
}