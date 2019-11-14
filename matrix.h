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
    Matrix(const Matrix &CopiaMatrix) {
        this->fila = CopiaMatrix.fila;
        this->columna = CopiaMatrix.columna;
        Matrix(this->fila, this->columna);
        for(int i=0 ; i < this->fila ; ++i) {
            for(int j=0 ; j < this->columna ; ++j) {
                auto value = CopiaMatrix(i, j);
                if (!value)
                    continue;
                set(i, j, value );
            }
        }
    }

    Matrix(unsigned fila, unsigned columna) {
        this->fila = fila;
        this->columna = columna;
        //Elimino primero lo que hay
        fila_.clear(), columna_.clear();
        //A todos Null
        for (int i = 0; i < fila; ++i) {
            fila_.push_back(nullptr);
        }
        for (int i = 0; i < columna; ++i) {
            columna_.push_back(nullptr);
        }
    }//Tamaño de la matrix dispersa

    bool SiguienteColumna(unsigned x, unsigned y, Node<T> **&pointer) {
        bool nuevo = false;
        for (pointer = &fila_[x]; *pointer != NULL; pointer = &(*pointer)->down) {
            if (y == (*pointer)->columna_y) {
                nuevo = true;
                break;
            } else {
                if (y < (*pointer)->columna_y) {
                    *pointer = (*pointer)->down;
                    nuevo = false;
                }
            }
        }
        return nuevo;
    }
    bool SiguienteFila(unsigned x, unsigned y, Node<T> **&pointer) {
        bool resultBool = false;

        for (pointer = &columna_[y]; *pointer != NULL; pointer = &(*pointer)->next) {
            if (x == (*pointer)->fila_x) {
                resultBool = true;
                break;
            } else {
                if (x < (*pointer)->fila_x) {
                    *pointer = (*pointer)->next;
                    resultBool = false;
                }
            }
        }

        return resultBool;
    }

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
                nuevoNodo->valor = valor;
                nuevoNodo->fila_x = fila;
                nuevoNodo->columna_y = columna;

                //Aqui asigno
                nuevoNodo->down = *DPunteroY;
                *DPunteroY = nuevoNodo;

                nuevoNodo->next = *DPunteroX;
                *DPunteroX = nuevoNodo;
            }
        }
    }//Para chantar los nuevos nodos o desaparecerlos

    T operator()(unsigned f, unsigned c) const{// agregue el F C nose mmm vere vere
        auto auxCol = fila_[f];
        //Puede ser asi tambien auto auxCol = col_link[y];
        if (!auxCol)//Si no es nada
            return 0;
        else {//Mando 0
            auto downAux = auxCol;//para el artificio
            while (downAux) {
                if (!(downAux->columna_y == c)) {
                    downAux = downAux->down;//Sigo hasta encontrarlo
                } else return downAux->valor;
            }
            return 0;
        }
    }
    Matrix<T>& operator=(const Matrix<T> &Matrix_Nuev) {
        if (this == &Matrix_Nuev) return *this;
        if (Matrix_Nuev.fila <= 0) return *this;
        this->fila = Matrix_Nuev.fila;
        this->columna = Matrix_Nuev.columna;
        Matrix(this->fila,this->columna);
        for(int i=0 ; i < this->fila ; ++i) {
            for(int j=0 ; j < this->columna ; ++j) {
                auto value = Matrix_Nuev(i, j);
                if (value) {
                    set(i, j, value);
                }
            }
        }
        return *this;
    }//Operador igual
    Matrix<T> operator*(T scalar) const {
        Matrix<T> nuevoresultado(this->fila, this->columna);
        for (auto auxColumna: fila_) {
            if (auxColumna) {
                while (auxColumna) {
                    nuevoresultado.set(auxColumna->fila_x, auxColumna->columna_y, auxColumna->valor * 3);
                    auxColumna = auxColumna->down;
                }
            }
        }
        return nuevoresultado;
    }//Operador escalar (solo multiplicar)
    Matrix<T> operator*(Matrix<T> other) const{
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
//Multiplicacion
    Matrix<T> operator+(Matrix<T> other) const{
        Matrix<T> NuevoResultado(this->fila, this->columna);//Se crea el nuevo
        if(this->fila != other.fila and this->columna != other.columna) {
            cout<<"No coincide el tamaño";
        }
        for (auto AuxFila: fila_) {
            if (AuxFila) {
                while (AuxFila) {
                    NuevoResultado.set(
                            AuxFila->fila_x,
                            AuxFila->columna_y,
                            AuxFila->valor + other(AuxFila->fila_x, AuxFila->columna_y));
                    AuxFila = AuxFila->down;
                }
            }
        }
        return NuevoResultado;
    }//suma
    Matrix<T> operator-(Matrix<T> other) const{
        Matrix<T> NuevoResultado(this->fila, this->columna);//Se crea el nuevo
        if(this->fila != other.fila and this->columna != other.columna) {
            cout<<"No coincide el tamaño";
        }
        for (auto AuxFila: fila_) {
            if (AuxFila) {
                while (AuxFila) {
                    NuevoResultado.set(
                            AuxFila->fila_x,
                            AuxFila->columna_y,
                            AuxFila->valor - other(AuxFila->fila_x, AuxFila->columna_y));
                    AuxFila = AuxFila->down;
                }
            }
        }
        return NuevoResultado;
    }//Resta
    Matrix<T> Transpuesta() const{
        Matrix<T> NuevoResultado(this->columna, this->fila);

        for( int i=0 ; i < this->fila ; ++i) {
            if (!this->fila_[i]) continue;
            auto auxColumna = fila_[i];
            while(auxColumna) {
                NuevoResultado.set(auxColumna->columna_y, auxColumna->fila_x, auxColumna->valor);
                auxColumna = auxColumna->down;
            }
        }
        return NuevoResultado;
    }//Invertir Filas y Columnas
    void ceros(int num)const{
        for(int j=0 ; j < num ; ++j) {
            cout<<"*"<<0<<"*";
        }
    }//imprimir los 0 en la funcion Mostrar();
    void Mostrar() const{
        for( int i=0 ; i < this->fila ; ++i) {
            if( !this->fila_[i] ) {  //empty row
                ceros(this->columna);
                cout << endl;
            }  else {
                auto colAux = fila_[i];
                int colNum = colAux->columna_y;

                ceros(colNum);

                while(colAux) {
                    ceros(colAux->columna_y - colNum - 1);
                    cout << "*" << colAux->valor << "*";
                    colNum = colAux->columna_y;
                    colAux = colAux->down;
                }
                ceros(columna - colNum - 1);
                cout << endl;
            }
        }
    }//Imprimir matriz

    ~Matrix(){
        fila_.clear();
        columna_.clear();
    }//Destructor; debo eliminar los nodos
};

#endif //SPARSE_MATRIX_MATRIX_H