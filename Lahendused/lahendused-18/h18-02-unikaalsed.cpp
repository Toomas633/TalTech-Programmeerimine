/**
 * Programmeerimine keeles C++
 * Standardteegi konteinerid
 * Harjutus 18-02: Unikaalsed elemendid
 * Ants-Oskar Mäesalu
 * 2022-04-01
 */

#include "include/ajakulu.h"		// ajakulu
#include <iostream>	 				// std::cout, std::fixed
#include <iomanip>					// std::setprecision
#include <cstdlib>					// rand, srand
#include <ctime>					// std::time
#include <vector>					// std::vector
#include <set>						// std::set
#include <unordered_set>			// std::unordered_set
#include <algorithm>				// std::find

// Funktsioon, mis genereerib juhuarvu vahemikus [alumine; ulemine]
int leia_juhuarv(int alumine, int ulemine) {
	return rand() % (ulemine - alumine + 1) + alumine;
}

// Funktsioon, mis genereerib N juhuarvu vahemikus [alumine; ulemine]
std::vector<int> genereeri_juhuarvud(unsigned int kogus, int alumine, int ulemine) {
	std::vector<int> juhuarvud(kogus);
	for (unsigned int i = 0; i < kogus; i++) {
		juhuarvud[i] = leia_juhuarv(alumine, ulemine);
	}
	return juhuarvud;
}

// Funktsioon, mis loendab unikaalsete elementide koguse loendis
// Unikaalsete elementide hoidmiseks kasutab std::vectorit ning elementide
// olemasolu kontrollimiseks järjestikotsingut - ajaline keerukus O(n)
unsigned int loenda_unikaalsed_loend(const std::vector<int>& loend) {
	std::vector<int> unikaalsed;
	for (int element: loend) {
		if (std::find(unikaalsed.begin(), unikaalsed.end(), element) == unikaalsed.end()) {
			unikaalsed.push_back(element);
		}
	}
	return unikaalsed.size();
}

// Funktsioon, mis loendab unikaalsete elementide koguse loendis
// Unikaalsete elementide hoidmiseks kasutab std::set'i ning elementide
// olemasolu kontrollimiseks kahendotsingut - ajaline keerukus O(log n)
unsigned int loenda_unikaalsed_hulk(const std::vector<int>& loend) {
	std::set<int> unikaalsed;
	for (int element: loend) {
		unikaalsed.insert(element);
	}
	return unikaalsed.size();
}

// Funktsioon, mis loendab unikaalsete elementide koguse loendis
// Unikaalsete elementide hoidmiseks kasutab std::unordered_set'i ning
// elementide olemasolu kontrollimiseks paisktabelit - ajaline keerukus O(1)
unsigned int loenda_unikaalsed_jarjestuseta_hulk(const std::vector<int>& loend) {
	std::unordered_set<int> unikaalsed;
	for (int element: loend) {
		unikaalsed.insert(element);
	}
	return unikaalsed.size();
}


int main() {
	// Genereerime andmestiku
	// Andmestik koosneb N juhuarvust vahemikus [-100; 100]
	unsigned int elemente = 1000000;
	std::srand(std::time(nullptr));
	std::vector<int> loend = genereeri_juhuarvud(elemente, -100, 100);

	// Viime läbi katsed ja mõõdame nendeks kuluvat aega
	unsigned int katseid = 5;
	double ajakulu_loend = ajakulu(katseid, loenda_unikaalsed_loend, loend);
	double ajakulu_hulk = ajakulu(katseid, loenda_unikaalsed_hulk, loend);
	double ajakulu_jarjestuseta_hulk = ajakulu(katseid, loenda_unikaalsed_jarjestuseta_hulk, loend);

	// Väljastame tulemused
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Katseid:     " << katseid << std::endl;
	std::cout << "Elemente:    " << elemente << std::endl;
	std::cout << "Unikaalseid: " << loenda_unikaalsed_jarjestuseta_hulk(loend) << std::endl;
	std::cout << "Unikaalsete elementide koguse leidmiseks kulus:" << std::endl;
	std::cout << "  std::vector:        " << ajakulu_loend << " sekundit" << std::endl;
	std::cout << "  std::set:           " << ajakulu_hulk << " sekundit" << std::endl;
	std::cout << "  std::unordered_set: " << ajakulu_jarjestuseta_hulk << " sekundit" << std::endl;

	return 0;
}
