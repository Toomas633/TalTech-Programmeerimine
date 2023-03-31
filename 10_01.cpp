#include <iostream>

using namespace std;

int main()
{
    int arv;
    int* viit = &arv;

    cout << "Sisest arv: " << endl;
    cin >> arv;

    cout << arv << endl;
    cout << &arv << endl;
    cin.ignore(256, '\n');
    getchar();
    return 0;
}