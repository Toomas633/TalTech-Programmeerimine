/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-02: Erikujulised küpsised
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout, std::cin, std::fixed
#include <iomanip>					// std::setprecision
#include <cmath>					// sqrt

using namespace std;

int main() {
	// Küsime kasutajalt kolmnurga küljed
	float a, b, c;
	cout << "Sisesta tuhikuga eraldatuna kolmnurga kulgede pikkused: ";
	cin >> a >> b >> c;

	// Kontrollime, et kolmnurga kõik küljed oleksid positiivsed
	if (a > 0 && b > 0 && c > 0) {

		// Kontrollime, et tegu saab olla kolmnurgaga
		// Kolmnurga mistahes kahe külje pikkuste summa peab olema pikem
		// kolmanda külje pikkusest
		if (a + b > c && a + c > b && b + c > a) {

			// Arvutame välja kolmnurga ümbermõõdu ja pindala
			float umbermoot = a + b + c;
			float p = umbermoot / 2;
			float pindala = sqrt(p * (p - a) * (p - b) * (p - c));

			// Väljastame vastuse
			cout << fixed << setprecision(2);
			cout << "Kolmnurga umbermoot on " << umbermoot << " ja pindala on " << pindala << "." << endl;

		} else {
			cout << "Viga! Kolmnurga mistahes kahe külje pikkuste summa peab olema pikem kolmanda külje pikkusest." << endl;
		}

	} else {
		cout << "Viga! Kolmnurga koigi kulgede pikkused peavad olema positiivsed." << endl;
	}

	return 0;
}
