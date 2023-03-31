/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-04: Otsing failist
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <limits>					// std::numeric_limits
#include <string>					// std::string

using namespace std;

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

// Protseduur, mis loeb sisendfailist arvud ja salvestab need massiivi
// Sisendfaili esimesel real on arvude kogus ning igal järgneval real üks arv
// Arvude massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
void loe_arvud_failist(const string& failinimi, int*& massiiv, unsigned int& kogus) {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return;
	}
	// Loeme sisse arvude koguse
	sisend >> kogus;
	// Eraldame arvude massiivile mälu nii mitme arvu salvestamiseks
	massiiv = new int[kogus];
	// Loeme sisse nii mitu arvu ja salvestame need massiivi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Loeme sisse järgmise arvu ja salvestame selle massiivi
		sisend >> massiiv[koht];
	}
}

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

// Protseduur, mis otsib massiivist väärtust ja tagastab selle kohanumbri
// Kui väärtust massiivis ei leidu, tagastab maksimaalse võimaliku märgita
// täisarvu
unsigned int otsi(int vaartus, int* massiiv, unsigned int kogus) {
	// Vaatleme ükshaaval massiivi iga elementi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Kui massiivi elemendi väärtus on väärtusega samaväärne, oleme leidnud
		// otsitava väärtuse ning tagastame selle kohanumbri
		if (massiiv[koht] == vaartus) return koht;
	}
	// Kui massiivi kõik elemendid on läbi vaadatud ning ükski neist ei olnud
	// võrdne otsitava väärtusega, tagastame maksimaalse võimaliku märgita
	// täisarvu (kasutame selleks märgita täisarvu alatäitumist)
	return -1;
}

// Protseduur, mis küsib kasutajalt väärtust, mida arvude massiivist otsida. Kui
// väärtus on massiivis olemas, väljastab protseduur selle kohanumbri; kui
// mitte, väljastab protseduur vastava veateate. Seejärel küsib protseduur
// kasutajalt uuesti otsitavat väärtust ja jätkab tööga, kuni kasutaja sisestab
// negatiivse arvu
void kaivita_otsing(int* massiiv, unsigned int kogus) {
	// Jätkame otsinguga nii kaua, kuni kasutaja seda soovib
	int vaartus;
	do {
		// Väljastame massiivi käsureale
		cout << "Massiiv: " << endl;
		valjasta(massiiv, kogus);
		cout << endl;
		// Küsime kasutajalt väärtust, mida massiivist otsida
		vaartus = loe_taisarv("Sisesta otsitav vaartus (voi negatiivne arv, kui soovid lopetada)");
		// Kui väärtus on mittenegatiivne, otsime seda massiivist
		if (vaartus >= 0) {
			unsigned int koht = otsi(vaartus, massiiv, kogus);
			// Kui väärtus leiti, väljastame selle kohanumbri
			if (koht < kogus) {
				cout << "Vaartus " << vaartus << " asub massiivis kohal " << koht << ".";
			}
			// Vastasel juhul väljastame vastava veateate
			else {
				cout << "Vaartust " << vaartus << " massiivist ei leitud.";
			}
			cout << endl << endl;
		}
	} while (vaartus >= 0);
}


int main() {
	// Defineerime sisendfaili asukoha ja nime
	string failinimi = "andmed/andmebaas.txt";

	// Loeme failist sisse N arvu ja salvestame need dünaamilisse massiivi
	int* arvud = nullptr;
	unsigned int kogus = 0;
	loe_arvud_failist(failinimi, arvud, kogus);

	// Kui arvude massiiv oli võimalik sisse lugeda, siis eraldati sellele
	// dünaamiliselt mälu ja arvude massiivile vastav mäluaadress pole tühiviit.
	// Ainult sellisel juhul saame massiivi kasutada.
	if (arvud != nullptr) {

		kaivita_otsing(arvud, kogus);

	} else {
		cout << "Viga! Arvude massiivi ei loodud." << endl;
	}

	// Vabastame arvude massiivile dünaamiliselt eraldatud mälu
	delete[] arvud;

	return 0;
}
