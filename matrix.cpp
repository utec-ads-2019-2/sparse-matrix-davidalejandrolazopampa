//
// Created by David Lazo on 11/11/2019.
/*
#include "node.h"
#include "matrix.h"
#include <iostream>
using namespace std;

template <typename T>
bool Matrix<T>::SiguienteColumna(unsigned x, unsigned y, Node<T> **&pointer) {
    bool valor = false;
    for (pointer = &fila_[x]; NULL != *pointer; pointer = &(*pointer)->down) {//recore y asigno
        if (x == (*pointer)->columna) {
            valor = true;//existe
            break;
        } else if (x < (*pointer)-> columna) {//si es menor ----
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
        if (x == (*pointer)->fila) {
            valor = true;//existe
            break;
        } else if (x < (*pointer)-> fila) {//si es menor ----
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
Matrix<T>::Matrix(unsigned fila, unsigned columna) {
    inicializar(fila,columna);
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
    auto resultY = SiguienteColumna(fila, columna, DPunteroY);
    auto resultX = SiguienteFila(fila, columna, DPunteroX);
    if (resultY) {//Si existe el Node
        if (valor) {//si es diferente de 0
            (*DPunteroY)->valor = valor;
            (*DPunteroX)->valor = valor;
        } else {// si es 0 lo elimino
            *DPunteroY = (*DPunteroY)->down;
            *DPunteroX = (*DPunteroX)->next;
        }
    } else {//puede ser X o Y cualquiera
        if (valor) {
            //Creo el nodo como lista
            auto nuevoNodo = new Node<T>();
            nuevoNodo->fila = fila;
            nuevoNodo->columna = columna;
            nuevoNodo->valor = valor;
            //Aqui asigno
            nuevoNodo->down = *DPunteroY;
            *DPunteroY = nuevoNodo;
            nuevoNodo->next = *DPunteroX;
            *DPunteroX = nuevoNodo;
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
template <typename T>
void Matrix<T>::Mostrar() const{//Espero no morir aqui
    for( int i=0 ; i < this->fila ; ++i) {
        if (this->fila_[i]) {
            auto AuxColumna = fila_[i];
            int num = AuxColumna->columna;
            ceros(num);
            while (AuxColumna) {
                ceros(AuxColumna->columna - num - 1);
                cout << " " << AuxColumna->valor << " ";
                num = AuxColumna->columna;
                AuxColumna = AuxColumna->down;
            }
            ceros(columna - num - 1);
            cout << endl;
        } else {
            ceros(this->columna);
            cout << endl;
        }
    }
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
            auxColumna->killSelf();
            break;
        }
    }
    fila_.clear();
    columna_.clear();
}
*/