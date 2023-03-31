/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-05: Kolme arvu järjestamine
 * Variant 02: Lisamuutujatega
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt kolme täisarvu, mida järjestada
	int a, b, c;
	cout << "Sisesta tuhikuga eraldatuna kolm taisarvu: ";
	cin >> a >> b >> c;
	cout << endl;

	// Kasutame valikulauseid ja paarikaupa võrdlemist, et leida nende kolme
	// täisarvu väärtuste positsioonid kasvavas järjekorras

	// Defineerime järjestuse leidmiseks uued muutujad
	// Alustame eeldusega, et arvud on juba õiges järjekorras ja asetame need
	// nimetatud kohtadele
	int esimene = a;
	int teine = b;
	int kolmas = c;

	// Kui esimesel kohal asuv väärtus on teisel kohal asuvast väärtusest
	// suurem, on esimesel kahel kohal asuvad väärtused vales järjekorras ja
	// tuleb ära vahetada
	// Väärtuste vahetamisel saame kasutada otse muutujate 'a' ja 'b' väärtusi,
	// kuna eelnevalt pole ühtegi muud operatsiooni tehtud
	if (esimene > teine) {
		esimene = b;
		teine = a;
	}

	// Kui teisel kohal asuv väärtus on kolmandal kohal asuvast väärtusest
	// suurem, on viimasel akhel kohal asuvad väärtused vales järjekorras ja
	// tuleb ära vahetada
	if (teine > kolmas) {

		// Väärtuste vahetamisel kasutame teadmist, et seni oli kolmandal kohal
		// asuv väärtus sama, mis muutuja 'c' väärtus; teisel kohal asuva
		// väärtuse kohta pole siin muutujate väärtusi nägemata võimalik teada,
		// kas seal asub muutuja 'a' või 'b' väärtus, seega kasutame nende
		// asemel hoopis muutuja 'teine' väärtust
		// Selle operatsiooni tulemusel saame olla kindlad, et kolmandal kohal
		// asuv väärtus on suurim
		kolmas = teine;
		teine = c;

		// Lisaks, kuna liigutasime kolmanda arvu teisele kohale, peame nüüd
		// taas kontrollima, et esimesel kahel kohal olevad arvud oleksid
		// õiges järjekorras
		// Kui esimesel kohal asuv väärtus on teisel kohal asuvast väärtusest
		// suurem, tuleb nende väärtused vahetada
		// Siin saame kasutada teadmist, et teisel kohal asub arv c
		if (esimene > teine) {
			teine = esimene;
			esimene = c;
		}

	}

	// Väljastame sisestatud väärtused nende kasvamise järjekorras käsureale
	cout << "Vaartuste kasvamise jarjekorras on need arvud:" << endl;
	cout << esimene << " " << teine << " " << kolmas << endl;

	return 0;
}
