//
// Created by David Lazo on 11/11/2019.
//
#include "matrix.h"

#include <iostream>
using namespace std;

template <typename T>
bool Matrix<T>::SiguienteColumna(unsigned x, unsigned y, Node<T> **&pointer) {
    bool valor = false;
    for (pointer = &fila_[x]; NULL != *pointer; pointer = &(*pointer)->down) {//recore y asigno
        if (x == (*pointer)->columnaa) {
            valor = true;//existe
            break;
        } else if (x < (*pointer)-> columnaa) {//si es menor ----
            *pointer = (*pointer)->down;//sigue
            valor = false;//No existe --- voy al set y meto
        }
    }
    return valor;
}
template <typename T>
bool Matrix<T>::SiguienteFila(unsigned x, unsigned y, Node<T> **&pointer) {
    bool valor = false;
    for (pointer = &columna_[x]; NULL != *pointer; pointer = &(*pointer)->next) {//recore y asigno
        if (x == (*pointer)->filaa) {
            valor = true;//existe
            break;
        } else if (x < (*pointer)-> filaa) {//si es menor ----
            *pointer = (*pointer)->next;//sigue
            valor = false;//No existe --- voy al set y meto
        }
    }
    return valor;
}
template <typename T>
void Matrix<T>::inicializar(unsigned fila, unsigned columna) {
    //Elimino primero lo que hay
    fila_.clear(),columna_.clear();
    //A todos Null
    for(int i=0; i < fila; ++i){
        fila_.push_back(nullptr);
    }
    for(int i=0; i<columna;++i){
        columna_.push_back(nullptr);
    }
}
template <typename T>
Matrix<T>::Matrix(unsigned rows, unsigned columns) {
    inicializar(this->fila_,this->columna_);
}
template <typename T>
Matrix<T>::Matrix(const Matrix &CopiaMatrix) {
    int i,j;
    this->columna = CopiaMatrix.columna;
    this->fila = CopiaMatrix.fila;
    inicializar(this->fila,this->columna);
    for(i=0 ; i < this->fila ; ++i) {
        for(j=0 ; j < this->columna ; ++j) {
            T valor;
            valor = CopiaMatrix(i, j);
            if (!!valor) {set(i, j, valor);//se manda al set para actualizar
            }
        }
    }
}
template <typename T>
void Matrix<T>::set(unsigned, unsigned, T){

}
template <typename T>
T Matrix<T>::operator()(unsigned f, unsigned c) const {// agregue el F C nose mmm vere vere
   /*
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
    }*/
}
template <typename T>
Matrix<T> Matrix<T>::operator*(T escalar) const{

}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const{//Tengo que revisarlo xD
    /*int i, j,k;
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
    }*/
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
    /*
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
    }*/
}
template <typename T>
Matrix<T> Matrix<T>::Transpuesta() const{

}
template <typename T>
void Matrix<T>::Mostrar() const{//Espero no morir aqui
    /*int i, j;//Elimine el root asi que vemos que hago aqui ,,,
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            cout<<root[i][j]<<"  ";
        }
        cout<<endl;
    }*/
}

template <typename T>
void Matrix<T>::ceros(int num) const {
    int contador=0;
    for(int j=0 ; j < num ; ++j) {
        cout<<" "<<contador<<" ";
    }
}

template <typename T>
Matrix<T>::~Matrix() {//Aun no estoy seguro que esto sea asi xD puedo poner kills... pero no se
    for(auto auxColumna : columna_ ) {
        if(auxColumna) {
            auxColumna->killSelf(); break;
        }
    }
    fila_.clear();
    columna_.clear();
}
