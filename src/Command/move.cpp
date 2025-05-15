// feito por MegaMan em 15/5

#include "Command/move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        move::move(int offsetx, int offsety)
            : Command("move"), offsetx(offsetx), offsety(offsety) {}

        Image* move::apply(Image* img) {
            int largura = img->width();
            int altura = img->height();

            // meter o pixel 0,0 como fill
            Color fill = img->at(0, 0);
            Image* result = new Image(largura, altura, fill);

            // copiar os pixeis da og e colar na clone
            for (int y = 0; y < altura; ++y) {
                for (int x = 0; x < largura; ++x) {
                    int novox = x + offsetx;
                    int novoy = y + offsety;

                    if (novox < largura && novoy < altura) {
                        result->at(novox, novoy) = img->at(x, y);
                    }
                }
            }

            delete img;
            return result;
        }

        std::string move::toString() const {
            return "move " + std::to_string(offsetx) + " " + std::to_string(offsety);
        }
    }
}