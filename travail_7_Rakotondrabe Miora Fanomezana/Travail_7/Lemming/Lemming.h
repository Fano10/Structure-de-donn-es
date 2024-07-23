#ifndef LEMMING_H
#define LEMMING_H

#include <iostream>
using namespace std;

class Lemming
{
private:
	int id;

public:
	Lemming() { id = ((rand()%100)+1); }
	friend ostream& operator<< (ostream&, const Lemming&);
	int getId() { return id; }

};


ostream& operator<< (ostream& out, const Lemming& lemming)
{
	out << lemming.id;
	return out;
}

bool operator>(Lemming& L1, Lemming& L2) {
	return L1.getId() > L2.getId();
}


#endif
