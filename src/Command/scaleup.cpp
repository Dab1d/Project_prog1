//feito tiago
#include "Command/scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        scaleup::scaleup(int factorX, int factorY)
            : Command("scaleup"), scalex(factorX), scaley(factorY) {}

        Image* scaleup::apply(Image* src) {
            if (!src){
                return nullptr;
            }

            int w = src->width();
            int h = src->height();
            int nw = w * scalex;
            int nh = h * scaley;

            // nova img
            Image* output = new Image(nw, nh);

            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    Color c = src->at(i, j);
                    int xx = i * scalex;
                    int yy = j * scaley;
                    for (int yyy = yy; yyy < yy + scaley; ++yyy) {
                        for (int xxx = xx; xxx < xx + scalex; ++xxx) {
                            output->at(xxx, yyy) = c; // copia a cor
                        }
                    }
                }
            }
            delete src;
            return output;
        }

        std::string scaleup::toString() const {
            return "scaleup factors => " + std::to_string(scalex) + " , " + std::to_string(scaley);
        }
    }
}