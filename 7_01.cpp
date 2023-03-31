#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int arv, len;
    cout << "Sisesta täisarv: " << endl;
    cin >> arv;

    if (arv > 0)
    {
        for (len = 0; arv > 0; len++)
        {
            arv = arv/10;
        }
    }
    

    cout << len << endl;
    cin.ignore(256, '\n');
    getchar();
    return 0;
}