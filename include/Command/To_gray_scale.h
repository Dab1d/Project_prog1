//
// Created by David on 15-05-2025.
//

#ifndef TO_GRAY_SCALE_HPP
#define TO_GRAY_SCALE_HPP
#include "Image.hpp"
#include "Command.hpp"
#include <string>

namespace prog {
  namespace command {

    class To_gray_scale : public Command {
        public:
        To_gray_scale();

        ~To_gray_scale();


        Image* apply(Image* base_img) override;
        std::string toString() const override;
    };
    }
}
#endif //TO_GRAY_SCALE_HPP
