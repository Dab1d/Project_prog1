#include "Command/move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        move::move(int offsetx, int offsety) // construtor
            : Command("move"), offsetx(offsetx), offsety(offsety) {}

        Image* move::apply(Image* img) {
            // dimensões da imagem
            int w = img->width();
            int h = img->height();

            // usa o pixel (0, 0) como cor fill
            Color fill = img->at(0, 0);
            Image* result = new Image(w, h, fill);

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int newx = x + offsetx;
                    int newy = y + offsety;

                    // copia o pixel se a nova posição estiver dentro dos limites da imagem
                    if (newx >= 0 && newx < w && newy >= 0 && newy < h) {
                        result->at(newx, newy) = img->at(x, y);
                    }
                }
            }

            delete img;
            return result;
        }

        // retorna o comando move e os seus valores offset como strings
        string move::toString() const {
            return "move " + to_string(offsetx) + " " + to_string(offsety);
        }
    }
}