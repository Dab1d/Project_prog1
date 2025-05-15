//
// Created by 2006d on 15/05/2025.
//
#include "Command/rotate_right.h"
#include <sstream>

namespace prog {
    namespace command {

        rotate_right::rotate_right() : Command("rotate_right") {}

        rotate_right::~rotate_right() {}

        Image *rotate_right::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();

            //img com dimensões trocadas
            Image *newImg = new Image(altura ,largura);

            //loop para inverter cada pixel da img
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    newImg->at(altura -y-1,x) = base;
                }
            }

            delete img;
            return newImg;
        }

        std::string rotate_right::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}