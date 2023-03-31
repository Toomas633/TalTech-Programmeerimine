/**
 * Programmeerimine keeles C++
 * Viidad ja viited
 * Harjutus 10-04: Leia viga viida kasutamisel
 * Ants-Oskar Mäesalu
 * 2022-02-18
 */

int main() {
	// Selgita, mis on viga järgnevas koodis
	char taht = 'X';
	double* viit = &taht;

	// Viitmuutuja peab endaga kaasas kandma selle muutuja andmetüüpi, millele
	// ta viitab. Vastasel juhul pole viitmuutuja järgi väärtuse väljastamisel
	// kujul *viit võimalik mälupesas asuvaid andmeid korrektselt teisendada.

	// Näiteks siin on muutuja 'taht' 1-baidine tähemärk ja muutuja 'viit'
	// 8-baidine ujupunktarv. Ei ole loogilist viisi teisendada esimest teiseks.
	// Lahendus oleks viitmuutuja andmetüübi double* asemel kasutada andmetüüpi
	// char*.

	return 0;
}
