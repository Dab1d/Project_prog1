#include "Command/Invert.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {
            //get the bounds of class image
            int largura = img->width();
            int altura = img->height();

            // new image with the same dimensions
            Image *newImg = new Image(largura, altura);

            // loop to invert all colors with the complent color (255-color)
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    Color alterada(255 - base.red(), 255 - base.green(), 255 - base.blue());
                    newImg->at(x, y) = alterada;
                }
            }
            // to prevent memory leaks
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
