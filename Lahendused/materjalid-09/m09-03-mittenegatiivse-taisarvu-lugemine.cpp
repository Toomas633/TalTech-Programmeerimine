/**
 * Programmeerimine keeles C++
 * Sisendi veahaldus
 * Näide 09-01: Algarvu kontroll
 * Ülesanne: Täienda programmi nõnda, et arvuti küsiks kasutajalt sisendit seni,
 * kuni sisestatakse mittenegatiivne täisarv.
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout
#include <limits>					// std::numeric_limits
#include <string>					// std::string
#include <cmath>					// std::sqrt

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

// Funktsioon, mis kontrollib, kas arv on algarv
// Kasutame naiivset algoritmi, st kontrollime jaguvust kõigi arvust väiksemate
// arvudega kuni arvu ruutjuureni
bool on_algarv(unsigned int arv) {
	// Kui arv on 0 või 1, ei ole tegu algarvuga
	if (arv <= 1) return false;
	// Kui arv jagub mõne arvuga vahemikus [2, sqrt(arv - 1)], ei ole tegu
	// algarvuga
	// Rakendame kontrolli vaid ruutjuureni arvust, sest kõiki arvu ruutjuurest
	// suuremaid kordajaid tuleb arvu saamiseks korrutada arvu ruutjuurest
	// väiksema(te) kordaja(te)ga
	for (unsigned int kordaja = 2; kordaja <= sqrt(arv); kordaja++) {
		if (arv % kordaja == 0) {
			return false;
		}
	}
	// Kui arv jagub vaid 1 ja iseendaga, on tegu algarvuga
	return true;
}


int main() {
	// Küsime kasutajalt mittenegatiivse täisarvu
	// Siit on puudu sisendi veahaldus mittenegatiivsuse tagamiseks
	int arv = loe_taisarv("Sisesta mittenegatiivne taisarv");
	cout << endl;

	// Kontrollime, kas tegu on algarvuga ja väljastame tulemuse
	if (on_algarv(arv)) {
		cout << "Suureparane! Arv " << arv << " on algarv!" << endl;
	} else {
		cout << "Arv " << arv << " ei ole algarv." << endl;
	}

	return 0;
}
