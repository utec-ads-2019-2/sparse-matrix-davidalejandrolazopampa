#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H
//Agregar cosas aqui
template <typename T>
class Matrix;
template <typename T>
class Node {
public:
    //T;//Aun no estoy seguro mmm
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

    void killSelf){
        if (this->next){
            this->next->killSelf();
        }else if(this->down){
            this->down->killSelf();
        }
     delete this;
    }
    ~Node(){};

};

#endif //SPARSE_MATRIX_NODE_H