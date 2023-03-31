/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-07: Algarvud
 * Variant 01: Naiivne, ebaoptimaalne algoritm
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab algarvude piiri
	int piir;
	cout << "Sisesta leitavate algarvude ulemine piir: ";
	cin >> piir;

	// Kontrollime iga arvu puhul kuni nimetatud piirini, kas tegu on algarvuga,
	// ja kui on, väljastame
	cout << endl << "Algarvud kuni " << piir << ":" << endl;
	for (int arv = 2; arv <= piir; arv++) {
		// Eeldame vastuväiteliselt, et tegu on algarvuga
		bool on_algarv = true;
		// Kui arv jagub mõne arvuga vahemikus [2, arv - 1], ei ole tegu
		// algarvuga
		for (int kordaja = 2; kordaja < arv; kordaja++) {
			if (arv % kordaja == 0) {
				on_algarv = false;
			}
		}
		// Kui tegu on algarvuga, väljastame selle
		if (on_algarv) {
			cout << arv << endl;
		}
	}

	return 0;
}
