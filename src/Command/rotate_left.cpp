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

            //img com dimensões trocadas
            Image *newImg = new Image(altura ,largura);

            //loop para rodar para a esquerda através da matriz de rotação [cos(90)  -sin(90)] [x]
            //                                                             [sin(90)   cos(90)] [y]
            //x' = -y e y' = x, e ajustando ao refencial da imagem(canto superior esquerdo)
            //x'= y e y =

            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    newImg->at(y,largura-x-1) = base;
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