//
// Created by 2006d on 13/05/2025.
//
#include "Command.hpp"
#include "Command/replace.h"

#include <float.h>
#include <sstream>
namespace prog {
    namespace command {

        replace::replace(rgb_value r1,rgb_value g1,rgb_value b1,rgb_value r2,rgb_value g2,rgb_value b2) : Command("replace"), r1_(r1),g1_(g1),b1_(b1),r2_(r2),g2_(g2),b2_(b2) {
        }

        replace::~replace() {}

        Image *replace::apply(Image *img) {
            //loop para alterar cada pixel da img
            Image *newimg = new Image(img->width(),img->height());
            for (int y = 0;y < img->height();y++) {
                for (int x = 0;x < img->width();x++) {
                    Color base = img->at(x,y);
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

        std::string replace::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}