// done by tiago

#include "Command/Slide.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Slide::Slide(int offsetx, int offsety)
            : Command("Slide"), offsetx(offsetx), offsety(offsety) {}

        // gets the original width and height
        Image* Slide::apply(Image* img) {
            int w = img->width();
            int h = img->height();

            // new blank image, using pointer
            Image* result = new Image(w, h);

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    int novox = (x + offsetx) % w;
                    int novoy = (y + offsety) % h;

                    if (novox < 0) novox += w;
                    if (novoy < 0) novoy += h;

                    result->at(novox, novoy) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }

        // returns the slide offsets used to transform the image
        std::string Slide::toString() const {
            return "Slide " + std::to_string(offsetx) + " " + std::to_string(offsety);
        }
    }
}