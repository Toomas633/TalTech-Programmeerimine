/**
 * Programmeerimine (RAM0620)
 * TalTech Tartu kolledž
 * Kodutöö 03: Kasutajasüsteem
 * Ants-Oskar Mäesalu
 * 2022-04-03
 * Kodutööna täiendas Toomas Kirsing
*/

#include <iostream>			// std::cout, std::cin, std::ostream, std::istream
#include <fstream>			// std::ifstream, std::ofstream
#include <vector>			// std::vector
#include "lib/sisend.hpp"	// loe_taisarv_vahemikus, loe_rida
#include <sstream>
#include "lib/sha512/sha512.hh"
#include <algorithm>

using namespace std;

class Kasutaja 
{
    public:
        Kasutaja() {};
        friend Kasutaja loe_andmed(string sisend);
        friend class Kasutajasusteem;
		~Kasutaja() {};
    private:
        int id;
        std::string kasutajanimi;
        std::string parool;
        std::string eesnimi;
        std::string perenimi;
};

class Kasutajasusteem 
{
public:
	Kasutajasusteem(const std::string& failinimi);
	void maaraFail(const std::string& failinimi);
	void kaivita();
	friend int main();

private:
	std::string failinimi;
	Kasutaja kasutaja;
	vector<Kasutaja> kasutajad;
	int number;

	bool onSisseLogitud;

	void loeKasutajad(string failinimi);
	void kirjutaKasutajad();

	void kuvaPealkiri(const std::string& pealkiri);
	void kuvaMenuu();
	void kuvaLopetus();

	int loeKasklus();
	bool taidaKasklus(int kasklus);
	void ootaKasutajat();

	void registreeri();
	void logiSisse();
	void logiValja();
	void kuvaProfiil();
	void muudaParool();
	void kuvaNimekiri();

};


Kasutajasusteem::Kasutajasusteem(const std::string& failinimi) {
	maaraFail(failinimi);
	onSisseLogitud = false;
}

void Kasutajasusteem::maaraFail(const std::string& failinimi) {
	this->failinimi = failinimi;
	loeKasutajad(failinimi);
}

void Kasutajasusteem::kaivita() {
	bool jatka;
	do {
		jatka = true;
		kuvaPealkiri("MENUU");
		kuvaMenuu();
		std::cout << std::endl;
		int kasklus = loeKasklus();
		std::cout << std::endl;
		jatka = taidaKasklus(kasklus);
		std::cout << std::endl;
	} while (jatka);
}

Kasutaja loe_andmed(string sisend) {
    Kasutaja kasutaja;
    string b;
    stringstream ss;
    ss.str(sisend);
    int n = 0;
    while(getline(ss, b, '|')) {
		b.erase(remove(b.begin(), b.end(), ' '), b.end());
        if (n == 0){
            istringstream(b) >> kasutaja.id;
            n++;
        }
        else if (n == 1) {
            kasutaja.kasutajanimi = b;
            n++;
        }
        else if (n == 2) {
            kasutaja.parool = b;
            n++;
        }
        else if (n == 3) {
            kasutaja.eesnimi = b;
            n++;
        }
       else kasutaja.perenimi = b;
    } 
    return kasutaja;
}

void Kasutajasusteem::loeKasutajad(string failinimi) {
    ifstream fail(failinimi);
    string a;
    if (!fail.is_open()) {
        cout << "Faili " << failinimi << " ei saanud avada, valjun!" << endl;
        exit(0);
    }
    getline(fail, a);
	number = 0;
    while (getline (fail, a)) {
        kasutaja = loe_andmed(a);
		kasutajad.push_back(kasutaja);
		number += 1;
    }
    fail.close();
}

void Kasutajasusteem::kirjutaKasutajad() {
	ofstream fail(failinimi);
	Kasutaja temp;
    fail << "id | kasutajanimi | parool | eesnimi | perekonnanimi" << endl;
    for (int i = 0; i < number; i++) {
		temp = kasutajad[i];
		fail << temp.id << " | " << temp.kasutajanimi << " | " << temp.parool << " | " << temp.eesnimi << " | " << temp.perenimi << endl;
	}
    fail.close();
}

