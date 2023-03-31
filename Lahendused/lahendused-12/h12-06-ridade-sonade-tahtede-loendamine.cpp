/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-06: Ridade, sõnade ja tähtede loendamine
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <sstream>					// std::istringstream
#include <limits>					// std::numeric_limits
#include <string>					// std::string

using namespace std;

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe sõne
string loe_sone(const string& kusimus = "Sisesta sone") {
	// Deklareerime muutuja, millesse sõne sisse lugeda
	string sone;
	// Esitame kasutajale küsimuse ja loeme sisse ühe sõne
	cout << kusimus << ": ";
	cin >> sone;
	// Tühjendame kõik, mis sisendvoogu jäänud
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// Tagastame sisseloetud sõne
	return sone;
}

// Funktsioon, mis loeb sisse kogu faili sisu ja tagastab selle sõnena
string loe_fail(const string& failinimi) {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return "";
	}
	// Loeme kogu faili sisu sisse
	ostringstream sonevoog;
	sonevoog << sisend.rdbuf();
	// Tagastame sisseloetud sisu sõnena
	return sonevoog.str();
}

// Protseduur, mis väljastab, mitu rida, mitu sõna ja mitu tähemärki on sõnes
void valjasta_sisu_statistika(const string& sisu) {
	// Deklareerime muutujad ridade, sõnade ja tähemärkide arvu loendamiseks
	unsigned int ridade_arv = 0, sonade_arv = 0, tahemarkide_arv = 0;
	// Avame sisule vastava sõne sisendvoona
	istringstream sisend(sisu);
	// Loeme sõnest järjest sisse kõik read
	string rida;
	while (getline(sisend, rida)) {
		// Kui rida oli võimalik sisse lugeda, suurendame ridade arvu
		ridade_arv++;
		// Samuti liidame tähemärkide arvule rea pikkuse tähemärkides
		// Liidame juurde 1, et ka reavahetusmärk sisse arvestada
		tahemarkide_arv += rida.size() + 1;
		// Kasutame rida sõnevoona ja loendame selles sõnade arvu
		// Liidame selle kogu failide sõnade arvule
		string sona;
		istringstream sonevoog(rida);
		while (sonevoog >> sona) {
			sonade_arv++;
		}
	}
	// Väljastame vastuse käsureale
	cout << "Ridade arv:      " << ridade_arv << endl;
	cout << "Sonade arv:      " << sonade_arv << endl;
	cout << "Tahemarkide arv: " << tahemarkide_arv << endl;
}


int main() {
	// Küsime kasutajalt failinime
	string failinimi = loe_sone("Sisestage analuusitava faili nimi");

	// Loeme kogu faili sisu sisse
	string sisu = loe_fail(failinimi);

	// Analüüsime faili sisu ja väljastame statistika
	cout << "Fail: " << failinimi << endl;
	valjasta_sisu_statistika(sisu);

	return 0;
}
