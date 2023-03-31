#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

// to_string() võib olla täiesti mõtetult kasutatud kui mul vahel mingil põhjusel otse int ei töötanud (arvatavasti minu seadme viga)
// Üksikuid juppe leidsin slack overflowst ja dokumentatsioonists (ootamised enne väljumist, faili avamine juurdekirjutamise formaadis, transform, rand(srand))

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

void salvesta(string nimi, vector<string> manguvali, vector<string> vordlus, bool lahendati, int katse) //Salvestan tulemused faili.
{
    ofstream fail("mangud.txt", ios::app); //Avan faili juurdekirjutamise formaadis

    fail << "Nimi:" << nimi << endl;
    
    for (int i = 0; i < 6; i++) fail << manguvali[i] << endl << "   " << vordlus[i] << endl;
    
    if (lahendati == true) fail << "Lahendati: Jah" << endl << "Katse nr.: " << to_string(katse) << endl << endl;
    else fail << "Lahendati: Ei" << endl << endl; 
    
    fail.close();
}

vector<string> tootlemine(string pakkumine, string lahendus, int kord, vector<string> vordlus) //Kontrollin pakkumise tähtede asukohta ja lisan tulemuse vastavale nimekirja kohale
{
    
    for (int i = 0; i < 5; i++)
    {
        if (pakkumine[i] == lahendus[i]) vordlus[kord][i] = '+'; //Kui täht on õigel kohal
        else if(lahendus.find(pakkumine[i]) < 0 || lahendus.find(pakkumine[i]) > 5) vordlus[kord][i] = ' '; //Lahend ei sisalda tähte
        else vordlus[kord][i] = '?'; //Täht on valel kohal
    }

    return vordlus; //Tagastan täiendatud nimekirja
}

vector<string> prindi_vali(vector<string> vordlus, vector<string> manguvali) //Kuvan kasutajale mänguvälja ja uuendan mälus olevat välja
{
    int valik;
    
    cout << endl;
       
    for (int i = 0; i < 6; i++) 
    {
        cout << manguvali[i] << endl << "   " << vordlus[i] << endl;
    }

    return manguvali; //Tagastan uue välja mällu
}

string loe_pakkumine(vector<string> lubatud, string lahendus, bool& oige) //Küsin ja kontrollin kasutaja pakkumist
{
    string pakkumine;
    bool viga;
    do
    {
        viga = false;
        cout << "Sisesta 5-e taheline s6na: ";
        cin >> pakkumine;
        cout << endl;
        transform(pakkumine.begin(), pakkumine.end(), pakkumine.begin(), ::toupper);
        if (pakkumine == lahendus) //Kontrollin kas pakuti õiget lahendsust
        {
            viga = false;
            oige = true;
        }
        else if (pakkumine.size() != 5) //Kas pakkumine on sobiva pikkusega
        {
            cout << "S6na vale pikkusega!" << endl;
            viga = true;
            oige = false;
        }
        else if (cin.fail())
        {
            cin.clear();
            cout << "Viga!" << endl;
            viga = true;
            oige = false;
        }
        else if (count(lubatud.begin(), lubatud.end(), pakkumine) == 0) //Kas on sobiv pakkumine failidest
        {
            cout << "Sellist pakkumist ei leitud!" << endl;
            viga = true;
            oige = false;
        }
    } while (viga); 
    
    return pakkumine;
}

string arvatav_sona(string lahendused) //Loen vastuste faili sisse ja valin sealt suvalise sõna vastuseks
{
    vector<string> soned;
    string n, sone;
    ifstream fail(lahendused);
    if (!fail.is_open()) 
    {
        cout << "Faili " << lahendused << "ei saanud avada!" << endl;
        exit(0);
    }   
    getline(fail, n);
    int num = stoi(n);   
    while (getline(fail, n))
    {
        transform(n.begin(), n.end(), n.begin(), ::toupper); //Suurtähtedeks
        soned.push_back(n);
    }
    srand(time(NULL)); //Leian suvalise indexi lahendi jaoks
    int suvaline = rand()%num; 
    sone = soned[suvaline];
    fail.close();
    return sone; //Tagastan vastuse
}

