#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    //constructor defaut (preto)
    Color::Color(): red_(0), green_(0),blue_(0){
    }
    //constructor de cópia (com valores predefinidos)
    Color::Color(const Color &other): red_(other.red_), green_(other.green_), blue_(other.blue_) {
    }
    // constructor sem valores predefenidos
    Color::Color(rgb_value red, rgb_value green, rgb_value blue):red_(red),green_(green),blue_(blue) {
    }
    //ler valores de RGB constantes
    rgb_value Color::red() const {
        return red_;
    }

    rgb_value Color::green() const {
        return green_;
    }

    rgb_value Color::blue() const {
        return blue_;
    }

    //valores RBG que podem sofrer alterações
    rgb_value &Color::red() {
        return red_;
    }

    rgb_value &Color::green() {
        return green_;
    }

    rgb_value &Color::blue() {
        return blue_;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
