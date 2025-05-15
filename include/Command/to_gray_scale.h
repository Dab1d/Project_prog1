//
// Created by David on 15-05-2025.
//

#ifndef TO_GRAY_SCALE_H
#define TO_GRAY_SCALE_H
#include "Image.hpp"
#include "Command.hpp"
#include <string>

namespace prog {
  namespace command {

    class to_gray_scale : public Command {
        public:
        to_gray_scale();

        ~to_gray_scale();


        Image* apply(Image* base_img) override;
        std::string toString() const override;
    };
    }
}
#endif //TO_GRAY_SCALE_H
