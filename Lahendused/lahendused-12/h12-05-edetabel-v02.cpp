/**
 * Programmeerimine keeles C++
 * Sisend ja väljund voona
 * Harjutus 12-05: Edetabel
 * Variant 02: Edetabelis talletatakse vaid viiteid kirjetele
 * Ants-Oskar Mäesalu
 * 2022-02-28
 */

#include <iostream>	 				// std::cout, std::cin
#include <fstream>					// std::ifstream
#include <string>					// std::string
#include <cctype>					// isspace

using namespace std;

// Protseduur, mis loeb sisendfailist mängijate tulemused ja salvestab need
// kahte massiivi - ühte punktid, teise nimed
// Sisendfaili esimesel real on tulemuste kogus ning igal järgneval real üks
// täisarv, mis tähistab punktisummat, ja tulemuse saavutanud mängija nimi
// Massiividele eraldatakse mälu dünaamiliselt ja see tuleb pärast kasutamise
// lõppu vabastada
void loe_tulemused_failist(const string& failinimi, int*& punktid, string*& nimed, unsigned int& kogus) {
	// Avame sisendfaili
	ifstream sisend(failinimi);
	// Kui faili avamine ebaõnnestus, väljastame veateate ja lõpetame
	// funktsiooni töö
	if (!sisend.is_open()) {
		cout << "Viga! Faili '" << failinimi << "' ei saanud avada." << endl;
		return;
	}
	// Loeme sisse tulemuste koguse
	sisend >> kogus;
	// Eraldame tulemuste massiividele mälu nii mitme tulemuse salvestamiseks
	punktid = new int[kogus];
	nimed = new string[kogus];
	// Loeme sisse nii mitu tulemust ja salvestame need massiividesse
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Loeme sisse punktisumma
		sisend >> punktid[koht];
		// Viskame sisendvoost pärast punktisummat ära kõik tühimärgid
		// Funktsioon isspace() kontrollib, kas tähemärk on tühimärk
		// Sisendvoo meetod peek() leiab järgmise märgi seda ära võtmata
		// Sisendvoo meetod ignore() viskab järgmise märgi minema
		while (isspace(sisend.peek())) sisend.ignore();
		// Loeme sisse mängija nime
		getline(sisend, nimed[koht]);
	}
}

// Protseduur, mis leiab tulemuste paremusjärjestuse
// Edetabelit piiritletakse kindla kohtade arvuga
// Edetabelis talletatakse vaid viiteid kirjetele, aga mitte kirjeid endid
void leia_edetabel(int* punktid, string* nimed, unsigned int kogus, unsigned int*& edetabel, unsigned int edetabeli_suurus) {
	// Eraldame edetabelile vastavale massiivile mälu
	edetabel = new unsigned int[edetabeli_suurus];
	// Vaatleme ükshaaval iga tulemust ja lisame parimad edetabelisse
	unsigned int edetabelis = 0;
	for (unsigned int i = 0; i < kogus; i++) {
		// Vaatleme edetabeli iga elementi ja leiame tulemusele sobiva koha
		unsigned int koht;
		for (koht = 0; koht < edetabelis; koht++) {
			// Kui tulemus on edetabeli vaadeldavast elemendist suurem, peaks
			// selle edetabelis praegusele kohale asetama
			if (punktid[i] > punktid[edetabel[koht]]) break;
		}
		// Kui edetabelis ei ole veel kõik kohad täidetud, suurendame
		// edetabelisse kantud elementide kogust
		if (edetabelis < edetabeli_suurus) {
			edetabelis++;
		}
		// Kui vaadeldav tulemus oli mõnest edetabelis asuvast kirjest parem või
		// edetabelis oli vabu kohti, on kohta tähistava muutuja väärtus
		// edetabeli suurusest väiksem. Sellisel juhul lisame tulemuse tabelisse
		if (koht < edetabeli_suurus) {
			// Tulemuse edetabelisse lisamiseks peame edetabeli iga kirjet
			// alates nimetatud kohast ühe võrra edasi nihutama. Sellele on
			// loogiline läheneda vastupidises suunas elementide väärtusi üle
			// kirjutades.
			for (unsigned int j = edetabelis - 1; j > koht; j--) {
				edetabel[j] = edetabel[j - 1];
			}
			// Kui elemendid on nihutatud, saame tulemuse lõpuks sobivale kohale
			// lisada
			edetabel[koht] = i;
		}
	}
}

// Protseduur, mis väljastab edetabeli käsureale
void valjasta_edetabel(int* punktid, string* nimed, unsigned int* edetabel, unsigned int kogus) {
	for (unsigned int koht = 0; koht < kogus; koht++) {
		cout << "#" << koht + 1 << " - " << nimed[edetabel[koht]] << ", " << punktid[edetabel[koht]] << " punkti" << endl;
	}
}


int main() {
	// Defineerime sisendfaili asukoha ja nime
	string failinimi = "andmed/tulemused.txt";

	// Defineerime väljastatava edetabeli suuruse
	unsigned int edetabeli_suurus = 5;

	// Loeme failist sisse mängijate tulemused
	int* punktid = nullptr;
	string* nimed = nullptr;
	unsigned int kogus = 0;
	loe_tulemused_failist(failinimi, punktid, nimed, kogus);

	// Piiritleme edetabeli suurust, kui see peaks olema suurem kui tulemuste
	// kogus
	if (edetabeli_suurus > kogus) {
		cout << "Hoiatus! Edetabeli suurus " << edetabeli_suurus << " uletab tulemuste kogust " << kogus << "." << endl;
		cout << "Kasutame edetabeli suurust " << kogus << "." << endl;
		edetabeli_suurus = kogus;
	}

	// Leiame edetabeli
	unsigned int* edetabel = nullptr;
	leia_edetabel(punktid, nimed, kogus, edetabel, edetabeli_suurus);

	// Väljastame edetabeli
	cout << "Edetabel:" << endl;
	valjasta_edetabel(punktid, nimed, edetabel, edetabeli_suurus);

	// Vabastame tulemuste massiividele dünaamiliselt eraldatud mälu
	delete[] punktid;
	delete[] nimed;
	delete[] edetabel;

	return 0;
}
