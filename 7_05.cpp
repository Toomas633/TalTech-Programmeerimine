#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int arv, i, j, tuhik;
    cout << "Sisesta arv: " << endl;
    cin >> arv;
    tuhik = arv - 1;
    for (i=1; i <= arv; i++ )
    {
        for (j=1; j <= tuhik; j++)
        {
            cout << " ";
        }
        tuhik--;
        for (j=1; j <= (2*i-1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    tuhik = 1;

    for (i=1; i <= (arv-1); i++)
    {
        for (j=1; j <= tuhik; j++)
        {
            cout << " ";
        }
        tuhik++;
        for (j=1; )
    }




    cin.ignore(256, '\n');
    getchar();
    return 0;
}