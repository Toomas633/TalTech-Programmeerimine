#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int on_liigaasta(int aasta)
{
    int liig;

    if ((aasta % 4 == 0 && aasta % 100 != 0) || aasta % 400 == 0)
    {
        liig = 1;
        cout << "Aasta " << aasta << " on liigaasta." << endl;
    }
    else 
    {
        liig = 0;
        cout << "Aasta " << aasta << " ei ole liigaasta." << endl;
    }
    return liig;
}

int paev(int kuu, int liig)
{   
    int pa;
    if (kuu == 1 || kuu == 3 || kuu == 5 || kuu == 7 || kuu == 8 || kuu == 10 || kuu == 12)
    {
        pa = 31;
    }
    else if (liig == 1 && kuu == 2)
    {
        pa = 29;
    }
    else if (kuu == 2)
    {
        pa = 28;
    }
    else
    {
        pa = 30;
    }
    return pa;
}

string kuunimi(int kuu)
{
    string kuu_n;
    string K[] = {"", "jaanuari", "veebruari", "martsi", "aprilli", "mai", "juuni", "juuli", "augusti", "septembri", "oktoobri", "novembri", "detsembri"};

    kuu_n = K[kuu];
    
    return kuu_n;
}

int main()
{
    int aasta, liig, kuu, paevad;
    string kuu_nimi;

    cout << "Sisesta aasta arv: " << endl;
    cin >> aasta;
    cout << "Sisesta kuu number: " << endl;
    cin >> kuu;
    cout << endl;

    if (aasta < 0)
    {
        cout << "Aasta ei saa olla negatiivne!" << endl;
    }
    else if (kuu <= 0)
    {
        cout << "Kuu ei saa olla negatiivne ega 0!" << endl;
    }
    else if (kuu > 12)
    {
        cout << "Nii suure numbriga kuud pole olemas!" << endl;
    }
    else
    {
        liig = on_liigaasta(aasta);
        paevad = paev(kuu, liig);
        kuu_nimi = kuunimi(kuu);

        cout << '\n' << aasta << " aasta " << kuu_nimi << " kuus on " << paevad << " paeva." << endl;
        cin.ignore(256, '\n');
        getchar();
    }
        
    return 0;
}