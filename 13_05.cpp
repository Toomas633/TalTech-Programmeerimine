#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

bool isikukoodi_kontroll(char isikukood[11])
{
    bool viga = false;
    
    char a = isikukood[0];
    char b1 = isikukood[1];
    char b2 = isikukood[2];
    char c1 = isikukood[3];
    char c2 = isikukood[4];
    char d1 = isikukood[5];
    char d2 = isikukood[6];
    char e1 = isikukood[7];
    char e2 = isikukood[8];
    char e3 = isikukood[9];
    char f = isikukood[10];

    if (a >= '0' && a <= '6') viga = false;
    else viga = true;

    if (b1 >= '0' && b1 <= '9') viga = false;
    else if (b2 >= '0' && b2 <= '9') viga = false;
    else viga = true;

    if (c1 == '0') 
    {
        if (c2 >= '1' && c2 <= '9') viga = false;
        else viga = true;
    }
    else if (c1 == '1')
    {
        if(c2 >= '0' && c2 <= '2') viga = false;
        else viga = true;
    }
    else viga = true;

    if (d1 == '0')
    {
        if (d2 >= '1' && d2 <= '9') viga =false;
        else viga = true;
    }
    else if (d1 >= '1' && d1 <= '2')
    {
        if (d2 >= '0' && d2 < '9') viga = false;
        else viga = true;
    }
    else if (d1 == '3')
    {
        if (d2 >= '0' && d2 <= '1') viga = false;
        else viga = true;
    }
    else viga = true;

    if (e1 >= '0' && e1 <= '9')
    {
        if (e2 >= '0' && e2 <= '9')
        {
            if (e3 >= '0' && e3 <= '9') viga = false;
            else viga = true;
        }
        else viga = true;
    }
    else viga = true;

    if (f >= '0' && f <= '9') viga = false;
    else viga = true;

    return viga;
}


int main()
{
    bool viga;
    char isikukood[11];
    string sisend;
    do
    {
        viga = false;
        cout << "Sisesta isikukood:" << endl;
        cin >> sisend;
        
        if (cin.fail())
        {
            cout << "Viga!" << endl;
            viga = true;
            cin.clear();
        }
        else if (sisend.length() != 11)
        {
            cout << "Viga! Vale pikkus!" << endl;
            viga = true;
            cin.clear();
        }
    } while(viga);

    strcpy(isikukood, sisend.c_str());

    bool vale = isikukoodi_kontroll(isikukood);
    if(vale) cout << "Isikukood on vale" << endl;
    else cout << "Isikukood on 6ige" << endl;
    
    cin.ignore(256, '\n');
    getchar();
    return 0;
}