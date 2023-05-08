#include <iostream>
#include <cmath>
using namespace std;

// абстрактний клас "набір даних"
class Data {
public:
    virtual double norm() = 0;
};

// клас "комплексне число"
class ComplexNumber : public Data {
public:
    double real_part;
    double imaginary_part;
    virtual double norm() {
        return (real_part * real_part) + (imaginary_part * imaginary_part);
    }
};

// клас "вектор з 10 елементів"
class Vector : public Data {
public:
    double elements[10];
    virtual double norm() {
        double sum_of_squares = 0;
        for (int i = 0; i < 10; i++) {
            sum_of_squares += elements[i] * elements[i];
        }
        return sqrt(sum_of_squares);
    }
};

// клас "матриця 2х2"
class Matrix : public Data {
public:
    double elements[2][2];
    virtual double norm() {
        double sum_of_squares = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum_of_squares += elements[i][j] * elements[i][j];
            }
        }
        return sqrt(sum_of_squares);
    }
};

int main() {
    ComplexNumber cn;
    cn.real_part = 3.0;
    cn.imaginary_part = 4.0;
    cout << "Norm of ComplexNumber object: " << cn.norm() << endl;

    Vector v;
    for (int i = 0; i < 10; i++) {
        v.elements[i] = i + 1;
    }
    cout << "Norm of Vector object: " << v.norm() << endl;

    Matrix m;
    m.elements[0][0] = 1.0;
    m.elements[0][1] = 2.0;
    m.elements[1][0] = 3.0;
    m.elements[1][1] = 4.0;
    cout << "Norm of Matrix object: " << m.norm() << endl;

    return 0;
}
