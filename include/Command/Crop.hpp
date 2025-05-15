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
            Crop();

            ~Crop();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}
#endif //CROP_HPP
