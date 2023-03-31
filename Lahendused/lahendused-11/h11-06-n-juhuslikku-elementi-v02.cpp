/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-06: N juhuslikku elementi
 * Variant 01: Kordusteta või kordustega vastavalt parameetrile
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout
#include <string>					// std::string
#include <cstdlib>					// rand, srand
#include <ctime>					// time

using namespace std;

// Protseduur, mis väljastab sõnede massiivi käsureale nõnda, et elemendid
// on üksteisest eraldatud komadega ja massiivi ümber on loogelised sulud
void valjasta(string* massiiv, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, väljastame tühjad loogelised sulud ja
	// väljume protseduurist
	if (kogus == 0) {
		cout << "{}";
		return;
	}
	// Kui massiivis on elemente, väljastame kõigepealt esimese elemendi ning
	// seejärel kõik järgmised elemendid, asetades nende ette komad
	cout << "{" << massiiv[0];
	for (unsigned int koht = 1; koht < kogus; koht++) {
		cout << ", " << massiiv[koht];
	}
	cout << "}";
}

// Protseduur, mis väljastab võtmete ja väärtuste massiivid käsureale nõnda, et
// elemendid on üksteisest eraldatud komadega, iga võtit ja väärtust eraldab
// koolon ja massiivi ümber on loogelised sulud
void valjasta(int* votmed, string* vaartused, unsigned int kogus) {
	// Kui massiivis pole ühtegi elementi, väljastame tühjad loogelised sulud ja
	// väljume protseduurist
	if (kogus == 0) {
		cout << "{}";
		return;
	}
	// Kui massiivis on elemente, väljastame kõigepealt esimese elemendi ning
	// seejärel kõik järgmised elemendid, asetades nende ette komad
	cout << "{" << endl;
	cout << "  " << votmed[0] << ": " << vaartused[0] << endl;
	for (unsigned int koht = 1; koht < kogus; koht++) {
		cout << "  " << votmed[koht] << ": " << vaartused[koht] << endl;
	}
	cout << "}";
}

// Protseduur, mis leiab massiivist valitud kohanumbritega elemendid ja
// salvestab nende väärtused teise massiivi
// Väärtuste massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
void filter(string* massiiv, int* kohanumbrid, unsigned int valikute_kogus, string*& vaartused) {
	// Eraldame mälu valitud kohanumbritega elementide väärtuste salvestamiseks
	vaartused = new string[valikute_kogus];
	// Lisame valitud elementide väärtused uude massiivi
	for (unsigned int koht = 0; koht < valikute_kogus; koht++) {
		vaartused[koht] = massiiv[kohanumbrid[koht]];
	}
}

// Funktsioon, mis otsib massiivist väärtust ja tagastab selle esimesele
// esinemisele vastava kohanumbri või -1, kui seda väärtust massiivis ei leidu
// Kasutame järjestik- ehk lineaarotsingut
int otsi(int* massiiv, unsigned int kogus, int otsitav) {
	// Vaatleme järjestikuselt massiivi iga elementi
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Kui massiivis vaadeldaval kohal asuva elemendi väärtus on võrdne
		// otsitava elemendi väärtusega, siis asub otsitav element massiivis
		// sellel kohal
		if (massiiv[koht] == otsitav) return koht;
	}
	// Kui massiivi ühegi elemendi väärtus polnud otsitava väärtusega võrdne,
	// siis ei leidu massiivis seda väärtust
	return -1;
}

// Funktsioon, mis genereerib juhuarvu vahemikus [alumine, ulemine]
int leia_juhuarv(int alumine, int ulemine) {
	// Funktsioon rand() genereerib juhuarvu vahemikus [0; RAND_MAX]
	// Jagamisel tekkiva jäägi leidmisel piirame selle vahemikku [0; jagaja - 1]
	// Jagaja peaks seega olema juhuarvude vahemiku suurus
	// Kui tulemusele juurde liita mingi arv, nihutab see tervet vahemikku
	return rand() % (ulemine - alumine + 1) + alumine;
}

