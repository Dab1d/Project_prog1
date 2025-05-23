#include "Command/scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        scaleup::scaleup(int factorx, int factory) // construtor
            : Command("scaleup"), scalex(factorx), scaley(factory) {}

        Image* scaleup::apply(Image* src) {
            if (!src){
                return nullptr; //retorna nulo se a imagem for inválida
            }

            // declaração de alturas e larguras
            int w = src->width();
            int h = src->height();
            int nw = w * scalex;
            int nh = h * scaley;

            // nova imagem com dimensões ampliadas, usando pointers
            Image* output = new Image(nw, nh);

            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    Color c = src->at(i, j);
                    int xx = i * scalex;
                    int yy = j * scaley;
                    for (int yyy = yy; yyy < yy + scaley; ++yyy) {
                        for (int xxx = xx; xxx < xx + scalex; ++xxx) {
                            output->at(xxx, yyy) = c; // preenche os pixeis com a respetiva cor
                        }
                    }
                }
            }
            delete src;
            return output;
        }

        // retorna os valores usados para ampliar a imagem
        string scaleup::toString() const {
            return "scaleup factors => " + to_string(scalex) + " , " + to_string(scaley);
        }
    }
}