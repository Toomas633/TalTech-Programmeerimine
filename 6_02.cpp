#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    float p, S;
    cout << "Sisesta 1ne kylg: " << endl;
    cin >> a;
    cout << "Sisesta 2ne kylg: " << endl;
    cin >> b;
    cout << "Sisesta 3s kylg: " << endl;
    cin >> c;

    if (a + b > c && b + c > a && a + c > b) 
    {
        p = (a + b + c) / 2.0;
        S = sqrt(p*(p-a)*(p-b)*(p-c));
        cout << "Sobib kolmnurgaks. Pindala: " << S << endl;
    }
    else 
    {
        cout << "Ei sobi kolmnurgaks." << endl;
    }

    cin.ignore(256, '\n');
    getchar();
    return 0;
}