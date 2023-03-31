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
#include <iomanip>					// std::setw, std::setfill

using namespace std;

int main() {
	// Loeme sisse kuupäeva vahemikus 1900-01-01 ... 2100-12-31
	// Siit on puudu sisendi veahaldus
	unsigned int aasta, kuu, paev;
	cout << "Sisesta aasta: ";
	cin >> aasta;
	cout << "Sisesta kuu: ";
	cin >> kuu;
	cout << "Sisesta paev: ";
	cin >> paev;
	cout << endl;

	// Väljastame kuupäeva käsureale kujul YYYY-MM-DD
	cout << "Sisestatud kuupaev on:" << endl;
	cout << setfill('0');
	cout << "  ";
	cout << setw(4) << aasta;
	cout << "-";
	cout << setw(2) << kuu;
	cout << "-";
	cout << setw(2) << paev;
	cout << endl;

	return 0;
}
