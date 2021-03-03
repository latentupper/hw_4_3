#include "Figure.h"
#include <iostream>
#include <functional>
#include <vector>

template<typename F>
double perimeter(Figure<F>* fig) {
    return fig->P();
}

template<typename F>
double square(F* fig) {
    return fig->S();
}

template<typename F, typename Fig>
class Vector {
public:
    Vector() {
        std::function<double(Fig*)> wrapped1(perimeter<Fig>);
        funcs.push_back(wrapped1);
        std::function<double(Fig*)> wrapped2(square<Fig>);
        funcs.push_back(wrapped2);
    }
    void call(Fig* fig) {
        for(int i=0; i<2; i++) {
            std::cout << funcs[i](fig) << std::endl;
        }
    }
private:
    std::vector<F> funcs;
};

int main() {
    Vector<std::function<double(Square*)>, Square> a_a;
    Vector<std::function<double(Rectangle*)>, Rectangle> b_b;
    Vector<std::function<double(Triangle*)>, Triangle> c_c;
    Vector<std::function<double(Circle*)>, Circle> d_d;
    Vector<std::function<double(Ellipse*)>, Ellipse> e_e;
    Square a(10);
    a_a.call(&a);
    Rectangle b(10, 20);
    b_b.call(&b);
    Triangle c(3, 4, 5);
    c_c.call(&c);
    Circle d(10);
    d_d.call(&d);
    Ellipse e(5, 4);
    e_e.call(&e);
    return 0;
}
