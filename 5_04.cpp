#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float laius, korgus, pikkus, pakk, hind, kulub, maksab;

    cout << "Tordi laius:" << endl;
    cin >> laius;

    cout << "Tordi pikkus:" << endl;
    cin >> pikkus;

    cout << "Tordi kihid:" << endl;
    cin >> korgus;
    
    cout << "Mitu kupsist on pakis:" << endl;
    cin >> pakk;
    
    cout << "Mis on paki hind:" << endl;
    cin >> hind;

    kulub = (laius * korgus * pikkus) / pakk;
    maksab =ceil(kulub * hind);

    cout << endl << "Kulub " << ceil(kulub) << " pakki. Maksab " << maksab << " eurot." << endl;
    
    cin.ignore(256, '\n');
    getchar();
    return 0;
}