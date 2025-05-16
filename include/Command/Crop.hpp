//
// Created by David on 15/05/2025.
//

#ifndef CROP_HPP
#define CROP_HPP
#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Crop: public Command {

        public:
            Crop(int x,int y, int w, int h):Command("Crop"), x_(x),y_(y),w_(w),h_(h) {};

            ~Crop();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x_, y_, w_ ,h_;
        };
    }
}
#endif //CROP_HPP
