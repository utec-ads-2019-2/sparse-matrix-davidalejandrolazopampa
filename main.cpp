#include <iostream>
#include "node.h"
#include "matrix.h"
#include "tester/tester.h"
//David Lazo
int main() {

    Matrix<int> matrix_A(3,3),matrix_B(3,3);
    matrix_A.set(0,0,6);
    matrix_A.set(0,1,4);
    matrix_A.set(0,3,5);

    matrix_A.set(1,0,7);
    matrix_A.set(1,1,2);
    matrix_A.set(1,2,8);
    matrix_A.set(1,3,-4);

    matrix_A.set(2,0,1);
    matrix_A.set(2,1,3);
    matrix_A.set(2,2,-3);
    matrix_A.set(2,3,9);

    matrix_B.set(0,0,-1);
    matrix_B.set(0,1,6);

    matrix_B.set(1,0,4);
    matrix_B.set(1,1,2);

    matrix_B.set(2,0,7);
    matrix_B.set(2,1,3);

    cout << "Matrix A"<<endl;
    matrix_A.Mostrar();
    cout << "Matrix B"<<endl;
    matrix_B.Mostrar();
    //return 0;
}

