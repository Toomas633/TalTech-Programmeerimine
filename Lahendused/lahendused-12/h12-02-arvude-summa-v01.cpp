/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-02: Arvude summa
 * Variant 01: Summa arvutatakse välja faili sisselugemise jooksul
 *   Funktsioon on väga spetsiifiline, modulaarsus madal
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <string>					// std::string

using namespace std;

// Funktsioon, mis loeb sisendfailist arvud ja tagastab nende summa
// Sisendfaili esimesel real on arvude kogus ning igal järgneval real üks arv
int arvuta_summa(const string& failinimi)  {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return 0;
	}
	// Loeme sisse arvude koguse
	unsigned int kogus;
	sisend >> kogus;
	// Loeme sisse nii mitu arvu ja arvutame kokku nende summa
	int summa = 0, arv;
	for (unsigned int i = 0; i < kogus; i++) {
		// Loeme sisse järgmise arvu
		sisend >> arv;
		// Liidame sisseloetud arvu summale otsa
		summa += arv;
	}
	// Sulgeme sisendfaili
	sisend.close();
	// Tagastame arvude summa
	return summa;
}


int main() {
	// Defineerime failinime, kust arvud sisse lugeda
	string failinimi = "andmed/arvud.txt";

	// Loeme failist sisse N arvu ja leiame nende summa
	int summa = arvuta_summa(failinimi);

	// Väljastame summa käsureale
	cout << "Sisendfailis '" << failinimi << "' olevate arvude summa on " << summa << "." << endl;

	return 0;
}
