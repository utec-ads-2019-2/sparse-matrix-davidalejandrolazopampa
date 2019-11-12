//
// Created by David Lazo on 11/11/2019.
//
#include "matrix.h"
#include <type_traits>
#include <random>
#include <iostream>
using namespace std;
template <typename T>
Matrix<T>::Matrix(unsigned rows, unsigned columns) {

}

template <typename T>
void Matrix<T>::set(unsigned, unsigned, T){

}

template <typename T>
T Matrix<T>::operator()(unsigned f, unsigned c) const {// agregue el F C nose mmm vere vere
    int i;
    rows = f;
    columns = c;
    root = new T * [rows];
    for(i=0; i<rows; i++){
        root[i] = new T[columns];

    }
    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            root[j][k]=0;
        }
    }
}

}

template <typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const{

}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const{//Tengo que revisarlo xD
    int i, j,k;
    if (this->columns == other.rows) {
        Matrix res(this->rows,other.columns);
        for (i = 0; i < this->rows; i++){
            for (j = 0; j < other.columns; j++){
                for( k = 0 ; k < other.rows; k++)
                    res.elementos[i][j] += root[i][k]*other.elementos[k][j];
            }
        }
        return res;
    } else{
        cout<<"La Columna de M1 no es igual a la fila de M2"<<endl;
    }
}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) const{//Posiblemente
    int i, j;
    if (this->filas == other.filas && this->columnas == other.columnas) {
        Matrix res(other);
        for (i = 0; i < other.filas; i++)
            for (j = 0; j < other.columnas; j++)
                res.elementos[i][j] += this->elementos[i][j];
        return res;
    } else {
        Matrix res;
        return res;
    }
}
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) const{//Solo cambiaria el signo mmm
    int i, j;
    if (this->filas == other.filas && this->columnas == other.columnas) {
        Matrix res(other);
        for (i = 0; i < other.filas; i++)
            for (j = 0; j < other.columnas; j++)
                res.elementos[i][j] -= this->elementos[i][j];
        return res;
    } else {
        Matrix res;
        return res;
    }
}
template <typename T>
Matrix<T> Matrix<T>::transpose() const{

}
template <typename T>
void Matrix<T>::Mostrar() const{//Espero no morir aqui
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            cout<<root[i][j]<<"  ";
        }
        cout<<endl;
    }
}


template <typename T>
Matrix<T>::~Matrix() {//Aun no estoy seguro que esto sea asi xD puedo poner kills... pero no se
    delete [] root;
}