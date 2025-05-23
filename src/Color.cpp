#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    // Default constructor (black)
    Color::Color() : red_(0), green_(0), blue_(0) {
    }

    // Copy constructor (copies predefined values)
    Color::Color(const Color &other) : red_(other.red_), green_(other.green_), blue_(other.blue_) {
    }

    // Constructor with custom values
    Color::Color(rgb_value red, rgb_value green, rgb_value blue)
        : red_(red), green_(green), blue_(blue) {
    }

    // Only read accessors for RGB values
    rgb_value Color::red() const {
        return red_;
    }

    rgb_value Color::green() const {
        return green_;
    }

    rgb_value Color::blue() const {
        return blue_;
    }

    // Mutable accessors for RGB values
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

// Used to read RGB values from a script file
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

// Used to write RGB values to output in the format R:G:B
std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int)c.red() << ":" << (int)c.green() << ":" << (int)c.blue();
    return output;
}
