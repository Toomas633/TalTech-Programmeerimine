/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-03: Liigaasta
 * Variant 01: Mitme pesastatud valikulausega
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt aastaarvu
	int aasta;
	cout << "Sisesta uks aastaarv: ";
	cin >> aasta;

	// Kontrollime, et aastaarv oleks mittenegatiivne
	if (aasta >= 0) {

		// Kui aastaarv jagub 4-ga, võib see olla liigaasta; vastasel juhul
		// mitte
		if (aasta % 4 == 0) {

			// Kui aastaarv jagub 4-ga (tuleneb välimistest tingimusest), aga ei
			// jagu 100-ga, on see liigaasta; vastasel juhul ei pruugi olla
			if (aasta % 100 != 0) {
				cout << "Aasta " << aasta << " on liigaasta." << endl;
			} else {

				// Kui aastaarv jagub 4-ga ja 100-ga (tuleneb välimistest
				// tingimustest) ning jagub 400-ga, on see liigaasta; vastasel
				// juhul mitte
				if (aasta % 400 == 0) {
					cout << "Aasta " << aasta << " on liigaasta." << endl;
				} else {
					cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
				}

			}

		} else {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
