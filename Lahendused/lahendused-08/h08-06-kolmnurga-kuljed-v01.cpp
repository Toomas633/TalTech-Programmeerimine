/**
 * Programmeerimine keeles C++
 * Alamprogrammide kirjutamine
 * Harjutus 08-06: Kolmnurga küljed
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream>	 				// std::cout, std::cin
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

// Funktsioon, mis leiab kahe punkti vahelise kauguse koordinaatteljestikul
double leia_kaugus(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}

// Funktsioon, mis kontrollib, kas kolm külge moodustavad kolmnurga
// Kolmnurgaga on tegu, kui mistahes kahe külje pikkuste summa on suurem
// kolmanda külje pikkusest
bool on_kolmnurk(double a, double b, double c) {
	return a + b > c && a + c > b && b + c > a;
}

// Funktsioon, mis leiab kolme külje pikkuste põhjal kolmnurga ümbermõõdu
double leia_umbermoot(double a, double b, double c) {
	return a + b + c;
}

// Funktsioon, mis leiab kolme külje pikkuste põhjal kolmnurga pindala,
// kasutades selleks Heroni valemit
double leia_pindala(double a, double b, double c) {
	double p = leia_umbermoot(a, b, c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main() {
	// Küsime kasutajalt kolme punkti koordinaadid
	double x1 = loe_reaalarv("Sisesta punkti A x-koordinaat");
	double y1 = loe_reaalarv("Sisesta punkti A y-koordinaat");
	double x2 = loe_reaalarv("Sisesta punkti B x-koordinaat");
	double y2 = loe_reaalarv("Sisesta punkti B y-koordinaat");
	double x3 = loe_reaalarv("Sisesta punkti C x-koordinaat");
	double y3 = loe_reaalarv("Sisesta punkti C y-koordinaat");

	// Leiame paarikaupa külgede vahelised kaugused
	double kulg1 = leia_kaugus(x1, y1, x2, y2);
	double kulg2 = leia_kaugus(x1, y1, x3, y3);
	double kulg3 = leia_kaugus(x2, y2, x3, y3);

	// Kui tegu on kolmnurgaga, leiame kolmnurga küljed, ümbermõõdu ja pindala
	// ning väljastame need käsureale
	if (on_kolmnurk(kulg1, kulg2, kulg3)) {
		cout << "Kolmnurga kuljed on "<< kulg1 << ", " << kulg2 << " ja " << kulg3 << "." << endl;
		cout << "Kolmnurga umbermoot on " << leia_umbermoot(kulg1, kulg2, kulg3) << "." << endl;
		cout << "Kolmnurga pindala on " << leia_pindala(kulg1, kulg2, kulg3) << "." << endl;
	}
	// Kui tegu ei ole kolmnurgaga, väljastame veateate
	else {
		cout << "Viga! Tegu ei ole kolmnurgaga." << endl;
	}

	return 0;
}
