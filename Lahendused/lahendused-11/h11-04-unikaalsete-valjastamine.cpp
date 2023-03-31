/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-04: Unikaalsete väljastamine
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout

using namespace std;

// Protseduur, mis väljastab täisarvude massiivi käsureale nõnda, et elemendid
// on üksteisest eraldatud komadega ja massiivi ümber on loogelised sulud
void valjasta(int* massiiv, unsigned int kogus) {
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

// Protseduur, mis leiab massiivist unikaalsed väärtused ja salvestab need teise
// massiivi
// Unikaalsete elementide massiivile eraldatakse mälu dünaamiliselt ja see
// tuleb pärast kasutamise lõppu vabastada
void leia_unikaalsed(int* massiiv, unsigned int kogus, int*& unikaalsed, unsigned int& unikaalsete_kogus) {
	// Eraldame mälu unikaalsete elementide salvestamiseks
	// Alustame eeldusest, et kõik elemendid massiivis on unikaalsed
	unikaalsed = new int[kogus];
	// Vaatleme järjestikuselt massiivi iga elementi ja lisame selle unikaalsete
	// elementide nimekirja lõppu, kui ilmneb, et seda seal veel ei ole
	// Võtame jooksvalt arvesse siiani leitud unikaalsete elementide kogust, et
	// nimekirja lisatavale elemendile sobiv koht leida
	unikaalsete_kogus = 0;
	for (unsigned int koht = 0; koht < kogus; koht++) {
		// Kui vaadeldavat elementi ei leidu unikaalsete elementide massiivis,
		// lisame selle
		if (otsi(unikaalsed, unikaalsete_kogus, massiiv[koht]) == -1) {
			unikaalsed[unikaalsete_kogus] = massiiv[koht];
			unikaalsete_kogus++;
		}
	}
	// Kui massiivis oli korduvaid elemente, on unikaalsete elementide massiivis
	// kohti, mida me pole puutunud ega plaani kasutada - see on mäluraisk
	// Lihtsamate rakenduste puhul on see aktsepteeritav
	// Kui ei soovi mälu raisata, tuleks kasutada mõnda keerukamat
	// andmestruktuuri, nt std::unordered_set konteinerit STList
}

// Protseduur, mis väljastab käsureale massiivi elementide väärtused nõnda, et
// ühtki väärtust ei korrata
void valjasta_unikaalsed(int* massiiv, unsigned int kogus) {
	// Leiame unikaalsed väärtused massiivis
	int* unikaalsed = nullptr;
	unsigned int unikaalsete_kogus = 0;
	leia_unikaalsed(massiiv, kogus, unikaalsed, unikaalsete_kogus);
	// Väljastame unikaalsed väärtused käsureale
	valjasta(unikaalsed, unikaalsete_kogus);
	// Vabastame unikaalsete elementide massiivile dünaamiliselt eraldatud
	// mälu
	delete[] unikaalsed;
}


int main() {
	// Defineerime täisarvude massiivi
	const unsigned int kogus = 10;
	int arvud[kogus] = {5, 10, 8, 5, 5, 7, 10, 5, 9, 42};

	// Väljastame massiivi käsureale
	cout << "Massiiv:" << endl;
	valjasta(arvud, kogus);
	cout << endl << endl;

	// Väljastame unikaalsed väärtused massiivis käsureale
	cout << "Unikaalsed väärtused:" << endl;
	valjasta_unikaalsed(arvud, kogus);
	cout << endl;

	return 0;
}
