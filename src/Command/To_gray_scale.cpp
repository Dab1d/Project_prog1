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
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();

            Image *newImg = new Image(largura, altura);

            //loop para alterar cada pixel da img
            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    int gray = (base.red() + base.green()+ base.blue())/3;
                    Color alterada( gray, gray, gray);
                    newImg->at(x, y) = alterada;
                }
            }

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
