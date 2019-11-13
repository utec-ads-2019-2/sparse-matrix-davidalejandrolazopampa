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
    Matrix(const Matrix &CopiaMatrix);
    Matrix(unsigned fila, unsigned columna);//Tamaño de la matrix dispersa

    bool SiguienteColumna(unsigned x, unsigned y, Node<T> **&pointer);//initialize Rows and Cols
    bool SiguienteFila(unsigned x, unsigned y, Node<T> **&pointer);//Usamos doble puntero para esto

    void inicializar(unsigned fila, unsigned columna); //A todos Null fila y columna
    void set(unsigned fila, unsigned columna, T valor);//Para chantar los nuevos nodos o desaparecerlos

    T operator()(unsigned, unsigned) const;
    Matrix<T> operator=(Matrix<T> other) const;//Operador igual
    Matrix<T> operator*(T escalar) const;//Operador escalar (solo multiplicar)
    Matrix<T> operator*(Matrix<T> other) const;//Multiplicacion
    Matrix<T> operator+(Matrix<T> other) const;//suma
    Matrix<T> operator-(Matrix<T> other) const;//Resta
    Matrix<T> Transpuesta() const;//Invertir Filas y Columnas
    void ceros(int num)const;//imprimir los 0 en la funcion Mostrar();
    void Mostrar() const;//Imprimir matriz

    ~Matrix();//Destructor; debo eliminar los nodos
};

#endif //SPARSE_MATRIX_MATRIX_H