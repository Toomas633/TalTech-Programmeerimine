#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

double kontroll(string k)
{
    double arv;
    bool viga;
    do
    {
        viga = false;
        cout << "Sisest arv " << k << ":" << endl;
        cin >> arv;
        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga=true;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(viga);
    return arv;
}

bool lahenda_ruutvorrand(double a, double b, double c, double& x1, double& x2)
{
    float x;
    if (a == 0) 
    {
        if (b == 0) return false;
        x1 = x2 = -c/b;
        return true;    
    }
    x = pow(b,2)-4*a*c;
    if (x < 0) return false;
    x1 = (-b-sqrt(x))/(2*a);
    x2 = (-b+sqrt(x))/(2*a);
    return true;
}


int main()
{
    double a, b, c;
    double x1 = 0;
    double x2 = 0;
    
    a = kontroll("a");
    b = kontroll("b");
    c = kontroll("c");

    bool onnestus = lahenda_ruutvorrand(a, b, c, x1, x2);

    if (onnestus)
    {
        cout << fixed << setprecision(2);
        cout << "Lahendid on: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else
    {
        cout << "Viga!" << endl;
    }
    
    getchar();
    return 0;
}