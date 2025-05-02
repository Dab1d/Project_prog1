//
// Created by JBispo on 05/04/2025.
//
#include "Command/Blank.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Blank::Blank(int w, int h, Color &fill) : Command("Blank"), w(w), h(h), fill(fill) {}

        Blank::~Blank() {};

        Image *Blank::apply(Image *img) {

            // Dispose of given image
            delete img;

            return new Image(w, h, fill);
        }


        std::string Blank::toString() const {
            std::ostringstream ss;
            ss << name() << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}