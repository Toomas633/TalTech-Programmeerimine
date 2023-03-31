#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    float poola;
    float euro;

    cout << "Sisestage summa Poola Zlottides" << endl;
    cin >> poola;

    euro = poola * 0.2207;

    cout << setprecision(2) << fixed << euro << endl;

    return 0;
}