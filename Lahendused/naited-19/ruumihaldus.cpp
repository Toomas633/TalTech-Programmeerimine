#include <iostream>

class Kast {
public:
	Kast(float x, float y, float z);
	void muuda(float x, float y, float z);
	void valjasta();
	float leiaRuumala();
private:
	float x, y, z;
};

Kast::Kast(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Kast::muuda(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Kast::valjasta() {
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "z = " << z << std::endl;
}

float Kast::leiaRuumala() {
	return x * y * z;
}


class Ruum {
public:
	Ruum(float x, float y, float z, float temperatuur) : mootmed(x, y, z) {
		this->temperatuur = temperatuur;
	}
private:
	Kast mootmed;
	float temperatuur;
};


int main() {
	Kast kingitus(20, 25, 40);
	kingitus.valjasta();
	std::cout << "Ruumala on " << kingitus.leiaRuumala() << std::endl;

	Ruum a202(5, 12, 3, 23.0);
	return 0;
}
