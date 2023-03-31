/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-03: Liigaasta
 * Variant 03: Kahese valikulausega
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

		// Kui aastaarv jagub 4-ga, on see liigaasta juhul, kui see ei jagu
		// 100-ga või jagub 400-ga
		// Kui kasutaksime jaguvuse kontrollimiseks bititehteid, saaksime veel
		// kiiremaks
		if (aasta % 4 == 0 && (aasta % 100 != 0 || aasta % 400 == 0)) {
			cout << "Aasta " << aasta << " on liigaasta." << endl;
		} else {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
