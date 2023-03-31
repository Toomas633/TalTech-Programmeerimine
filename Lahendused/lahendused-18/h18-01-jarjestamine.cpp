/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-01: Järjestamine
 * Ants-Oskar Mäesalu
 * 2022-04-01
 */

#include <iostream>	 				// std::cout
#include <fstream>					// std::ifstream, std::ofstream
#include <string>					// std::string, std::getline
#include <vector>					// std::vector
#include <algorithm>				// std::sort

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

// Protseduur, mis kirjutab sõnede loendi faili, asetades iga sõne eraldi reale
void kirjuta_read(const std::vector<std::string>& read, const std::string& failinimi) {
	std::ofstream valjund(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja katkestame töö
	if (!valjund.is_open()) {
		std::cout << "Viga! Faili \"" << failinimi << "\" avamine ebaonnestus." << std::endl;
		return;
	}
	// Vastasel juhul kirjutame loendi elemendid ridade kaupa faili
	for (const std::string& rida: read) {
		valjund << rida << std::endl;
	}
	valjund.close();
}


int main() {
	// Defineerime sisend- ja väljundfaili asukohad
	std::string sisendfail = "data/sonad.txt";
	std::string valjundfail = "data/jarjestatud.txt";
	// Loeme sõnad sisse
	std::vector<std::string> sonad = loe_read(sisendfail);
	// Järjestame need
	std::sort(sonad.begin(), sonad.end());
	// Kirjutame sõnad järjestatud kujul väljundfaili
	kirjuta_read(sonad, valjundfail);

	return 0;
}
