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

            // New image
            Image *newimg = new Image(img->width(),img->height());

            //loop from swap the colors
            for (int y = 0;y < img->height();y++) {
                for (int x = 0;x < img->width();x++) {
                    //get the color at coords x,y;
                    Color orig = img->at(x,y);
                    // change the color if it matches with the color given
                    if (( r1_ == orig.red()) && ( g1_ == orig.green()) && ( b1_ == orig.blue())) {
                        newimg->at(x, y) = Color( r2_, g2_, b2_);
                    }
                    //else do nothing
                    else {
                        newimg ->at(x,y) = img->at(x,y);
                    }
                }
            }
            //to prevent memory leaks
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