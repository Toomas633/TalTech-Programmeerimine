#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float i, laen, kuu, intress, laenusumma, koguintress, kuine;

    cout << "Sisesta laenusumma: " << endl;
    cin >> laen;
    cout << "Sisesta intressi maar kuus (%): " << endl;
    cin >> intress;
    intress = intress / 100;
    i = intress / 12;
    cout << "Sisesa kuude arv: " << endl;
    cin >> kuu;

    kuine = (laen*i*pow(1+i, kuu))/(pow(1+i, kuu)-1);
    kuine = roundf(kuine*100)/100;

    laenusumma = kuine * kuu;
    laenusumma = roundf(laenusumma*100)/100;
    
    koguintress = laenusumma - laen;

    cout << "Laenusumma on " << laenusumma << endl;
    cout << "Koguintress on " << koguintress << endl;
    cin.ignore(256, '\n');
    getchar();
    return 0;
}