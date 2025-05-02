#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() {
    }

    Color::Color(const Color &other) {
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
    }

    rgb_value Color::red() const {
        return 0;
    }

    rgb_value Color::green() const {
        return 0;
    }

    rgb_value Color::blue() const {
        return 0;
    }

    // TODO: remove this DUMMY variable once you have appropriate fields for representing colors.
    rgb_value DUMMY_rgb_value = 0;

    rgb_value &Color::red() {
        return DUMMY_rgb_value;
    }

    rgb_value &Color::green() {
        return DUMMY_rgb_value;
    }

    rgb_value &Color::blue() {
        return DUMMY_rgb_value;
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
