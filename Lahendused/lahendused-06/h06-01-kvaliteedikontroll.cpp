/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-01: Kvaliteedikontroll
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

int main() {
	// Defineerime ettenähtud küpsiste arvu ühes küpsisepakis
	int kupsiseid_pakis = 10;

	// Küsime käsurealt küpsiste arvu, mida küpsisepakki lisada üritatakse
	int kupsiste_arv;
	cout << "Sisesta lisatavate kupsiste arv: ";
	cin >> kupsiste_arv;
	cout << endl;

	// Kontrollime, kas küpsiseid on liiga palju, liiga vähe või täpselt
	// parajalt, ja väljastame käsureale vastava teate
	if (kupsiste_arv > kupsiseid_pakis) {
		cout << "Viga! Kupsiseid on liiga palju." << endl;
		cout << kupsiste_arv - kupsiseid_pakis << " kupsist on ule.";
	} else if (kupsiste_arv < kupsiseid_pakis) {
		cout << "Viga! Kupsiseid on liiga vahe." << endl;
		cout << kupsiseid_pakis - kupsiste_arv << " kupsist on puudu.";
	} else {
		cout << "Kupsiseid on tapselt parajalt!";
	}
	cout << endl;

	return 0;
}
