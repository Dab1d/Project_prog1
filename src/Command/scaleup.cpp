// done by tiago

#include "Command/scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        scaleup::scaleup(int factorx, int factory)
            : Command("scaleup"), scalex(factorx), scaley(factory) {}

        Image* scaleup::apply(Image* src) {
            if (!src){
                return nullptr;
            }

            // declaring widths and heights for the image
            int w = src->width();
            int h = src->height();
            int nw = w * scalex;
            int nh = h * scaley;

            // new image with scaled dimensions, using pointer
            Image* output = new Image(nw, nh);

            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    Color c = src->at(i, j);
                    int xx = i * scalex;
                    int yy = j * scaley;
                    for (int yyy = yy; yyy < yy + scaley; ++yyy) {
                        for (int xxx = xx; xxx < xx + scalex; ++xxx) {
                            output->at(xxx, yyy) = c; // fills the pixels with the respective colour
                        }
                    }
                }
            }
            delete src;
            return output;
        }

        // returns the used values to scaleup the image
        string scaleup::toString() const {
            return "scaleup factors => " + to_string(scalex) + " , " + to_string(scaley);
        }
    }
}