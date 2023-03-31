#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float omahind, muugihind, kogus, periood, kasum, muuk, keskmine;
    cout << "Sisesta toote omahind:" << endl;
    cin >> omahind;

    cout << "Sisesta muugihind:" << endl;
    cin >> muugihind;

    cout << "Sisesta muudud kogus:" << endl;
    cin >> kogus;   
    
    cout << "Sisesta muugiperiood paevades:" << endl;
    cin >> periood;
    
    kasum = (muugihind - omahind) * kogus;
    muuk = (kogus / periood);
    keskmine = kasum / periood;

    cout << fixed;
    cout << "Teenitud kasum : " << setprecision(2) << kasum << " eurot." << endl;
    cout << "Paevas muudud hulk: " << setprecision(2) << muuk <<  endl;
    cout << "Keskmine paeva kasum: " << setprecision(2) << keskmine <<  endl;


    cin.ignore(256, '\n');
    getchar();
    return 0;
}