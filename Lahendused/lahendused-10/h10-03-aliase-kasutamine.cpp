/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-03: Aliase kasutamine
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt täisarvu
	int a;
	cout << "Sisestage uks taisarv: ";
	cin >> a;

	// Loome muutujale 'a' aliase (ehk viite) 'b'
	int& b = a;

	// Väljastame mõlema muutuja väärtused
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// Küsime kasutajalt aliasele uue väärtuse; kirjutame vana väärtuse üle
	cout << "Sisestage uus taisarv: ";
	cin >> b;

	// Väljastame mõlema muutuja väärtused
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// Mis juhtus? Miks?
	// Muutuja 'b' on muutuja 'a' aliasmuutuja. See tähendab, et mõlemad
	// muutujad asuvad arvuti mälus tegelikult täpselt samal aadressil, st
	// mõlemad kasutavad sama mälupesa. Seega, kui muuta ühe muutuja väärtust,
	// muutub ka teise väärtus, ja vastupidi.

	return 0;
}
