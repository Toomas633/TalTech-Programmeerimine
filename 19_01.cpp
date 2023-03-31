#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class maatriks
{
    public:
        maatriks() { veergude_arv = ridade_arv = 0;};
        void loefailist(const string failinimi);
        void valjasta(const string failinimi);
        friend maatriks liida(const maatriks esimene, const maatriks teine);
        friend bool kontroll(maatriks esimene, maatriks teine);
        friend maatriks korruta(const maatriks esimene, const maatriks teine);
    private:
        int ridade_arv;
        int veergude_arv;
        vector<int> vaartused;
};

void maatriks::valjasta(const string failinimi)
{
    ofstream fail(failinimi);

    if (!fail.is_open())
    {
        cout << "Viga, faili" << failinimi << " avamine ebaonnestus!" << endl;
        exit(0);
    }
    
    fail << ridade_arv << ' ' << veergude_arv << endl;

    int k = 0;
    for (int i = 0; i < ridade_arv; i++)
    {
        for (int j = 0; j < veergude_arv; j++)
        {
            fail << vaartused[k] << ' ';
            k++;
        }
        
        fail << endl;
    }


    fail.close();
}

void maatriks::loefailist(const string failinimi)
{
    ifstream fail(failinimi);
    
    if (!fail.is_open())
    {
        cout << "Viga, faili " << failinimi << " avamine ebaonnestus!" << endl;
        exit(0);
    }
    
    fail >> ridade_arv >> veergude_arv;

    int vaartus;
    int k = 0;
    for (int i = 0; i < ridade_arv; i++)
    {
        for (int j = 0; j < veergude_arv; j++)
        {
            fail >> vaartus;
            vaartused.push_back(vaartus);
            k++;
        }
    }

    fail.close();
}

maatriks liida(const maatriks esimene, const maatriks teine)
{
    maatriks liit_maatriks;
    bool sobib;
    
    int ridade_arv = esimene.ridade_arv;
    int veergude_arv = esimene.veergude_arv;

    int index = ridade_arv*veergude_arv;
    liit_maatriks.veergude_arv = veergude_arv;
    liit_maatriks.ridade_arv = ridade_arv;
    
    if (esimene.ridade_arv == teine.ridade_arv && esimene.veergude_arv == teine.veergude_arv)
    {
        cout << "Liidan maatriksid..." << endl;
        int k = 0;
        for (int i = 0; i < ridade_arv; i++)
        {
            for (int j = 0; j < veergude_arv; j++)
            {
                liit_maatriks.vaartused.push_back(esimene.vaartused[k] + teine.vaartused[k]);
                k ++;
            }
        }
    }
    else cout << "Maatriksid pole sama suured, ei saa liita" << endl;

    return liit_maatriks;
}

maatriks korruta(const maatriks esimene, const maatriks teine)
{
    maatriks kord_maatriks;

    int ridade_arv = esimene.ridade_arv;
    int veergude_arv = teine.veergude_arv;
    
    kord_maatriks.veergude_arv = veergude_arv;
    kord_maatriks.ridade_arv = ridade_arv;
    
    int es[esimene.ridade_arv][esimene.veergude_arv];
    int te[teine.ridade_arv][teine.veergude_arv];

    if (esimene.veergude_arv == teine.ridade_arv)
    {
        int l = 0;
        for (int i = 0; i < esimene.ridade_arv; i++)
        {
            for (int j = 0; j < esimene.veergude_arv; j++)
            {
                es[i][j] = esimene.vaartused[l];
                l++;
            }
        }
        l = 0;
        for (int i = 0; i < teine.ridade_arv; i++)
        {
            for (int j = 0; j < teine.veergude_arv; j++)
            {
                te[i][j] = teine.vaartused[l];
                l++;
            }
        }

        cout << "Korrutan maatriksid..." << endl;
        l = 0;
        int vaartus;
        for (int i = 0; i < ridade_arv; i++)
        {   
            for (int j = 0; j < veergude_arv; j++)
            {
                vaartus = 0;
                for (int k = 0; k < esimene.veergude_arv; k++)
                {
                    vaartus += es[i][k] * te[k][j];
                    l++;
                }
                kord_maatriks.vaartused.push_back(vaartus);
            }   
        }
    }
    else cout << "Maatrikseid ei saa korrutada" << endl;

    return kord_maatriks;
}

int main()
{
    maatriks esimene, teine, liit_maatriks, kord_maatriks;

    esimene.loefailist("maatriks-01.txt");
    teine.loefailist("maatriks-02.txt");
    liit_maatriks = liida(esimene, teine);
    kord_maatriks = korruta(esimene, teine);
    liit_maatriks.valjasta("liidetud_maatriksid.txt");
    kord_maatriks.valjasta("korrutatud_maatriksid.txt");
    
    return 0;
}