/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-05: Teemant
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab teemandi küljepikkust
	int pikkus;
	cout << "Sisesta teemandi kuljepikkus: ";
	cin >> pikkus;

	// Väljastame teemandi ülemise nurga, st esimese rea
	// Nurgale vastava tärni ees peab asuma 'pikkus - 1' tühikut
	for (int i = 1; i < pikkus; i++) {
		cout << ' ';
	}
	cout << '*' << endl;

	// Väljastame teemandi teisest reast kuni keskpunktini
	for (int rida = 2; rida <= pikkus; rida++) {
		// Vasakpoolsele tärnile eelneb 'pikkus - rida' tühikut
		for (int i = rida; i < pikkus; i++) {
			cout << ' ';
		}
		// Väljastame vasakpoolse tärni
		cout << '*';
		// Vasak- ja parempoolse tärni vahel asub '2 * (rida - 2) + 1' tühikut,
		// st '2 * rida - 3' tühikut
		for (int i = 3; i < 2 * rida; i++) {
			cout << ' ';
		}
		// Väljastame parempoolse tärni ja lõpetame rea
		cout << '*' << endl;
	}

	// Väljastame teemandi keskpunktile järgnevast reast kuni eelviimase reani
	for (int rida = pikkus - 1; rida > 1; rida--) {
		// Vasakpoolsele tärnile eelneb 'pikkus - rida' tühikut
		for (int i = rida; i < pikkus; i++) {
			cout << ' ';
		}
		// Väljastame vasakpoolse tärni
		cout << '*';
		// Vasak- ja parempoolse tärni vahel asub '2 * (rida - 2) + 1' tühikut,
		// st '2 * rida - 3' tühikut
		for (int i = 3; i < 2 * rida; i++) {
			cout << ' ';
		}
		// Väljastame parempoolse tärni ja lõpetame rea
		cout << '*' << endl;
	}

	// Väljastame teemandi alumise nurga, st viimase rea
	// Nurgale vastava tärni ees peab asuma 'pikkus - 1' tühikut
	// Kui kolmnurga küljepikkus on 1, siis peaksime kokku väljastama vaid ühe
	// tärni, seega sellisel juhul viimast tärni väljastada ei tohiks
	if (pikkus != 1) {
		for (int i = 1; i < pikkus; i++) {
			cout << ' ';
		}
		cout << '*' << endl;
	}

	return 0;
}
