#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define N 5

bool pilihPria(int prioritas[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prioritas[w][i] == m1)
            return true;

        if (prioritas[w][i] == m)
            return false;
    }
} 
void stableMarriage(int prioritas[2 * N][N]) //smp adalah untuk pencocokan nya 
{
    int partnerWanita[N];

    bool priaSendiri[N];

    memset(partnerWanita, -1, sizeof(partnerWanita));
    memset(priaSendiri, false, sizeof(priaSendiri));
    int jumlahSendiri = N;

    while (jumlahSendiri > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (priaSendiri[m] == false)
                break;

        for (int i = 0; i < N && priaSendiri[m] == false; i++)
        {
            int w = prioritas[m][i];

            if (partnerWanita[w - N] == -1)
            {
                partnerWanita[w - N] = m;
                priaSendiri[m] = true;
                jumlahSendiri--;
            }

            else
            {
                int m1 = partnerWanita[w - N];

                if (pilihPria(prioritas, w, m, m1) == false)
                {
                    partnerWanita[w - N] = m;
                    priaSendiri[m] = true;
                    priaSendiri[m1] = false;
                }
            } 
        }
    }
    cout << " Pria     Wanita  " << endl;
    cout << "-----------------" << endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++)
    {
        if (i < N)
        {
            if (partnerWanita[i] == 0)
                man = "Victor";
            if (partnerWanita[i] == 1)
                man = "Wyatt";
            if (partnerWanita[i] == 2)
                man = "Xavier";
            if (partnerWanita[i] == 3)
                man = "Yancey";
            if (partnerWanita[i] == 4)
                man = "Zeus";
                
            if (i == 0)
                woman = "Amy";
            if (i == 1)
                woman = "Bertha";
            if (i == 2)
                woman = "Clare";
            if (i == 3)
                woman = "Diane";
            if (i == 4)
                woman = "Erika";
        }
        cout << " " << man << "\t  " << woman << endl;
    }
}

int main()
{
    int prioritas[2 * N][N] = {{6, 5, 8, 9, 7},
                            {8, 6, 5, 7, 9},
                            {6, 9, 7, 8, 5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                            {4, 0, 1, 3, 2},
                            {2, 1, 3, 0, 4},
                            {1, 2, 3, 4, 0},
                            {0, 4, 3, 2, 1},
                            {3, 1, 4, 2, 0}};
    stableMarriage(prioritas);

    return 0;
}
 
