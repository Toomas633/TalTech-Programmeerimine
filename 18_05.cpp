#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>


using namespace std;

struct sort_class {
    bool operator() (string i,string j) { return (i<j);}
} sort_object;

int leia_vaartus(string nimi, int index)
{
    int x = 0, vaartus = 0;

    for (int i = 0; i < nimi.size(); i++)
    {
        x = char(nimi[i]) - 'A' + 1;
        vaartus += x;
    }

    vaartus *= index;
    return vaartus;
}

int main()
{
    int summa = 0;

    vector<string> nimed;
    string sisse;
    ifstream fail("18/names.txt");

    if (!fail.is_open())
    {
        cout << "Faili ei saanud avada!" << endl;
        exit(0);
    }
    
    while (getline(fail, sisse, ','))
    {
        sisse.erase(remove(sisse.begin(), sisse.end(), '"'), sisse.end());
        nimed.push_back(sisse);
    }

    fail.close();
    sort(nimed.begin(), nimed.end(), sort_object);

    for (int i = 0; i < nimed.size(); i++)
    {
        int index = i + 1;
        int vaartus = leia_vaartus(nimed[i], index);
        summa += vaartus;
    }

    cout << summa << endl;

    getchar();
    return 0;
}