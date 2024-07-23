#pragma once
#include<iostream>
#include<iomanip>
#include"hasard.h"
using namespace std;


void EmplacementBateau(int BateauOrdiX[3], int BateauOrdiY[3], int BateauJoueurX[3], int BateauJoueurY[3]);
void RemplirTableau(int TabJoueur[5][5], int TabOrdi[5][5]);
void InstallerBateau(int TabJoueur[5][5], int TabOrdi[5][5], int BateauOrdiX[3], int BateauOrdiY[3], int BateauJoueurX[3], int BateauJoueurY[3]);
void AfficherInstruction(void);
void AfficherTerrain(int TabJoueur[5][5], int TabOrdi[5][5]);
void  DemanderChoixJoueur(int& cordX, int& cordY);
void EtatDuTireJoueur(int cordX, int cordY, int TabOrdi[5][5], int BateauOrdiX[3], int BateauOrdiY[3], int& Boucle);
void EtatDuTireOrdi(int cordX, int cordY, int TabJoueur[5][5], int BateauJoueurX[3], int BateauJoueurY[3], int& Boucle);
void Victoire(int BoucleJoueur, int TabJoueur[5][5], int TabOrdi[5][5]);