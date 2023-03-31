/**
 * Programmeerimine keeles C++
 * Sisend ja väljund käsureal
 * Harjutus 05-02: Valuutapunkt
 * Ants-Oskar Mäesalu
 * 2022-02-04
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision

using namespace std;

int main() {
	// Küsime kasutajalt Poola zlottide koguse ja salvestame selle ujupunktarvu
	// tüüpi muutujasse
	float zlotid;
	cout << "Sisesta rahasumma zlottides: ";
	cin >> zlotid;

	// Teisendame zlotid eurodeks
	float kurss = 0.2343;
	float eurod = zlotid * kurss;

	// Määrame, et kõik edaspidi käsureale väljastatavad ujupunktarvud
	// väljastatakse täpsusega kaks kohta pärast koma.
	// Väljundimanipulaator 'fixed' määrab, et täpsust arvestatakse pärast koma
	// ning 'setprecision' määrab kohtade arvu. Kui jätta väljundimanipulaator
	// 'fixed' ära, määraks 'setprecision' tüvenumbrite arvu.
	cout << fixed << setprecision(2);

	// Väljastame vastuse käsureale
	cout << zlotid << " PLN = " << eurod << " EUR" << endl;

	return 0;
}
