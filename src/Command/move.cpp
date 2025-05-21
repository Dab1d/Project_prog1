// done by tiago

#include "Command/move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        move::move(int offsetx, int offsety)
            : Command("move"), offsetx(offsetx), offsety(offsety) {}

        // applies the move operation by shifting all pixels with the given offsets
        Image* move::apply(Image* img) {
            int w = img->width();
            int h = img->height();

            // use the pixel at (0, 0) as the fill color
            Color fill = img->at(0, 0);
            Image* result = new Image(w, h, fill);

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int newx = x + offsetx;
                    int newy = y + offsety;

                    // copy pixel if destination is in the image bounds
                    if (newx >= 0 && newx < w && newy >= 0 && newy < h) {
                        result->at(newx, newy) = img->at(x, y);
                    }
                }
            }

            delete img;
            return result;
        }

        // returns the move command and its offset values as a string
        string move::toString() const {
            return "move " + to_string(offsetx) + " " + to_string(offsety);
        }
    }
}