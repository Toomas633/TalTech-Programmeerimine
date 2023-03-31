/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-01: Faili esitamine
 * Versioon 01: Fail loetakse sisse osade kaupa
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
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

// Protseduur, mis väljastab faili sisu ridade kaupa käsureale
// Iga kord pärast soovitud arvu ridade väljastamist jääb programm ootama
// kasutajapoolset sisendit, et kuvada järgmine tükk failist
void valjasta_osadena(const string& failinimi, unsigned int ridade_limiit) {
	// Avame sisendfaili voona
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// protseduuri töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return;
	}
	// Loeme failist sisse read kuni limiidini ja väljastame need käsureale
	// Seejäreal ootame kasutaja sisendit, et järgmine plokk ridu väljastada
	unsigned int ridade_arv = 0;
	string rida;
	while (getline(sisend, rida)) {
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
	// Sulgeme sisendfaili
	sisend.close();
}


int main() {
	// Defineerime ridade arvu, mille kaupa fail käsureale kirjutada
	unsigned int ridade_limiit = 20;

	// Küsime kasutajalt failinime
	string failinimi = loe_sone("Sisestage analuusitava faili nimi");

	// Väljastame faili sisu osade kaupa
	cout << "Faili sisu:" << endl;
	valjasta_osadena(failinimi, ridade_limiit);
	cout << endl;

	return 0;
}
