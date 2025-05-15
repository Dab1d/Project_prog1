//
// Created by Davidf on 15-05-2025.
//

#ifndef REPLACE_H
#define REPLACE_H
#include "Image.hpp"
#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {

        class replace : public Command {
        public:
            replace(rgb_value r1,rgb_value g1,rgb_value b1,rgb_value r2,rgb_value g2,rgb_value b2);

            ~replace();

            Image* apply(Image* base_img) override;
            std::string toString() const override;

          private:
            rgb_value r1_,g1_,b1_,r2_,g2_,b2_;
        };
    }
}
#endif //REPLACE_H
