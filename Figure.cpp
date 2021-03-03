//
// Created by Никита Тоглохинов on 03.03.2021.
//

#include "Figure.h"

Square::Square(double a): a(a) {};
double Square::P() const {
    return 4*a;
}

double Square::S() const {
    return a*a;
}

int Square::angles() const {
    if(a!=0) {
        return 4;
    } else return 0;
}


Rectangle::Rectangle(double a, double b): a(a), b(b) {};
double Rectangle::P() const {
    return 2*(a+b);
}

double Rectangle::S() const {
    return a*b;
}

int Rectangle::angles() const {
    if(a*b == 0) {
        return 0;
    } else return 4;
}


Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    if(NotExists()) {
        std::cout << "THIS TRIANGLE CAN'T BE CONSTRUCTED" << std::endl;
    }
    if(IsDegenerated()) {
        std::cout << "WARNING: THIS TRIANGLE IS DEGENERATED" << std::endl;
    }
}

Triangle::Triangle(double a) : a(a), b(a), c(a) { }

double Triangle::P() const {
    if(!NotExists()) {
        return a+b+c;
    } else return -1; //типа ошибка, несуществующи треугольник
}

double Triangle::S() const {
    double p = (a+b+c)/2;
    if(!NotExists()) {
        if(IsDegenerated()) {
            return 0;
        } else return sqrt(p * (p-a) * (p-b) * (p-c));
    } else return -1;
}

int Triangle::angles() const {
    if(!NotExists()) {
        if(IsDegenerated()) {
            return 0;
        } else return 3;
    } else return -1;
}

bool Triangle::NotExists() const {
    if( (a > b+c) || (b > a+c) || (c > a+b) ) {
        return true;
    } else return false;
}

bool Triangle::IsDegenerated() const {
    if( (a == b+c) || (b == a+c) || (c == a+b) ) {
        return true;
    } else return false;
}


Circle::Circle(double r): r(r) {};
double Circle::P() const {
    return 2*std::acos(-1)*r;
}

double Circle::S() const {
    return std::acos(-1)*r*r;
}

int Circle::angles() const {
    return 0;
}


Ellipse::Ellipse(double a, double b) : a(a), b(b) {}

double Ellipse::P() const {
    return 4 * (std::acos(-1)*a*b + (a-b)*(a-b)) / (a+b); //приближенная формула
}

double Ellipse::S() const {
    return std::acos(-1)*a*b;
}

int Ellipse::angles() const {
    return 0;
}