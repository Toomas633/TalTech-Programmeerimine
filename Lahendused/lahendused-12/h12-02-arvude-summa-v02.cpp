/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-02: Arvude summa
 * Variant 02: Andmed loetakse massiivi, summa arvutatakse massiivi põhjal
 *   Modulaarsem lähenemine, aga pisut rohkem tööd
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <string>					// std::string

using namespace std;

// Protseduur, mis loeb sisendfailist arvud ja salvestab need massiivi
// Sisendfaili esimesel real on arvude kogus ning igal järgneval real üks arv
// Arvude massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
void loe_arvud_failist(const string& failinimi, int*& massiiv, unsigned int& kogus) {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return;
	}
	// Loeme sisse arvude koguse
	sisend >> kogus;
	// Eraldame arvude massiivile mälu nii mitme arvu salvestamiseks
	massiiv = new int[kogus];
	// Loeme sisse nii mitu arvu ja salvestame need massiivi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Loeme sisse järgmise arvu ja salvestame selle massiivi
		sisend >> massiiv[koht];
	}
}

// Funktsioon, mis arvutab välja ja tagastab täisarvude massiivi elementide
// väärtuste summa
int arvuta_summa(int* massiiv, unsigned int kogus) {
	// Algväärtustame summa 0-na
	int summa = 0;
	// Vaatleme järjestikuselt iga elementi massiivis ja liidame selle summale
	// juurde
	for (unsigned int koht = 0; koht < kogus; koht++) {
		summa += massiiv[koht];
	}
	// Tagastame väärtuste summa
	return summa;
}


int main() {
	// Defineerime failinime, kust arvud sisse lugeda
	string failinimi = "andmed/arvud.txt";

	// Loeme failist sisse N arvu ja salvestame need dünaamilisse massiivi
	int* arvud = nullptr;
	unsigned int kogus = 0;
	loe_arvud_failist(failinimi, arvud, kogus);

	// Kui arvude massiiv oli võimalik sisse lugeda, siis eraldati sellele
	// dünaamiliselt mälu ja arvude massiivile vastav mäluaadress pole tühiviit.
	// Ainult sellisel juhul saame massiivi kasutada.
	if (arvud != nullptr) {

		// Arvutame välja massiivi salvestatud arvude summa
		int summa = arvuta_summa(arvud, kogus);

		// Väljastame summa käsureale
		cout << "Sisendfailis '" << failinimi << "' oleva " << kogus << " arvu summa on " << summa << "." << endl;

	} else {
		cout << "Viga! Arvude massiivi ei loodud." << endl;
	}

	// Vabastame arvude massiivile dünaamiliselt eraldatud mälu
	delete[] arvud;

	return 0;
}
