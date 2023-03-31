/**
 * Programmeerimine keeles C++
 * Sisend ja väljund käsureal
 * Harjutus 05-05: Raamatupidaja
 * Ants-Oskar Mäesalu
 * 2022-02-04
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision

using namespace std;

int main() {
	// Küsime kasutajalt toote omahinna
	float omahind;
	cout << "Sisesta toote omahind: ";
	cin >> omahind;

	// Küsime kasutajalt toote müügihinna
	float muugihind;
	cout << "Sisesta toote muugihind: ";
	cin >> muugihind;

	// Küsime kasutajalt müüdud toodete koguse
	int kogus;
	cout << "Sisesta muudud toodete kogus: ";
	cin >> kogus;

	// Küsime kasutajalt müügiperioodi pikkuse päevades
	int periood;
	cout << "Sisesta muugiperioodi pikkus paevades: ";
	cin >> periood;

	// Arvutame kogukasumi, päevas müüdud toodete koguse ja päeva keskmise
	// kasumi
	float kasum = (muugihind - omahind) * kogus;
	float paevas_muudud = float(kogus) / periood;
	float paeva_kasum = kasum / periood;

	// Väljastame vastuse käsureale
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "Kogukasum:     " << kasum << " eurot" << endl;
	cout << "Paevas muudud: " << paevas_muudud << " tk" << endl;
	cout << "Paeva kasum:   " << paeva_kasum << " eurot" << endl;

	return 0;
}
