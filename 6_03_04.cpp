#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int liigaasta(int aasta)
{
    int liig;

    if (aasta % 4 == 0 && aasta % 100 != 0)
    {
        liig = 1;
        cout << aasta << " on liigaasta." << endl;
    }
    else if (aasta % 100 == 0 && aasta % 400 != 0)
    {
        liig = 0;
        cout << aasta << " ei ole liigaasta." << endl;
    }
    else if (aasta % 400 == 0)
    {
        liig = 1;
        cout << aasta << " on liigaasta." << endl;
    }
    else 
    {
        liig = 0;
        cout << aasta << " ei ole liigaasta." << endl;
    }
    return liig;
}

int paev(int kuu, int liig)
{
    if (kuu == 1 || kuu == 3 || kuu == 5 || kuu == 7 || kuu == 8 || kuu == 10 || kuu == 12)
    {

    }
}

int main()
{
    int aasta, liig, kuu, paevad;
    cout << "Sisesta aasta arv: " << endl;
    cin >> aasta;
    cout << "Sisesta kuu number: " << endl;
    cin >> kuu;

    liig = liigaasta(aasta);
    paevad = paev(kuu, liig);



    cin.ignore(256, '\n');
    getchar();
    return 0;
}