void Kasutajasusteem::kuvaMenuu() {
	if (onSisseLogitud) {
		std::cout << "Tere, " << kasutaja.eesnimi << ' ' << kasutaja.perenimi << "!" << std::endl << std::endl;
		std::cout << "1. Kuva profiil" << std::endl;
		std::cout << "2. Muuda parooli" << std::endl;
		std::cout << "0. Logi valja" << std::endl;
	} else {
		std::cout << "1. Logi sisse" << std::endl;
		std::cout << "2. Registreeri" << std::endl;
		std::cout << "3. Kasutajate nimekiri" << std::endl;
		std::cout << "0. Valju" << std::endl;
	}
}

void Kasutajasusteem::kuvaPealkiri(const std::string& pealkiri) {
	for (unsigned int i = 0; i < pealkiri.size(); i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << pealkiri << std::endl;
	for (unsigned int i = 0; i < pealkiri.size(); i++) {
		std::cout << "-";
	}
	std::cout << std::endl << std::endl;
}

void Kasutajasusteem::kuvaLopetus() {
	std::cout << "Taname, et kasutasite meie programmi!" << std::endl;
}

int Kasutajasusteem::loeKasklus() {
	unsigned int menuus_valikuid = onSisseLogitud ? 3 : 4;
	return loe_taisarv_vahemikus(0, menuus_valikuid - 1, "Sisesta valik menuus");
}

bool Kasutajasusteem::taidaKasklus(int kasklus) {
	if (onSisseLogitud) {
		switch (kasklus) {
			case 1:
				kuvaPealkiri("MINU PROFIIL");
				kuvaProfiil();
				std::cout << std::endl;
				ootaKasutajat();
				return true;
			case 2:
				kuvaPealkiri("PAROOLI VAHETAMINE");
				muudaParool();
				std::cout << std::endl;
				return true;
			case 0:
			default:
				kuvaPealkiri("VALJALOGIMINE");
				logiValja();
				std::cout << std::endl;
				return true;
		}
	} else {
		switch (kasklus) {
			case 1:
				kuvaPealkiri("SISSELOGIMINE");
				logiSisse();
				std::cout << std::endl;
				return true;
			case 2:
				kuvaPealkiri("REGISTREERIMINE");
				registreeri();
				std::cout << std::endl;
				return true;
			case 3:
				kuvaPealkiri("KASUTAJATE NIMEKIRI");
				kuvaNimekiri();
				std::cout << std::endl;
				ootaKasutajat();
				return true;
			case 0:
			default:
				kuvaPealkiri("PROGRAMMI SULGEMINE");
				kuvaLopetus();
				return false;
		}
	}
}

void Kasutajasusteem::ootaKasutajat() {
	loe_rida("Vajuta ENTERit, et jatkata");
}

void Kasutajasusteem::registreeri() {
	bool lopp = false, tuhi = true, tuhi_1 = true, tuhi_2 = true;
	string kasnimi, pass, nimi, pernimi;
	vector<string> k;
	for (int i = 0; i < number; i++) {
		k.push_back(string(kasutajad[i].kasutajanimi));
	}
	do {
		cout << "Sisesta kasutajanimi: ";
		cin >> kasnimi;
		auto it = find(k.begin(), k.end(), kasnimi);
		if (it != k.end()) {
			cout << "Kasutaja on juba olemas!" << endl;
			lopp = false;
		}
		else {
			kasutaja.kasutajanimi = kasnimi;
			do {
				cout << "Sisesta parool (6+ marki): ";
				cin >> pass;
				if (pass.size() < 6) {
					cout << "Parool on liiga luhike! Peab olema vahemalt 6 marki." << endl;
					lopp = false;
				}
				else {
					kasutaja.parool = sw::sha512::calculate(pass);
					do {
						cout << "Sisesta enda eesnimi: ";
						cin >> nimi;
						if (nimi.length() == 0) tuhi_1 = true;
						else tuhi_1 = false;
						cout << "Sisesta enda perekonnanimi: ";
						cin >> pernimi;
						if (pernimi.length() == 0)tuhi_2 = true;
						else tuhi_2 = false;
						if (tuhi_1 == true && tuhi_2 == true) {
							cout << "Uks nime lahtritest peab olema taidetud!" << endl;
							tuhi = true;
						}
						else {
							kasutaja.eesnimi = nimi;
							kasutaja.perenimi = pernimi;
							int id_1 = kasutajad[0].id;
							int id;
							for (int i = 1; i < number; i++) {
								int id_2 = kasutajad[i].id;
								if (id_2 > id_1) {
									id_1 = id_2;
									id = id_1 + 1;
								}
								else id = id_1 + 1;
							}
							kasutaja.id = id;
							kasutajad.push_back(kasutaja);
							number += 1;
							kirjutaKasutajad();
							tuhi = false;
							lopp = true;
						} 

					} while (tuhi);
				}
			} while (!lopp);
		}
	} while (!lopp);
}

void Kasutajasusteem::logiSisse() {
	string nimi, pass;
	Kasutaja temp;
	vector<string> k;
	int n = 0, m = 0;
	bool lopp = false;
	for (int i = 0; i < number; i++) {
		k.push_back(string(kasutajad[i].kasutajanimi));
	}
	do {
		cout << "Sisesta kasutajanimi: ";
		cin >> nimi;
		auto it = find(k.begin(), k.end(), nimi);
		if (it != k.end()) {
			int index = distance(k.begin(), it);
			temp = kasutajad[index];
			do {
				cout << "Sisesta parool: ";
				cin >> pass;
				if (sw::sha512::calculate(pass) == temp.parool) {
					kasutaja = temp;
					onSisseLogitud = true;
					lopp = true;
				}
				else {
					cout << "Vale parool!" << endl;
					if (m < 3) {
						m++;
						lopp = false;
					}
					else lopp = true;
				}
			} while (!lopp);
		}
		else {
			cout << "Kasutajat ei leitud!" << endl;
			if (n < 3) {
				n++;
				lopp = false;
			}
			else lopp = true;
		}
	} while (!lopp);
}

void Kasutajasusteem::logiValja() {
	std::cout << "Olete edukalt valja logitud!" << std::endl;
	Kasutaja temp;
	temp.eesnimi = temp.kasutajanimi = temp.parool = temp.perenimi = "";
	temp.id = 0;
	kasutaja = temp;
	onSisseLogitud = false;
}

void Kasutajasusteem::kuvaProfiil() {
	cout << "id: " << kasutaja.id << endl;
	cout << "kasutajanimi: " << kasutaja.kasutajanimi << endl;
	cout << "eesnimi: " << kasutaja.eesnimi << endl;
	cout << "perekonnanimi: " << kasutaja.perenimi << endl;
}

void Kasutajasusteem::muudaParool() {
	string pass, pass_1;
	bool lopp = false;
	do {
		cout << "Sisesta praegune parool: ";
		cin >> pass;
		if (sw::sha512::calculate(pass) != kasutaja.parool) {
			cout << "Vale parool! Proovi uuesti." << endl;
			lopp = false;
		}
		else {
			do {
				cout << "Sisesta uus parool (6+ marki): ";
				cin >> pass;
				cout << "Sisesta uus parool uuesti: ";
				cin >> pass_1;
				if (pass != pass_1) {
					cout << "Paroolid ei uhti!";
					lopp = false;
				}
				else {
					kasutaja.parool = sw::sha512::calculate(pass_1);
					for (int i = 0; i < number; i++) {
						if (kasutaja.id == kasutajad[i].id) {
							kasutajad[i].parool = kasutaja.parool;
						}
					}
					kirjutaKasutajad();
					lopp = true;
				}
			} while (!lopp);
		}
	} while (!lopp);
}

void Kasutajasusteem::kuvaNimekiri() {
	Kasutaja kas;
    for (int i = 0; i < number; i++){
		kas = kasutajad[i];
		cout << "id: " << kas.id << " | kasutajanimi: " << kas.kasutajanimi << " | eesnimi: " << kas.eesnimi << " | perekonnanimi: " << kas.perenimi << endl;
	}
}

int main() {
	Kasutajasusteem kasutajasusteem("data/kasutajad.txt");
	kasutajasusteem.kaivita();
	return 0;
}