#include <iostream>
#include "node.h"
#include "matrix.h"
#include "tester/tester.h"
//David Lazo
int main() {
    //Tester::execute();
    int f1,c1,f2,c2;
    Matrix m1(f1,c1);
    m1.operator()();
    m1.Mostrar();
    m1.Mostrar();
    m1=m1*m1;

    return EXIT_SUCCESS;

}

