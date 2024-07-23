/*En tête du programme*/
/////////////////////////////////////////////////////////////////////////////////////////////
// Fichier:
// Auteur:Rakotondrabe Miora Fanomezana
// Date:26-09-2022
// Description:Cette programme permet de chronometrer la duree d'execution d'une fonction
////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

void F1(int n);
void F2(int n);
void F3(int n);
void F4(int n);
void F5(int n);
void F6(int n);

int main()
{
	LARGE_INTEGER freq, depart, fin;
	double duree = 0;
	QueryPerformanceFrequency(&freq); // Obtient fr�quence
	QueryPerformanceCounter(&depart);

	F6(10);


	QueryPerformanceCounter(&fin);

	duree = ((fin.QuadPart - depart.QuadPart) / (double)freq.QuadPart) * 1000L;
	printf("Duree: %.4lf millisecondes\n", duree);

	system("pause");
	return 0;
}

void F1(int n) { // C1 + nC2 = Cn
	int somme = 0; // C1
	for (int i = 0; i < n; i++) { //n
		somme = somme+ 1;  // C2
	}
}

void F2(int n) { // C1 + (n*n*C2) = C1 + C2n^2 = Cn^2
	int somme = 0; //C1
	for (int i = 0; i < n; i++) { //n
		for (int j = 0; j < n; j++) { //n
			somme = somme+1; // C2
		}
	}
}

void F3(int n) { // C1 + n(n*n*C2) = C1 + C2n^3 = Cn^3
	int somme = 0;// C1
	for (int i = 0; i < n; i++) { // n
		for (int j = 0; j < (n * n); j++) { // n*n
			somme = somme + 1;//C2
		}
	}
}

void F4(int n) { // C1 + C2/2*(n(n-1)) = C1 + C2n^2/2 - C2n/2 = Cn^2
	int somme = 0;//C1
	for (int i = 0; i < n; i++) { // n
		for (int j = 0; j < i; j++) { // (n-1) , 0+1+2+3+...+n-1 = (n(n-1))/2
			somme = somme + 1; //C2
		}
	}
}

void F5(int n) { // C1 + (((n(n-1)(2n-1))/6)*(((n(n-1)(2n-1))/6)-1)) /2 * C2 = C1 + C2((n^6-12n^5+5n^4+4n^3+4n^2+n)/72) = Cn^6
	int somme = 0;//C1
	for (int i = 0; i < n; i++) { //n
		for (int j = 0; j < i * i; j++) { // (n-1)(n-1) = n^2 - 2n + 1, 0 + 1^2 +2^2 +3^2 +....+(n-1)^2 = (n(n-1)(2n-1))/6
			for (int k = 0; k < j; k++) { // (n-1)(n-1) - 1 = n^2 - 2n +1 -1 = n^2 -2n , (((n(n-1)(2n-1))/6)*(((n(n-1)(2n-1))/6)-1)) /2
				somme = somme + 1; // C2
			}
		}
	}
}

void F6(int n) { // C1 + C2((n(n-1)(2n-1))/6) + C3(((n(n-1)(2n-1))/6)*(((n(n-1)(2n-1))/6)-1)) /4n = C1 + C2(2n^3-n^2-2n+1) + C3((n^6-12n^5+5n^4+4n^3+4n^2+n)/72) - 2C3n = Cn^6
	int somme = 0; // C1
	for (int i = 0; i < n; i++) { // n
		for (int j = 0; j < i * i; j++) { //(n-1)(n-1) = n^2 - 2n +1,0 + 1^2 +2^2 +3^2 +....+(n-1)^2 = (n(n-1)(2n-1))/6
			if (j % i == 0) { // C2
				for (int k = 0; k < j; k++) { // (n-1)(n-1) - 1 = n^2 - 2n +1 -1 = n^2 -2n,(((n(n-1)(2n-1))/6)*(((n(n-1)(2n-1))/6)-1)) /2 - 2n 
					somme = somme + 1; // C3
				}
			}
		}
	}
}