#include <iostream>

class Vektor {
public:
	Vektor();
	Vektor(int x, int y);
	Vektor(const Vektor& teine);
	void muuda(int x, int y);
	void valjasta();
	void liida(const Vektor& teine);
	int leiaX();
	int leiaY();
private:
	int x;
	int y;
};

Vektor::Vektor() {
	x = y = 0;
}

Vektor::Vektor(int x, int y) {
	this->x = x;
	this->y = y;
}

Vektor::Vektor(const Vektor& teine) {
	x = teine.x;
	y = teine.y;
}

void Vektor::muuda(int x, int y) {
	this->x = x;
	this->y = y;
}

void Vektor::valjasta() {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

void Vektor::liida(const Vektor& teine) {
	x += teine.x;
	y += teine.y;
}

int Vektor::leiaX() {
	return x;
}

int Vektor::leiaY() {
	return y;
}


int main() {
	Vektor esimene;
	esimene.valjasta();
	esimene.muuda(5, 2);
	esimene.valjasta();

	Vektor teine(-4, 11);
	teine.valjasta();

	Vektor summa(esimene);
	summa.liida(teine);
	summa.valjasta();

	return 0;
}
