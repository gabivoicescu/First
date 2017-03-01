#include<stdlib.h>
#include<iostream>
#include<ctime>
using namespace std;

//ajutatoare
void clear()
{
    getchar();
    system("cls");
}

//Ajutatoare Array
template<typename T>
void populare(T *pa, unsigned short SIZE, T startInterval = -5, T endInterval = 5)
{
    for (int i = 0; i < SIZE; ++i)
    {
        *pa = rand() % (endInterval + 1 - startInterval) + startInterval;
        ++pa;
    }
}

template<typename T>
void afisare(T *pa, unsigned short SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        cout << pa[i] << "\t";
    }
    cout << endl;
}

//Ajutatoare Matrice
template<typename T>
void populare(T **pa, unsigned short SIZE_X, unsigned short SIZE_Y, T startInterval = -5, T endInterval = 5)
{
    for (int i = 0; i < SIZE_Y; ++i)
        populare(pa[i], SIZE_X, startInterval, endInterval);
}


template<typename T>
void afisare(T **pa, unsigned short SIZE_X, unsigned short SIZE_Y)
{
    for (int i = 0; i < SIZE_Y; ++i)
    {
        afisare(pa[i], SIZE_X);
    }
    cout << endl;
}

//Ajutatoare Matrice
template<typename T>
void populare(T ***pa, unsigned short SIZE_X, unsigned short SIZE_Y, unsigned short SIZE_Z, T startInterval = -5, T endInterval = 5)
{
    for (int i = 0; i < SIZE_Z; ++i)
        populare(pa[i], SIZE_X, SIZE_Y, startInterval, endInterval);
}


template<typename T>
void afisare(T ***pa, unsigned short SIZE_X, unsigned short SIZE_Y, unsigned short SIZE_Z)
{
    for (int i = 0; i < SIZE_Z; ++i)
    {
        afisare(pa[i], SIZE_X, SIZE_Y);
    }
    cout << endl;
}

void main()
{
    const unsigned short SIZE_X = 7;
    const unsigned short SIZE_Y = 8;
    const unsigned short SIZE_Z = 3;
    int ***matrice = new int**[SIZE_Z];
 
    for (int i = 0; i < SIZE_Z; ++i)
    {
        matrice[i] = new int*[SIZE_Y];

        for (int j = 0; j < SIZE_Y; ++j)
        {
            matrice[i][j] = new int[SIZE_X];
        }
    }
    populare(matrice, SIZE_X, SIZE_Y, SIZE_Z, -20, 80);

    afisare(matrice, SIZE_X, SIZE_Y, SIZE_Z);

    clear();
}