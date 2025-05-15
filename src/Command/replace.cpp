//
// Created by 2006d on 13/05/2025.
//
#include "Command.hpp"
#include "Command/replace.h"
#include <sstream>
namespace prog {
    namespace command {

        replace::replace(rgb_value r1,rgb_value g1,rgb_value b1,rgb_value r2,rgb_value g2,rgb_value b2) : Command("replace") {}

        replace::~replace() {}

        Image *replace::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();

            Image *newImg = new Image(largura, altura);

            //loop para alterar cada pixel da img
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color alterada( r2, g2, b2);
                    newImg->at(x, y) = alterada;
                }
            }

            delete img;
            return newImg;
        }

        std::string replace::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}