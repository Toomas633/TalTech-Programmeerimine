#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int arv, i, a, alg = 0;
    cout << "Sisesta taisarv: " << endl;
    cin >> arv;    
    
    cout << "Algarvud kuni arvuni " << arv << " on:" << endl;
    for (a=2; a <= arv; a++)
    {   
        bool algarv = true;
        for (i=2; i < a; i++ )
        {
            if (a % i == 0)
            {
                algarv = false;
            }
        }
        if (algarv)
        {
            cout << a << endl;
        }
    }
    
    cin.ignore(256, '\n');
    getchar();
    return 0;
}