/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-04: Project Euler problem 18: Maximum path sum I
 * Variant 02: Dünaamilise plaanimisega lahendus suunaga alt üles (kiirem)
 * Ants-Oskar Mäesalu
 * 2022-04-01
 */

#include <iostream>	 				// std::cout
#include <fstream>					// std::ifstream
#include <sstream>					// std::stringstream
#include <string>					// std::string, std::getline
#include <vector>					// std::vector

// Funktsioon, mis loeb failist sisse arvupüramiidi
std::vector<std::vector<int>> loe_puramiid(const std::string& failinimi) {
	std::vector<std::vector<int>> puramiid;
	std::ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja katkestame töö
	if (!sisend.is_open()) {
		std::cout << "Viga! Faili \"" << failinimi << "\" avamine ebaonnestus." << std::endl;
		return puramiid;
	}
	// Vastasel juhul loeme failist arvupüramiidi ridade kaupa sisse
	std::string rida;
	while (std::getline(sisend, rida)) {
		// Tükeldame rea arvudeks sõnevoo abil
		std::stringstream sonevoog(rida);
		std::vector<int> puramiidi_rida;
		int arv;
		while (sonevoog >> arv) {
			puramiidi_rida.push_back(arv);
		}
		// Lisame rea püramiidi
		puramiid.push_back(puramiidi_rida);
	}
	sisend.close();
	return puramiid;
}

// Funktsioon, mis leiab maksimaalse summaga tee püramiidi tipust püramiidi
// aluseni
// Kasutame dünaamilist plaanimist, st salvestame vahetulemusi
unsigned int leia_maksimaalne_tee(std::vector<std::vector<int>> puramiid) {
	// Püramiidi võtame parameetris vastu nõnda, et loome sellest koopia
	// Kasutame seda koopiat ära, et salvestada algoritmi vahetulemusi

	// Vaatleme püramiidi ridade kaupa suunaga alt üles
	// Püramiidi viimasel real asuvad arvud vastavad juba maksimaalsetele
	// teedele neist elementidest allapoole
	// Püramiidi eelviimase rea elementide väärtusi saame vastavalt uuendada:
	// liidame neile neist allpool asuva vasakpoolse ja parempoolse elemendi
	// hulgast suurema
	// Selle tulemusel asuvad püramiidi eelviimasel real väärtused, mis vastavad
	// maksimaalsetele teedele neist elementidest allapoole
	// Sama saab jätkata kogu püramiidis, liikudes pidevalt sammhaaval ülespoole
	for (int rida = puramiid.size() - 2; rida >= 0; rida--) {
		for (unsigned int veerg = 0; veerg < puramiid[rida].size(); veerg++) {
			int vasak = puramiid[rida + 1][veerg];
			int parem = puramiid[rida + 1][veerg + 1];
			puramiid[rida][veerg] += (vasak > parem) ? vasak : parem;
		}
	}

	// Pärast kogu püramiidi sedasi töötlemist vastab püramiidi tipus asuv
	// väärtus maksimaalsele teele püramiidi tipust püramiidi aluseni
	return puramiid[0][0];
}


int main() {
	std::vector<std::vector<int>> puramiid = loe_puramiid("data/arvupuramiid.txt");
	std::cout << leia_maksimaalne_tee(puramiid) << std::endl;
	return 0;
}
