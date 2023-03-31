/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-05: Juhuarvu genereerimine
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <cstdlib>					// rand, srand
#include <ctime>					// time

using namespace std;

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

	// Defineerime juhuarvude alumise ja ülemise piiri
	int alumine = 5;
	int ulemine = 15;

	// Defineerime genereeritavate juhuarvude koguse
	int kogus = 12;

	// Genereerime ja väljastame nimetatud koguse juhuarve käsureale
	cout << "Valjastame " << kogus << " juhuarvu vahemikus [" << alumine << "; " << ulemine << "]:" << endl;
	for (int i = 0; i < kogus; i++) {
		cout << "  " << leia_juhuarv(alumine, ulemine) << endl;
	}

	return 0;
}
