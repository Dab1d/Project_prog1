#include "Command/crop.hpp"
#include <sstream>

namespace prog {
    namespace command {

        crop::crop(int x,int y, int w, int h):Command("crop"), x_(x),y_(y),w_(w),h_(h) {};

        crop::~crop() {}

        Image *crop::apply(Image *img) {

            // iterators for the new image
            int new_x=0,new_y = 0;

            // upper bounds of the new image, ensuring they don't exceed the original limits
            int up_x = (x_ + w_ > img->width() )? img->width() : x_ + w_;
            int up_y = (y_ + h_ > img-> height()) ? img->height() : y_ + h_;

            // new image with new dimensions
            Image *newImg = new Image(up_x - x_,up_y -y_);

            // loop that cross the selected portion of the original image
            // and copies it into the new one, starting at the given coordinates
            for (int y = y_ ;y  < up_y;y++) {
                for (int x = x_; x < up_x ;x++) {
                    //get the color to copy in the new image
                    newImg -> at(new_x,new_y ) = img -> at(x,y);
                    new_x++;
                }
                new_x=0;
                new_y++;
            }
            // to prevent iamge leaks
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

