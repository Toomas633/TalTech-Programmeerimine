#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int* address_a = &a;
    int* address_b = &b;

    cout << "Sisest arvud a ja b: " << endl;
    cin >> a >> b;

    cout << a << endl;
    cout << address_a << endl;
    cout << b << endl;
    cout << address_b << endl;
    cin.ignore(256, '\n');
    getchar();
    return 0;
}