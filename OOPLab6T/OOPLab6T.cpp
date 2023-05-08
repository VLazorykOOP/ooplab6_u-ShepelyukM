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
//-----------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

class Entity {
protected:
    string name;
public:
    Entity(const string& name) : name(name) {}
    virtual ~Entity() {}

    virtual void print() const {
        cout << "Name: " << name << endl;
    }
};

class Person : public Entity {
protected:
    int age;
public:
    Person(const string& name, int age) : Entity(name), age(age) {}

    virtual void print() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Mother : public Person {
public:
    Mother(const string& name, int age) : Person(name, age) {}
    virtual void print() const override {
        cout << "Mother - ";
        Person::print();
    }
};

class Father : public Person {
public:
    Father(const string& name, int age) : Person(name, age) {}
    virtual void print() const override {
        cout << "Father - ";
        Person::print();
    }
};

class Daughter : public Person {
public:
    Daughter(const string& name, int age) : Person(name, age) {}
    virtual void print() const override {
        cout << "Daughter - ";
        Person::print();
    }
};

int main() {
    Entity* entity = new Entity("John Smith");
    entity->print();

    Person* person = new Person("Jane Smith", 30);
    person->print();

    Mother* mother = new Mother("Mary Smith", 50);
    mother->print();

    Father* father = new Father("Bob Smith", 55);
    father->print();

    Daughter* daughter = new Daughter("Alice Smith", 20);
    daughter->print();

    delete entity;
    delete person;
    delete mother;
    delete father;
    delete daughter;

    return 0;
}
