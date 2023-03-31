#include <iostream>
#include <string>

using namespace std;
int main() {
    string nimi;
    int vanus;
    string too;
    
    cout << "Mis on Teie nimi:" << endl;
    getline(cin, nimi);

    cout << "Mis on Teie vanus:" << endl;
    cin >> vanus;
    cin.ignore(256, '\n');

    cout << "Mis on teie kool/tookoht:" << endl;
    getline(cin, too);

    cout << "Tere " << nimi << " " << too << "ist!" << endl;

    return 0;
}