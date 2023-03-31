/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-05: Teemant
 * Variant 02: Korduvat koodi on vähendatud
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab teemandi küljepikkust
	int pikkus;
	cout << "Sisesta teemandi kuljepikkus: ";
	cin >> pikkus;

	// Väljastame teemandi ülemise nurga, st esimese rea
	// Nurgale vastava tärni ees peab asuma 'pikkus - 1' tühikut
	for (int i = 1; i < pikkus; i++) {
		cout << ' ';
	}
	cout << '*' << endl;

	// Paneme tähele, et eelmises variandis oli teemandi teisest reast kuni
	// keskpunktini ja sealt kuni eelviimase reani korduslauses kasutatud
	// täpselt sama sisu. Selle korduvuse saame kaotada, kui kasutame reanumbri
	// muutmisel uut muutujat 'suund', mille väärtus on kas 1 või -1 vastavalt
	// sellele, kas reanumber peaks kasvama või kahanema
	int rida = 0;
	for (int suund = 1; suund > -2; suund -= 2) {
		// Kasvavas suunas peaks alustama alates reast 2
		// Kahanevas suunas peaks alustama alates reast 'pikkus - 1', aga
		// kasvava suuna lõpuks on reaks 'pikkus + 1'
		rida += 2 * suund;
		// Väljastame ükshaaval iga rea, nagu eelmiseski variandis
		// Erinevuseks on tingimus, mis katab nii alumist kui ka ülemist piiri,
		// ja iga korduse lõpus olev reanumbri muutmine suunamuutuja abil
		while (rida >= 2 && rida <= pikkus) {
			// Vasakpoolsele tärnile eelneb 'pikkus - rida' tühikut
			for (int i = rida; i < pikkus; i++) {
				cout << ' ';
			}
			// Väljastame vasakpoolse tärni
			cout << '*';
			// Vasak- ja parempoolse tärni vahel asub '2 * (rida - 2) + 1' tühikut,
			// st '2 * rida - 3' tühikut
			for (int i = 3; i < 2 * rida; i++) {
				cout << ' ';
			}
			// Väljastame parempoolse tärni ja lõpetame rea
			cout << '*' << endl;
			// Muudame rea väärtust
			// Kasvavas suunas liidame juurde 1, kahanevas suunas -1
			rida += suund;
		}
	}

	// Kasutatud meetod korduva koodi vähendamiseks pole tingimata optimaalne,
	// kuna lisasime operatsioone ja rea väljastamise tingimus muutus natuke
	// keerukamaks, kuna peab hõlmama nii alumist kui ülemist piirangut. Samas
	// on kood selle tulemusel natuke hallatavam: kui tahame ridade väljastamise
	// loogikas muutust sisse viia, siis peame seda tegema vaid ühes kohas.

	// Väljastame teemandi alumise nurga, st viimase rea
	// Nurgale vastava tärni ees peab asuma 'pikkus - 1' tühikut
	// Kui kolmnurga küljepikkus on 1, siis peaksime kokku väljastama vaid ühe
	// tärni, seega sellisel juhul viimast tärni väljastada ei tohiks
	if (pikkus != 1) {
		for (int i = 1; i < pikkus; i++) {
			cout << ' ';
		}
		cout << '*' << endl;
	}

	return 0;
}
