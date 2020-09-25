#include <iostream>
#include "Matrice.h"
#include <thread>


using namespace std;

Matrice::Matrice(const int l) {
    this->ligne = l;
    this->colonne = l;
    this->values[l][l];
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j <l; j++)
        {
            this->values[i][j] = 0;
        }
    }
}

Matrice::~Matrice() {}

void Matrice::Display() {
    for(int i = 0; i < this->ligne; i++) {
        for(int j = 0; j < this->colonne; j++) {
            if(j == this->colonne-1) cout << this->values[i][j];
            else cout << this->values[i][j] << " - ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrice::FillMatrice() {
    for(int i = 0; i < this->ligne; i++) {
        for(int j = 0; j < this->colonne; j++) {
            this->values[i][j] = rand()%5+1; //Donne un nombre random entre 1 et 5
        }
    }
}

void Helloworld() {
    cout << "Helloworld !" << endl;
}

Matrice Matrice::ProduitMatricielThread(Matrice& A, Matrice& B, Matrice& P) {
    for(int i = 0; i < A.ligne ; i++) {
        for(int j = 0; j < B.colonne; j++) {
            for(int k = 0; k < A.colonne; k++) {
                thread t(&Matrice::ProduitPij, this, ref(A), ref(B), ref(P), i, j, k);
                t.join();
            }
        }
    }
    return P;
}

void Matrice::ProduitPij(Matrice& A, Matrice& B, Matrice& P, int i, int j, int k) {
    P.values[i][j] += A.values[i][k] * B.values[k][j];
}

int main(int ac, char** av) {

    const int length = 4;
    Matrice A = Matrice(length);
    //A.Display();
    A.FillMatrice();
    A.Display();
    Matrice B = Matrice(length);
    B.FillMatrice();
    B.Display();
    Matrice P = Matrice(length);
    P = P.ProduitMatricielThread(A, B, P);
    P.Display();

}
