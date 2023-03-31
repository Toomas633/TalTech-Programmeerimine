/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-01: Arvu pikkus
 * Variant 02: Kasutame jagamistehte tulemust valikulause tingimusena
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu
	int arv;
	cout << "Sisesta uks taisarv: ";
	cin >> arv;

	// Leiame selle täisarvu pikkuse
	// 0 on 1-kohaline ning negatiivsete arvude korral miinusmärki arvesse ei
	// võeta
	unsigned int pikkus = 1;
	while (arv /= 10) { // Tingimuseks on muutuja 'arv' väärtus pärast tehet
		pikkus++;
	}

	// Väljastame vastuse käsureale
	cout << "Arvu pikkus on " << pikkus << "." << endl;

	return 0;
}
