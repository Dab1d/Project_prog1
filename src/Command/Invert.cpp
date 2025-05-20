#include "Command/Invert.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();

            Image *newImg = new Image(largura, altura);

        //loop para inverter cada pixel da imagem, pelo seu complemento (255-Color)
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

        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
