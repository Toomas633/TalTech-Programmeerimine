/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-06: Palgaarvutus
 * Ants-Oskar Mäesalu
 * 2022-02-05
 *
 * Arvesse pole võetud miinimumpalka ega sotsiaalmaksu minimaalset kohustust.
 * Samuti puudub võimalus valida, kas rakendada tulumaksuvaba miinimumi,
 * töötuskindlustusmakseid ja kogumispensioni makset.
 * Väljund vastab palk.crew.ee 2021. aasta väljundile.
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision

using namespace std;

int main() {
	// Defineerime Eesti Vabariigi maksukeskkonnale vastavad konstandid

	// Tööandja maksud
	float tooandja_tootuskindlustuse_maar = 0.008;
	float sotsiaalmaksu_maar = 0.33;
	// Töötaja maksud
	float tootaja_tootuskindlustuse_maar = 0.016;
	float kogumispensioni_maar = 0.02;
	float tulumaksu_maar = 0.2;
	float tulumaksuvaba_max = 500;
	float tulumaksuvaba_kahanemise_algus = 1200;
	float tulumaksuvaba_kahanemise_lopp = 2100;

	// Küsime kasutajalt brutopalga, millega palgaarvutused läbi viia
	float brutokuupalk;
	cout << "Sisesta brutokuupalk: ";
	cin >> brutokuupalk;
	cout << endl;

	// Kontrollime, et sisestatud brutokuupalk oleks mittenegatiivne
	if (brutokuupalk >= 0) {

		// Arvutame välja tööandja kulud ja maksud
		float tooandja_tootuskindlustus = brutokuupalk * tooandja_tootuskindlustuse_maar;
		float sotsiaalmaks = brutokuupalk * sotsiaalmaksu_maar;
		float tooandja_maksud = tooandja_tootuskindlustus + sotsiaalmaks;
		float kogukulu = brutokuupalk + tooandja_maksud;

		// Arvutame välja töötaja palga ja maksud
		float tootaja_tootuskindlustus = brutokuupalk * tootaja_tootuskindlustuse_maar;
		float kogumispension = brutokuupalk * kogumispensioni_maar;
		float tulumaksuvaba = tulumaksuvaba_max;
		if (brutokuupalk > tulumaksuvaba_kahanemise_algus) {
			if (brutokuupalk < tulumaksuvaba_kahanemise_lopp) {
				tulumaksuvaba -= tulumaksuvaba_max * (brutokuupalk - tulumaksuvaba_kahanemise_algus) / (tulumaksuvaba_kahanemise_lopp - tulumaksuvaba_kahanemise_algus);
			} else {
				tulumaksuvaba = 0;
			}
		}
		float tulumaks = (brutokuupalk - tootaja_tootuskindlustus - kogumispension - tulumaksuvaba) * tulumaksu_maar;
		if (tulumaks < 0) {
			tulumaks = 0;
		}
		float tootaja_maksud = tootaja_tootuskindlustus + kogumispension + tulumaks;
		float netokuupalk = brutokuupalk - tootaja_maksud;

		// Arvutame välja maksud kokku
		float maksuametile = tooandja_maksud + tootaja_maksud;

		// Väljastame vastuse käsureale
		cout << fixed << setprecision(2);

		cout << "Tootaja palk ja maksud" << endl;
		cout << "  Brutokuupalk:                 " << brutokuupalk << endl;
		cout << "  Tootuskindlustus (tootaja):   " << tootaja_tootuskindlustus << endl;
		cout << "  Kogumispension:               " << kogumispension << endl;
		cout << "  Tulumaks:                     " << tulumaks << endl;
		cout << "  Netosumma (katte):            " << netokuupalk << endl << endl;

		cout << "Tooandja kulud ja maksud" << endl;
		cout << "  Kogukulu tooandjale:          " << kogukulu << endl;
		cout << "  Brutokuupalk:                 " << brutokuupalk << endl;
		cout << "  Sotsiaalmaks:                 " << sotsiaalmaks << endl;
		cout << "  Tootuskindlustus (tooandja):  " << tooandja_tootuskindlustus << endl << endl;

		cout << "Rahade jaotus" << endl;
		cout << "  Kogukulu tooandjale:          " << kogukulu << endl;
		cout << "  Tootajale (netosumma katte):  " << netokuupalk << endl;
		cout << "  Maksuametile (koik maksud):   " << maksuametile << endl;

	} else {
		cout << "Viga! Brutokuupalk peab olema mittenegatiivne." << endl;
	}

	return 0;
}
