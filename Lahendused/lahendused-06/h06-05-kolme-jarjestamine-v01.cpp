/**
 * Programmeerimine keeles C++
 * Valikulaused ja loogilised avaldised
 * Harjutus 06-05: Kolme arvu järjestamine
 * Variant 01: Mitme pesastatud valikulausega
 * Ants-Oskar Mäesalu
 * 2022-02-05
 */

#include <iostream> 				// std::cout, std::cin

using namespace std;

int main() {
	// Küsime kasutajalt kolme täisarvu, mida järjestada
	int a, b, c;
	cout << "Sisesta tuhikuga eraldatuna kolm taisarvu: ";
	cin >> a >> b >> c;
	cout << endl;

	// Kasutame valikulauseid ja paarikaupa võrdlemist, et need kolm täisarvu
	// väärtuste kasvamise järjekorras käsureale väljastada
	cout << "Vaartuste kasvamise jarjekorras on need arvud:" << endl;

	// Kui a on väiksem b-st, teame, et a on 1. või 2. kohal ja b on 2. või 3.
	// kohal
	if (a < b) {

		// Kui a on väiksem ka c-st, teame, et a on 1. kohal; b ja c kohta ei
		// tea veel, kumb on 2. ja kumb 3. kohal
		if (a < c) {

			// Kui b on väiksem c-st, on b 2. kohal ja c 3. kohal
			if (b < c) {
				cout << a << " " << b << " " << c;
			}
			// Kui b ei ole väiksem c-st, on c väiksem või võrdne b-ga; seega
			// on c 2. kohal ja b 3. kohal
			else {
				cout << a << " " << c << " " << b;
			}

		}
		// Kui a ei ole väiksem c-st, on c väiksem või võrdne a-ga; seega on
		// c 1. kohal, a 2. kohal ja b 3. kohal
		else {
			cout << c << " " << a << " " << b;
		}

	}
	// Kui a ei ole väiksem b-st, on b väiksem või võrdne a-ga; seega on b 1.
	// või 2. kohal ja a on 2. või 3. kohal
	else {

		// Kui b on väiksem ka c-st, teame, et b on 1. kohal; a ja c kohta ei
		// tea veel, kumb on 2. ja kumb 3. kohal
		if (b < c) {

			// Kui a on väiksem c-st, on a 2. kohal ja c 3. kohal
			if (a < c) {
				cout << b << " " << a << " " << c;
			}
			// Kui a ei ole väiksem c-st, on c väiksem või võrdne a-ga; seega
			// on c 2. kohal ja a 3. kohal
			else {
				cout << b << " " << c << " " << a;
			}

		}
		// Kui b ei ole väiksem c-st, on c väiksem või võrdne b-ga; seega on
		// c 1. kohal, b 2. kohal ja a 3. kohal
		else {
			cout << c << " " << b << " " << a;
		}

	}
	cout << endl;

	return 0;
}
