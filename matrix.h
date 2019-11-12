#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H
#include <stdexcept>
#include "node.h"
using namespace std;
template <typename T>
class Matrix {
private:
    Node<T> *root;
    unsigned rows, columns;

public:
    Matrix(unsigned rows, unsigned columns);//Tamaño

    void set(unsigned, unsigned, T);
    T operator()(unsigned, unsigned) const;

    Matrix<T> operator*(T scalar) const;
    Matrix<T> operator*(Matrix<T> other) const;//Multiplicacion
    Matrix<T> operator+(Matrix<T> other) const;//suma
    Matrix<T> operator-(Matrix<T> other) const;//Resta
    Matrix<T> transpose() const;
    void Mostrar() const;

    ~Matrix();//Destructor
};

#endif //SPARSE_MATRIX_MATRIX_H