/**
 * Programmeerimine keeles C++
 * Sisend ja väljund käsureal
 * Harjutus 05-01: Tervitus
 * Ants-Oskar Mäesalu
 * 2022-02-04
 */

#include <iostream> 				// std::cout, std::cin
#include <string>					// std::string, std::getline

using namespace std;

int main() {

	// 1. Küsime kasutajalt tema nime

	// Eraldame mälu kasutaja nime salvestamiseks
	string nimi;
	// Väljastame käsureale küsimuse
	cout << "Mis on Sinu nimi? ";
	// Loeme käsurealt sõne ja salvestame selle nime muutujasse
	// Kasutame selleks protseduuri getline(), mis loeb käsurealt sisse kõik
	// kuni reavahetusmärgini; reavahetusmärki sõnesse ei salvestata, vaid
	// visatakse minema
	getline(cin, nimi);

	// 2. Küsime kasutajalt tema vanust

	// Eraldame mälu kasutaja vanuse salvestamiseks
	int vanus;
	// Väljastame käsureale küsimuse
	cout << "Kui vana Sa oled? ";
	// Loeme käsurealt ühe täisarvu ja salvestame selle vanuse muutujasse
	// Kasutame selleks sisendvoo-operaatorit >>, mis loeb käsurealt sisse
	// esimese väärtuse kuni esimese ebasobiva märgini (näiteks tühimärk ehk
	// tühik või reavahetus vmt).
	cin >> vanus;
	// Vanuse sisestamiseks peab kasutaja vajutama sisestusklahvi (enter). Kuna
	// järgmiseks soovime taas kasutada protseduuri getline(), et sisse lugeda
	// kasutaja kool, peame vanusele järgneva reavahetusmärgi sisendvoost
	// minema viskama. Vastasel juhul ei saa me kooli andmeid kätte.
	// Sisendvoo-objekti cin meetod cin.ignore() loeb käsurealt ühe märgi ja
	// viskab selle minema. Kasutame seda üleliigse reavahetusmärgi minema-
	// viskamiseks.
	cin.ignore();

	// 3. Küsime kasutajalt tema kooli nime

	// Eraldame mälu kasutaja kooli salvestamiseks
	string kool;
	// Väljastame käsureale küsimuse
	cout << "Kus koolis Sa kaid? ";
	// Loeme käsurealt sõne ja salvestame selle kooli muutujasse
	getline(cin, kool);

	// 4. Väljastame käsureale kasutajale suunatud tervituse

	cout << endl << "Tere, " << nimi << "!" << endl;
	cout << "Loodan, et " << vanus << "-aastasena on Sul " << kool << "-s tore!" << endl;

	return 0;
}
