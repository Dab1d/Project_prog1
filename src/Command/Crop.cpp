//
// Created by 2006d on 15/05/2025.
//
#include "Command/crop.hpp"
#include <sstream>

namespace prog {
    namespace command {

        crop::crop(int x,int y, int w, int h):Command("crop"), x_(x),y_(y),w_(w),h_(h) {};

        crop::~crop() {}

        Image *crop::apply(Image *img) {

            // iteradores da nova imagem
            int new_x=0,new_y = 0;

            // upper bounds da nova imagem, garantido que não ultrapassam os limites anteriores
            int up_x = (x_ + w_ > img->width() )? img->width() : x_ + w_;
            int up_y = (y_ + h_ > img-> height()) ? img->height() : y_ + h_;

            // nova imagem com as dimensões dadas:
            Image *newImg = new Image(up_x - x_,up_y -y_);

            // loop que percorre a secção da imagem orginal e copia para a nova
            for (int y = y_ ;y  < up_y;y++) {
                for (int x = x_; x < up_x ;x++) {
                    newImg -> at(new_x,new_y ) = img -> at(x,y);
                    new_x++;
                }
                new_x=0;
                new_y++;
            }

            delete img;
            return newImg;
        }

        std::string crop::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}

