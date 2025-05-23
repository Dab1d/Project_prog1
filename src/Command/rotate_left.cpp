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
            // Get the width and height of the original image
                int largura = img->width();
                int altura = img->height();

            // New image the dimensions swap
                Image *newImg = new Image(altura ,largura);

            // Loop to perform a left (90° counterclockwise) rotation using the rotation matrix:
            //
            //     M(90°) = [cos(90°)  -sin(90°)]   = [0  -1]
            //              [sin(90°)   cos(90°)]     [1   0]
            //
            //     Applying M(90°) to a point [x, y] gives: [-y, x]
            //
            // Considering that the Y-axis points downward, y = -x;
            // and that the image coordinate system starts at the top-left corner,
            // (shift (0,0) to (-x,0)) we have:
            //
            //          x' = y
            //          y' = width - 1 - x

                for (int y = 0;y < altura;y++) {
                    for (int x = 0;x < largura;x++) {
                        Color base = img->at(x, y);
                        newImg->at(y,largura-x-1) = base;
                    }
                }
            //to prevent memory leaks
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