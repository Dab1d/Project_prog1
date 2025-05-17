//
// Created by David on 15/05/2025.
//

#ifndef CROP_HPP
#define CROP_HPP
#include <string>
#include "Command.hpp"

namespace prog {
    namespace command {
        class crop: public Command {

        public:
            crop(int x,int y, int w, int h);

            ~crop();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x_, y_, w_ ,h_;
        };
    }
}
#endif //CROP_HPP
