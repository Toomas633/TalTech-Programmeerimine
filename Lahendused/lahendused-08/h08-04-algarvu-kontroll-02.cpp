/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-04: Algarvu kontroll
 * Variant 02: Optimeeritud algoritm
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

// Funktsioon, mis kontrollib, kas arv on algarv
// Kasutame optimeeritud algoritmi, milles kontrollime vaid kordajaid kujul 6k+1
// ja 6k-1 kuni arvu ruutjuureni
bool on_algarv(const unsigned int& arv) {
	// Kui arv on 0 või 1, ei ole tegu algarvuga
	if (arv <= 1) return false;
	// Kui arv on 2 või 3, on tegu algarvuga
	if (arv <= 3) return true;
	// Kui arv on 3-st suurem ja jagub 2 või 3-ga, ei ole tegu algarvuga
	if (arv % 2 == 0 || arv % 3 == 0) return false;
	// Suuremate arvude puhul tuleb kontrollida vaid kordajaid kujul 6k+1 ja
	// 6k-1. Kõiki arve saab väljendada kujul 6k+i, kus i = {0, 1, 2, 3, 4, 5}.
	// Arvud kujul 6k+0, 6k+2 ja 6k+4 jaguvad 2-ga ning arvud kujul 6k+3 jaguvad
	// 3-ga, seega neid pole tarvis kontrollida. Alles jäävad vaid arvud kujul
	// 6k+1 ja 6k+5. Arve kujul 6k+5 saab aga esitada ka kujul 6k-1.
	// Seejuures rakendame kontrolli vaid ruutjuureni arvust, sest kõiki arvu
	// ruutjuurest suuremaid kordajaid tuleb arvu saamiseks korrutada arvu
	// ruutjuurest väiksema(te) kordaja(te)ga.
	// Arvu ruutjuure funktsiooni kasutamise asemel võtame tema potentsiaalse
	// kordaja ruutu, sest korrutamine on kiirem operatsioon kui arvu ruutjuure
	// leidmine.
	for (unsigned int i = 5; i * i <= arv; i += 6) {
		if (arv % i == 0 || arv % (i + 2) == 0) return false;
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

	// Kontrollime, et arv oleks mittenegatiivne
	if (arv >= 0) {

		// Kontrollime, kas tegu on algarvuga ja väljastame tulemuse
		if (on_algarv(arv)) {
			cout << "Suureparane! Arv " << arv << " on algarv!" << endl;
		} else {
			cout << "Arv " << arv << " ei ole algarv." << endl;
		}

	} else {
		cout << "Viga! Arv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
