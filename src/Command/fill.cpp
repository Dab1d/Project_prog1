#include "Command.hpp"
#include "Command/fill.h"
#include <sstream>

namespace prog {
    namespace command {
        fill::fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b)
            : Command("fill"), x_(x), y_(y), w_(w), h_(h), r_(r), g_(g), b_(b) {}

        fill::~fill() {}

        Image* fill::apply(Image* img) {
            int largura = img->width();
            int altura = img->height();

            Color c(r_, g_, b_);

            int x_limite = x_ + w_;
            int y_limite = y_ + h_;

            for (int y = y_; y < y_limite; y++) {
                for (int x = x_; x < x_limite; x++) {
                    if (x >= 0 && x < largura && y >= 0 && y < altura)
                        img->at(x, y) = c;
                }
            }

            return img;
        }

        std::string fill::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
