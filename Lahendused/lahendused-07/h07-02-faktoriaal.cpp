/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-02: Faktoriaal
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

	// Kui arv on mittenegatiivne, leiame ja väljastame arvu faktoriaali
	if (arv >= 0) {

		// Kui faktoriaali algväärtustame 1-na, võime korduslauses alustada 2-st,
		// sest 0! == 1! == 1
		unsigned long long faktoriaal = 1;
		for (int i = 2; i <= arv; i++) {
			faktoriaal *= i;
		}

		// Väljastame arvu faktoriaali käsureale
		cout << arv << "! = " << faktoriaal << endl;

	}
	
	// Vastasel juhul väljastame veateate
	else {
		cout << "Arvu " << arv << " faktoriaali ei saa leida, sest see on negatiivne." << endl;
	}

	return 0;
}
