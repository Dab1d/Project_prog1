// feito pelo MegaMan(Tiago Ribeiro) en lo dia 12 del 5

#include "Command/slide.hpp"
#include <sstream>

namespace prog {
    namespace command {

        slide::slide(int offset_x, int offset_y)
            : Command("slide"), x_offset(offset_x), y_offset(offset_y) {}

        Image* slide::apply(Image* img) {
            int larg = img->width();
            int alt = img->height();

            Image* result = new Image(larg, alt);

            for (int y = 0; y < alt; y++) {
                for (int x = 0; x < larg; x++) {
                    int novo_x = (x + x_offset) % larg;
                    int novo_y = (y + y_offset) % alt;

                    if (novo_x < 0) novo_x += larg;
                    if (novo_y < 0) novo_y += alt;

                    result->at(novo_x, novo_y) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }

        std::string slide::toString() const {
            return "slide" + std::to_string(x_offset) + " " + std::to_string(y_offset);
        }

    } // namespace command
} // namespace prog