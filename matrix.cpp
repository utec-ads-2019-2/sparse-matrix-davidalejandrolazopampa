//
// Created by David Lazo on 11/11/2019.
/*
#include "node.h"
#include "matrix.h"
#include <iostream>
using namespace std;
template <typename T>
T Matrix<T>::operator()(unsigned f, unsigned c) const {// agregue el F C nose mmm vere vere
    auto auxCol = fila_[f];
    //Puede ser asi tambien auto auxCol = col_link[y];
    if (auxCol)//Si no es nada
    {//Mando 0
        auto downAux = auxCol;//para el artificio
        while (downAux) {
            if (downAux->posY == c)
                return downAux->valor;
            downAux = downAux->down;//Sigo hasta encontrarlo
        }
        return 0;
    } else return 0;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(T escalar) const{
    Matrix<T> NuevoResultado(this->fila, this->columna);//objeto nuevo
    for (auto auxCol: fila_) {//bloque
        if (auxCol)//Sigo sigo sigo
        {
            while (auxCol) {
                NuevoResultado.set(auxCol->fila, auxCol->columna, auxCol->valor * escalar);//Hago la accion
                auxCol = auxCol->down;//empiso el primero y luego el siguente del siguente
            }
        }
    }
    return NuevoResultado;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const{//Tengo que revisarlo xD
    int i,j,k;T aux = 0;
    Matrix<T> NuevoResultado(this->fila, other.columna);
    if(this->columna != other.fila) {
        cout<<"No coincide el tamaño";
    }
    for (i=0;i< NuevoResultado.fila;++i) {
        for (j=0;j< NuevoResultado.columna;++j) {
            for (k=0;k<this->columna;k++){
                aux = aux +  operator()(i, k) * other(k, j);
                NuevoResultado.set(i, j, aux);
            }
        }
    }
    return NuevoResultado;
}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) const{//Posiblemente
    Matrix<T> NuevoResultado(this->fila, this->columna);//Se crea el nuevo
    if(this->fila != other.fila and this->columna != other.columna) {
        cout<<"No coincide el tamaño";
    }
    for (auto AuxFila: fila_) {
        if (AuxFila) {
            while (AuxFila) {
                NuevoResultado.set(
                        AuxFila->fila,
                        AuxFila->columna,
                        AuxFila->valor + other(AuxFila->fila, AuxFila->columna));
                AuxFila = AuxFila->down;
            }
        }
    }
    return NuevoResultado;
}
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) const{//Solo cambiaria el signo mmm
    Matrix<T> NuevoResultado(this->fila, this->columna);//Se crea el nuevo
    if(this->fila != other.fila and this->columna != other.columna) {
        cout<<"No coincide el tamaño";
    }
    for (auto AuxFila: fila_) {
        if (AuxFila) {
            while (AuxFila) {
                NuevoResultado.set(
                        AuxFila->fila,
                        AuxFila->columna,
                        AuxFila->valor - other(AuxFila->fila, AuxFila->columna));
                AuxFila = AuxFila->down;
            }
        }
    }
    return NuevoResultado;
}
template <typename T>
Matrix<T> Matrix<T>::Transpuesta() const{
    Matrix<T> NuevoResultado(this->columna, this->fila);

    for( int i=0 ; i < this->fila ; ++i) {
        if (!this->fila_[i]) continue;
        auto auxColumna = fila_[i];
        while(auxColumna) {
            NuevoResultado.set(auxColumna->columna, auxColumna->columna, auxColumna->valor);
            auxColumna = auxColumna->down;
        }
    }
    return NuevoResultado;
}
*/