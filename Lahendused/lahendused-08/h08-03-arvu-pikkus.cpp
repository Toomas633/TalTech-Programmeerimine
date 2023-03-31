/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-03: Arvu pikkus
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin

using namespace std;

// Funktsioon, mis leiab täisarvu pikkuse tähemärkides
unsigned int leia_pikkus(int arv) {
	// Alustame pikkusega 1, sest mistahes arvu üleskirjutamiseks on tarvis
	// vähemalt üht tähemärki
	unsigned int pikkus = 1;
	// Kui väärtus on negatiivne, tuleb ka miinusmärk tähemärkide koguse hulka
	// arvestada
	if (arv < 0) pikkus++;
	// Loeme kokku, mitu korda saab väärtust 10-ga jagada enne, kui sellest jääb
	// alles vaid 0. Väärtus 0 tähendab valikulause tingimuses väära väärtust
	// (false) ning mistahes muu väärtus tähistab tõest väärtust (true)
	while (arv /= 10) pikkus++;
	// Tagastame leitud pikkuse funktsiooni väljakutsujale
	return pikkus;
}


int main() {
	// Küsime kasutajalt ühe täisarvu
	// Siit on puudu sisendi veahaldus
	int arv;
	cout << "Sisesta uks taisarv: ";
	cin >> arv;

	// Leiame selle arvu pikkuse tähemärkides
	unsigned int pikkus = leia_pikkus(arv);

	// Väljastame selle arvu pikkuse käsureale
	cout << "Arvu " << arv << " pikkus: " << pikkus << " tahemark" << (pikkus != 1 ? "i" : "") << endl;

	return 0;
}
