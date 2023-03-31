/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-03: Liigaasta
 * Variant 02: Mitmese valikulausega
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

		// Kui aastaarv ei jagu 4-ga, ei ole see liigaasta
		if (aasta % 4 != 0) {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}
		// Kui aastaarv jagub 4-ga (tuleneb eelnevast tingimusest) ja aastaarv
		// ei jagu 100-ga, on see liigaasta
		else if (aasta % 100 != 0) {
			cout << "Aasta " << aasta << " on liigaasta." << endl;
		}
		// Kui aastaarv jagub 4-ga ja 100-ga (tuleneb eelnevatest tingimustest)
		// ja aastaarv jagub 400-ga, on see liigaasta
		else if (aasta % 400 == 0) {
			cout << "Aasta " << aasta << " on liigaasta." << endl;
		}
		// Vastasel juhul pole tegemist liigaastaga
		else {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
