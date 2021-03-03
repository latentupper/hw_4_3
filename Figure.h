//
// Created by Никита Тоглохинов on 03.03.2021.
//

#ifndef INC_2_FIGURE_H
#define INC_2_FIGURE_H
#include <cmath>
#include <iostream>


template<typename DerivedFigure>
class Figure{
public:
    double P() {
        return static_cast<DerivedFigure*>(this)->P();
    }
    double S() {
        return static_cast<DerivedFigure*>(this)->S();
    }
    int angles() {
        return static_cast<DerivedFigure*>(this)->angles();
    }
};

class Square: public Figure<Square> {
public:
    explicit Square(double a);
    [[nodiscard]] double P() const;
    [[nodiscard]] double S() const;
    [[nodiscard]] int angles() const;
private:
    double a;
};

class Rectangle: public Figure<Rectangle> {
public:
    explicit Rectangle(double a, double b);
    [[nodiscard]] double P() const;
    [[nodiscard]] double S() const;
    [[nodiscard]] int angles() const;
private:
    double a;
    double b;
};

class Triangle: public Figure<Triangle> {
public:
    explicit Triangle(double a, double b, double c);
    explicit Triangle(double a);
    [[nodiscard]] double P() const;
    [[nodiscard]] double S() const;
    [[nodiscard]] int angles() const;
private:
    double a;
    double b;
    double c;
    [[nodiscard]] bool NotExists() const;
    [[nodiscard]] bool IsDegenerated() const; //вырожден ли треугольник
};

class Circle: public Figure<Circle> {
public:
    explicit Circle(double r);
    [[nodiscard]] double P() const;
    [[nodiscard]] double S() const;
    [[nodiscard]] int angles() const;
private:
    double r;
};

class Ellipse: public Figure<Ellipse> {
public:
    explicit Ellipse(double a, double b);
    [[nodiscard]] double P() const;
    [[nodiscard]] double S() const;
    [[nodiscard]] int angles() const;
private:
    double a;
    double b;
};


#endif //INC_2_FIGURE_H
