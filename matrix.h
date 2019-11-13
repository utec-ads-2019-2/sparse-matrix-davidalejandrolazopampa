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
    //Node<T> *root;
    vector<Node<T> *> fila_;
    vector<Node<T> *> columna_;
    unsigned rows, columns;
    bool PosColumna(unsigned x, unsigned y, Node<T> **&pointer);//initialize Rows and Cols
    bool PosFila(unsigned x, unsigned y, Node<T> **&pointer);
    void inicializar(unsigned rows, unsigned columns) ;
public:
    int tamaño =3;
    Matrix(unsigned rows, unsigned columns);//Tamaño

    void set(unsigned, unsigned, T);
    T operator()(unsigned, unsigned) const;

    Matrix<T> operator*(T scalar) const;
    Matrix<T> operator*(Matrix<T> other) const;//Multiplicacion
    Matrix<T> operator+(Matrix<T> other) const;//suma
    Matrix<T> operator-(Matrix<T> other) const;//Resta
    Matrix<T> transpose() const;
    void ceros(int num)const;
    void Mostrar() const;

    ~Matrix();//Destructor
};

#endif //SPARSE_MATRIX_MATRIX_H