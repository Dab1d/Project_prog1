#ifndef REPLACE_HPP
#define REPLACE_HPP
#include "Image.hpp"
#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {

        class Replace : public Command {
        public:
            Replace(rgb_value r1,rgb_value g1,rgb_value b1,rgb_value r2,rgb_value g2,rgb_value b2); // constructor

            ~Replace(); // destructor

            Image* apply(Image* base_img) override;
            std::string toString() const override;

          private:
            rgb_value r1_,g1_,b1_,r2_,g2_,b2_;
        };
    }
}
#endif
