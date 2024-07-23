#pragma once
#include<iostream>
#include<string>
using namespace std;
class Thermostat
{
private:
	string Marque;
	char Mode;
	int TemperatureAutomatique;
	int ZoneTemperature[3];

	char DemanderMode(void);
	void AfficherMode(void);
	int DemanderZone(void);
	int DemanderTemperature(void);

public:
	Thermostat(void);
	void ChoisirMode(void);
	void ChoisirTemperature(void);
	friend ostream& operator<< (ostream&, Thermostat&);
};

