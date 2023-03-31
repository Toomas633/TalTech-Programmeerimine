/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-01: Liigaasta kontroll
 * Variant 01: Jäägiga jagamine
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

// Funktsioon, mis kontrollib, kas aasta on liigaasta
// Kasutame jäägiga jagamist
bool on_liigaasta(unsigned int aasta) {
	// Kui aastaarv jagub 4-ga, on see liigaasta juhul, kui see ei jagu 100-ga
	// või jagub 400-ga.
	// Kui kasutaksime jaguvuse kontrollimiseks bititehteid, saaksime veel
	// kiiremaks.
	return aasta % 4 == 0 && (aasta % 100 != 0 || aasta % 400 == 0);
}


int main() {
	// Küsime kasutajalt aastaarvu
	// Siit on puudu sisendi veahaldus
	int aasta;
	cout << "Sisesta uks aastaarv: ";
	cin >> aasta;

	// Kontrollime, et aastaarv oleks mittenegatiivne
	if (aasta >= 0) {

		// Väljastame, kas tegu on liigaastaga
		if (on_liigaasta(aasta)) {
			cout << "Aasta " << aasta << " on liigaasta." << endl;
		} else {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
