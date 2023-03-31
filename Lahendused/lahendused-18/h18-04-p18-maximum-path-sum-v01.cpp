/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-04: Project Euler problem 18: Maximum path sum I
 * Variant 01: Rekursiivne lahendus suunaga ülevalt alla (aeglasem)
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
// Kasutame rekursiooni, st kutsume sama funktsiooni uuesti välja
unsigned int leia_maksimaalne_tee(const std::vector<std::vector<int>>& puramiid, unsigned int rida = 0, unsigned int veerg = 0) {
	// Vaatleme üht elementi püramiidis kohal [rida; veerg]
	// Kui vaadeldava koha rida ja veerg pole määratud, määrati need vaikimi
	// parameetritega 0-ks - sel juhul on tegu püramiidi tipuga

	// Soovime tagastada maksimaalse tee vaadeldavast kohast allapoole
	// Kui tegu on viimase reaga, siis maksimaalne tee sellest allapoole koosneb
	// ainult elemendist endast
	// Sellisel juhul on teel asuvate elementide summa elemendi enda väärtus
	if (rida == puramiid.size() - 1) {
		return puramiid[rida][veerg];
	}

	// Vastasel juhul pole tegu püramiidi viimase reaga
	// Sellisel juhul algab maksimaalne tee sellest allapoole kas elemendist
	// vasakul või elemendist paremal asuvast elemendist tema all
	// Leiame need teed
	unsigned int vasak = leia_maksimaalne_tee(puramiid, rida + 1, veerg);
	unsigned int parem = leia_maksimaalne_tee(puramiid, rida + 1, veerg + 1);

	// Maksimaalne tee alates praegusest elemendist allapoole koosneb elemendist
	// endast ning kas vasakust või paremast teest - kumb iganes on suurem
	return puramiid[rida][veerg] + (vasak > parem ? vasak : parem);
}


int main() {
	std::vector<std::vector<int>> puramiid = loe_puramiid("data/arvupuramiid.txt");
	std::cout << leia_maksimaalne_tee(puramiid) << std::endl;
	return 0;
}
