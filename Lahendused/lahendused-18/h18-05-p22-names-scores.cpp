/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-05: Project Euler problem 22: Names scores
 * Ants-Oskar Mäesalu
 * 2022-04-01
 */

#include <iostream>	 				// std::cout
#include <fstream>					// std::ifstream>
#include <sstream>					// std::stringstream
#include <limits>					// std::numeric_limits, std::streamsize
#include <string>					// std::string, std::getline
#include <vector>					// std::vector
#include <unordered_map>			// std::unordered_map
#include <algorithm>				// std::sort

// Funktsioon, mis loeb failist sisse nimede loendi
// Nimed on eraldatud komadega ning nimede ümber on jutumärgid
std::vector<std::string> loe_nimed(const std::string& failinimi) {
	std::vector<std::string> nimed;
	std::ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja katkestame töö
	if (!sisend.is_open()) {
		std::cout << "Viga! Faili \"" << failinimi << "\" avamine ebaonnestus." << std::endl;
		return nimed;
	}
	// Vastasel juhul loeme failist nimed sisse
	std::string nimi;
	while (std::getline(sisend, nimi, ',')) {
		std::stringstream sonevoog(nimi);
		sonevoog.ignore(std::numeric_limits<std::streamsize>::max(), '"');
		std::getline(sonevoog, nimi, '"');
		nimed.push_back(nimi);
	}
	return nimed;
}

// Funktsioon, mis koostab tabeli, mille võtmeteks on tähed ladina tähestikust
// ja vastavateks väärtusteks nende positsioonid tähestikus
std::unordered_map<char, unsigned int> koosta_tahestiku_vastavustabel() {
	std::unordered_map<char, unsigned int> tabel;
	for (unsigned int i = 0; i <= 'Z' - 'A'; i++) {
		tabel['A' + i] = i + 1;
	}
	return tabel;
}

// Funktsioon, mis leiab nimele vastava summa, mille liidetavateks on nimes
// sisladuvate tähtede positsioonid ladina tähestikus
unsigned int leia_tahtede_summa(const std::string& nimi, const std::unordered_map<char, unsigned int>& tahestik) {
	unsigned int summa = 0;
	for (char taht: nimi) {
		summa += tahestik.at(taht);
	}
	return summa;
}

// Funktsioon, mis leiab igale nimele vastava summa, mille liidetavateks on
// nimes sisalduvate tähtede positsioonid ladina tähestikus
std::vector<unsigned int> leia_tahtede_summad(const std::vector<std::string>& nimed, const std::unordered_map<char, unsigned int>& tahestik) {
	std::vector<unsigned int> summad(nimed.size());
	for (unsigned int i = 0; i < nimed.size(); i++) {
		summad[i] = leia_tahtede_summa(nimed[i], tahestik);
	}
	return summad;
}

// Funktsioon, mis korrutab loendi elementide järjekorranumbrid järjestatud
// loendis neile vastavate väärtustega teises loendis
std::vector<unsigned int> leia_korrutised_jarjestusega(const std::vector<std::string>& loend, const std::vector<unsigned int>& vaartused) {
	// Leiame iga nime järjekorranumbri
	std::vector<std::string> jarjestatud(loend);
	std::sort(jarjestatud.begin(), jarjestatud.end());
	std::unordered_map<std::string, unsigned int> jarjekorranumbrid;
	for (unsigned int i = 0; i < jarjestatud.size(); i++) {
		jarjekorranumbrid[jarjestatud[i]] = i + 1;
	}
	// Leiame elementidele vastavate väärtuste korrutised elementide
	// järjekorranumbritega järjestatud loendis
	std::vector<unsigned int> korrutised(loend.size());
	for (unsigned int i = 0; i < loend.size(); i++) {
		korrutised[i] = vaartused[i] * jarjekorranumbrid[loend[i]];
	}
	return korrutised;
}

// Funktsioon, mis leiab loendi elementide väärtuste summa
unsigned int leia_summa(const std::vector<unsigned int>& loend) {
	unsigned int summa = 0;
	for (unsigned int element: loend) {
		summa += element;
	}
	return summa;
}


int main() {
	std::vector<std::string> nimed = loe_nimed("data/names.txt");
	std::unordered_map<char, unsigned int> tahestik = koosta_tahestiku_vastavustabel();
	std::vector<unsigned int> summad = leia_tahtede_summad(nimed, tahestik);
	std::vector<unsigned int> korrutised = leia_korrutised_jarjestusega(nimed, summad);
	std::cout << leia_summa(korrutised) << std::endl;
	return 0;
}
