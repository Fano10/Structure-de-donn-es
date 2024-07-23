/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:18-10-2022
// Description:Cette programme permet de mesurer la performance de chaque trie
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<algorithm>
#include <chrono>
#include "algorithme.cpp"
using namespace std;

/////////////////////////////////////////// Signature des fonctions
template<class T>
void TableauNonTrie(T* , int);
template<class T>
void TableauTrieDecroissant(T*, int);
template<class T>
void CopieTableau(T*, T*, int);
template<class T>
void Chronometre(T*, int);
template<class T>
void Execution(T*, int*);
////////////////////////////////////////////////////////

int main(void) {
	//Declaration de mes tableau
	int Tab[2000];
	int taille [] = {5,10,15,20,25,30,50,100,1000};
	///////////////////////////////Appel de fonction
	Execution(Tab, taille);
	return 0;
}


template<class T>
void TableauNonTrie(T* Tab, int N) {

	for (int i = 0; i < N; i++) {
		Tab[i] = rand();
	}
	
}


template<class T>
void TableauTrieDecroissant(T* Tab, int N) {
	triBullesInverser(Tab, N);
}

template<class T>
void CopieTableau(T* Tab, T* TabIntermediaire, int N) {
	for (int i = 0; i < N; i++) {
		Tab[i] = TabIntermediaire[i];
	}
}

template<class T>
void Chronometre(T* Tab, int N) {
	T TabIntermediaire[3000];
	CopieTableau(TabIntermediaire, Tab, N);
	int duree=15;
	for (int i = 0; i < 6; i++) {
		switch (i)
		{
		case 0:
			cout << "    Trie a bulle: ";
			duree = triBulles(Tab, N);
			break;
		case 1:
			cout << "    Trie par selection: ";
			duree = triSelection(Tab, N);
			break;
		case 2:
			cout << "    Trie par insertion: ";
			duree = triInsertion(Tab, N);
			break;
		case 3:
			cout << "    Trie par fusion: ";
			duree = triFusionne(Tab,N);
			break;
		case 4:
			cout << "    Trie par segmentation: ";
			duree = triSegmentation(Tab, N);
			break;
		case 5:
			cout << "    Trie par sort: ";
			duree = TrieSort(Tab, N);
			break;
		}
		cout << duree << " nanosecondes"<<endl;
		if (i != 5) {
			CopieTableau(Tab, TabIntermediaire, N);
		}
	}
}

template<class T>
void Execution(T* Tab, int* taille) {
	for (int i = 0; i < 9; i++) {
		cout << "Temps d'execution du tableau a taille " << taille[i] << " non trier:" << endl;
		TableauNonTrie(Tab, taille[i]);
		Chronometre(Tab, taille[i]);
		cout <<endl<< "Temps d'execution du tableau a taille " << taille[i] << " trier croissant:" << endl;
		Chronometre(Tab, taille[i]);
		cout <<endl<< "Temps d'execution du tableau a taille " << taille[i] << " trier decroissant:" << endl;
		TableauTrieDecroissant(Tab, taille[i]);
		Chronometre(Tab, taille[i]);
		cout << endl << endl<<endl;
	}
}

