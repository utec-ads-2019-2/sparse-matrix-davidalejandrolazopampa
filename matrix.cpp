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
T Matrix<T>::operator()(unsigned, unsigned) const {

}

template <typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const{

}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const{
}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) const{

}
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) const{

}
template <typename T>
Matrix<T> Matrix<T>::transpose() const{

}
template <typename T>
void Matrix<T>::Mostrar() const{
    cout<<"Hola";
}


template <typename T>
Matrix<T>::~Matrix() {

}