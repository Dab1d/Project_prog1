#include "Command/Slide.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Slide::Slide(int offsetx, int offsety)
            : Command("Slide"), offsetx(offsetx), offsety(offsety) {}

        // vai buscar a largura e altura originais
        Image* Slide::apply(Image* img) {
            int w = img->width();
            int h = img->height();

            // nova imagem vazia, usando pointer
            Image* result = new Image(w, h);

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    int novox = (x + offsetx) % w;
                    int novoy = (y + offsety) % h;

                    if (novox < 0){
                        novox += w;
                    }
                    if (novoy < 0){
                        novoy += h;
                    }

                    result->at(novox, novoy) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }

        // retorna os offsets usados para deslizar a imagem
        string Slide::toString() const {
            return "Slide " + to_string(offsetx) + " " + to_string(offsety);
        }
    }
}