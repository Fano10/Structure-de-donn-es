#include "TableHachage.h"

TableHachage::TableHachage(int m)
{
	this->m = m;					// La taille du tableau
	T = new list<Couple>[m];		// Le tableau de Couple (taille m)
}

TableHachage::~TableHachage()
{
	delete[] T;						// On efface le tableau lors de la destruction de la table de hachage 
	// pour éviter une fuite de mémoire  
	// (Rappel : Si on utilise un pointeur  (new) alors il faut un delete)
}

// Ajout trié dans la liste
void TableHachage::ajouter(int cle, int valeur)
{
	int position = hachage(cle);
	Couple value(cle, valeur);
	list<Couple>::iterator it;
	it = T[position].begin();
	for (it; it != T[position].end(); it++) {
		if (value == *it) {
			return;
		}
		if (*it > value) {
			T[position].insert(it, value);
			return;
		}
	}
	T[position].push_back(value);

}

bool TableHachage::supprimer(int cle)
{
	int position = hachage(cle);
	Couple value(cle, 0);
	list<Couple>::iterator it;
	it = T[position].begin();
	for (it; it != T[position].end(); it++) {
		if (*it == value) {
			T[position].erase(it);
			return true;
		}
	}
	return false;
}

int TableHachage::rechercher(int cle)
{
	int position = hachage(cle);
	Couple value(cle, 0);
	list<Couple>::iterator it;
	it = T[position].begin();
	for (it; it != T[position].end(); it++) {
		if (*it == value) {
			return it->getValeur();
		}
	}
	return -1;
}

int TableHachage::hachage(int cle)
{

	return (cle % m);

}

ostream& operator<< (ostream& out, const TableHachage& tableHachage)
{
	list<Couple>::iterator itCouple;

	out << "----------------------" << endl;
	out << "T[], \t(CLE, \tVALEUR)" << endl;
	for (int x = 0; x < tableHachage.m; x++)
		for (itCouple = tableHachage.T[x].begin(); itCouple != tableHachage.T[x].end(); itCouple++)
		{
			out << x << "\t" << (*itCouple);
			out << endl;
		}
	out << "----------------------" << endl;

	return out;
}