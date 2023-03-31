#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>
#include <stdlib.h>

using namespace std;

double raha_algus()
{
    double raha;
    bool viga;
    do
    {
        viga = false;
        cout << "Palju raha kontol on?" << endl;
        cin >> raha;
        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga = true;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(viga);
    return raha;
}

double raha_sisse(double raha)
{
    double sisse;
    bool viga;
    do
    {
        viga = false;
        cout << "Palju raha kontole panna?" << endl;
        cin >> sisse;
        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga = true;
            cin.clear();
        }
        else if (sisse < 0)
        {
            cout << "Sisestatud raha ei saa olla negatiivne!" << endl;
            viga = true;
            cin.clear();
        }
        else
        {
            raha = raha + sisse;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(viga);
    return raha;
}

double raha_valja(double raha)
{
    double valja;
    bool viga;
    do
    {
        viga = false;
        cout << "Palju raha kontolt v6tta?" << endl;
        cin >> valja;
        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga = true;
            cin.clear();
        }
        else if (valja < 0)
        {
            cout << "Sisestatud raha ei saa olla negatiivne!" << endl;
            viga = true;
            cin.clear();
        }
        else if (valja > raha)
        {
            cout << "Kontol pole piisavalt raha!" << endl;
            viga = true;
            cin.clear();
        }
        else
        {
            raha = raha - valja;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(viga);
    return raha;

}
void menu(double raha)
{
    bool viga;
    int valik;
    do 
    {
        cout << endl << "Teil on " << raha << "€" << endl << endl;
        cout << "[1] Raha sisse" << endl;
        cout << "[2] Raha valja" << endl;
        cout << "[0] Valju" << endl << endl;
        viga = false;
        cout << "sisesa valik: ";
        cin >> valik;
        cout << endl;

        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga = true;
            cin.clear();

        }
        else if (valik == 1) 
        {
            raha = raha_sisse(raha);
            menu(raha);
        }
        else if (valik == 2) 
        {
            raha = raha_valja(raha);
            menu(raha);
        }
        else if (valik == 0) 
        {
            cout << "Tanan kasutamast!" << endl;
            cout << endl;
            exit(0);
        }
        else 
        {
            cout << "Vale valik!" << endl;
            viga = true;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (viga);
}
int main()
{
    double raha;
    
    raha = raha_algus();
    
    menu(raha);
    
    return 0;
}