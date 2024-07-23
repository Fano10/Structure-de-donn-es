#include "Thermostat.h"



Thermostat::Thermostat(void)
{
	Marque = "SUPER THERMOSTAT 8STXV";
	Mode = 'A';
	TemperatureAutomatique = 10;
	for (int i = 0; i < 3; i++) {
		ZoneTemperature[i] = 10;
	}
}

char Thermostat::DemanderMode(void)
{

	char Choix;
	cout << "Definir le nouveau mode (M) ou (A) : ";
	cin >> Choix;
	return Choix;
}
void Thermostat::AfficherMode(void)
{
	if (Mode == 'A') {
		cout << "Mode actuel: AUTOMATIQUE\n";
	}
	else {
		cout << "Mode actuel: MANUEL\n";
	}
}
int Thermostat::DemanderZone(void)
{
	int Choix;
	cout << "Definir la zone (0) ou (1) ou (2) : ";
	cin >> Choix;
	return Choix;
}
int Thermostat::DemanderTemperature(void)
{
	int Choix;
	cout << "Definir la nouvelle temperature (10-20) : ";
	cin >> Choix;
	if (Choix < 10 || Choix >20) {
		Choix = 10;
	}
	return Choix;
}
void Thermostat::ChoisirMode(void)
{
	AfficherMode();
	char Choix = DemanderMode();
	if (Choix == 'A' || Choix == 'M') {
		Mode = Choix;
	}
	else {
		cout << "Mode invalide\n";
	}
}

void Thermostat::ChoisirTemperature(void)
{
	AfficherMode();
	if (Mode == 'A') {
		int Zone = DemanderZone();
		int Temperature = DemanderTemperature();
		ZoneTemperature[Zone] = Temperature;
	}
	else {
		int Temperature = DemanderTemperature();
		TemperatureAutomatique = Temperature;
	}
}

ostream& operator<<(ostream& Out, Thermostat& T)
{
	if (T.Mode == 'A') {
		Out << "------------------------------------\n";
		Out << "-" << T.Marque << endl;
		Out << "-Mode : AUTOMATIQUE" << endl;
		for (int i = 0; i < 3; i++) {
			Out << "-Zone : " << i << endl;
			Out << "   Temperature : " << T.ZoneTemperature[i] << endl;
		}
		Out << "------------------------------------\n";
	}
	else {
		Out << "------------------------------------\n";
		Out << "- " << T.Marque << endl;
		Out << "- Mode : MANUEL" << endl;
		Out << "   Temperature : " << T.TemperatureAutomatique << endl;
		Out << "------------------------------------\n";
	}
	return Out;
}

