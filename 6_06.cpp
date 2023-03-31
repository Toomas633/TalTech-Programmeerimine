#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float tulumaks_calc(int bruto, float tootuskindlustus, float maksuvaba, float kogumispension) 
{
    float tulumaks;
    tulumaks = (bruto - tootuskindlustus - maksuvaba - kogumispension) * 0.2;
    tulumaks = roundf(tulumaks * 100) / 100;
    if (tulumaks <= 0) 
    {
        tulumaks = 0;
    }
    else 
    {
        tulumaks = tulumaks;
    }
    return tulumaks;
}

float maksuvaba_calc(int bruto, int aastatulu) 
{
    float maksuvaba;

    if (aastatulu <= 14400) 
    {
        maksuvaba = 6000 / 12;
    } 
    else 
    {
        if (14400 < aastatulu && aastatulu < 25200) 
        {
            maksuvaba = (6000 - 6000.0 / 10800 * (aastatulu - 14400)) / 12;
            maksuvaba = roundf(maksuvaba * 100) / 100;
        } 
        else 
        {
            maksuvaba = 0;
        }
    }
    return maksuvaba;
}

int main() 
{
    int bruto, aastatulu;
    float maksuvaba, tootuskindlustus, kogumispension, tulumaks, neto, sotsiaalmaks, tootuskindlustus_tooandja, kogukulu, maks;
    
    cout << "Sisesta brutopalk:" << endl;
    cin >> bruto;
    
    aastatulu = bruto * 12;

    maksuvaba = maksuvaba_calc(bruto, aastatulu);

    tootuskindlustus = bruto * 0.016;
    tootuskindlustus = roundf(tootuskindlustus * 100) / 100;

    kogumispension = bruto * 0.02;
    kogumispension = roundf(kogumispension * 100) / 100;
    
    tulumaks = tulumaks_calc(bruto, tootuskindlustus, maksuvaba, kogumispension);

    neto = bruto - tulumaks - kogumispension - tootuskindlustus;
    
    sotsiaalmaks = bruto * 0.33;
    sotsiaalmaks = roundf(sotsiaalmaks * 100) / 100;

    tootuskindlustus_tooandja = bruto * 0.008;
    tootuskindlustus_tooandja = roundf(tootuskindlustus_tooandja * 100) / 100;

    kogukulu = bruto + sotsiaalmaks + tootuskindlustus_tooandja;

    maks = tootuskindlustus_tooandja + sotsiaalmaks + tulumaks + tootuskindlustus + kogumispension;

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Kogukulu tooandjale: " << kogukulu << " eurot." << endl;
    cout << "Tootajale (netosumma): " << neto << " eurot." << endl;
    cout << "Maksuametile makstav summa: " << maks << " eurot." << endl;
    
    cin.ignore(256, '\n');
    getchar();
    return 0;
}