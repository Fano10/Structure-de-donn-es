#include<iostream>
#include<queue>
using namespace std;

class Dijkstra
{
private:
	int** matrice;
	int nombreCote;
	int depart;
	int arriver;
	int**tabInformation;
	enum type_couleur {rouge,blanc};

	bool CheckCarte(void) {
		bool reponse = false;
		for (int i = 0; i < nombreCote; i++) {
			if (tabInformation[2][i] == blanc){
				reponse = true;
			}
		}
		return reponse;
	}
	void remplirVoisin(int SommetActuel, queue<int>& voisin) {
		for (int i = 0; i < nombreCote; i++) {
			if (matrice[SommetActuel][i] != 0) {
				if (tabInformation[2][i] == blanc) {
					voisin.push(i);
				}
			}
		}
	}
	void Relache(int SommetActuel, int voisin) {
		if (tabInformation[0][voisin] > tabInformation[0][SommetActuel] + matrice[SommetActuel][voisin]) {
			tabInformation[0][voisin] = tabInformation[0][SommetActuel] + matrice[SommetActuel][voisin];
			tabInformation[1][voisin] = SommetActuel;
		}
	}
	int ExtraireMin() {
		int valeur = 100000;
		int reponse = 100;
		for (int i = 0; i < nombreCote; i++) {
			if (tabInformation[0][i] < valeur && tabInformation[2][i] == blanc) {
				valeur = tabInformation[0][i];
				reponse = i;
			}
		}
		return reponse;
	}

public:
	Dijkstra(int** carte, int nb, int dp, int arr) {
		matrice = carte;
		nombreCote = nb;
		depart = dp;
		arriver = arr;
		tabInformation = new int* [nombreCote];
		for (int i = 0; i < 3; i++)
		{
			tabInformation[i] = new int[nombreCote];
		}
		for (int i = 0; i < nombreCote; i++)//distance
		{
			tabInformation[0][i] = 10000;
		}
		for (int i = 0; i < nombreCote; i++)//parent
		{
			tabInformation[1][i] = -1;
		}
		for (int i = 0; i < nombreCote; i++)//couleur
		{
			tabInformation[2][i] = blanc;
		}
	}

	friend ostream& operator<< (ostream& out, const Dijkstra & dijkstra) {

		char alphabet;
		out << "Les destinations a parcourir entre ";
		alphabet = dijkstra.depart + 65;
		out << alphabet << " et ";
		alphabet = dijkstra.arriver + 65;
		out << alphabet << " : { ";
		int iterateur = dijkstra.arriver;
		do {
			alphabet = iterateur + 65;
			out << alphabet << " ";
			iterateur = dijkstra.tabInformation[1][iterateur];

		} while (iterateur != -1);
		out << " } " << endl;
		out << endl<<"Les distances:\n";
		for (int i = 0; i < dijkstra.nombreCote; i++) {
			alphabet = i + 65;
			out << alphabet << " : "<<dijkstra.tabInformation[0][i]<<endl;
		}
		return out;

	}

	void Parcourir() {
		char alphabet;
		tabInformation[0][depart] = 0;//distance =0 pour le point de depart
		int SommetActuel;
		SommetActuel = depart;
		queue<int> voisin;
		while (CheckCarte()) {
			alphabet = SommetActuel + 65;
			remplirVoisin(SommetActuel, voisin);
			while (voisin.size() > 0) {
				alphabet = voisin.front() + 65;
				Relache(SommetActuel, voisin.front());//relacher
				voisin.pop();
			}
			tabInformation[2][SommetActuel] = rouge;
			SommetActuel = ExtraireMin(); //Extraire Min
		}
	}
};