/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-03: Sõnade esinemissagedused
 * Ants-Oskar Mäesalu
 * 2022-04-01
 */

#include "include/ajakulu.h"		// ajakulu
#include <iostream>	 				// std::cout, std::fixed
#include <fstream>					// std::ifstream
#include <iomanip>					// std::setprecision
#include <string>					// std::string, std::getline
#include <vector>					// std::vector
#include <map>						// std::map
#include <unordered_map>			// std::unordered_map

// Funktsioon, mis loeb failist sisse kõik read ja tagastab need sõnede loendina
std::vector<std::string> loe_read(const std::string& failinimi) {
	std::vector<std::string> read;
	std::ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja katkestame töö
	if (!sisend.is_open()) {
		std::cout << "Viga! Faili \"" << failinimi << "\" avamine ebaonnestus." << std::endl;
		return read;
	}
	// Vastasel juhul loeme failist andmed ridade kaupa sisse
	std::string rida;
	while (getline(sisend, rida)) {
		read.push_back(rida);
	}
	sisend.close();
	return read;
}

// Funktsioon, mis leiab sõnede esinemissagedused loendis
// Kasutab std::map andmestruktuuri, seega sisemiselt kahendotsingupuud
// Ajaline keerukus O(log n)
std::map<std::string, unsigned int> leia_sagedused_tabel(const std::vector<std::string>& loend) {
	std::map<std::string, unsigned int> sagedused;
	for (const std::string& element: loend) {
		sagedused[element]++;
	}
	return sagedused;
}

// Funktsioon, mis leiab sõnede esinemissagedused loendis
// Kasutab std::unordered_map andmestruktuuri, seega sisemiselt paisktabelit
// Ajaline keerukus O(1)
std::unordered_map<std::string, unsigned int> leia_sagedused_jarjestuseta_tabel(const std::vector<std::string>& loend) {
	std::unordered_map<std::string, unsigned int> sagedused;
	for (const std::string& element: loend) {
		sagedused[element]++;
	}
	return sagedused;
}


int main() {
	// Loeme sisse testandmed
	std::vector<std::string> sonad = loe_read("data/sonad.txt");

	// Viime läbi katsed ja mõõdame nendeks kuluvat aega
	unsigned int katseid = 10000;
	double ajakulu_tabel = ajakulu(katseid, leia_sagedused_tabel, sonad);
	double ajakulu_jarjestuseta_tabel = ajakulu(katseid, leia_sagedused_jarjestuseta_tabel, sonad);

	// Väljastame tulemused
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Katseid:     " << katseid << std::endl;
	std::cout << "Elemente:    " << sonad.size() << std::endl;
	std::cout << "Unikaalseid: " << leia_sagedused_jarjestuseta_tabel(sonad).size() << std::endl;
	std::cout << "Esinemissageduste loendamiseks kulus:" << std::endl;
	std::cout << "  std::map:           " << ajakulu_tabel << " sekundit" << std::endl;
	std::cout << "  std::unordered_map: " << ajakulu_jarjestuseta_tabel << " sekundit" << std::endl;

	return 0;
}
