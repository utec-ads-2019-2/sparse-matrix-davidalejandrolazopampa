#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H
//Agregar cosas aqui
template <typename T>
class Matrix;
template <typename T>
class Node {
public:
    T valor;
    Node<T> *next;
    Node<T> *down;
    int fila_x,columna_y;
    explicit Node(){
        next= nullptr;
        down= nullptr;
        fila_x=0;
        columna_y=0;
    };
    friend class Matrix<T>;//Matrix puede aceeder a nodo

    void killSelf(){//Lo uso ya que esta en casi todos los proyectos de usted profe
        if (this->next){//Para el next
            this->next->killSelf();
        }else if(this->down){//Para el down
            this->down->killSelf();
        }
     delete this;
    }
    ~Node(){}

};

#endif //SPARSE_MATRIX_NODE_H