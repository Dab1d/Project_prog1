#include "Command/Invert.h"
#include <sstream>

namespace prog {
    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {

            int width = img->width();
            int height = img->height();
            Image *newImg = new Image(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Color original = img->at(x, y);
                Color inverted(255 - original.red(), 255 - original.green(), 255 - original.blue());
                newImg->at(x, y) = inverted;
            }
         }

            delete img;
            return newImg;
        }

        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
