/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-01: Massiivi väljastamine
 * Variant 02: Massiivi sõneks teisendamiseks on eraldi protseduur
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout
#include <string>					// std::string
#include <sstream>					// std::ostringstream

using namespace std;

// Protseduur, mis tagastab täisarvude massiivi sõne kujul nii, et elemendid on
// üksteisest eraldatud komadega ja massiivi ümber on loogelised sulud
string to_string(int* massiiv, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, tagastame tühjad loogelised sulud
	if (kogus == 0) return "{}";
	// Kui massiivis on elemente, deklareerime sõne väljundvoo, mida kasutame
	// sõne konstrueerimiseks
	ostringstream sone;
	// Kõigepealt lisame sõnevoogu esimese elemendi, seejärel ükshaaval kõik
	// järgmised elemendid, asetades nende ette komad
	sone << "{" << massiiv[0];
	for (unsigned int koht = 1; koht < kogus; koht++) {
		sone << ", " << massiiv[koht];
	}
	sone << "}";
	// Tagastame massiivi elementidest konstrueeritud sõne
	return sone.str();
}


// Protseduur, mis väljastab täisarvude massiivi käsureale nõnda, et elemendid
// on üksteisest eraldatud komadega ja massiivi ümber on loogelised sulud
void valjasta(int* massiiv, unsigned int kogus) {
	cout << to_string(massiiv, kogus) << endl;
}


int main() {
	// Defineerime täisarvude massiivi
	const unsigned int kogus = 10;
	int arvud[kogus] = {42, 5, 0, -7, 9, 100, 32, 88, 15, -5};

	// Väljastame selle käsureale
	valjasta(arvud, kogus);

	return 0;
}
