//
// Created by 2006d on 13/05/2025.
//
#include "Command.hpp"
#include "Command/To_gray_scale.h"
#include <sstream>
namespace prog {
    namespace command {

        To_gray_scale::To_gray_scale() : Command("To_gray_scale") {}

        To_gray_scale::~To_gray_scale() {}

        Image *To_gray_scale::apply(Image *img) {
            // Get the width and height of the original image
            int largura = img->width();
            int altura = img->height();

            // New image
            Image *newImg = new Image(largura, altura);

            // Loop to update each pixel in the image with the average of its RGB components: (r+g+b)/3
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    //average of the r,b,g
                    int cinza = (base.red() + base.green()+ base.blue())/3;
                    Color alterada( cinza, cinza, cinza);
                    newImg->at(x, y) = alterada;
                }
            }
            // To prevent memory leaks
            delete img;
            return newImg;
        }

        std::string To_gray_scale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
