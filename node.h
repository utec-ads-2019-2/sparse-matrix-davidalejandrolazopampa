#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H
//Agregar cosas aqui
template <typename T>
class Matrix;
template <typename T>
class Node {
public:
    T;
    int fila;
    int columna;
    Node<T> *next;
    Node<T> *down;

    explicit Node(){
        next= nullptr;
        down= nullptr;
        fila=0;
        columna=0;
    };

    friend class Matrix<T>;//Matrix puede aceeder a nodo
    
    ~Node();
};

#endif //SPARSE_MATRIX_NODE_H