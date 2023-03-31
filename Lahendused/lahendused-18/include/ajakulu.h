/**
 * Programmeerimine keeles C++
 * Abiprogramm ajakulu mõõtmiseks
 * Ants-Oskar Mäesalu
 */

#ifndef _H_AJAKULU_
#define _H_AJAKULU_

#include <ctime>	 				// clock, clock_t

// Funktsioon, mis käivitab alamprogrammi määratud arv kordi ja mõõdab tööks
// kokku kulunud aega sekundites
template <typename Funktsioon, typename ... Parameetrid>
double ajakulu(const unsigned long& kordusi, const Funktsioon& funktsioon, const Parameetrid& ... parameetrid) {
	clock_t algus = clock();
	for (unsigned long i = 0; i < kordusi; i++) {
		funktsioon(parameetrid...);
	}
	clock_t lopp = clock();
	return double(lopp - algus) / CLOCKS_PER_SEC;
}

#endif
