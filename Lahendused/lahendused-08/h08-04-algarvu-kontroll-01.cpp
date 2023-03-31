/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-04: Algarvu kontroll
 * Variant 01: Naiivne algoritm
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

// Funktsioon, mis kontrollib, kas arv on algarv
// Kasutame naiivset algoritmi, st kontrollime jaguvust kõigi arvust väiksemate
// arvudega
bool on_algarv(unsigned int arv) {
	// Kui arv on 0 või 1, ei ole tegu algarvuga
	if (arv <= 1) return false;
	// Kui arv jagub mõne arvuga vahemikus [2, arv - 1], ei ole tegu algarvuga
	for (unsigned int i = 2; i < arv; i++) {
		if (arv % i == 0) return false;
	}
	// Kui arv jagub vaid 1 ja iseendaga, on tegu algarvuga
	return true;
}


int main() {
	// Küsime kasutajalt mittenegatiivse täisarvu
	// Siit on puudu sisendi veahaldus
	int arv;
	cout << "Sisesta mittenegatiivne taisarv: ";
	cin >> arv;

	// Kontrollime, et arv oleks mittenegatiivne
	if (arv >= 0) {

		// Kontrollime, kas tegu on algarvuga ja väljastame tulemuse
		if (on_algarv(arv)) {
			cout << "Suureparane! Arv " << arv << " on algarv!" << endl;
		} else {
			cout << "Arv " << arv << " ei ole algarv." << endl;
		}

	} else {
		cout << "Viga! Arv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
