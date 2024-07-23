#include<iostream>
#include<queue>
using namespace std;

class Carte
{
private:
	int** Matrice;
	int nombreSommet;


public:
	Carte(int n) {
		nombreSommet = n;
		Matrice = new int* [nombreSommet];
		for (int i = 0; i < nombreSommet; i++) {
			Matrice[i] = new int[nombreSommet];
		}
	}
	void CompleterMatrice(void) {
		for (int i = 0; i < nombreSommet; i++) {
			for (int a = 0; a < nombreSommet; a++) {
				Matrice[i][a] = 0;
			}
		}
	}
	void ModifierMatrice(int ligne, int colonne, int valeur) {
		Matrice[ligne][colonne] = valeur;
	}
	int ** getMatrice() {
		return Matrice;
	}
	friend ostream& operator<< (ostream& out, const Carte& matrice) {
		out << "-----------------------------------------------------------------------------------------------------------------" << endl;
		out << "\t";//5 espaces
		char alphabet;
		for (int i = 0; i < matrice.nombreSommet; i++) {
			alphabet = i + 65;	
			out << alphabet << "\t";
		}
		out << endl << endl;
		for (int i = 0; i < matrice.nombreSommet; i++) {
			alphabet = i + 65;
				out << alphabet << "\t";
			for (int a = 0; a < matrice.nombreSommet; a++) {
				out << matrice.Matrice[i][a] << "\t";
			}
			out << endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------" << endl;
		return out;
	}
};