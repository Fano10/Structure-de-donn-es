#ifndef PRISME_H
#define PRISME_H

#include <iostream>
#include <string>
using namespace std;

class Prisme
{
public:
	Prisme(string noPrisme, int larg, int lon, int prof);// Constructeur
	~Prisme();//destructeur

	// Accesseurs
	string getNoPrisme() const {return noPrisme;} //obtenir numero du prisme
	int getLargeur() const {return largeur;}//obtenir largeur du prisme
	int getLongueur() const {return longueur;}//obtenir longeur du prisme
	int getProfondeur() const {return profondeur;}//obtenir profondeur du prisme
	void setLargeur(int la) {largeur = la;} // modifier largeur du prisme
	void setLongueur(int lo) {longueur = lo;}// modifier longeur du prisme
	void setProfondeur(int pr) {profondeur = pr;} // modifier profondeur du prisme

	// Surcharge des opérateurs
	bool operator<(const Prisme& prisme) const;
	bool operator<=(const Prisme& prisme) const;
	bool operator==(const Prisme& prisme) const;
	bool operator>=(const Prisme& prisme) const;
	bool operator>(const Prisme& prisme) const;
	bool operator!=(const Prisme& prisme) const;

	friend ostream &operator<< (ostream& out, const Prisme& prisme);
	Prisme& operator=(const Prisme& prisme);

private:

	int getVolume() const; // obtenir la volume du prisme

	string noPrisme;
	int largeur;
	int longueur;
	int profondeur;
};

#endif
