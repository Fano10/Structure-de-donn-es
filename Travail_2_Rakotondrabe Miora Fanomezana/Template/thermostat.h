#pragma once
#include<iostream>
#include<string>
using namespace std;
class thermostat
{
private:
	string Marque;
	char Mode;
	int TemperatureAutomatique;
	int ZoneTemperature[3];

public:
	thermostat(void);
	friend ostream& operator<< (ostream&, thermostat&);
};

