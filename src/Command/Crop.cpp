//
// Created by 2006d on 15/05/2025.
//
#include "Command/Crop.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Crop::Crop() : Command("Crop") {}

        Crop::~Crop() {}

        Image *Crop::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();

            Image *newImg = new Image(largura, altura);

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

        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}

