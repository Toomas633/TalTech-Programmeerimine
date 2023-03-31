/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-01: Liigaasta kontroll
 * Variant 02: Bititehted
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

// Funktsioon, mis kontrollib, kas aasta on liigaasta
// Optimeeritud lähenemine bititehetega
bool on_liigaasta(unsigned int aasta) {
	// Kui aastaarv jagub 4-ga, on see liigaasta juhul, kui see ei jagu 100-ga
	// või jagub 400-ga.
	// Bititehete kasutamine on täisarvude jagamisel tekkiva jäägi leidmisest
	// kiirem operatsioon. Kontrollimisel kasutame järgnevaid reegleid:
	// - Aasta jagub 4-ga, kui selle paremalt esimene ja teine bitt on mõlemad
	//   0. Arv 3 on kahendsüsteemis 11, nii et bitipõhise konjunktsiooniga
	//   (AND) saamegi kontrollida paremalt esimese ja teise biti väärtust.
	// - Aasta jagub 100-ga, kui jagamisel 100-ga annab see jäägi 0. Kuna aga
	//   esimesena kontrollime juba 4-ga jaguvust, võime 100-ga jaguvuse asemel
	//   kontrollida 25-ga jaguvust. Bititehe pole siin võimalik, sest 100 ega
	//   ka 25 pole kahe astmed.
	// - Aasta jagub 400-ga, kui jagamisel 400-ga annab see jäägi 0. Kuna aga
	//   25-ga jaguvust juba kontrollisime, võime siin kontrollida jaguvust
	//   16-ga. 16 on kahe aste, seega saame kasutada sarnast bititehet nagu
	//   4-ga jaguvuse kontrollimisel.
	// Lisainfo: https://stackoverflow.com/a/11595914/821442
	return (aasta & 3) == 0 && ((aasta % 25) != 0 || (aasta & 15) == 0);
}


int main() {
	// Küsime kasutajalt aastaarvu
	// Siit on puudu sisendi veahaldus
	int aasta;
	cout << "Sisesta uks aastaarv: ";
	cin >> aasta;

	// Kontrollime, et aastaarv oleks mittenegatiivne
	if (aasta >= 0) {

		// Väljastame, kas tegu on liigaastaga
		if (on_liigaasta(aasta)) {
			cout << "Aasta " << aasta << " on liigaasta." << endl;
		} else {
			cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
		}

	} else {
		cout << "Viga! Aastaarv peab olema mittenegatiivne." << endl;
	}

	return 0;
}
