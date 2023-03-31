/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-01: Muutuja mäluaadress
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt täisarvu
	int arv;
	cout << "Sisestage uks taisarv: ";
	cin >> arv;

	// Väljastame muutuja 'arv' väärtuse ja mäluaadressi
	cout << "Vaartus: " << arv << endl;
	cout << "Aadress: " << &arv << endl;

	return 0;
}
