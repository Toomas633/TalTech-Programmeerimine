/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-01: Massiivi väljastamine
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout
#include <string>					// std::string

using namespace std;

// Protseduur, mis väljastab täisarvude massiivi käsureale nõnda, et elemendid
// on üksteisest eraldatud komadega ja massiivi ümber on loogelised sulud
void valjasta(int* massiiv, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, väljastame tühjad loogelised sulud ja
	// väljume protseduurist
	if (kogus == 0) {
		cout << "{}";
		return;
	}
	// Kui massiivis on elemente, väljastame kõigepealt esimese elemendi ning
	// seejärel kõik järgmised elemendid, asetades nende ette komad
	cout << "{" << massiiv[0];
	for (unsigned int koht = 1; koht < kogus; koht++) {
		cout << ", " << massiiv[koht];
	}
	cout << "}";
}


int main() {
	// Defineerime täisarvude massiivi
	const unsigned int kogus = 10;
	int arvud[kogus] = {42, 5, 0, -7, 9, 100, 32, 88, 15, -5};

	// Väljastame selle käsureale
	valjasta(arvud, kogus);
	cout << endl;

	return 0;
}
