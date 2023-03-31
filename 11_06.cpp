#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void leia_juhuarvud(int al, int yl, int*& arvud, int n)
{
    arvud = new int[n];
    for (int i = 0; i < n; i++)
    {
        int range = yl - al + 1;
        arvud[i] = rand() % range + al;
    }
}

void juhus6ned(string* s6ned, int* arvud, int n, string*& vaartused)
{
    vaartused = new string[n];
    for (int k = 0; k < n; k++)
    {
        vaartused[k] = s6ned[arvud[k]];
    }
}

int main()
{
    int n = 3, yl = 10, al = 1, k = 10;
    int* arvud = nullptr;

    string s6ned[k]={"null", "yks", "kaks", "kolm", "neli", "viis", "kuus", "seitse", "kaheksa", "yheksa"};
    cout << "S6ned:" << endl;
    cout << "{";
    for (int i = 1; i < k; i++)
    {
        cout << s6ned[i] << ", ";
    }
    cout << endl;

    leia_juhuarvud(al, yl, arvud, n);

    cout << "Juhuarvud on: " << endl;
    cout << "{";
    for (int j = 0; j < n; j++)
    {
        cout << arvud[j] << ", ";
    }
    cout << "}" << endl;
    
    string* vaartused = nullptr;
    juhus6ned(s6ned, arvud, n, vaartused);
    cout << n << " juhuslikku s6ne on:" << endl;
    cout << "{";
    for (int l = 0; l < n; l++)
    {
        cout << vaartused[l] << ", ";
    }
    cout << "}" << endl;

    delete[] arvud;
    delete[] vaartused;
    getchar();
    return 0;
}