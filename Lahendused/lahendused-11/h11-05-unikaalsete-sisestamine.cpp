/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-05: Unikaalsete sisestamine
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits
#include <string>					// std::string

using namespace std;

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// täisarvu
int loe_taisarv(const string& kusimus = "Sisesta taisarv") {
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

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// mittenegatiivse täisarvu
unsigned int loe_mittenegatiivne_taisarv(const string& kusimus = "Sisesta mittenegatiivne taisarv") {
	// Deklareerime muutuja, millesse täisarv sisse lugeda
	int arv;
	// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse mittenegatiivne
	// täisarv
	bool vigane_sisend;
	do {
		// Eeldame, et kasutaja sisestab korrektse mittenegatiivse täisarvu
		vigane_sisend = false;
		// Esitame kasutajale küsimuse ja loeme sisse ühe täisarvu
		arv = loe_taisarv(kusimus);
		// Kui sisend ei ole mittenegatiivne, väljastame veateate ning määrame
		// sisendi vigaseks, et seda uuesti küsitaks
		if (arv < 0) {
			cout << "Viga! Arv ei ole mittenegatiivne." << endl;
			vigane_sisend = true;
		}
	} while (vigane_sisend);
	// Kui kasutaja sisestas nõuetekohase täisarvu, tagastame selle
	return arv;
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

// Protseduur, mis loeb käsurealt sisse soovitud koguse unikaalseid väärtusi ja
// salvestab need massiivi
// Unikaalsete väärtuste massiivile eraldatakse mälu dünaamiliselt ja see tuleb
// pärast kasutamise lõppu vabastada
void loe_unikaalsed(int*& massiiv, unsigned int kogus) {
	// Eraldame mälu unikaalsete väärtuste salvestamiseks
	massiiv = new int[kogus];
	// Küsime kasutajalt unikaalseid väärtusi nii kaua, kuni massiiv saab täis
	// Kui kasutaja sisestab väärtuse, mis on massiivis juba olemas, küsitakse
	// temalt uut väärtust
	cout << "Loeme sisse " << kogus << " unikaalset vaartust." << endl;
	for (unsigned int sisestatud = 0; sisestatud < kogus; sisestatud++) {
		// Väljastame unikaalsete elementide massiivi hetkeseisu käsureale
		cout << endl;
		cout << "Hetkel on massiivis " << sisestatud << " vaartust: " << endl;
		valjasta(massiiv, sisestatud);
		cout << endl;
		// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse väärtus, mida
		// massiivis veel ei ole
		int sisend;
		bool vigane_sisend;
		do {
			// Eeldame, et kasutaja sisestab unikaalse väärtuse
			vigane_sisend = false;
			// Esitame kasutajale küsimuse ja loeme sisse ühe väärtuse
			sisend = loe_taisarv("Sisesta uus vaartus");
			// Kui sisestatud väärtus on massiivis juba olemas, väljastame
			// veateate ning määrame sisendi vigaseks, et seda uuesti küsitaks
			if (otsi(massiiv, sisestatud, sisend) != -1) {
				cout << "Viga! See vaartus on massiivis juba olemas." << endl;
				vigane_sisend = true;
			}
		} while (vigane_sisend);
		// Asetame kasutaja sisestatud väärtuse massiivi
		massiiv[sisestatud] = sisend;
	}
}


int main() {
	// Küsime kasutajalt, mitu unikaalset väärtust sisestada
	unsigned int kogus = loe_mittenegatiivne_taisarv("Sisesta, mitu unikaalset vaartust soovid sisestada");
	cout << endl;

	// Loeme käsurealt nii mitu unikaalset väärtust sisse
	int* unikaalsed = nullptr;
	loe_unikaalsed(unikaalsed, kogus);
	cout << endl;

	// Väljastame unikaalsete väärtuste massiivi käsureale
	cout << "Sisestatud unikaalsete vaartuste massiiv:" << endl;
	valjasta(unikaalsed, kogus);
	cout << endl;

	// Vabastame unikaalsete väärtuste massiivile dünaamiliselt eraldatud mälu
	delete[] unikaalsed;

	return 0;
}
