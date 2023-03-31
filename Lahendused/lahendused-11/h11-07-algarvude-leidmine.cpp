/**
 * Programmeerimine keeles C++
 * Massiivid
 * Harjutus 11-07: Algarvude leidmine
 * Ants-Oskar Mäesalu
 * 2022-02-21
 */

#include <iostream>	 				// std::cout, std::cin
#include <limits>					// std::numeric_limits
#include <string>					// std::string

using namespace std;

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// täisarvu
int loe_taisarv(const string& kusimus = "Sisesta taisarv") {
	// Deklareerime muutuja, millesse täisarv sisse lugeda
	int arv;
	// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse täisarv
	bool vigane_sisend;
	do {
		// Eeldame, et kasutaja sisestab korrektse täisarvu
		vigane_sisend = false;
		// Esitame kasutajale küsimuse ja loeme sisse ühe täisarvu
		cout << kusimus << ": ";
		cin >> arv;
		// Kui sisend läks katki, siis ei sisestatud täisarvu
		// Sel juhul väljastame veateate, määrame sisendi vigaseks, et seda
		// uuesti küsitaks, ning puhastame sisendvoo veaseisundi
		if (cin.fail()) {
			cout << "Viga! Tegu pole taisarvuga." << endl;
			vigane_sisend = true;
			cin.clear();
		}
		// Tühjendame kõik, mis sisendvoogu jäänud
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (vigane_sisend);
	// Kui kasutaja sisestas nõuetekohase täisarvu, tagastame selle
	return arv;
}

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// mittenegatiivse täisarvu
unsigned int loe_mittenegatiivne_taisarv(const string& kusimus = "Sisesta mittenegatiivne taisarv") {
	// Deklareerime muutuja, millesse täisarv sisse lugeda
	int arv;
	// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse mittenegatiivne
	// täisarv
	bool vigane_sisend;
	do {
		// Eeldame, et kasutaja sisestab korrektse mittenegatiivse täisarvu
		vigane_sisend = false;
		// Esitame kasutajale küsimuse ja loeme sisse ühe täisarvu
		arv = loe_taisarv(kusimus);
		// Kui sisend ei ole mittenegatiivne, väljastame veateate ning määrame
		// sisendi vigaseks, et seda uuesti küsitaks
		if (arv < 0) {
			cout << "Viga! Arv ei ole mittenegatiivne." << endl;
			vigane_sisend = true;
		}
	} while (vigane_sisend);
	// Kui kasutaja sisestas nõuetekohase täisarvu, tagastame selle
	return arv;
}

// Protseduur, mis väljastab märgita täisarvude massiivi käsureale nõnda, et
// elemendid on üksteisest eraldatud komadega ja massiivi ümber on loogelised
// sulud
void valjasta(unsigned int* massiiv, unsigned int kogus) {
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

// Protseduuri 'eratosthenese_soel' abiprotseduur, mis märgib sõelas kõik mingi
// arvu kordsed kordarvudeks
void margi_kordarvud(bool* soel, unsigned int ulemine_piir, unsigned int algtegur) {
	// Alustame algteguri kahekordsest väärtusest, kuna see on vähim temast
	// erinev kordne. Igal sammul märgime vaadeldava arvu sõelas kordarvuks.
	// Iga kordne on eelmisest algteguri võrra suurem. Vaatleme kordseid kuni
	// sõelas määratud ülemise piirini
	for (unsigned int kordne = 2 * algtegur; kordne <= ulemine_piir; kordne += algtegur) {
		if (soel[kordne]) soel[kordne] = false;
	}
}

// Protseduur, mis leiab kõik algarvud kuni ülemise piirini, kasutades
// Eratosthenese sõela algoritmi
// Protseduuri tulemuseks on teises parameetris tõeväärtuste massiiv pikkusega
// arv+1, milles igale arvule vastaval kohanumbril asub tõeväärtus, mis näitab,
// kas see arv on algarv või mitte
void eratosthenese_soel(unsigned int ulemine_piir, bool*& soel) {
	// Eraldame dünaamiliselt mälu tõeväärtuste massiivile, mida kasutame
	// sõelana. Algoritmi tulemusel on igal kohal tõeväärtus, mis näitab, kas
	// nimetatud kohale vastav arv on algarv. Kuna massiivi indeksite loendamine
	// algab 0-st, kasutame massiivi pikkusena sisendparameetris edastatud
	// arvust ühe võrra suuremat
	soel = new bool[ulemine_piir + 1];
	// Märgime ära, et arv 0 pole algarv
	soel[0] = false;
	// Kui ülemine piir on 0, väljume protseduurist
	if (ulemine_piir == 0) return;
	// Vastasel juhul on ülemine piir 1 või suurem
	// Märgime ära, et arv 1 pole algarv
	soel[1] = false;
	// Oletame vastuväiteliselt, et arvud vahemikus [2; ülemine piir] on algarvud
	for (unsigned int i = 2; i <= ulemine_piir; i++) {
		soel[i] = true;
	}
	// Edasi vaatleme arve vahemikus [2; ülemine piir] ja hakkame nende hulgas
	// kordarve märgistama
	// Kui ülemine piir on 2 või suurem, märgime arvu 2 kordsed kordarvudeks
	if (ulemine_piir >= 2) margi_kordarvud(soel, ulemine_piir, 2);
	// Kui ülemine piir on 3 või suurem, märgime arvu 3 kordsed kordarvudeks
	if (ulemine_piir >= 3) margi_kordarvud(soel, ulemine_piir, 3);
	// Kuna 4 on juba arvu 2 kordne, peaksime järgmisena vaatlema arvu 5.
	// Iga arvu saab väljendada kujul 6k+i, kus i = {0, 1, 2, 3, 4, 5}. Kuna
	// arvud kujul 6k+0, 6k+2 ja 6k+4 jaguvad 2-ga ja arvud kujul 6k+0 ja 6k+3
	// jaguvad 3-ga, tuleb alates 5-st vaadelda vaid arve kujul 6k-1 ja 6k+1.
	// Kui vaadeldav arv on algarv, märgime kõik selle kordsed kordarvudeks.
	// Seejuures rakendame kontrolli vaid ruutjuureni ülemisest piirist, sest
	// kõiki arvu ruutjuurest suuremaid algtegureid tuleb arvu saamiseks
	// korrutada arvu ruutjuurest väiksema(te) algteguri(te)ga
	for (unsigned int arv = 5; arv * arv <= ulemine_piir; arv += 6) {
		if (soel[arv]) margi_kordarvud(soel, ulemine_piir, arv);
		if (soel[arv] + 2) margi_kordarvud(soel, ulemine_piir, arv + 2);
	}
}

// Protseduur, mis leiab algarvud kuni soovitud piirini ning salvestab need
// massiivi
// Algarvude leidmiseks kasutatakse Eratosthenese sõela algoritmi
// Algarvude massiivile eraldatakse mälu dünaamiliselt ja see tuleb pärast
// kasutamise lõppu vabastada
void leia_algarvud(unsigned int ulemine_piir, unsigned int*& algarvud, unsigned int& kogus) {
	// Leiame kõik algarvud kuni ülemise piirini, kasutades Eratostenese sõela
	// algoritmi. Algoritmi tulemuseks on tõeväärtuste massiiv pikkusega arv+1,
	// milles igale arvule vastaval kohanumbril asub tõeväärtus, mis näitab, kas
	// see arv on algarv või mitte.
	bool* soel = nullptr;
	eratosthenese_soel(ulemine_piir, soel);

	// Algarvude massiivile mälu eraldamiseks tuleb teada, kui palju elemente on
	// tarvis sellesse salvestada. Seega tuleb kokku loendada, kui palju algarve
	// sõel sisaldab
	kogus = 0;
	// Kui ülemine piir on 2-st suurem, arvestame 2 algarvude hulka. Sarnaselt
	// toimime 3-ga
	if (ulemine_piir >= 2) kogus++;
	if (ulemine_piir >= 3) kogus++;
	// Iga arvu saab väljendada kujul 6k+i, kus i = {0, 1, 2, 3, 4, 5}. Kuna
	// arvud kujul 6k+0, 6k+2 ja 6k+4 jaguvad 2-ga ja arvud kujul 6k+0 ja 6k+3
	// jaguvad 3-ga, tuleb alates 5-st kontrollida vaid arve kujul 6k-1 ja 6k+1
	for (unsigned int algarv = 5; algarv <= ulemine_piir; algarv += 6) {
		if (soel[algarv]) kogus++;
		if (soel[algarv + 2]) kogus++;
	}

	// Kui oleme sõelas kokku loendanud algarvude koguse, saame dünaamiliselt
	// mälu eraldada algarvude massiivile
	algarvud = new unsigned int[kogus];
	// Seejärel lisame eelnevale algarvude loendamise meetodile sarnaselt
	// needsamad algarvud järjestikuselt algarvude massiivi
	if (ulemine_piir >= 2) algarvud[0] = 2;
	if (ulemine_piir >= 3) algarvud[1] = 3;
	for (unsigned int algarv = 5, koht = 2; algarv <= ulemine_piir; algarv += 6) {
		if (soel[algarv]) algarvud[koht++] = algarv;
		if (soel[algarv + 2]) algarvud[koht++] = algarv + 2;
	}

	// Vabastame sõelale dünaamiliselt eraldatud mälu, kuna oleme lõpetanud
	// selle kasutamise
	delete[] soel;
}


int main() {
	// Küsime kasutajalt algarvude ülemise piiri
	unsigned int piir = loe_mittenegatiivne_taisarv("Sisesta algarvude ulemine piir");
	cout << endl;

	// Leiame kõik algarvud kuni nimetatud ülemise piirini
	unsigned int* algarvud = nullptr;
	unsigned int kogus = 0;
	leia_algarvud(piir, algarvud, kogus);

	// Väljastame need algarvud käsureale
	cout << "Algarvud kuni " << piir << "-ni:" << endl;
	valjasta(algarvud, kogus);
	cout << endl;

	// Vabastame algarvude massiivile dünaamiliselt eraldatud mälu
	delete[] algarvud;

	return 0;
}
