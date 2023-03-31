#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int read = 0, s6ned = 0, tahed = 0, rida = 0;
    string fail, line, s6na;
    cout << "Sisesta faili nimi" << endl;
    cin >> fail;
    ifstream file(fail);
    
    if (file.is_open())
    {
        while (getline(file, line))
        {
            read += 1;
            tahed += line.length();
        }
        cout << "Ridu: " << read << endl;
        cout << "Tahti: " << tahed << endl;
        file.close();
    }
    
    else if (!file.is_open())
    {
        cout << "Ei suutnud faili avada - '" << fail << "'" << endl;
        main();
    }
    else 
    {
        cout << "Error" << endl;
        return 0;
    }

    file.open(fail);
    while(file >> s6na) s6ned += 1;
    file.close();
    cout << "S6nu :" << s6ned << endl;

    cin.ignore(256, '\n');
    getchar();
    return 0;
}