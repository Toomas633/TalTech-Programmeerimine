/**
 * Programmeerimine keeles C++
 * Sisend ja väljund käsureal
 * Harjutus 05-03: Müügitehing
 * Ants-Oskar Mäesalu
 * 2022-02-04
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision
#include <string>					// std::string, std::getline

using namespace std;

int main() {
	// Küsime kasutajalt piruka nime
	string nimi;
	cout << "Sisesta muudud piruka nimi: ";
	getline(cin, nimi);

	// Küsime kasutajalt müüdud pirukate koguse
	int kogus;
	cout << "Sisesta muudud pirukate kogus: ";
	cin >> kogus;

	// Küsime kasutajalt ühe piruka hinna
	float hind;
	cout << "Sisesta uhe piruka hind: ";
	cin >> hind;

	// Arvutame pirukate müügitulu ja väljastame vastuse käsureale
	float tulu = kogus * hind;
	cout << fixed << setprecision(2);
	cout << "Pirukat \"" << nimi << "\" muudi hinnaga " << hind << " eurot " << kogus << " tukki." << endl;
	cout << "Muugist teeniti kokku " << tulu << " eurot." << endl;

	return 0;
}
