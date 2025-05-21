// Created by Eduardo on 16/05/2025.

#ifndef FILL_H
#define FILL_H

#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class fill : public Command {
        public:
            fill(int x, int y, int w, int h, rgb_value red, rgb_value green, rgb_value blue);

            ~fill();

            Image* apply(Image* base_img) override;

            std::string toString() const override;
        private:
            int x_, y_, w_, h_;
            rgb_value r_, g_, b_;
        };
    }
}

#endif // FILL_H
