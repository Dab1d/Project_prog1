
#include "Command/resize.h"
#include <sstream>

namespace prog {
    namespace command {

        resize::resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

        resize::~resize() {}

        Image *resize::apply(Image *img) {
            // iterators for new image
            int new_x=0,new_y = 0;

            // upper bounds of the new image
            int up_x = x_ + w_;
            int up_y = y_ + h_;

            // new image to be return
            Image *newImg = new Image(up_x - x_,up_y -y_);

            // Loop that copies the selected region from the original image to the new image
            for (int y = y_ ;y  < up_y;y++) {
                for (int x = x_; x < up_x ;x++) {

                    // If the pixel exists within the bounds of the original image, copy its color;
                    // otherwise, fill the pixel with a default color
                    if (x < img->width() && y < img->height() ) {
                        newImg -> at(new_x,new_y ) = img -> at(x,y);
                    }
                    new_x++;
                }
                //reset the iterator and moves to the next colum
                new_x=0;
                new_y++;
            }
            //to prevent memory leaks
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