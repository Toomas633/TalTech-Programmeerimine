#include <iostream>

using namespace std;

struct Kuupaev
{
    int paev;
    int kuu;
    int aasta;
    bool liig;
};

bool on_liigaasta(int aasta)
{
    bool liig;

    if ((aasta % 4 == 0 && aasta % 100 != 0) || aasta % 400 == 0)
    {
        liig = true;
    }
    else 
    {
        liig = false;
    }
    return liig;
}

int paevad(int kuu, bool liig)
{   
    int pa;
    if (kuu == 1 || kuu == 3 || kuu == 5 || kuu == 7 || kuu == 8 || kuu == 10 || kuu == 12)
    {
        pa = 31;
    }
    else if (liig == true && kuu == 2)
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

int kuupaevade_vahe(Kuupaev kuupaev01, Kuupaev kuupaev02)
{
    bool liig;
    int vahe, vahe_01 = 0, vahe_02 = 0, vahe_03 = 0;

    int pa = 0;
    for (int i = kuupaev01.kuu; i < 12; i++)
    {
        pa += paevad(i, kuupaev01.liig);
    }
    vahe_01 = pa - kuupaev01.paev;
    
    pa = 0;
    for (int j = 1; j <= kuupaev02.kuu; j++)
    {
        pa += paevad(j, kuupaev02.liig);
    }
    vahe_02 = pa + kuupaev02.paev;

    for (int k = kuupaev01.aasta; k < kuupaev02.aasta - 1; k++)
    {
        liig = on_liigaasta(k);
        if (liig == true)
        {
            vahe_03 += 366;
        }
        else vahe_03 += 365;
    }

    vahe = vahe_01 + vahe_02 + vahe_03;
    return vahe;
}

int main()
{   
    Kuupaev kuupaev01, kuupaev02;
    int vahe;
    
    algus:

    cout << "Sisesta esimene kuupaev (paev kuu aasta):" << endl;
    cin >> kuupaev01.paev >> kuupaev01.kuu >> kuupaev01.aasta;
    cout << "Sisesta teine kuupaev (paev kuu aasta):" << endl;
    cin >> kuupaev02.paev >> kuupaev02.kuu >> kuupaev02.aasta;

    if (kuupaev01.aasta < 0 || kuupaev02.aasta < 0)
    {
        cout << "Aasta ei saa olla negatiivne!" << endl;
        cin.clear();
        goto algus;
    }
    else if (kuupaev01.kuu <= 0 || kuupaev02.kuu <= 0)
    {
        cout << "Kuu ei saa olla negatiivne ega 0!" << endl;
        cin.clear();
        goto algus;
    }
    else if (kuupaev01.kuu > 12 || kuupaev02.kuu > 12)
    {
        cout << "Nii suure numbriga kuud pole olemas!" << endl;
        cin.clear();
        goto algus;
    }
    else
    {
        kuupaev01.liig = on_liigaasta(kuupaev01.aasta);
        kuupaev02.liig = on_liigaasta(kuupaev02.aasta);

        vahe = kuupaevade_vahe(kuupaev01, kuupaev02);

        cout << "Kuupaevade vahe on " << vahe << " paeva." << endl;
        cin.ignore(256, '\n');
        getchar();
    }

    return 0;
}