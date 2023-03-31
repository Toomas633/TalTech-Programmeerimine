/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-01: Arvu pikkus
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu
	int arv;
	cout << "Sisesta uks taisarv: ";
	cin >> arv;

	// Leiame selle täisarvu pikkuse

	// Algväärtustame pikkuse 0-na
	// Hakkame seda vastavalt sisestatud arvu väärtusele suurendama
	unsigned int pikkus = 0;

	// Kui arv on 0 või negatiivne, võtame seda arvesse 1 kohana
	// St miinusmärki võtame siin samuti kohana arvesse, aga selle tarvilikkus
	// on vaieldav
	if (arv <= 0) {
		pikkus++;
	}

	// Loendame, mitu korda on võimalik arvu 10-ga jagada
	while (arv != 0) {
		arv /= 10; // Sama, mis arv = arv / 10
		pikkus++;  // Sama, mis pikkus = pikkus + 1
	}

	// Väljastame vastuse käsureale
	cout << "Arvu pikkus on " << pikkus << "." << endl;

	return 0;
}
