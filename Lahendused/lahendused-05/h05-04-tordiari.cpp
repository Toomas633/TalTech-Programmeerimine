/**
 * Programmeerimine keeles C++
 * Sisend ja väljund käsureal
 * Harjutus 05-04: Tordiäri
 * Ants-Oskar Mäesalu
 * 2022-02-04
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision
#include <cmath>					// ceil

using namespace std;

int main() {
	// Küsime kasutajalt küpsisetordi põhja mõõtmed
	int pikkus, laius;
	cout << "Sisesta tuhikuga eraldatult tordi pohja mootmed: ";
	cin >> pikkus >> laius;

	// Küsime kasutajalt küpsisetordi kõrguse
	int korgus;
	cout << "Sisesta tordi korgus: ";
	cin >> korgus;

	// Küsime kasutajalt küpsisepaki mahu
	int kupsiseid_pakis;
	cout << "Sisesta, mitu kupsist on uhes pakis: ";
	cin >> kupsiseid_pakis;

	// Küsime kasutajalt küpsisepaki hinna
	float paki_hind;
	cout << "Sisesta uhe kupsisepaki hind: ";
	cin >> paki_hind;

	// Arvutame tordi valmistamiseks vajalike küpsiste koguse, küpsisepakkide
	// koguse ja küpsisepakkide kogumaksumuse

	// Küpsisetordi valmistamiseks tarviliku küpsiste koguse arvutamiseks
	// kasutame küpsisetordi mõõtmeid
	int kupsiseid_tarvis = pikkus * laius * korgus;
	// Saadud tulemust kasutame küpsisepakkide koguse väljaarvutamiseks.
	// Siin võtame arvesse, et mõlemad jagamistehtes kasutatavad muutujad on
	// täisarvud, seega oleks ka nende tulemus täisarv ilma murdosata ehk tehte
	// matemaatilise tulemuse alumine täisosa. Seega peame ühe operandidest enne
	// tehte sooritamist ujupunktarvuks muutma.
	// Seejärel saame kasutada <cmath> teegis olevat funktsiooni ceil() (nagu
	// "ceiling" ehk "lagi"), et leida arvutustehte ülemine täisosa.
	// Lõpptulemuse salvestame täisarvu tüüpi muutujasse.
	int pakke_tarvis = ceil(float(kupsiseid_tarvis) / kupsiseid_pakis);
	// Saadud tulemust saame kasutada küpsisepakkide kogumaksumuse arvutamisel
	float maksumus = pakke_tarvis * paki_hind;

	// Väljastame tulemuse käsureale
	cout << fixed << setprecision(2);
	cout << endl << "Kupsisetordi valmistamiseks on tarvis " << kupsiseid_tarvis << " kupsist." << endl;
	cout << "Seega on tarvis " << pakke_tarvis << " pakki kupsiseid, mis lahevad kokku maksma " << maksumus << " eurot." << endl;

	return 0;
}
