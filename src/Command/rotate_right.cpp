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


            // loop para rodar para a direita através da matriz de rotação:
            //
            //    M(90º) = [cos(270°)  -sin(270°)]   [0  1]
            //             [sin(270°)   cos(270°)] = [-1 0]
            //
            //  M(90º)[x',y'] ==> [y,-x]
            //
            // e considerando que o eixo oY aponta para baixo y' = -(-x),
            //e o sistema de coordenados da imagem que começa no top left corner temos que
            //
            //          x'= altura -1 -y e y' = x

            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);

                    newImg->at(altura-1 -y ,x) = base;
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