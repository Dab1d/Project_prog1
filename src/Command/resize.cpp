#include "Command/resize.h"
#include <sstream>

namespace prog {
    namespace command {

        //Constructor: initializes position and size of the crop area
        resize::resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

        resize::~resize() {}

        Image *resize::apply(Image *img) {
            //Iterators for the new image
            int new_x = 0, new_y = 0;

            //Upper bounds of the selected area
            int up_x = x_ + w_;
            int up_y = y_ + h_;

            //Create new image with specified width and height
            Image *newImg = new Image(up_x - x_, up_y - y_);

            //Loop through the selected section of the original image
            for (int y = y_; y < up_y; y++) {
                for (int x = x_; x < up_x; x++) {
                    //If the pixel is inside the original image, copy it
                    //Otherwise, default fill color is applied automatically
                    if (x < img->width() && y < img->height()) {
                        newImg->at(new_x, new_y) = img->at(x, y);
                    }
                    new_x++;
                }
                //Reset x counter and move to the next row
                new_x = 0;
                new_y++;
            }

            delete img; //Free memory of original image
            return newImg; //Return the resized (cropped) image
        }

        //Returns the command name as string
        std::string resize::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
