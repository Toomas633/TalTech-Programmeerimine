/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-03: Juhuslik sõne
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <string>					// std::string
#include <cstdlib>					// rand, srand
#include <ctime>					// time

using namespace std;

// Protseduur, mis loeb sisendfailist sõned ja salvestab need massiivi
// Sisendfaili esimesel real on sõnede kogus ning igal järgneval real üks sõne
// Sõnede massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
void loe_soned_failist(const string& failinimi, string*& massiiv, unsigned int& kogus) {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return;
	}
	// Loeme sisse sõnede koguse
	sisend >> kogus;
	// Eraldame sõnede massiivile mälu nii mitme sõne salvestamiseks
	massiiv = new string[kogus];
	// Loeme sisse nii mitu sõne ja salvestame need massiivi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Loeme sisse järgmise sõne ja salvestame selle massiivi
		sisend >> massiiv[koht];
	}
}

// Funktsioon, mis genereerib juhuarvu vahemikus [alumine, ulemine]
int leia_juhuarv(int alumine, int ulemine) {
	// Funktsioon rand() genereerib juhuarvu vahemikus [0; RAND_MAX]
	// Jagamisel tekkiva jäägi leidmisel piirame selle vahemikku [0; jagaja - 1]
	// Jagaja peaks seega olema juhuarvude vahemiku suurus
	// Kui tulemusele juurde liita mingi arv, nihutab see tervet vahemikku
	return rand() % (ulemine - alumine + 1) + alumine;
}


int main() {
	// Defineerime juhuarvude generaatori seemne
	// Seeme määrab, millises järjestuses pseudojuhuarve genereeritakse. Sama
	// seemne puhul on järjestus alati samasugune, st kasutatav juhuarvude
	// genereerimise algoritm on deterministlik. Hetkel kasutame seemnena
	// praeguse ajahetke väärtust, et programmi igal käivituskorral oleks seeme
	// erinev.
	srand(time(NULL));

	// Defineerime sisendfaili asukoha ja nime
	string failinimi = "andmed/soned.txt";

	// Loeme failist sisse N sõne ja salvestame need dünaamilisse massiivi
	string* soned = nullptr;
	unsigned int kogus = 0;
	loe_soned_failist(failinimi, soned, kogus);

	// Kui sõnede massiiv oli võimalik sisse lugeda, siis eraldati sellele
	// dünaamiliselt mälu ja sõnede massiivile vastav mäluaadress pole tühiviit.
	// Ainult sellisel juhul saame massiivi kasutada.
	if (soned != nullptr) {

		// Kui sõnede kogus ei olnud 0, leiame massiivis juhusliku elemendi
		// kohanumbri ja väljastame sellele vastava elemendi väärtuse
		if (kogus > 0) {

			// Kuna massiivi elementide indeksid on vahemikus [0, N-1], leiame
			// juhusliku elemendi valimiseks juhuarvu just selles vahemikus
			unsigned int juhuslik = leia_juhuarv(0, kogus - 1);
			// Väljastame juhusliku elemendi
			// Kasutame selleks juhuslikult valitud kohanumbrit
			// Selliste operatsioonide puhul tuleb alati jälgida, et kasutatav
			// kohanumber oleks õiges vahemikus. Vastasel juhul on mäluvigade
			// tekkimise oht.
			cout << "Juhuslik sone: " << soned[juhuslik] << endl;

		} else {
			cout << "Viga! Tuhjast massiivist pole voimalik juhuslikku elementi leida." << endl;
		}

	} else {
		cout << "Viga! Sonede massiivi ei loodud." << endl;
	}

	// Vabastame sõnede massiivile dünaamiliselt eraldatud mälu
	delete[] soned;

	return 0;
}
