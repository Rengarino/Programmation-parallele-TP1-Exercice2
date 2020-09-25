//fichier Matrice.h
#ifndef _MATRICE_H_
#define _MATRICE_H_
#include <iostream>
#include <thread>

using namespace std;
class Matrice
{
public:
    int ligne;
    int colonne;
    int values[4][4];
    Matrice(const int length);
    ~Matrice();
    void Display();
    void FillMatrice();
    Matrice ProduitMatricielThread(Matrice& A, Matrice& B, Matrice& P);
    void ProduitPij(Matrice& A, Matrice& B, Matrice& P, int i, int j, int k);
};

#endif
