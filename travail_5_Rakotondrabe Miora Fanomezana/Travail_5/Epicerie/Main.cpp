/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:Main.cpp
// Auteur:Rakotondrabe Miora Fanomezana
// Date:10-10-2022
// Description:Cette programme est une simulation de gestion d'achat
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
#include"Article.h"
using namespace std;


void AjouterArticle(list<Article>&, Article);
void AfficherFacture(list<Article>);

int main(void) {

	list<Article> Epicerie;
	Article mesArticles[] = {
		Article("Banane",10,12),
		Article("Fraise",25,10),
		Article("Mangue",5,30),
		Article("Letchis",10,30),
		Article("Pomme ",7,12),
		Article("Oeuf  ",10,15),
		Article("Patate",2,3)
	};
	for (Article article : mesArticles) {
		AjouterArticle(Epicerie, article);
	}
	AfficherFacture(Epicerie);
	return 0;
}

void AjouterArticle(list<Article> &ListeArticle, Article UnArticle) {

	list<Article>::iterator it;
	int PrixUnArticle;
	int PrixListe;
	bool InsertionBack;

	if (ListeArticle.size() == 0) {
		ListeArticle.push_back(UnArticle);
	}
	else {
		it = ListeArticle.begin();
		PrixUnArticle = (UnArticle.getMontant() * UnArticle.getQuantite());
		InsertionBack = true;
		while (it != ListeArticle.end()) {
			PrixListe = it->getMontant() * it->getQuantite();
			if (PrixUnArticle <= PrixListe) {
				ListeArticle.insert(it, UnArticle);
				InsertionBack = false;
				break;
			}
			else {
				it++;
			}
		}
		if (InsertionBack == true) {
			ListeArticle.push_back(UnArticle);
		}
	}
}

void AfficherFacture(list<Article> ListeArticle) {
	list<Article>::iterator it;
	int Total = 0;
	cout << "  NOM        MONTANT  QUANTITE  SOUS-TOTAL\n";
	it = ListeArticle.begin();
	while (it != ListeArticle.end()) {
		cout << *it << endl;
		Total = Total + (it->getMontant() * it ->getQuantite());
		it++;
	}
	cout << "  TOTAL-------------------------"<< Total ;
}