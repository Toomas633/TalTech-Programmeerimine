#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int loe_ridade_arv(const string sisend)
{
    ifstream fail(sisend);
    string a;
    int read;

    if (fail.is_open())
    {
        getline(fail, a, ' ');
    }
    
    istringstream(a) >> read;
    fail.close();
    return read;
}

int loe_veergude_arv(const string sisend)
{
    ifstream fail(sisend);
    string a;
    int veerud, b;

    if (fail.is_open())
    {
        getline(fail, a);
        istringstream(a) >> b >> veerud;
    }

    fail.close();
    return veerud;
}

void loe_maatriks(const string failinimi, int *maatriks, int ridade_arv,int veergude_arv)
{
    ifstream fail(failinimi);
    int k = 0;
    
    if (!fail)
    {
        ofstream valjund("summa.txt");
        valjund << "Faili " << failinimi <<" ei saanud avada!" << endl;
        valjund.close();
        fail.close();
        exit(0);
    }
    for (int l = 0; l < 1; l++)
    {
        fail.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < ridade_arv; i++) 
    {
        for (int j = 0; j < veergude_arv; j++)
        {
            fail >> maatriks[k];
            k++;
        }
    }
    fail.close();
}

void liida_maatriksid(int* maatriks_1, int* maatriks_2, int* maatriks_3, const int n)
{
    for (int i = 0; i < n; i++)
    {
        maatriks_3[i] = maatriks_1[i] + maatriks_2[i];
    }

}

void valjasta(const string valjund, int* maatriks, const int ridade_arv, const int veergude_arv)
{
    int l = 0;
    ofstream fail(valjund);
    fail << ridade_arv << ' ' << veergude_arv << endl;
    for (int i = 0; i < ridade_arv; i++)
    {
        for (int j = 0; j < veergude_arv; j++)
        {
            fail << maatriks[l] << ' ';
            l++;
        }
        fail << endl;
    }
    fail.close();
}

int main()
{
    string sisend_1 = "maatriks-01.txt";
    string sisend_2 = "maatriks-02.txt";
    string valjund = "summa.txt";

    int veergude_arv_1 = loe_veergude_arv(sisend_1);
    int ridade_arv_1 = loe_ridade_arv(sisend_1);
    int veergude_arv_2 = loe_veergude_arv(sisend_2);
    int ridade_arv_2 = loe_ridade_arv(sisend_2);
    int n = veergude_arv_1 * ridade_arv_1;
    
    int maatriks_1[n];
    int maatriks_2[n]; 
    int maatriks_3[n];

    if (veergude_arv_1 == veergude_arv_2 && ridade_arv_1 == ridade_arv_2)
    {
        loe_maatriks(sisend_1, maatriks_1, ridade_arv_1, veergude_arv_1);
        loe_maatriks(sisend_2, maatriks_2, ridade_arv_2, veergude_arv_2);
        liida_maatriksid(maatriks_1, maatriks_2, maatriks_3, n);
        valjasta(valjund, maatriks_3, ridade_arv_1, veergude_arv_1);
    }
    else
    {
        ofstream error(valjund);
        error << "Maatriksid ei ole sama suured!" << endl;
        error.close();
    }
    
    return 0;
}