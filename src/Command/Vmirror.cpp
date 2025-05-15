//
// Created by Eduardo on 15/05/2025.
//
#include "Command.hpp"
#include "Command/v_mirror.h"

namespace prog {
    namespace command {
        v_mirror::v_mirror() : Command("v_mirror") {}

        v_mirror::~v_mirror(){}

        Image *v_mirror::apply(Image *img) {
            //obter valores da class img
            int largura = img->width();
            int altura = img->height();
            Image *newImg = new Image(largura, altura);

            //loop por todas as colunas, percorre cada coluna e atribui a cada pixel da nova img a cor do do  pixel "oposto" na img original
            for (int x = 0; x < largura; x++) {
                for (int y = 0; y < altura; y++) {
                    newImg->at(x,y) = img->at(x,altura-1-y);
                }
            }
            return newImg;
        }
    }
}