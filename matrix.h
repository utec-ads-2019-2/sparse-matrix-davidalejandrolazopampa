#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H
#include <stdexcept>
#include <vector>
#include <iomanip>
#include "node.h"
using namespace std;
template <typename T>
class Matrix {
private:
    vector<Node<T> *> fila_;//Vector para la fila
    vector<Node<T> *> columna_;//Vector para la columna
    unsigned fila, columna;
public:

    //Matrix();Aun nose si usarlo
    Matrix(const Matrix &CopiaMatrix){

    }
    Matrix(unsigned fila, unsigned columna){
        inicializar(fila,columna);
    }//Tamaño de la matrix dispersa

    bool SiguienteColumna(unsigned x, unsigned y, Node<T> **&pointer){
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
    }//initialize Rows and Cols
    bool SiguienteFila(unsigned x, unsigned y, Node<T> **&pointer){
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
    }//Usamos doble puntero para esto

    void inicializar(unsigned fila, unsigned columna){
        //Elimino primero lo que hay
        fila_.clear(),columna_.clear();
        //A todos Null
        for(int i=0; i < fila; ++i){
            fila_.push_back(nullptr);
        }
        for(int i=0; i<columna;++i){
            columna_.push_back(nullptr);
        }
    } //A todos Null fila y columna
    void set(unsigned fila, unsigned columna, T valor){
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
    }//Para chantar los nuevos nodos o desaparecerlos

    T operator()(unsigned, unsigned) const;
    Matrix<T> operator=(Matrix<T> other) const;//Operador igual
    Matrix<T> operator*(T escalar) const;//Operador escalar (solo multiplicar)
    Matrix<T> operator*(Matrix<T> other) const;//Multiplicacion
    Matrix<T> operator+(Matrix<T> other) const;//suma
    Matrix<T> operator-(Matrix<T> other) const;//Resta
    Matrix<T> Transpuesta() const;//Invertir Filas y Columnas
    void ceros(int num)const{
        int contador=0;
        for(int j=0 ; j < num ; ++j) {
            cout<<" "<<contador<<" ";
        }
    }//imprimir los 0 en la funcion Mostrar();
    void Mostrar() const{
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
                //ceros(this->fila);
                cout << endl;
            }
        }
    }//Imprimir matriz

    ~Matrix(){
        /*for(auto auxColumna : columna_ ) {
            if(auxColumna) {
                auxColumna->killSelf();
                break;
            }
        }*/
        fila_.clear();
        columna_.clear();
    }//Destructor; debo eliminar los nodos
};

#endif //SPARSE_MATRIX_MATRIX_H