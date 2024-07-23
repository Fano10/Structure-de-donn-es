#include "thermostat.h"



thermostat::thermostat(void)
{
	Marque = "SUPER THERMOSTAT 8STXV";
	Mode = 'A';
	TemperatureAutomatique = 10;
	for (int i = 0; i < 3; i++) {
		ZoneTemperature[i] = 10;
	}
}

ostream& operator<<(ostream& Out, thermostat& T)
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

