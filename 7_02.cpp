#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int arv, i;
    float fakt = 1.0;
    cout << "Sisesta täisarv: " << endl;
    cin >> arv;

    for (i = 1; i <= arv; i++)
    {
        fakt = fakt*i;
    }
    

    cout << fakt << endl;
    cin.ignore(256, '\n');
    getchar();
    return 0;
}