//
// Created by Eduardo on 15/05/2025.
//
//
// Created by Eduardo on 15/05/2025.
//
#include "Command.hpp"
#include "Command/Hmirror.h"

namespace prog {
    namespace command {
        Hmirror::Hmirror() : Command("Hmirror") {}

        Hmirror::~Hmirror(){}

        Image *Hmirror::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();
            Image *newImg = new Image(largura, altura);

            //loop por todas as linhas, percorre cada linha e atribui a cada pixel da nova img a cor do pixel "oposto" na img original
            for (int y = 0; y < altura; y++) {
                for (int x = 0; x < largura; x++) {
                    newImg->at(x,y) = img->at(largura-x-1,y);
                }
            }
            return newImg;
        }
    }
}