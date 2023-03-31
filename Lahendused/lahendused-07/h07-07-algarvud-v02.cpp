/**
 * Programmeerimine keeles C++
 * Korduslaused
 * Harjutus 07-07: Algarvud
 * Variant 02: Naiivne algoritm, aga kontrollime vaid paarituid kordajaid kuni
 *   ruutjuureni
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits

using namespace std;

int main() {
	// Küsime kasutajalt ühe täisarvu, mis tähistab algarvude piiri
	int piir;
	cout << "Sisesta leitavate algarvude ulemine piir: ";
	cin >> piir;

	// Kontrollime iga arvu puhul kuni nimetatud piirini, kas tegu on algarvuga,
	// ja kui on, väljastame.
	// Erinevalt eelmisest variandist kontrollime alates 3-st vaid paarituid
	// arve.
	cout << endl << "Algarvud kuni " << piir << ":" << endl;
	if (piir >= 2) {
		cout << 2 << endl;
	}
	for (int arv = 3; arv <= piir; arv += 2) {
		// Eeldame vastuväiteliselt, et tegu on algarvuga
		bool on_algarv = true;
		// Kui arv jagub mõne arvuga vahemikus [3, arv - 1], ei ole tegu
		// algarvuga.
		// Erinevalt eelmisest variandist pole siin enam 2-ga jagumist tarvis
		// kontrollida, kuna välise korduslause põhjal teame, et vaadeldav arv
		// on paaritu.
		// Erinevalt eelmisest variandist rakendame kontrolli vaid ruutjuureni
		// arvust, sest kõiki arvu ruutjuurest suuremaid kordajaid tuleb arvu
		// saamiseks korrutada arvu ruutjuurest väiksema(te) kordaja(te)ga.0
		// Arvu ruutjuure funktsiooni kasutamise asemel võtame tema võimaliku
		// kordaja ruutu, sest korrutamine on kiirem operatsioon kui arvu
		// ruutjuure leidmine.
		for (int kordaja = 3; kordaja * kordaja <= arv; kordaja += 2) {
			if (arv % kordaja == 0) {
				on_algarv = false;
			}
		}
		// Kui tegu on algarvuga, väljastame selle
		if (on_algarv) {
			cout << arv << endl;
		}
	}

	// Seda algoritmi annab ka edasi optimeerida:
	// 1. Algarvu kontrollimisel kasutada ära teadmist, et iga arvu saab
	//    väljendada kujul 6k+i, kus i = {0, 1, 2, 3, 4, 5}. Kuna arvud kujul
	//    6k+0, 6k+2 ja 6k+4 jaguvad 2-ga ja arvud kujul 6k+0 ja 6k+3 jaguvad
	//    3-ga, tuleb alates 5-st kontrollida vaid arve kujul 6k-1 ja 6k+1.
	// 2. Kuna soovime leida kõiki algarve kuni mingi piirini, on võimalik
	//    algarvuks olemise kontrolli käigus kontrollida kõigi võimalike
	//    kordajate asemel vaid algarvulisi kordajaid, st proovida kordajatena
	//    eelnevalt leitud algarve. Selleks tuleb samas kõiki eelnevaid arve
	//    kuhugi salvestada; sellega tegeleme massiivide teemas.

	return 0;
}
