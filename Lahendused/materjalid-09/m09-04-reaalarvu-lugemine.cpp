/**
 * Programmeerimine keeles C++
 * Sisendi veahaldus
 * Näide 09-02: Kolmnurga pindala
 * Küsime käsurealt sisendit seni, kuni kasutaja sisestab mittenegatiivse
 * reaalarvu.
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout
#include <limits>					// std::numeric_limits
#include <string>					// std::string

using namespace std;

// Funktsioon, mis leiab kolmnurga pindala aluse ja kõrguse järgi
double leia_pindala(double alus, double korgus) {
	return alus * korgus / 2;
}

int main() {
	// Küsime kasutajalt kolmnurga aluse ja kõrguse
	// Tagame, et tegu oleks mittenegatiivsete reaalarvudega
	double alus, korgus;
	cout << "Sisesta kolmnurga alus: ";
	cin >> alus;
	cout << "Sisesta kolmnurga korgus: ";
	cin >> korgus;
	cout << endl;

	// Väljastame kolmnurga mõõtmed käsureale
	cout << "Kolmnurga mootmed:" << endl;
	cout << "  Alus:   " << alus << endl;
	cout << "  Korgus: " << korgus << endl;
	cout << endl;

	// Leiame ja väljastame kolmnurga pindala selle aluse ja kõrguse kaudu
	cout << "Kolmnurga pindala:" << endl;
	cout << "  " << leia_pindala(alus, korgus) << " (ruutuhikut)" << endl;

	return 0;
}
