//
// Created by 2006d on 13/05/2025.
//
#include "Command.hpp"
#include "Command/Replace.hpp"

#include <sstream>
namespace prog {
    namespace command {

        Replace::Replace(rgb_value r1,rgb_value g1,rgb_value b1,rgb_value r2,rgb_value g2,rgb_value b2) : Command("Replace"), r1_(r1),g1_(g1),b1_(b1),r2_(r2),g2_(g2),b2_(b2) {
        }

        Replace::~Replace() {
        }

        Image *Replace::apply(Image *img) {

            //Nova imagem com as mesmas dimensões da original
            Image *newimg = new Image(img->width(),img->height());

            //loop para alterar os pixeis selecionados da imagem
            for (int y = 0;y < img->height();y++) {
                for (int x = 0;x < img->width();x++) {
                    //Cor do pixel nas cordenadas x y
                    Color base = img->at(x,y);
                    // caso seja a cor selecionada para trocar
                    if (( r1_ == base.red()) && ( g1_ == base.green()) && ( b1_ == base.blue())) {
                        newimg->at(x, y) = Color( r2_, g2_, b2_);
                    }
                    else {
                        newimg ->at(x,y) = img->at(x,y);
                    }
                }
            }

            delete img;
            return newimg;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}