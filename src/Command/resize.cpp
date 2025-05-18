//
// Created by 2006d on 18/05/2025.
//
#include "Command/resize.h"
#include <sstream>

namespace prog {
    namespace command {

        resize::resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

        resize::~resize() {}

        Image *resize::apply(Image *img) {
            // iteradores da nova imagem
            int new_x=0,new_y = 0;

            // upper bounds da nova imagem
            int up_x = x_ + w_;
            int up_y = y_ + h_;

            // nova imagem com as dimensões dadas:
            Image *newImg = new Image(up_x - x_,up_y -y_);

            // loop que percorre a secção da imagem orginal e copia para a nova
            for (int y = y_ ;y  < up_y;y++) {
                for (int x = x_; x < up_x ;x++) {

                    if (x < img->width() && y < img->height() ) {
                        newImg -> at(new_x,new_y ) = img -> at(x,y);
                    }
                    else {
                        //não sei explicar esta lina, preenchi a branco e começou a funcionar
                        newImg -> at(new_x,new_y ) = Color(255,255,255);
                    }
                    new_x++;
                }
                new_x=0;
                new_y++;
            }
            delete img;
            return newImg;
        }
        std::string resize::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}