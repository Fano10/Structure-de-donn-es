/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:30-11-2022
// Description:Cette programme permet de gerer une prisme a l'aide d'un arbre balancee
////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "arbreBST.cpp"
using namespace std;
void chargerArbre(BinarySearchTree<int>& arbreAVL);
int main(int argc, char* argv[])
{
	BinarySearchTree<int> arbreAVL;
	chargerArbre(arbreAVL);
	cout << arbreAVL;
	system("PAUSE");
	return EXIT_SUCCESS;
}
void chargerArbre(BinarySearchTree<int>& arbreAVL)
{
	int valeurs[] = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9 };
	int nbValeurs = sizeof valeurs / sizeof * valeurs;
	for (int x = 0; x < nbValeurs; x++)
		arbreAVL.insert(valeurs[x]);
}

