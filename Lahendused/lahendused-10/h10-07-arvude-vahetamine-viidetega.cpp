/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-07: Arvude vahetamine viidetega
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

#include <iostream>	 				// std::cout

using namespace std;

// Protseduur, mis vahetab kaks arvu, kasutades aliasmuutujaid ehk viiteid ehk
// aliasi
void vaheta(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}


int main() {
	// Defineerime kaks täisarvu
	int arv1 = 0;
	int arv2 = 42;

	// Väljastame
	cout << arv1 << " " << arv2 << endl;

	// Vahetame need arvud
	vaheta(arv1, arv2);

	// Väljastame
	cout << arv1 << " " << arv2 << endl;

	return 0;
}
