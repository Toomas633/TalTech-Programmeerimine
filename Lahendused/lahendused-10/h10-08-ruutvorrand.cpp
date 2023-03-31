/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-08: Ruutvõrrand
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

#include <iostream>	 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision
#include <limits>					// std::numeric_limits
#include <string>					// std::string
#include <cmath>					// sqrt

using namespace std;

// Funktsioon, mis esitab kasutajale küsimuse ja loeb käsurealt sisse ühe
// reaalarvu
double loe_reaalarv(string kusimus = "Sisesta reaalarv") {
	// Deklareerime muutuja, millesse reaalarv sisse lugeda
	double arv;
	// Küsime kasutajalt sisendit nii kaua, kuni sisestatakse reaalarv
	bool vigane_sisend;
	do {
		// Eeldame, et kasutaja sisestab korrektse reaalarvu
		vigane_sisend = false;
		// Esitame kasutajale küsimuse ja loeme sisse ühe reaalarvu
		cout << kusimus << ": ";
		cin >> arv;
		// Kui sisend läks katki, siis ei sisestatud reaalarvu
		// Sel juhul väljastame veateate, määrame sisendi vigaseks, et seda
		// uuesti küsitaks, ning puhastame sisendvoo veaseisundi
		if (cin.fail()) {
			cout << "Viga! Tegu pole reaalarvuga." << endl;
			vigane_sisend = true;
			cin.clear();
		}
		// Tühjendame kõik, mis sisendvoogu jäänud
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (vigane_sisend);
	// Kui kasutaja sisestas nõuetekohase reaalarvu, tagastame selle
	return arv;
}

// Funktsioon, mis lahendab ruutvõrrandi kujul ax^2 + bx + c
// Funktsioon käitub protseduurina ja asetab lahendid 4. ja 5. parameetrisse,
// ent on siiski kirjutatud funktsiooni kujul, et oleks tuvastatav, kas
// ruutvõrrand oli üldse lahendatav.
// Alternatiivne lahendus on veakoodi asemel kasutada erinditöötlust (ingl
// exception handling).
bool lahenda_ruutvorrand(double a, double b, double c, double& x1, double& x2) {
	// Kui konstant a on 0, jääb ruutvõrrandist alles bx + c = 0
	// Sel juhul pole tegu ruutvõrrandiga, aga lahendi saab ikka leida
	if (a == 0) {
		// Kui konstant b on 0, jääb ruutvõrrandist alles c = 0
		// Sellisel juhul lahendit ei leidu
		if (b == 0) return false;
		// Vastasel juhul leiame lahendi ja tagastame, et võrrandi lahendamine
		// õnnestus
		x1 = x2 = -c / b;
		return true;
	}
	// Kui konstant a ei ole 0, on tegu ruutvõrrandiga
	// Leiame ruutvõrrandi diskriminandi
	float diskriminant = b * b - 4 * a * c;
	// Kui diskriminant on negatiivne, ei saa ruutvõrrandit lahendada
	if (diskriminant < 0) return false;
	// Vastasel juhul leiame ruutvõrrandi lahendid ja tagastame, et võrrandi
	// lahendamine õnnestus
	x1 = (-b + sqrt(diskriminant)) / (2 * a);
	x2 = (-b - sqrt(diskriminant)) / (2 * a);
	return true;
}


int main() {
	// Loeme sisse ruutvõrrandi ax^2 + bx + c = 0 konstandid a, b ja c
	cout << "Olgu meil ruutvorrand kujul ax^2 + bx + c = 0" << endl << endl;
	cout << "Sisesta ruutvorrandi konstandid a, b ja c:" << endl;
	double a = loe_reaalarv("a");
	double b = loe_reaalarv("b");
	double c = loe_reaalarv("c");

	// Lahendame ruutvõrrandi
	double x1 = 0, x2 = 0;
	bool onnestus = lahenda_ruutvorrand(a, b, c, x1, x2);

	// Väljastame vastuse
	cout << fixed << setprecision(2);
	if (onnestus) {
		cout << "Ruutvorrandi lahendid:" << endl;
		cout << "  x1 = " << x1 << endl;
		cout << "  x2 = " << x2 << endl;
	} else {
		cout << "Viga! Ruutvorrandit konstantidega a = " << a << ", b = " << b << " ja c = " << c << " ei saa lahendada." << endl;
	}

	return 0;
}
