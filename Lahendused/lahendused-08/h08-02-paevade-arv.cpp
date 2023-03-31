/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-02: Päevade arv kuus
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

// Funktsioon, mis leiab päevade arvu mingi aasta mingis kuus
unsigned int leia_paevade_arv(unsigned int aasta, unsigned int kuu) {
	// Kui tegu on veebruariga, peame päevade arvu leidmiseks arvesse
	// võtma, kas tegu on liigaastaga. Liigaastal on veebruarikuus 29 päeva;
	// vastasel juhul 28 päeva.
	if (kuu == 2) return on_liigaasta(aasta) ? 29 : 28;
	// Kui tegu on aprilli, juuni, septembri või novembriga, on kuus
	// 30 päeva.
	else if (kuu == 4 || kuu == 6 || kuu == 9 || kuu == 11) return 30;
	// Muudel juhtudel on kuus 31 päeva.
	else return 31;
}


int main() {
	// Küsime kasutajalt aastaarvu
	// Siit on puudu sisendi veahaldus
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

			// Väljastame vastuse käsureale
			cout << "Aastal " << aasta << " on kuus " << kuu << " kokku " << leia_paevade_arv(aasta, kuu) << " paeva." << endl;

		} else {
			cout << "Viga! Kuu peab olema vahemikus 1-12." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
