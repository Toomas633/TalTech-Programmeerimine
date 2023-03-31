#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int kypsis;
    cout << "Sisesta lisatavate kypsiste arv: " << endl;
    cin >> kypsis;
    if (kypsis == 10)
    {
        cout << "Kypsiseid on parajalt."<< endl;
    }
    else if (kypsis < 10) 
    {
        cout << "Kypsiseid on vaja juurde panna.";
    }
    else 
    {
        cout << "Kypsiseid on vaja vahemaks v6tta." << endl;
    }


    cin.ignore(256, '\n');
    getchar();
    return 0;
}