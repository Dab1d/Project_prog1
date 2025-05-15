//
// Created by 2006d on 15/05/2025.
//
#include "Command/rotate_left.h"
#include <sstream>

namespace prog {
    namespace command {

        rotate_left::rotate_left() : Command("rotate_left") {}

        rotate_left::~rotate_left() {}

        Image *rotate_left::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();


            Image *newImg = new Image(altura ,largura);

            //loop para inverter cada pixel da img
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    Color alterada(255 - base.red(), 255 - base.green(), 255 - base.blue());
                    newImg->at(x, y) = alterada;
                }
            }

            delete img;
            return newImg;
        }

        std::string rotate_left::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}