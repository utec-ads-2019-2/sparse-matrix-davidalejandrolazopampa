#include <iostream>
#include "matrix.h"
using namespace std;
//David Lazo
int main() {

    Matrix<int> matrix_A(3,3);
    Matrix<int> matrix_B(3,3);
    Matrix<int> matrix_C(3,3);
    Matrix<int> matrix_D(3,3);
    Matrix<int> matrix_E(3,3);
    Matrix<int> matrix_F(3,3);
    Matrix<int> matrix_G(3,3);
    Matrix<int> matrix_H(3,3);

    matrix_A.set(0,0,1);
    matrix_A.set(1,1,1);
    matrix_A.set(2,1,2);

    matrix_B.set(0,0,2);
    matrix_B.set(1,1,2);
    matrix_B.set(2,2,2);

    cout<<"Matrix A"<<endl;
    matrix_A.Mostrar();cout<<endl;
    cout<<"Matrix B"<<endl;
    matrix_B.Mostrar();cout<<endl;
    cout<<"Matrix A = C Probando que funciona Operator() y Operator=()"<<endl;
    matrix_C=matrix_A;
    matrix_C.Mostrar();cout<<endl;
    cout<<"Matrix D Mostrando el Operador Escalar x3"<<endl;
    matrix_D = matrix_A.operator*(3);
    matrix_D.Mostrar();cout<<endl;

    cout<<"Matrix A Transpuesta"<<endl;
    matrix_F = matrix_A.Transpuesta();
    matrix_F.Mostrar();cout<<endl;

    cout<<"Matrix E = Matrix A * MatrixB"<<endl;
    matrix_E = matrix_B * matrix_C;
    matrix_E.Mostrar();cout<<endl;

    cout<<"Matrix F = Matrix A + MatrixB"<<endl;
    matrix_F = matrix_A + matrix_B;
    matrix_F.Mostrar();cout<<endl;

    cout<<"Matrix G = Matrix A - MatrixB"<<endl;
    matrix_G = matrix_A - matrix_B;
    matrix_G.Mostrar();cout<<endl;


    return 0;
}

