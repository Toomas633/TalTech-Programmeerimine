/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-01: Faili esitamine
 * Versioon 02: Fail loetakse sisse korraga, hiljem töödeldakse sõnevoo abil
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <sstream>					// std::ostringstream, std::istringstream
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

// Protseduur, mis väljastab mitmerealise sõne osade kaupa käsureale
// Iga kord pärast soovitud arvu ridade väljastamist jääb programm ootama
// kasutajapoolset sisendit, et kuvada järgmine tükk sõnest
void valjasta_osadena(const string& sone, unsigned int ridade_limiit) {
	// Avame sõne sisendvoona
	istringstream sonevoog(sone);
	// Loeme sõnevoost sisse read kuni limiidini ja väljastame need käsureale
	// Seejärel ootame kasutaja sisendit, et järgmine plokk ridu väljastada
	unsigned int ridade_arv = 0;
	string rida;
	while (getline(sonevoog, rida)) {
		// Kui rida oli võimalik sisse lugeda, väljastame selle käsureale ning
		// suurendame ridade loendurit
		cout << rida << endl;
		ridade_arv++;
		// Kui ridade arv on jõudnud limiidini, ootame kasutajalt sisendit ja
		// alustame ridade loendamist uuesti otsast peale
		if (ridade_arv == ridade_limiit) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			ridade_arv = 0;
		}
	}
}


int main() {
	// Defineerime ridade arvu, mille kaupa fail käsureale kirjutada
	unsigned int ridade_limiit = 20;

	// Küsime kasutajalt failinime
	string failinimi = loe_sone("Sisestage analuusitava faili nimi");

	// Loeme kogu faili sisu sisse
	string sisu = loe_fail(failinimi);

	// Väljastame faili sisu osade kaupa
	cout << "Faili sisu:" << endl;
	valjasta_osadena(sisu, ridade_limiit);
	cout << endl;

	return 0;
}
