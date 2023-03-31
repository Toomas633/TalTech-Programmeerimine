/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-06: Paaritud ja paarisarvud
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab sisestatavate arvude kogust
	int kogus;
	cout << "Sisesta sisestatavate arvude kogus: ";
	cin >> kogus;

	// Deklareerime ja algväärtustame muutujad paaritute ja paarisarvude koguste
	// ja summade loendamiseks
	unsigned int kogus_paaris = 0, kogus_paaritu = 0;
	int summa_paaris = 0, summa_paaritu = 0;

	// Loeme käsurealt sisse nimetatud koguse täisarve ning arvutame välja
	// paaritute ja paarisarvude kogused ja summad
	int arv;
	for (int nr = 1; nr <= kogus; nr++) {
		// Esitame kasutajale küsimuse ja loeme sisse ühe täisarvu
		cout << "Sisesta taisarv nr " << nr << ": ";
		cin >> arv;

		// Kontrollime, kas sisestatud arv on paaris või paaritu ning suurendame
		// tulemuse alusel vastavat tüüpi arvude kogust ja summat
		if (arv % 2 == 0) {
			kogus_paaris++;
			summa_paaris += arv;
		} else {
			kogus_paaritu++;
			summa_paaritu += arv;
		}
	}


	// Väljastame tulemuse käsureale
	cout << endl;
	cout << "Arve kokku:      " << kogus << endl << endl;
	cout << "Paarisarve:      " << kogus_paaris << endl;
	cout << "Nende summa:     " << summa_paaris << endl << endl;
	cout << "Paarituid arve:  " << kogus_paaritu << endl;
	cout << "Nende summa:     " << summa_paaritu << endl << endl;

	return 0;
}
