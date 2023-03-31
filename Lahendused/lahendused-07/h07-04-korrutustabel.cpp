/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-04: Korrutustabel
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <iomanip>					// std::setfill, std::setw
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab korrutustabeli suurust
	int suurus;
	cout << "Sisesta korrutustabeli suurus: ";
	cin >> suurus;

	// Arvutame korrutustabeli vormistamiseks välja korrutustabeli kõige suurema
	// arvu pikkuse
	// Kui soovime korrutustabelit tabeli kujul vormindada, saame suurima
	// elemendi pikkust ära kasutada kõigi elementide soovitud laiusena ning
	// tühjad kohad täita tühikutega. Siin liidame laiusele veel 1, et asetada
	// tühik ka kõrvutiasetsevate elementide vahele.
	int suurim = suurus * suurus;
	int laius = 1;
	while (suurim /= 10) {
		laius++;
	}
	laius++;

	// Määrame väljundvoos täitemärgiks tühiku. Kui väljastatavatele väärtustele
	// määratud pikkus on suurem nende tegelikust pikkusest, täidetakse
	// puuduvad märgid tühikutega. Vaikimisi joondatakse tegelik väärtus
	// paremale, st tühikud asetatakse väärtuse ette. Nii on võimalik väärtusi
	// kergesti tabeli kujul vormistada.
	// Tasub tähele panna, et täitemärki on tarvis määrata vaid korra. See
	// rakendub edaspidi kõigile väärtustele, mis pärast seda väljastatakse ja
	// millele on eelnevalt mingi pikkus määratud.
	cout << setfill(' ');

	// Kasutame kahekordset korduslauset, et korrutustabel väljastada
	for (int rida = 1; rida <= suurus; rida++) {
		for (int veerg = 1; veerg <= suurus; veerg++) {
			// Väljastame elemendi mingi kindla laiusega. Kui elemendi väärtus
			// on märkide arvult lühem, pannakse selle ette vastav kogus
			// tühikuid.
			cout << setw(laius) << (rida * veerg);
		}
		// Iga korrutustabeli rea lõpetame reavahetusmärgiga
		cout << endl;
	}

	return 0;
}
