/**
 * Programmeerimine keeles C++
 * Sisendi veahaldus
 * Näide 09-01: Algarvu kontroll
 * Ülesanne: Täienda programmi nõnda, et arvuti küsiks kasutajalt sisendit seni,
 * kuni sisestatakse täisarv.
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout
#include <cmath>					// std::sqrt

using namespace std;

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
	// Siit on puudu sisendi veahaldus
	int arv;
	cout << "Sisesta mittenegatiivne taisarv: ";
	cin >> arv;
	cout << endl;

	// Kontrollime, kas tegu on algarvuga ja väljastame tulemuse
	if (on_algarv(arv)) {
		cout << "Suureparane! Arv " << arv << " on algarv!" << endl;
	} else {
		cout << "Arv " << arv << " ei ole algarv." << endl;
	}

	return 0;
}