vector<string> lubatud_pakkumised(string pakkumised, string lahendused) //Koostan lubatud pakkumiste nimekirja
{
    vector<string> lubatud;
    string n;
    ifstream fail(pakkumised);  
    ifstream fail_2(lahendused);

    if (!fail.is_open()) 
    {
        cout << "Faili " << pakkumised << "ei saanud avada!" << endl;
        exit(0);
    }  
    else if (!fail_2.is_open()) 
    {
        cout << "Faili " << lahendused << "ei saanud avada!" << endl;
        exit(0);
    }  

    getline(fail, n);
    int num = stoi(n);
    getline(fail_2, n); //Loen / "tühjendan" esimese sonade arvuga rea 

    while (getline(fail, n)) //Kannan pakkumised.txt sõned nimekirja
    {
        transform(n.begin(), n.end(), n.begin(), ::toupper);
        lubatud.push_back(n);
    }
    while (getline(fail_2, n)) //Kannan lahendused.txt sõned nimekijra
    {
        transform(n.begin(), n.end(), n.begin(), ::toupper);
        lubatud.push_back(n);
    }

    fail.close();
    fail_2.close();
    return lubatud; //Tagastan lubatud pakkumiste nimekirja
}

int main()
{
    string lahendused = "lahendused.txt";
    string pakkumised = "pakkumised.txt";
    string nimi;
    cout << "Sisestage nimi:";
    cin >> nimi;
    cout << endl;
    
    start: //Uue mängu alusamiseks tullakse siia tagasi
    
    int valik = 0;
    bool oige = false;
    vector<string> manguvali = {};    
    vector<string> vordlus = {};
    vector<string> lubatud = {};
    lubatud = lubatud_pakkumised(pakkumised, lahendused); 
    string arvatav = arvatav_sona(lahendused);
    

    for (int i = 0; i < 6; i++) vordlus.push_back("     "); //Vormindan ette kontrolli/võrdluse/+? nimekirja
    
    for (int i = 0; i < 6; i++) manguvali.push_back(to_string(i + 1) + ". _____"); //Vormindan ette mänguvälja

    for (int i = 0; i < 6; i++) cout << endl << to_string(i + 1) << ". "<< "_____" << endl << "        " << endl; //Prindin esimese tühja mänguvälja
    cout << endl; 

    for (int i = 0; i < 6; i++) 
    {
        string pakkumine = loe_pakkumine(lubatud, arvatav, oige);
        vordlus = tootlemine(pakkumine, arvatav, i, vordlus); // +?
        manguvali[i] = to_string(i + 1) + ". " + pakkumine; //Asendan mänguväla vastava rea pakkumisega
        manguvali = prindi_vali(vordlus, manguvali); //Kuvan mänguvälja ja võtan vastu uuendatud välja
        if (oige == true) //Kui lahendati sõna ära
        {
            bool lahendati = true;
            salvesta(nimi, manguvali, vordlus, lahendati, (i + 1)); //Salvestan tulemuse
            cout << "Palju 6nne, s6na arvatud!" << endl;
            cout << "Kas soovite uuesti alustada?" << endl << endl;
            cout << "  [1] Jah           [2] Ei" << endl;
            cin >> valik;
            if (valik == 1)
            {
                goto start; //Algusesse
            }
            else //Ei näinud pointi mingi ilge kontrolli tegemiseks
            {
                cout << "Nagemist!" << endl;
                sleep_for(seconds(3));
                exit(0);
            }
        }
    }
    bool lahendati = false;
    salvesta(nimi, manguvali, vordlus, lahendati, 0); //Salvestan tulemuse (0 on lihtsalt kohatäide kuna mittelahendamise puhul käikude arvu väljundfailis ei kuva)
    cout << "Mang labi!" << endl << "S6na oli: " << arvatav << endl;
    cout << "Kas soovite uuesti alustada?" << endl << endl;
    cout << "  [1] Jah           [2] Ei" << endl;
    cin >> valik;
    if (valik == 1)
    {
        goto start; //Algusesse
    }
    else //Ei näinud pointi mingi ilge kontrolli tegemiseks
    {
        cout << "Nagemist!" << endl;
        sleep_for(seconds(3));
        exit(0);
    }

    return 0;
}