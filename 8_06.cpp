#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float pindala(float k1, float k2, float k3)
{
    float p, S;
    p = (k1 + k2 + k3) / 2.0;
    S = sqrt(p*(p-k1)*(p-k2)*(p-k3));
    return S;
}

float umberm66t(float k1, float k2, float k3)
{
    float P;
    P = k1 + k2 + k3;
    return P;
}

int kolmnurga_kontroll(float k1, float k2, float k3)
{
    int kolmnurk;
    if (k1 + k2 > k3 && k1 + k3 > k2 && k2 + k3 > k1) kolmnurk = 1;
    else kolmnurk = 0;
    return kolmnurk;
}

int main()
{
    int x1, x2, x3, y1, y2, y3, kolmnurk;
    float k1, k2, k3, S, P;
    cout << "Sisesta punkti 1 kordinaadid (tuhik eraldab): " << endl;
    cin >> x1 >> y1;
    cout << "Sisesta punkti 2 kordinaadid (tuhik eraldab): " << endl;
    cin >> x2 >> y2;
    cout << "Sisesta punkti 3 kordinaadid (tuhik eraldab): " << endl;
    cin >> x3 >> y3;

    k1 = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
    k2 = sqrt(pow(x3-x2, 2)+pow(y3-y2, 2));
    k3 = sqrt(pow(x3-x1, 2)+pow(y3-y1, 2));

    kolmnurk = kolmnurga_kontroll(k1, k2, k3);
    
    if (kolmnurk == 0)
    {
        cout << "Ei saa olla kolmnurk." << endl;
    }
    else if (kolmnurk == 1)
    {
        S = pindala(k1, k2, k3);
        P = umberm66t(k1, k2 ,k3);
        cout << fixed << setprecision(2);
        cout << "Kolmnurga pindala on: " << S << endl;
        cout << "Kolmnurga umberm66t on: " << P << endl;
    }

    cin.ignore(256, '\n');
    getchar();
    return 0;
}