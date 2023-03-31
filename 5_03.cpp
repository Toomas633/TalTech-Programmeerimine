#include <iostream>
#include <string>

using namespace std;

int main() {
    string pirukas;
    float hind;
    int kogus;

    cout << "Piruka nimi:";
    cin >> pirukas;
    cout << "Hind:";
    cin >> hind;
    cout << "Kogus:";
    cin >> kogus;

    cout << endl << pirukas << " tulu " << hind * kogus << endl;

    return 0;
}