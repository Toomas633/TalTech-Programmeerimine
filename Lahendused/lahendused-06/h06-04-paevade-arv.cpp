/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-04: Päevade arv kuus
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt aastaarvu
	int aasta;
	cout << "Sisesta aastaarv: ";
	cin >> aasta;

	// Kontrollime, et aastaarv oleks mittenegatiivne
	if (aasta >= 0) {

		// Küsime kasutajalt kuu
		int kuu;
		cout << "Sisesta kuu (vahemikus 1-12): ";
		cin >> kuu;

		// Kontrollime, et kuu oleks sobivas vahemikus
		if (kuu >= 1 && kuu <= 12) {

			// Deklareerime muutuja, mis hoiab endas päevade arvu
			int paevade_arv;

			// Kui tegu on veebruariga, peame päevade arvu leidmiseks arvesse
			// võtma, kas tegu on liigaastaga
			if (kuu == 2) {

				// Liigaastal on veebruarikuus 29 päeva; vastasel juhul 28 päeva
				// Kui aastaarv jagub 4-ga, on see liigaasta juhul, kui see ei
				// jagu 100-ga või jagub 400-ga
				// Kui kasutaksime jaguvuse kontrollimiseks bititehteid,
				// saaksime veel kiiremaks
				if (aasta % 4 == 0 && (aasta % 100 != 0 || aasta % 400 == 0)) {
					paevade_arv = 29;
				} else {
					paevade_arv = 28;
				}

			}
			// Kui tegu on aprilli, juuni, septembri või novembriga, on kuus
			// 30 päeva
			else if (kuu == 4 || kuu == 6 || kuu == 9 || kuu == 11) {
				paevade_arv = 30;
			}
			// Muudel juhtudel on kuus 31 päeva
			else {
				paevade_arv = 31;
			}

			// Väljastame vastuse käsureale
			cout << "Aastal " << aasta << " on kuus " << kuu << " kokku " << paevade_arv << " paeva." << endl;

		} else {
			cout << "Viga! Kuu peab olema vahemikus 1-12." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
