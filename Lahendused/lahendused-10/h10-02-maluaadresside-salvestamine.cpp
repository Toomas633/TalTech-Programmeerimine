/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-02: Mäluaadresside salvestamine
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt kaks täisarvu
	int a, b;
	cout << "Sisestage tuhikuga eraldatuna kaks taisarvu: ";
	cin >> a >> b;

	// Salvestame muutujate 'a' ja 'b' mäluaadressid
	int* aadress_a = &a;
	int* aadress_b = &b;

	// Väljastame täisarvud ja neile vastavate viitmuutujate väärtused
	cout << "Arv a:" << endl;
	cout << "  Vaartus: " << a << endl;
	cout << "  Aadress: " << aadress_a << endl;
	cout << "Arv b:" << endl;
	cout << "  Vaartus: " << b << endl;
	cout << "  Aadress: " << aadress_b << endl;

	return 0;
}
