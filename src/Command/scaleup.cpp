#include "Command/scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        //Constructor: initializes scale factors for x and y
        scaleup::scaleup(int factorx, int factory)
            : Command("scaleup"), scalex(factorx), scaley(factory) {}

        Image* scaleup::apply(Image* src) {
            if (!src){
                return nullptr; //return null if image is invalid
            }

            //Original image width and height
            int w = src->width();
            int h = src->height();
            //New width and height after scaling
            int nw = w * scalex;
            int nh = h * scaley;

            //Create new image with scaled dimensions
            Image* output = new Image(nw, nh);

            //Loop through each pixel of original image
            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    Color c = src->at(i, j); //Get color of current pixel
                    int xx = i * scalex;
                    int yy = j * scaley;

                    //Fill corresponding pixels in new image according to scale factors
                    for (int yyy = yy; yyy < yy + scaley; ++yyy) {
                        for (int xxx = xx; xxx < xx + scalex; ++xxx) {
                            output->at(xxx, yyy) = c; //Assign color to scaled pixel block
                        }
                    }
                }
            }
            delete src; //Free original image memory
            return output; //Return scaled image
        }

        //Return string representation of scale factors
        string scaleup::toString() const {
            return "scaleup factors => " + to_string(scalex) + " , " + to_string(scaley);
        }
    }
}
