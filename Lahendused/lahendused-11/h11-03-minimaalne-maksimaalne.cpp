/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-03: Minimaalne ja maksimaalne
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout

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

// Funktsioon, mis leiab massiivist vähima väärtusega elemendi ja tagastab selle
// kohanumbri
// Kui leitud väärtust on massiivi elementide hulgas korduvalt, tagastatakse
// neist esimese kohanumber
// Kui elementi ei leidu, st kui massiiv on tühi, tagastatakse -1
int minimaalne(int* massiiv, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, tagastame -1
	if (kogus == 0) return -1;
	// Vastasel juhul deklareerime muutujad vähima väärtustega elemendi
	// väärtuse ja kohanumbri salvestamiseks
	// Algväärtustame need eeldusega, et esimene element massiivis on vähima
	// väärtusega
	int min_vaartus = massiiv[0];
	int min_koht = 0;
	// Vaatleme järjestikuselt massiivi iga elementi alates teisest
	for (unsigned int koht = 1; koht < kogus; koht++) {
		// Kui massiivis vaaddeldaval kohal asuva elemendi väärtus on väiksem
		// kui siiani leitud vähima väärtusega element, määrame selle uueks
		// vähima väärtusega elemendiks
		if (massiiv[koht] < min_vaartus) {
			min_vaartus = massiiv[koht];
			min_koht = koht;
		}
	}
	// Tagastame vähima väärtusega elemendi kohanumbri
	return min_koht;
}

// Funktsioon, mis leiab massiivist suurima väärtusega elemendi ja tagastab
// selle kohanumbri
// Kui leitud väärtust on massiivi elementide hulgas korduvalt, tagastatakse
// neist esimese kohanumber
// Kui elementi ei leidu, st kui massiiv on tühi, tagastatakse -1
int maksimaalne(int* massiiv, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, tagastame -1
	if (kogus == 0) return -1;
	// Vastasel juhul deklareerime muutujad suurima väärtustega elemendi
	// väärtuse ja kohanumbri salvestamiseks
	// Algväärtustame need eeldusega, et esimene element massiivis on suurima
	// väärtusega
	int max_vaartus = massiiv[0];
	int max_koht = 0;
	// Vaatleme järjestikuselt massiivi iga elementi alates teisest
	for (unsigned int koht = 1; koht < kogus; koht++) {
		// Kui massiivis vaaddeldaval kohal asuva elemendi väärtus on suurem
		// kui siiani leitud suurima väärtusega element, määrame selle uueks
		// suurima väärtusega elemendiks
		if (massiiv[koht] > max_vaartus) {
			max_vaartus = massiiv[koht];
			max_koht = koht;
		}
	}
	// Tagastame suurima väärtusega elemendi kohanumbri
	return max_koht;
}


int main() {
	// Defineerime täisarvude massiivi
	const unsigned int kogus = 10;
	int arvud[kogus] = {42, 5, 0, -7, 9, 100, 32, 88, 15, -5};

	// Väljastame massiivi käsureale
	cout << "Massiiv:" << endl;
	valjasta(arvud, kogus);
	cout << endl << endl;

	// Leiame massiivist vähima väärtusega elemendi kohanumbri ja väljastame
	// selle koos vastava elemendi väärtusega käsureale
	int min_koht = minimaalne(arvud, kogus);
	if (min_koht != -1) {
		cout << "Minimaalne element " << arvud[min_koht] << " asub kohal " << min_koht << "." << endl;
	} else {
		cout << "Minimaalset elementi polnud voimalik leida." << endl;
	}

	// Leiame massiivist suurima väärtusega elemendi kohanumbri ja väljastame
	// selle koos vastava elemendi väärtusega käsureale
	int max_koht = maksimaalne(arvud, kogus);
	if (max_koht != -1) {
		cout << "Maksimaalne element " << arvud[max_koht] << " asub kohal " << max_koht << "." << endl;
	} else {
		cout << "Maksimaalset elementi polnud voimalik leida." << endl;
	}

	return 0;
}
