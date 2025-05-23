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
            // Get the width and height of the original image
            int largura = img->width();
            int altura = img->height();

            // New image the dimensions swap
            Image *newImg = new Image(altura ,largura);


            // Loop to perform a right (270° clockwise) rotation using the rotation matrix:
            //
            //     M(270°) = [cos(270°)  -sin(270°)]   = [0  1]
            //               [sin(270°)   cos(270°)]     [-1 0]
            //
            //     Applying M(270°) to a point [x, y] gives: [y, -x]
            //
            // Considering that the Y-axis points downward, y = -(-x);
            // and that the image coordinate system starts at the top-left corner,
            // (shift (0,0) to (-x,0)) we have:
            //
            //          x' = altura -1 -y
            //          y' = x

            for (int y = 0;y < altura;y++) {
                for (int x = 0;x < largura;x++) {
                    Color base = img->at(x, y);
                    newImg->at(altura-1 -y ,x) = base;
                }
            }
            // To prevent memory leaks
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