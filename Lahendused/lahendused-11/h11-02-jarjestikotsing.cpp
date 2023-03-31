/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-02: Järjestikotsing
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits
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

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// täisarvu
int loe_taisarv(string kusimus = "Sisesta taisarv") {
	// Deklareerime muutuja, millesse täisarv sisse lugeda
	int arv;
	// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse täisarv
	bool vigane_sisend;
	do {
		// Eeldame, et kasutaja sisestab korrektse täisarvu
		vigane_sisend = false;
		// Esitame kasutajale küsimuse ja loeme sisse ühe täisarvu
		cout << kusimus << ": ";
		cin >> arv;
		// Kui sisend läks katki, siis ei sisestatud täisarvu
		// Sel juhul väljastame veateate, määrame sisendi vigaseks, et seda
		// uuesti küsitaks, ning puhastame sisendvoo veaseisundi
		if (cin.fail()) {
			cout << "Viga! Tegu pole taisarvuga." << endl;
			vigane_sisend = true;
			cin.clear();
		}
		// Tühjendame kõik, mis sisendvoogu jäänud
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (vigane_sisend);
	// Kui kasutaja sisestas nõuetekohase täisarvu, tagastame selle
	return arv;
}

// Funktsioon, mis otsib massiivist väärtust ja tagastab selle esimesele
// esinemisele vastava kohanumbri või -1, kui seda väärtust massiivis ei leidu
// Kasutame järjestik- ehk lineaarotsingut
int otsi(int* massiiv, unsigned int kogus, int otsitav) {
	// Vaatleme järjestikuselt massiivi iga elementi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Kui massiivis vaadeldaval kohal asuva elemendi väärtus on võrdne
		// otsitava elemendi väärtusega, siis asub otsitav element massiivis
		// sellel kohal
		if (massiiv[koht] == otsitav) return koht;
	}
	// Kui massiivi ühegi elemendi väärtus polnud otsitava väärtusega võrdne,
	// siis ei leidu massiivis seda väärtust
	return -1;
}


int main() {
	// Defineerime täisarvude massiivi
	const unsigned int kogus = 10;
	int arvud[kogus] = {42, 5, 0, -7, 9, 100, 32, 88, 15, -5};

	// Väljastame massiivi käsureale
	cout << "Massiiv:" << endl;
	valjasta(arvud, kogus);
	cout << endl << endl;

	// Küsime kasutajalt täisarvu, mida massiivist otsida
	int arv = loe_taisarv("Sisesta otsitav vaartus");

	// Leiame väärtuse esimesele esinemisele vastava kohanumbri massiivis
	int koht = otsi(arvud, kogus, arv);

	// Väljastame elemendi asukoha massiivis või vastava veateate, kui elementi
	// ei leidu
	if (koht != -1) {
		cout << "Arv " << arv << " asub massiivis kohal " << koht << "." << endl;
	} else {
		cout << "Sellist arvu massiivis ei leidu." << endl;
	}

	return 0;
}
