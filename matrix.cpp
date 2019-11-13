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
void Matrix<T>::set(unsigned fila, unsigned columna, T valor){
//Inicio el nuevo puntero
    Node<T> **DPunteroX = nullptr;
    Node<T> **DPunteroY = nullptr;
    //devolvere el bool
    auto resultY = whichPosInCol(fila, columna, DPunteroY);
    auto resultX = whichPosInRow(fila, columna, DPunteroX);
    if (resultY) {//Si existe el Node
        if (valor) {//si es diferente de 0
            (*DPunteroY)->data = valor;
            (*DPunteroX)->data = valor;
        } else {// si es 0 lo elimino
            *DPunteroY = (*DPunteroY)->down;
            *DPunteroX = (*DPunteroX)->next;
        }
    } else {//puede ser X o Y cualquiera
        if (valor) {
            //Creo el nodo como lista
            auto newNode = new Node<T>();
            newNode->posX = fila;
            newNode->posY = columna;
            newNode->data = valor;
            //Aqui asigno
            newNode->down = *DPunteroY;
            *DPunteroY = newNode;

            newNode->next = *DPunteroX;
            *DPunteroX = newNode;
        }
    }
}
template <typename T>
T Matrix<T>::operator()(unsigned f, unsigned c) const {// agregue el F C nose mmm vere vere
    auto auxCol = fila_[f];
    //Puede ser asi tambien auto auxCol = col_link[y];
    if (auxCol)//Si no es nada
    {//Mando 0
        auto downAux = auxCol;//para el artificio
        while (downAux) {
            if (downAux->posY == c)
                return downAux->data;
            downAux = downAux->down;//Sigo hasta encontrarlo
        }
        return 0;
    } else return 0;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(T escalar) const{
    Matrix<T> result(this->fila, this->columna);//objeto nuevo
    for (auto auxCol: fila_) {//bloque
        if (auxCol)//Sigo sigo sigo
        {
            while (auxCol) {
                result.set(auxCol->fila, auxCol->columna, auxCol->data * escalar);//Hago la accion
                auxCol = auxCol->down;//empiso el primero y luego el siguente del siguente
            }
        }
    }
    return result;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const{//Tengo que revisarlo xD

}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) const{//Posiblemente
    Matrix<T> result(this->rows, this->columns);//Se crea el nuevo
    if(this->rows != other.rows and this->columns != other.columns) {
        cout<<"No coincide el tamaño";
    }
    for (auto AuxFila: fila_) {
        if (AuxFila) {
            while (AuxFila) {
                result.set(
                        AuxFila->fila,
                        AuxFila->columna,
                        AuxFila->data + other(AuxFila->fila, AuxFila->columna));
                AuxFila = AuxFila->down;
            }
        }
    }
    return result;
}
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) const{//Solo cambiaria el signo mmm
    Matrix<T> result(this->rows, this->columns);//Se crea el nuevo
    if(this->rows != other.rows and this->columns != other.columns) {
        cout<<"No coincide el tamaño";
    }
    for (auto AuxFila: fila_) {
        if (AuxFila) {
            while (AuxFila) {
                result.set(
                        AuxFila->fila,
                        AuxFila->columna,
                        AuxFila->data - other(AuxFila->fila, AuxFila->columna));
                AuxFila = AuxFila->down;
            }
        }
    }
    return result;
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