// Protseduur, mis genereerib soovitud koguse kordustega või kordusteta juhuarve
// vahemikus [alumine, ulemine]
// Juhuarvude massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
// Kui juhuarvude leidmine pole võimalik, sest arvud tuleb valida kordusteta,
// aga vahemikus ei ole piisavalt arve, ei tehta midagi
void leia_juhuarvud(int alumine, int ulemine, int*& massiiv, unsigned int kogus, bool kordustega = true) {
	// Kui juhuarvud tuleb valida kordusteta, aga arvude vahemik on soovitud
	// koguse jaoks liiga väike, väljume protseduurist
	if (!kordustega && kogus > (unsigned int) (ulemine - alumine + 1)) return;
	// Eraldame mälu juhuarvude salvestamiseks
	massiiv = new int[kogus];
	// Genereerime soovitud koguse juhuarve
	// Kui kordused on lubatud, täidame juhuarvude operatsiooni lihtsalt
	// soovitud arvu kordi
	if (kordustega) {
		for (unsigned int koht = 0; koht < kogus; koht++) {
			massiiv[koht] = leia_juhuarv(alumine, ulemine);
		}
	}
	// Vastasel juhul kontrollime pärast iga juhuarvu genereerimist, et sellist
	// ei oleks veel genereeritud. Kui on, genereerime uue arvu
	// Selline naiivne algoritm on küllalt ebaoptimaalne. Optimaalsema
	// lähenemise saavutamiseks võiks kasutada nt Fisheri-Yatesi algoritmi
	else {
		for (unsigned int koht = 0; koht < kogus; koht++) {
			// Genereerime juhuarve nii kaua, kuni leiame sellise, mida juba
			// genereeritud juhuarvude massiivis veel ei leidu
			int juhuarv;
			bool on_korduv;
			do {
				// Eeldame, et juhuarvude generaator valib unikaalse väärtuse
				on_korduv = false;
				// Genereerime juhuarvu
				juhuarv = leia_juhuarv(alumine, ulemine);
				// Kui valitud väärtus leidub juba genereeritud juhuarvude
				// hulgas, tuleb uus element genereerida
				if (otsi(massiiv, koht, juhuarv) != -1)  {
					on_korduv = true;
				}
			} while (on_korduv);
			// Lisame juhuarvu massiivi
			massiiv[koht] = juhuarv;
		}
	}
}


int main() {
	// Defineerime juhuarvude generaatori seemne
	// Teeme seda põhiprogrammi alguses, sest seeme tuleb defineerida vaid korra
	// kogu programmi töö jooksul
	srand(time(NULL));

	// Defineerime sõnede massiivi
	const unsigned int kogus = 10;
	string soned[kogus] = {"hunt", "karu", "rebane", "ilves", "orav", "hiir", "kobras", "naarits", "nirk", "hirv"};

	// Väljastame massiivi käsureale
	cout << "Massiiv:" << endl;
	valjasta(soned, kogus);
	cout << endl << endl;

	// Defineerime, mitu juhuslikku elementi massiivist valida
	unsigned int juhuslike_kogus = 3;
	// Valime massiivist nii mitme juhusliku elemendi kohanumbrid
	int* juhuslikud_kohad = nullptr;
	leia_juhuarvud(0, kogus - 1, juhuslikud_kohad, juhuslike_kogus, false);
	// Leiame nende elementide väärtused
	string* juhuslikud_vaartused = nullptr;
	filter(soned, juhuslikud_kohad, juhuslike_kogus, juhuslikud_vaartused);

	// Väljastame juhuslikud elemendid koos nende kohanumbritega käsureale
	cout << juhuslike_kogus << " juhuslikku kordusteta elementi sellest massiivist:" << endl;
	valjasta(juhuslikud_kohad, juhuslikud_vaartused, juhuslike_kogus);
	cout << endl;

	// Vabastame juhuslike elementide kohanumbrite ja väärtuste massiividele
	// dünaamiliselt eraldatud mälu
	delete[] juhuslikud_kohad;
	delete[] juhuslikud_vaartused;

	return 0;
}
