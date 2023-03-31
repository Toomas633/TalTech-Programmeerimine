/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-03: Liitintress
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime käsurealt positiivse reaalarvu, mis tähistab laenusummat
	double laenusumma;
	cout << "Sisesta laenusumma: ";
	cin >> laenusumma;

	// Küsime käsurealt reaalarvu, mis tähistab intressimäära kuus
	double intressimaar;
	cout << "Sisesta kuu intressimäär: ";
	cin >> intressimaar;

	// Küsime käsurealt positiivse täisarvu, mis tähistab kuude hulka
	int kuude_arv;
	cout << "Sisesta kuude arv: ";
	cin >> kuude_arv;

	// Määrame, et reaalarve väljastame käsureale kahe kohaga pärast koma
	cout << fixed << setprecision(2);

	// Arvutame välja ja väljastame laenusumma koos kogunenud intressidega igal
	// kuul
	double volg = laenusumma;
	for (int kuu = 1; kuu <= kuude_arv; kuu++) {
		// Rakendame liitintressi valemit, et välja arvutada uus võlasumma
		volg *= 1 + intressimaar;
		// Väljastame kuu tulemuse käsureale
		cout << kuu << ". kuu:" << endl;
		cout << "  Intressid:  " << volg - laenusumma << endl;
		cout << "  Volg kokku: " << volg << endl;
		cout << endl;
	}

	return 0;
}
