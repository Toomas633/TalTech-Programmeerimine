#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int arv, i;
    cout << "Sisesta arv: " << endl;
    cin >> arv;

    for (i=1; i <= arv; ++i )
    {
        cout << arv << " * " << i << " = " << arv*i << endl;
    }


    cin.ignore(256, '\n');
    getchar();
    return 0;
}